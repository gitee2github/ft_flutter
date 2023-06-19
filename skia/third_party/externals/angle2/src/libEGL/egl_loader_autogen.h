// GENERATED FILE - DO NOT EDIT.
// Generated by generate_loader.py using data from egl.xml and egl_angle_ext.xml.
//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// egl_loader_autogen.h:
//   Simple EGL function loader.

#ifndef LIBEGL_EGL_LOADER_AUTOGEN_H_
#define LIBEGL_EGL_LOADER_AUTOGEN_H_

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <export.h>

ANGLE_NO_EXPORT extern PFNEGLCHOOSECONFIGPROC EGL_ChooseConfig;
ANGLE_NO_EXPORT extern PFNEGLCOPYBUFFERSPROC EGL_CopyBuffers;
ANGLE_NO_EXPORT extern PFNEGLCREATECONTEXTPROC EGL_CreateContext;
ANGLE_NO_EXPORT extern PFNEGLCREATEPBUFFERSURFACEPROC EGL_CreatePbufferSurface;
ANGLE_NO_EXPORT extern PFNEGLCREATEPIXMAPSURFACEPROC EGL_CreatePixmapSurface;
ANGLE_NO_EXPORT extern PFNEGLCREATEWINDOWSURFACEPROC EGL_CreateWindowSurface;
ANGLE_NO_EXPORT extern PFNEGLDESTROYCONTEXTPROC EGL_DestroyContext;
ANGLE_NO_EXPORT extern PFNEGLDESTROYSURFACEPROC EGL_DestroySurface;
ANGLE_NO_EXPORT extern PFNEGLGETCONFIGATTRIBPROC EGL_GetConfigAttrib;
ANGLE_NO_EXPORT extern PFNEGLGETCONFIGSPROC EGL_GetConfigs;
ANGLE_NO_EXPORT extern PFNEGLGETCURRENTDISPLAYPROC EGL_GetCurrentDisplay;
ANGLE_NO_EXPORT extern PFNEGLGETCURRENTSURFACEPROC EGL_GetCurrentSurface;
ANGLE_NO_EXPORT extern PFNEGLGETDISPLAYPROC EGL_GetDisplay;
ANGLE_NO_EXPORT extern PFNEGLGETERRORPROC EGL_GetError;
ANGLE_NO_EXPORT extern PFNEGLGETPROCADDRESSPROC EGL_GetProcAddress;
ANGLE_NO_EXPORT extern PFNEGLINITIALIZEPROC EGL_Initialize;
ANGLE_NO_EXPORT extern PFNEGLMAKECURRENTPROC EGL_MakeCurrent;
ANGLE_NO_EXPORT extern PFNEGLQUERYCONTEXTPROC EGL_QueryContext;
ANGLE_NO_EXPORT extern PFNEGLQUERYSTRINGPROC EGL_QueryString;
ANGLE_NO_EXPORT extern PFNEGLQUERYSURFACEPROC EGL_QuerySurface;
ANGLE_NO_EXPORT extern PFNEGLSWAPBUFFERSPROC EGL_SwapBuffers;
ANGLE_NO_EXPORT extern PFNEGLTERMINATEPROC EGL_Terminate;
ANGLE_NO_EXPORT extern PFNEGLWAITGLPROC EGL_WaitGL;
ANGLE_NO_EXPORT extern PFNEGLWAITNATIVEPROC EGL_WaitNative;
ANGLE_NO_EXPORT extern PFNEGLBINDTEXIMAGEPROC EGL_BindTexImage;
ANGLE_NO_EXPORT extern PFNEGLRELEASETEXIMAGEPROC EGL_ReleaseTexImage;
ANGLE_NO_EXPORT extern PFNEGLSURFACEATTRIBPROC EGL_SurfaceAttrib;
ANGLE_NO_EXPORT extern PFNEGLSWAPINTERVALPROC EGL_SwapInterval;
ANGLE_NO_EXPORT extern PFNEGLBINDAPIPROC EGL_BindAPI;
ANGLE_NO_EXPORT extern PFNEGLQUERYAPIPROC EGL_QueryAPI;
ANGLE_NO_EXPORT extern PFNEGLCREATEPBUFFERFROMCLIENTBUFFERPROC EGL_CreatePbufferFromClientBuffer;
ANGLE_NO_EXPORT extern PFNEGLRELEASETHREADPROC EGL_ReleaseThread;
ANGLE_NO_EXPORT extern PFNEGLWAITCLIENTPROC EGL_WaitClient;
ANGLE_NO_EXPORT extern PFNEGLGETCURRENTCONTEXTPROC EGL_GetCurrentContext;
ANGLE_NO_EXPORT extern PFNEGLCREATESYNCPROC EGL_CreateSync;
ANGLE_NO_EXPORT extern PFNEGLDESTROYSYNCPROC EGL_DestroySync;
ANGLE_NO_EXPORT extern PFNEGLCLIENTWAITSYNCPROC EGL_ClientWaitSync;
ANGLE_NO_EXPORT extern PFNEGLGETSYNCATTRIBPROC EGL_GetSyncAttrib;
ANGLE_NO_EXPORT extern PFNEGLCREATEIMAGEPROC EGL_CreateImage;
ANGLE_NO_EXPORT extern PFNEGLDESTROYIMAGEPROC EGL_DestroyImage;
ANGLE_NO_EXPORT extern PFNEGLGETPLATFORMDISPLAYPROC EGL_GetPlatformDisplay;
ANGLE_NO_EXPORT extern PFNEGLCREATEPLATFORMWINDOWSURFACEPROC EGL_CreatePlatformWindowSurface;
ANGLE_NO_EXPORT extern PFNEGLCREATEPLATFORMPIXMAPSURFACEPROC EGL_CreatePlatformPixmapSurface;
ANGLE_NO_EXPORT extern PFNEGLWAITSYNCPROC EGL_WaitSync;
ANGLE_NO_EXPORT extern PFNEGLSETBLOBCACHEFUNCSANDROIDPROC EGL_SetBlobCacheFuncsANDROID;
ANGLE_NO_EXPORT extern PFNEGLGETCOMPOSITORTIMINGANDROIDPROC EGL_GetCompositorTimingANDROID;
ANGLE_NO_EXPORT extern PFNEGLGETCOMPOSITORTIMINGSUPPORTEDANDROIDPROC
    EGL_GetCompositorTimingSupportedANDROID;
