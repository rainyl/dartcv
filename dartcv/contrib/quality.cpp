#include "dartcv/contrib/quality.h"

CvStatus* cv_quality_QualityBRISQUE_create(
    const char* model_file, const char* range_file, QualityBRISQUE* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr = new cv::Ptr<cv::quality::QualityBRISQUE>(
        cv::quality::QualityBRISQUE::create(model_file, range_file)
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_quality_QualityBRISQUE_close(QualityBRISQUEPtr self) {
    self->ptr->reset();
    CVD_FREE(self);
}

CvStatus* cv_quality_QualityBRISQUE_compute(
    QualityBRISQUE self, Mat img, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = (*self.ptr)->compute(*img.ptr);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_quality_QualityBRISQUE_compute_static(
    Mat img, const char* model_file, const char* range_file, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = cv::quality::QualityBRISQUE::compute(*img.ptr, model_file, range_file);
    if (callback != nullptr) {
        callback();
    }
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    END_WRAP
}

CvStatus* cv_quality_QualityBRISQUE_computeFeatures_static(
    Mat img, Mat features, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::quality::QualityBRISQUE::computeFeatures(*img.ptr, *features.ptr);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_quality_QualityGMSD_create(Mat ref, QualityGMSD* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    *rval = {new cv::Ptr<cv::quality::QualityGMSD>(cv::quality::QualityGMSD::create(*ref.ptr))};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_quality_QualityGMSD_close(QualityGMSDPtr self) {
    self->ptr->reset();
    CVD_FREE(self);
}

CvStatus* cv_quality_QualityGMSD_compute(
    QualityGMSD self, Mat cmp, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = (*self.ptr)->compute(*cmp.ptr);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_quality_QualityGMSD_compute_static(
    Mat ref, Mat cmp, Mat qualityMap, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = cv::quality::QualityGMSD::compute(*ref.ptr, *cmp.ptr, *qualityMap.ptr);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_quality_QualityMSE_create(Mat ref, QualityMSE* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    *rval = {new cv::Ptr<cv::quality::QualityMSE>(cv::quality::QualityMSE::create(*ref.ptr))};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_quality_QualityMSE_close(QualityMSEPtr self) {
    self->ptr->reset();
    CVD_FREE(self);
}

CvStatus* cv_quality_QualityMSE_compute(
    QualityMSE self, Mat cmpImgs, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = (*self.ptr)->compute(*cmpImgs.ptr);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_quality_QualityMSE_compute_static(
    Mat ref, Mat cmp, Mat qualityMap, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = cv::quality::QualityMSE::compute(*ref.ptr, *cmp.ptr, *qualityMap.ptr);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_quality_QualityPSNR_create(
    Mat ref, double maxPixelValue, QualityPSNR* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    *rval = {new cv::Ptr<cv::quality::QualityPSNR>(
        cv::quality::QualityPSNR::create(*ref.ptr, maxPixelValue)
    )};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_quality_QualityPSNR_close(QualityPSNRPtr self) {
    self->ptr->reset();
    CVD_FREE(self);
}

CvStatus* cv_quality_QualityPSNR_compute(
    QualityPSNR self, Mat cmp, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = (*self.ptr)->compute(*cmp.ptr);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_quality_QualityPSNR_compute_static(
    Mat ref, Mat cmp, double maxPixelValue, Mat qualityMap, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r =
        cv::quality::QualityPSNR::compute(*ref.ptr, *cmp.ptr, *qualityMap.ptr, maxPixelValue);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

double cv_quality_QualityPSNR_getMaxPixelValue(QualityPSNR self) {
    return (*self.ptr)->getMaxPixelValue();
}

void cv_quality_QualityPSNR_setMaxPixelValue(QualityPSNR self, double maxPixelValue) {
    (*self.ptr)->setMaxPixelValue(maxPixelValue);
}

CvStatus* cv_quality_QualitySSIM_create(Mat ref, QualitySSIM* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    *rval = {new cv::Ptr<cv::quality::QualitySSIM>(cv::quality::QualitySSIM::create(*ref.ptr))};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_quality_QualitySSIM_close(QualitySSIMPtr self) {
    self->ptr->reset();
    CVD_FREE(self);
}

CvStatus* cv_quality_QualitySSIM_compute(
    QualitySSIM self, Mat cmp, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = (*self.ptr)->compute(*cmp.ptr);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_quality_QualitySSIM_compute_static(
    Mat ref, Mat cmp, Mat qualityMap, Scalar* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar r = cv::quality::QualitySSIM::compute(*ref.ptr, *cmp.ptr, *qualityMap.ptr);
    *rval = {r.val[0], r.val[1], r.val[2], r.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
