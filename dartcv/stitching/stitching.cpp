/*
    Created by Rainyl.
    Licensed: Apache 2.0 license. Copyright (c) 2024 Rainyl.
*/

#include "dartcv/stitching/stitching.h"
#include "dartcv/core/vec.hpp"

CvStatus* cv_Stitcher_create(int mode, Stitcher* rval) {
    BEGIN_WRAP
    const auto ptr = cv::Stitcher::create(static_cast<cv::Stitcher::Mode>(mode));
    rval->ptr = new cv::Ptr<cv::Stitcher>(ptr);
    END_WRAP
}

void cv_Stitcher_close(StitcherPtr stitcher) {
    stitcher->ptr->reset();
    CVD_FREE(stitcher);
}

double cv_Stitcher_get_registrationResol(Stitcher self) {
    return (CVDEREF(self))->registrationResol();
}
void cv_Stitcher_set_registrationResol(Stitcher self, double val) {
    (CVDEREF(self))->setRegistrationResol(val);
}

double cv_Stitcher_get_seamEstimationResol(Stitcher self) {
    return (CVDEREF(self))->seamEstimationResol();
}
void cv_Stitcher_set_seamEstimationResol(Stitcher self, double val) {
    (CVDEREF(self))->setSeamEstimationResol(val);
}

double cv_Stitcher_get_compositingResol(Stitcher self) {
    return (CVDEREF(self))->compositingResol();
}
void cv_Stitcher_set_compositingResol(Stitcher self, double val) {
    (CVDEREF(self))->setCompositingResol(val);
}

double cv_Stitcher_get_panoConfidenceThresh(Stitcher self) {
    return (CVDEREF(self))->panoConfidenceThresh();
}
void cv_Stitcher_set_panoConfidenceThresh(Stitcher self, double val) {
    (CVDEREF(self))->setPanoConfidenceThresh(val);
}

bool cv_Stitcher_get_waveCorrection(Stitcher self) {
    return (CVDEREF(self))->waveCorrection();
}
void cv_Stitcher_set_waveCorrection(Stitcher self, bool val) {
    (CVDEREF(self))->setWaveCorrection(val);
}

int cv_Stitcher_get_interpolationFlags(Stitcher self) {
    return (CVDEREF(self))->interpolationFlags();
}
void cv_Stitcher_set_interpolationFlags(Stitcher self, int val) {
    (CVDEREF(self))->setInterpolationFlags(static_cast<cv::InterpolationFlags>(val));
}

int cv_Stitcher_get_waveCorrectKind(Stitcher self) {
    return (CVDEREF(self))->waveCorrectKind();
}
void cv_Stitcher_set_waveCorrectKind(Stitcher self, int val) {
    (CVDEREF(self))->setWaveCorrectKind(static_cast<cv::detail::WaveCorrectKind>(val));
}

CvStatus* Stitcher_EstimateTransform(
    Stitcher self, VecMat mats, VecMat masks, int* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _mats = vecmat_c2cpp(mats);
    if (masks.length > 0) {
        auto _masks = vecmat_c2cpp(masks);
        *rval = static_cast<int>((CVDEREF(self))->estimateTransform(_mats, _masks));
    } else {
        *rval = static_cast<int>((CVDEREF(self))->estimateTransform(_mats));
    }
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* Stitcher_ComposePanorama(Stitcher self, Mat rpano, int* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    *rval = static_cast<int>((CVDEREF(self))->composePanorama(CVDEREF(rpano)));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* Stitcher_ComposePanorama_1(
    Stitcher self, VecMat mats, Mat rpano, int* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _mats = vecmat_c2cpp(mats);
    *rval = static_cast<int>((CVDEREF(self))->composePanorama(_mats, CVDEREF(rpano)));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* Stitcher_Stitch(Stitcher self, VecMat mats, Mat rpano, int* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    auto _mats = vecmat_c2cpp(mats);
    *rval = static_cast<int>((CVDEREF(self))->stitch(_mats, CVDEREF(rpano)));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* Stitcher_Stitch_1(
    Stitcher self, VecMat mats, VecMat masks, Mat rpano, int* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _mats = vecmat_c2cpp(mats);
    auto _masks = vecmat_c2cpp(masks);
    *rval = static_cast<int>((CVDEREF(self))->stitch(_mats, _masks, CVDEREF(rpano)));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* Stitcher_Component(Stitcher self, VecI32* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    std::vector<int> _rval = (CVDEREF(self))->component();
    *rval = vecint_cpp2c(_rval);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
