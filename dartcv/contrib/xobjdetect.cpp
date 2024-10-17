#include "dartcv/contrib/xobjdetect.h"
#include "dartcv/core/vec.hpp"

CvStatus* cv_xobjdetect_WBDetector_create(PtrWBDetector* rval) {
    BEGIN_WRAP
    *rval = {new cv::Ptr<cv::xobjdetect::WBDetector>(cv::xobjdetect::WBDetector::create())};
    END_WRAP
}

void cv_xobjdetect_WBDetector_close(PtrWBDetectorPtr self) {
    self->ptr->reset();
    CVD_FREE(self);
}

CvStatus* cv_xobjdetect_WBDetector_detect(
    PtrWBDetector self, Mat img, CVD_OUT VecRect* bbox, CVD_OUT VecF64* confidences
) {
    BEGIN_WRAP
    std::vector<cv::Rect> _bboxes;
    std::vector<double> _confidences;
    (CVDEREF(self))->detect(CVDEREF(img), _bboxes, _confidences);
    *bbox = vecrect_cpp2c(_bboxes);
    *confidences = vecdouble_cpp2c(_confidences);
    END_WRAP
}

CvStatus* cv_xobjdetect_WBDetector_train(
    PtrWBDetector self, const char* pos_samples, const char* neg_imgs
) {
    BEGIN_WRAP(CVDEREF(self))->train(pos_samples, neg_imgs);
    END_WRAP
}

CvStatus* cv_xobjdetect_WBDetector_read(PtrWBDetector self, const char* filename) {
    BEGIN_WRAP
    auto fs = cv::FileStorage(filename, cv::FileStorage::READ);
    (CVDEREF(self))->read(fs.root());
    END_WRAP
}

CvStatus* cv_xobjdetect_WBDetector_write(PtrWBDetector self, const char* filename) {
    BEGIN_WRAP
    auto fs = cv::FileStorage(filename, cv::FileStorage::WRITE);
    (CVDEREF(self))->write(fs);
    END_WRAP
}
