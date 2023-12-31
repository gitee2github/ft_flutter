/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "src/gpu/text/GrAtlasManager.h"

#include "src/gpu/GrGlyph.h"
#include "src/gpu/text/GrStrikeCache.h"

GrAtlasManager::GrAtlasManager(GrProxyProvider* proxyProvider, GrStrikeCache* glyphCache,
                               size_t maxTextureBytes,
                               GrDrawOpAtlas::AllowMultitexturing allowMultitexturing,
                               int plotOldThreshold)
            : fAllowMultitexturing{allowMultitexturing}
            , fProxyProvider{proxyProvider}
            , fCaps{fProxyProvider->refCaps()}
            , fGlyphCache{glyphCache}
            , fAtlasConfig{fCaps->maxTextureSize(), maxTextureBytes}
            , fPlotOldThreshold(plotOldThreshold)
            , fAtlasHitCount(0)
            , fAtlasMissCount(0) { }

GrAtlasManager::~GrAtlasManager() = default;

static GrColorType mask_format_to_gr_color_type(GrMaskFormat format) {
    switch (format) {
        case kA8_GrMaskFormat:
            return GrColorType::kAlpha_8;
        case kA565_GrMaskFormat:
            return GrColorType::kBGR_565;
        case kARGB_GrMaskFormat:
            return GrColorType::kRGBA_8888;
        default:
            SkDEBUGFAIL("unsupported GrMaskFormat");
            return GrColorType::kAlpha_8;
    }
}

void GrAtlasManager::freeAll() {
    for (int i = 0; i < kMaskFormatCount; ++i) {
        fAtlases[i] = nullptr;
    }
}

bool GrAtlasManager::hasGlyph(GrGlyph* glyph) {
    SkASSERT(glyph);
    return this->getAtlas(glyph->fMaskFormat)->hasID(glyph->fID);
}

// add to texture atlas that matches this format
GrDrawOpAtlas::ErrorCode GrAtlasManager::addToAtlas(
                                GrResourceProvider* resourceProvider,
                                GrStrikeCache* glyphCache,
                                GrTextStrike* strike, GrDrawOpAtlas::AtlasID* id,
                                GrDeferredUploadTarget* target, GrMaskFormat format,
                                int width, int height, const void* image, SkIPoint16* loc) {
    glyphCache->setStrikeToPreserve(strike);
    return this->getAtlas(format)->addToAtlas(resourceProvider, id, target, width, height,
                                              image, loc);
}

void GrAtlasManager::addGlyphToBulkAndSetUseToken(GrDrawOpAtlas::BulkUseTokenUpdater* updater,
                                                  GrGlyph* glyph,
                                                  GrDeferredUploadToken token) {
    SkASSERT(glyph);
    if (updater->add(glyph->fID)) {
        this->getAtlas(glyph->fMaskFormat)->setLastUseToken(glyph->fID, token);
    }
}

void GrAtlasManager::postFlush(GrDeferredUploadToken startTokenForNextFlush,
                   const uint32_t* opListIDs, int numOpListIDs) {
    bool isRadicals = false;
    static int count = 0;
    count++;
    if (count == 5) {
        float hitRate = atlasHitRate();
        if (!(fabs(hitRate-0) <= 1.0e-6)) {
#ifdef SK_DEGUB_ATLAS_HIT_RATE
            SkDebugf("----- last 5 flush AtlasHitRate = %{public}6.2f.", hitRate);
#endif
#ifdef SK_ENABLE_SMALL_PAGE
            if (hitRate < 0.2) {
                isRadicals = true;
            }
#endif
        }
        resetHitCount();
        count = 0;
    }

    for (int i = 0; i < kMaskFormatCount; ++i) {
        if (fAtlases[i]) {
            fAtlases[i]->compact(startTokenForNextFlush, isRadicals);
        }
    }
}

#ifdef SK_DUMP_ATLAS_IMAGE
#include "src/gpu/GrContextPriv.h"
#include "src/gpu/GrSurfaceContext.h"
#include "src/gpu/GrSurfaceProxy.h"
#include "src/gpu/GrTextureProxy.h"

#include "include/core/SkBitmap.h"
#include "include/core/SkImageEncoder.h"
#include "include/core/SkStream.h"
#include <stdio.h>

/**
  * Write the contents of the surface proxy to a PNG. Returns true if successful.
  * @param filename      Full path to desired file
  */