ANGLE_NO_EXPORT extern PFNEGLGETFRAMETIMESTAMPSUPPORTEDANDROIDPROC
    EGL_GetFrameTimestampSupportedANDROID;
ANGLE_NO_EXPORT extern PFNEGLGETFRAMETIMESTAMPSANDROIDPROC EGL_GetFrameTimestampsANDROID;
ANGLE_NO_EXPORT extern PFNEGLGETNEXTFRAMEIDANDROIDPROC EGL_GetNextFrameIdANDROID;
ANGLE_NO_EXPORT extern PFNEGLGETNATIVECLIENTBUFFERANDROIDPROC EGL_GetNativeClientBufferANDROID;
ANGLE_NO_EXPORT extern PFNEGLDUPNATIVEFENCEFDANDROIDPROC EGL_DupNativeFenceFDANDROID;
ANGLE_NO_EXPORT extern PFNEGLPRESENTATIONTIMEANDROIDPROC EGL_PresentationTimeANDROID;
ANGLE_NO_EXPORT extern PFNEGLCREATEDEVICEANGLEPROC EGL_CreateDeviceANGLE;
ANGLE_NO_EXPORT extern PFNEGLRELEASEDEVICEANGLEPROC EGL_ReleaseDeviceANGLE;
ANGLE_NO_EXPORT extern PFNEGLQUERYDISPLAYATTRIBANGLEPROC EGL_QueryDisplayAttribANGLE;
ANGLE_NO_EXPORT extern PFNEGLQUERYSTRINGIANGLEPROC EGL_QueryStringiANGLE;
ANGLE_NO_EXPORT extern PFNEGLPROGRAMCACHEGETATTRIBANGLEPROC EGL_ProgramCacheGetAttribANGLE;
ANGLE_NO_EXPORT extern PFNEGLPROGRAMCACHEPOPULATEANGLEPROC EGL_ProgramCachePopulateANGLE;
ANGLE_NO_EXPORT extern PFNEGLPROGRAMCACHEQUERYANGLEPROC EGL_ProgramCacheQueryANGLE;
ANGLE_NO_EXPORT extern PFNEGLPROGRAMCACHERESIZEANGLEPROC EGL_ProgramCacheResizeANGLE;
ANGLE_NO_EXPORT extern PFNEGLQUERYSURFACEPOINTERANGLEPROC EGL_QuerySurfacePointerANGLE;
ANGLE_NO_EXPORT extern PFNEGLCREATESTREAMPRODUCERD3DTEXTUREANGLEPROC
    EGL_CreateStreamProducerD3DTextureANGLE;
