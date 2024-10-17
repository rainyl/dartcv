#include "dartcv/contrib/wechat_qrcode.h"
#include "dartcv/core/vec.hpp"
#include <vector>

CvStatus* cv_wechat_qrcode_WeChatQRCode_create(WeChatQRCode* qrcode) {
    BEGIN_WRAP
    qrcode->ptr = new cv::wechat_qrcode::WeChatQRCode();
    END_WRAP
}

CvStatus* cv_wechat_qrcode_WeChatQRCode_create_1(
    const char* detector_prototxt_path,
    const char* detector_caffe_model_path,
    const char* super_resolution_prototxt_path,
    const char* super_resolution_caffe_model_path,
    WeChatQRCode* qrcode,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    qrcode->ptr = new cv::wechat_qrcode::WeChatQRCode(
        detector_prototxt_path,
        detector_caffe_model_path,
        super_resolution_prototxt_path,
        super_resolution_caffe_model_path
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_wechat_qrcode_WeChatQRCode_close(WeChatQRCodePtr self) {
    CVD_FREE(self);
}

CvStatus* cv_wechat_qrcode_WeChatQRCode_detectAndDecode(
    WeChatQRCode self, Mat img, VecMat* points, VecVecChar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Mat> pts;

    auto strings = self.ptr->detectAndDecode(*img.ptr, pts);
    *points = vecmat_cpp2c(pts);

    std::vector<std::vector<char>> cstrings;
    cstrings.reserve(strings.size());
    for (auto s : strings) {
        cstrings.emplace_back(s.begin(), s.end());
    }
    *rval = vecvecchar_cpp2c(cstrings);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_wechat_qrcode_WeChatQRCode_getScaleFactor(
    WeChatQRCode self, float* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    *rval = self.ptr->getScaleFactor();
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_wechat_qrcode_WeChatQRCode_setScaleFactor(
    WeChatQRCode self, float scale_factor, CvCallback_0 callback
) {
    BEGIN_WRAP
    self.ptr->setScaleFactor(scale_factor);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
