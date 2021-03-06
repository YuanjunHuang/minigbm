/*
 * Copyright 2017 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * Android graphics.h defines the formats and leaves 0x100 - 0x1FF
 * range available for HAL implementation specific formats.
 */

#ifndef i915_PRIVATE_ANDROID_TYPES_H_
#define i915_PRIVATE_ANDROID_TYPES_H_

#ifdef USE_GRALLOC1
#include <hardware/gralloc1.h>
#endif

enum { HAL_PIXEL_FORMAT_NV12_Y_TILED_INTEL = 0x100,
       HAL_PIXEL_FORMAT_NV12_LINEAR_INTEL = 0x101,
       HAL_PIXEL_FORMAT_YCrCb_422_H_INTEL = 0x102,
       HAL_PIXEL_FORMAT_NV12_LINEAR_PACKED_INTEL = 0x103,
       HAL_PIXEL_FORMAT_YCbCr_422_H_INTEL = 0x104,
       HAL_PIXEL_FORMAT_NV12_X_TILED_INTEL = 0x105,
       HAL_PIXEL_FORMAT_RGBA_5551_INTEL = 0x106,
       HAL_PIXEL_FORMAT_RGBA_4444_INTEL = 0x107,
       HAL_PIXEL_FORMAT_GENERIC_8BIT_INTEL = 0x108,
       HAL_PIXEL_FORMAT_YCbCr_411_INTEL = 0x109,
       HAL_PIXEL_FORMAT_YCbCr_420_H_INTEL = 0x10A,
       HAL_PIXEL_FORMAT_YCbCr_422_V_INTEL = 0x10B,
       HAL_PIXEL_FORMAT_YCbCr_444_INTEL = 0x10C,
       HAL_PIXEL_FORMAT_RGBP_INTEL = 0x10D,
       HAL_PIXEL_FORMAT_BGRP_INTEL = 0x10E,
       HAL_PIXEL_FORMAT_NV12_LINEAR_CAMERA_INTEL = 0x10F,
       HAL_PIXEL_FORMAT_P010_INTEL = 0x110,
       HAL_PIXEL_FORMAT_Z16_INTEL = 0x111,
       HAL_PIXEL_FORMAT_UVMAP64_INTEL = 0x112,
       HAL_PIXEL_FORMAT_A2R10G10B10_INTEL = 0x113,
       HAL_PIXEL_FORMAT_A2B10G10R10_INTEL = 0x114,
       HAL_PIXEL_FORMAT_YCrCb_NORMAL_INTEL = 0x115,
       HAL_PIXEL_FORMAT_YCrCb_SWAPUVY_INTEL = 0x116,
       HAL_PIXEL_FORMAT_YCrCb_SWAPUV_INTEL = 0x117,
       HAL_PIXEL_FORMAT_YCrCb_SWAPY_INTEL = 0x118,
       HAL_PIXEL_FORMAT_X2R10G10B10_INTEL = 0x119,
       HAL_PIXEL_FORMAT_X2B10G10R10_INTEL = 0x11A,
       HAL_PIXEL_FORMAT_P016_INTEL = 0x11C,
       HAL_PIXEL_FORMAT_Y210_INTEL = 0x11D,
       HAL_PIXEL_FORMAT_Y216_INTEL = 0x11E,
       HAL_PIXEL_FORMAT_Y410_INTEL = 0x11F,
       HAL_PIXEL_FORMAT_Y416_INTEL = 0x120,
       HAL_PIXEL_FORMAT_Y8I_INTEL = 0x121,
       HAL_PIXEL_FORMAT_Y12I_INTEL = 0x122,
       HAL_PIXEL_FORMAT_YUYV_INTEL = HAL_PIXEL_FORMAT_YCrCb_NORMAL_INTEL,
       HAL_PIXEL_FORMAT_YUY2_INTEL = HAL_PIXEL_FORMAT_YCrCb_NORMAL_INTEL,
       HAL_PIXEL_FORMAT_VYUY_INTEL = HAL_PIXEL_FORMAT_YCrCb_SWAPUVY_INTEL,
       HAL_PIXEL_FORMAT_YVYU_INTEL = HAL_PIXEL_FORMAT_YCrCb_SWAPUV_INTEL,
       HAL_PIXEL_FORMAT_UYVY_INTEL = HAL_PIXEL_FORMAT_YCrCb_SWAPY_INTEL,
       HAL_PIXEL_FORMAT_NV12_TILED_INTEL = HAL_PIXEL_FORMAT_NV12_Y_TILED_INTEL,
       HAL_PIXEL_FORMAT_NV12_INTEL = HAL_PIXEL_FORMAT_NV12_Y_TILED_INTEL,
       HAL_PIXEL_FORMAT_INTEL_NV12 = HAL_PIXEL_FORMAT_NV12_Y_TILED_INTEL,
       HAL_PIXEL_FORMAT_NV12 = 0x10F,
       HAL_PIXEL_FORMAT_YUV420PackedSemiPlanar_INTEL = 0x7FA00E00,
       HAL_PIXEL_FORMAT_YUV420PackedSemiPlanar_Tiled_INTEL = 0x7FA00F00,
};

#ifdef USE_GRALLOC1
enum { GRALLOC1_FUNCTION_SET_MODIFIER = 101,
       GRALLOC1_FUNCTION_GET_BYTE_STRIDE = 102,
       GRALLOC1_FUNCTION_GET_PRIME = 103,
       GRALLOC1_FUNCTION_SET_INTERLACE = 104,
       GRALLOC1_FUNCTION_SET_PROTECTIONINFO = 105,
       GRALLOC1_LAST_CUSTOM = 500 };

typedef int32_t /*gralloc1_error_t*/ (*GRALLOC1_PFN_SET_MODIFIER)(
    gralloc1_device_t *device, gralloc1_buffer_descriptor_t descriptor, uint64_t modifier);

typedef int32_t /*gralloc1_error_t*/ (*GRALLOC1_PFN_GET_BYTE_STRIDE)(
        gralloc1_device_t *device, buffer_handle_t buffer, uint32_t *outStride, uint32_t size);

typedef int32_t /*gralloc1_error_t*/ (*GRALLOC1_PFN_GET_PRIME)(
        gralloc1_device_t *device, buffer_handle_t buffer, uint32_t *prime);

typedef int32_t /*gralloc1_error_t*/ (*GRALLOC1_PFN_SET_INTERLACE)(
        gralloc1_device_t *device, buffer_handle_t buffer, uint32_t interlace);

typedef int32_t /*gralloc1_error_t*/ (*GRALLOC1_PFN_SET_PROTECTIONINFO)(
        gralloc1_device_t *device, buffer_handle_t buffer, uint32_t protection_info);

typedef union intel_protection_info_type_t {
       uint32_t value;
       struct {
           uint32_t is_encrypted  : 8;
           uint32_t pavp_sesion_id : 8;
           uint32_t pavp_instance_id: 16;
       };
}intel_protection_info_type_t;

#endif

#endif