ANGLE_NO_EXPORT extern PFNEGLSTREAMPOSTD3DTEXTUREANGLEPROC EGL_StreamPostD3DTextureANGLE;
ANGLE_NO_EXPORT extern PFNEGLGETSYNCVALUESCHROMIUMPROC EGL_GetSyncValuesCHROMIUM;
ANGLE_NO_EXPORT extern PFNEGLQUERYDEVICEATTRIBEXTPROC EGL_QueryDeviceAttribEXT;
ANGLE_NO_EXPORT extern PFNEGLQUERYDEVICESTRINGEXTPROC EGL_QueryDeviceStringEXT;
ANGLE_NO_EXPORT extern PFNEGLQUERYDISPLAYATTRIBEXTPROC EGL_QueryDisplayAttribEXT;
ANGLE_NO_EXPORT extern PFNEGLCREATEPLATFORMPIXMAPSURFACEEXTPROC EGL_CreatePlatformPixmapSurfaceEXT;
ANGLE_NO_EXPORT extern PFNEGLCREATEPLATFORMWINDOWSURFACEEXTPROC EGL_CreatePlatformWindowSurfaceEXT;
ANGLE_NO_EXPORT extern PFNEGLGETPLATFORMDISPLAYEXTPROC EGL_GetPlatformDisplayEXT;
ANGLE_NO_EXPORT extern PFNEGLDEBUGMESSAGECONTROLKHRPROC EGL_DebugMessageControlKHR;
ANGLE_NO_EXPORT extern PFNEGLLABELOBJECTKHRPROC EGL_LabelObjectKHR;
ANGLE_NO_EXPORT extern PFNEGLQUERYDEBUGKHRPROC EGL_QueryDebugKHR;
ANGLE_NO_EXPORT extern PFNEGLCLIENTWAITSYNCKHRPROC EGL_ClientWaitSyncKHR;
ANGLE_NO_EXPORT extern PFNEGLCREATESYNCKHRPROC EGL_CreateSyncKHR;
ANGLE_NO_EXPORT extern PFNEGLDESTROYSYNCKHRPROC EGL_DestroySyncKHR;
ANGLE_NO_EXPORT extern PFNEGLGETSYNCATTRIBKHRPROC EGL_GetSyncAttribKHR;
ANGLE_NO_EXPORT extern PFNEGLCREATEIMAGEKHRPROC EGL_CreateImageKHR;
ANGLE_NO_EXPORT extern PFNEGLDESTROYIMAGEKHRPROC EGL_DestroyImageKHR;
ANGLE_NO_EXPORT extern PFNEGLCREATESTREAMKHRPROC EGL_CreateStreamKHR;
ANGLE_NO_EXPORT extern PFNEGLDESTROYSTREAMKHRPROC EGL_DestroyStreamKHR;
ANGLE_NO_EXPORT extern PFNEGLQUERYSTREAMKHRPROC EGL_QueryStreamKHR;
ANGLE_NO_EXPORT extern PFNEGLQUERYSTREAMU64KHRPROC EGL_QueryStreamu64KHR;
ANGLE_NO_EXPORT extern PFNEGLSTREAMATTRIBKHRPROC EGL_StreamAttribKHR;
ANGLE_NO_EXPORT extern PFNEGLSTREAMCONSUMERACQUIREKHRPROC EGL_StreamConsumerAcquireKHR;
ANGLE_NO_EXPORT extern PFNEGLSTREAMCONSUMERGLTEXTUREEXTERNALKHRPROC
    EGL_StreamConsumerGLTextureExternalKHR;
ANGLE_NO_EXPORT extern PFNEGLSTREAMCONSUMERRELEASEKHRPROC EGL_StreamConsumerReleaseKHR;
ANGLE_NO_EXPORT extern PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC EGL_SwapBuffersWithDamageKHR;
ANGLE_NO_EXPORT extern PFNEGLWAITSYNCKHRPROC EGL_WaitSyncKHR;
ANGLE_NO_EXPORT extern PFNEGLPOSTSUBBUFFERNVPROC EGL_PostSubBufferNV;
ANGLE_NO_EXPORT extern PFNEGLSTREAMCONSUMERGLTEXTUREEXTERNALATTRIBSNVPROC
    EGL_StreamConsumerGLTextureExternalAttribsNV;

namespace angle
{
using GenericProc = void (*)();
using LoadProc    = GenericProc(KHRONOS_APIENTRY *)(const char *);
ANGLE_NO_EXPORT void LoadEGL_EGL(LoadProc loadProc);
}  // namespace angle

#endif  // LIBEGL_EGL_LOADER_AUTOGEN_H_