static bool save_pixels(GrContext* context, GrSurfaceProxy* sProxy, GrColorType colorType,
                        const char* filename) {
    if (!sProxy) {
        return false;
    }

    SkImageInfo ii = SkImageInfo::Make(sProxy->width(), sProxy->height(),
                                       kRGBA_8888_SkColorType, kPremul_SkAlphaType);
    SkBitmap bm;
    if (!bm.tryAllocPixels(ii)) {
        return false;
    }

    sk_sp<GrSurfaceContext> sContext(context->priv().makeWrappedSurfaceContext(
            sk_ref_sp(sProxy), colorType, kUnknown_SkAlphaType));
    if (!sContext || !sContext->asTextureProxy()) {
        return false;
    }

    bool result = sContext->readPixels(ii, bm.getPixels(), bm.rowBytes(), {0, 0});
    if (!result) {
        SkDebugf("------ failed to read pixels for %s\n", filename);
        return false;
    }

    // remove any previous version of this file
    remove(filename);

    SkFILEWStream file(filename);
    if (!file.isValid()) {
        SkDebugf("------ failed to create file: %s\n", filename);
        remove(filename);   // remove any partial file
        return false;
    }

    if (!SkEncodeImage(&file, bm, SkEncodedImageFormat::kPNG, 100)) {
        SkDebugf("------ failed to encode %s\n", filename);
        remove(filename);   // remove any partial file
        return false;
    }

    return true;
}

void GrAtlasManager::dump(GrContext* context) const {
    static int gDumpCount = 0;
    for (int i = 0; i < kMaskFormatCount; ++i) {
        if (fAtlases[i]) {
            const sk_sp<GrTextureProxy>* proxies = fAtlases[i]->getProxies();
            for (uint32_t pageIdx = 0; pageIdx < fAtlases[i]->numActivePages(); ++pageIdx) {
                SkASSERT(proxies[pageIdx]);
                SkString filename;
#ifdef SK_BUILD_FOR_ANDROID
                filename.printf("/sdcard/fontcache_%d%d%d.png", gDumpCount, i, pageIdx);
#else
                filename.printf("/data/storage/el2/base/cache/fontcache_%d_%d_%d.png", gDumpCount, i, pageIdx);
#endif
                auto ct = mask_format_to_gr_color_type(AtlasIndexToMaskFormat(i));
                save_pixels(context, proxies[pageIdx].get(), ct, filename.c_str());
            }
        }
    }
    ++gDumpCount;
}
#endif

void GrAtlasManager::setAtlasSizesToMinimum_ForTesting() {
    // Delete any old atlases.
    // This should be safe to do as long as we are not in the middle of a flush.
    for (int i = 0; i < kMaskFormatCount; i++) {
        fAtlases[i] = nullptr;
    }

    // Set all the atlas sizes to 1x1 plot each.
    new (&fAtlasConfig) GrDrawOpAtlasConfig{};
}

bool GrAtlasManager::initAtlas(GrMaskFormat format) {
    int index = MaskFormatToAtlasIndex(format);
    if (fAtlases[index] == nullptr) {
        GrColorType grColorType = mask_format_to_gr_color_type(format);
        int pageNum = 4; // The maximum number of texture pages in the original skia code is 4
#ifdef SK_ENABLE_SMALL_PAGE
        if (format == kA8_GrMaskFormat && fAtlasConfig.getARGBDimensions().width() > 512) {
            // reset fAtlasConfig to suit small page.
            pageNum = fAtlasConfig.resetAsSmallPage();
        }
#endif
        SkISize atlasDimensions = fAtlasConfig.atlasDimensions(format);
        SkISize plotDimensions = fAtlasConfig.plotDimensions(format);

        const GrBackendFormat format = fCaps->getDefaultBackendFormat(grColorType,
                                                                      GrRenderable::kNo);

        fAtlases[index] = GrDrawOpAtlas::Make(
                fProxyProvider, format, grColorType,
                atlasDimensions.width(), atlasDimensions.height(),
                plotDimensions.width(), plotDimensions.height(),
                fAllowMultitexturing, pageNum, fPlotOldThreshold, &GrStrikeCache::HandleEviction, fGlyphCache);
        if (!fAtlases[index]) {
            return false;
        }
    }
    return true;
}
