#include "utils.h"

VecU8* cv_yuv420_888_to_nv21(VecU8 y, VecU8 u, VecU8 v, size_t width, size_t height) {
    if (width == 0 || height == 0) {
        return nullptr;
    }
    const size_t y_size = width * height;
    const size_t uv_size = y_size / 4;

    // uint8_t* nv21 = new uint8_t[(height + height / 2) * width];
    uint8_t* nv21_ptr = new uint8_t[y.length + u.length + v.length];
    memcpy(nv21_ptr, y.ptr, y_size);

    for (int i = 0; i < uv_size; ++i) {
        nv21_ptr[y_size + 2 * i] = v.ptr[i];  // V first in NV21
        nv21_ptr[y_size + 2 * i + 1] = u.ptr[i];  // U second in NV21
    }
    return new VecU8{nv21_ptr, (y.length + u.length + v.length)};
}
