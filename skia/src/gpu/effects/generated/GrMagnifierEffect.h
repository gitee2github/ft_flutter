/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrMagnifierEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrMagnifierEffect_DEFINED
#define GrMagnifierEffect_DEFINED
#include "include/core/SkTypes.h"

#include "src/gpu/GrCoordTransform.h"
#include "src/gpu/GrFragmentProcessor.h"
class GrMagnifierEffect : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(sk_sp<GrTextureProxy> src, SkIRect bounds,
                                                     SkRect srcRect, float xInvZoom, float yInvZoom,
                                                     float xInvInset, float yInvInset) {
        return std::unique_ptr<GrFragmentProcessor>(new GrMagnifierEffect(
                src, bounds, srcRect, xInvZoom, yInvZoom, xInvInset, yInvInset));
    }
    GrMagnifierEffect(const GrMagnifierEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "MagnifierEffect"; }
    GrCoordTransform srcCoordTransform;
    TextureSampler src;
    SkIRect bounds;
    SkRect srcRect;
    float xInvZoom;
    float yInvZoom;
    float xInvInset;
    float yInvInset;

private:
    GrMagnifierEffect(sk_sp<GrTextureProxy> src, SkIRect bounds, SkRect srcRect, float xInvZoom,
                      float yInvZoom, float xInvInset, float yInvInset)
            : INHERITED(kGrMagnifierEffect_ClassID, kNone_OptimizationFlags)
            , srcCoordTransform(SkMatrix::I(), src.get())
            , src(std::move(src))
            , bounds(bounds)
            , srcRect(srcRect)
            , xInvZoom(xInvZoom)
            , yInvZoom(yInvZoom)
            , xInvInset(xInvInset)
            , yInvInset(yInvInset) {
        this->setTextureSamplerCnt(1);
        this->addCoordTransform(&srcCoordTransform);
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    const TextureSampler& onTextureSampler(int) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif
