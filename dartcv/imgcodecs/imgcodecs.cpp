/*
    This file is originally from gocv project
    Licensed: Apache 2.0 license. Copyright (c) 2017-2021 The Hybrid Group.

    Modified by Rainyl.
    Licensed: Apache 2.0 license. Copyright (c) 2024 Rainyl.
*/

#include "dartcv/imgcodecs/imgcodecs.h"
#include "dartcv/core/vec.hpp"
#include <vector>

bool cv_haveImageReader(const char* filename) {
    return cv::haveImageReader(filename);
}
bool cv_haveImageWriter(const char* filename) {
    return cv::haveImageWriter(filename);
}
size_t cv_imcount(const char* filename, int flags) {
    return cv::imcount(filename, flags);
}

CvStatus* cv_imdecode(VecUChar buf, int flags, Mat rval, CvCallback_0 callback) {
    BEGIN_WRAP
    auto _buf = vecuchar_c2cpp(buf);
    auto m = cv::imdecode(_buf, flags);
    rval.ptr = new cv::Mat(m);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_imencode(
    const char* fileExt, Mat img, bool* success, VecUChar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<uchar> buf;
    *success = cv::imencode(fileExt, CVDEREF(img), buf);
    *rval = vecuchar_cpp2c(buf);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_imencode_1(
    const char* fileExt,
    Mat img,
    VecI32 params,
    bool* success,
    VecUChar* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<uchar> buf;
    auto _params = vecint_c2cpp(params);
    *success = cv::imencode(fileExt, CVDEREF(img), buf, _params);
    *rval = vecuchar_cpp2c(buf);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_imread(const char* filename, int flags, Mat rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval.ptr = new cv::Mat(cv::imread(filename, flags));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_imwrite(const char* filename, Mat img, bool* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    *rval = cv::imwrite(filename, CVDEREF(img));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_imwrite_1(
    const char* filename, Mat img, VecI32 params, bool* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _params = vecint_c2cpp(params);
    *rval = cv::imwrite(filename, CVDEREF(img), _params);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
