/*
    This file is originally from gocv project
    Licensed: Apache 2.0 license. Copyright (c) 2017-2021 The Hybrid Group.

    Modified by Rainyl.
    Licensed: Apache 2.0 license. Copyright (c) 2024 Rainyl.
*/

#include "dartcv/objdetect/objdetect.h"
#include "dartcv/core/vec.hpp"

// CascadeClassifier
CvStatus* cv_CascadeClassifier_create(CascadeClassifier* rval) {
    BEGIN_WRAP
    *rval = {new cv::CascadeClassifier()};
    END_WRAP
}
CvStatus* cv_CascadeClassifier_create_1(const char* filename, CascadeClassifier* rval) {
    BEGIN_WRAP
    *rval = {new cv::CascadeClassifier(filename)};
    END_WRAP
}
void cv_CascadeClassifier_close(CascadeClassifierPtr self) {
    CVD_FREE(self);
}

CvStatus* cv_CascadeClassifier_load(CascadeClassifier self, const char* name, int* rval) {
    BEGIN_WRAP
    *rval = self.ptr->load(name);
    END_WRAP
}
CvStatus* cv_CascadeClassifier_detectMultiScale(
    CascadeClassifier self, Mat img, VecRect* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Rect> rects = std::vector<cv::Rect>();
    self.ptr->detectMultiScale(CVDEREF(img), rects);
    *rval = vecrect_cpp2c(rects);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_CascadeClassifier_detectMultiScale_1(
    CascadeClassifier self,
    Mat img,
    VecRect* objects,
    double scale,
    int minNeighbors,
    int flags,
    CvSize minSize,
    CvSize maxSize,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Rect> rects;
    auto minsize = cv::Size(minSize.width, minSize.height);
    auto maxsize = cv::Size(maxSize.width, maxSize.height);
    self.ptr->detectMultiScale(CVDEREF(img), rects, scale, minNeighbors, flags, minsize, maxsize);
    *objects = vecrect_cpp2c(rects);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_CascadeClassifier_detectMultiScale_2(
    CascadeClassifier self,
    Mat img,
    VecRect* objects,
    VecI32* numDetections,
    double scaleFactor,
    int minNeighbors,
    int flags,
    CvSize minSize,
    CvSize maxSize,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Rect> rects;
    std::vector<int> nums;
    auto minsize = cv::Size(minSize.width, minSize.height);
    auto maxsize = cv::Size(maxSize.width, maxSize.height);
    self.ptr->detectMultiScale(
        CVDEREF(img), rects, nums, scaleFactor, minNeighbors, flags, minsize, maxsize
    );
    *objects = vecrect_cpp2c(rects);
    *numDetections = vecint_cpp2c(nums);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_CascadeClassifier_detectMultiScale_3(
    CascadeClassifier self,
    Mat img,
    VecRect* objects,
    VecI32* rejectLevels,
    VecF64* levelWeights,
    double scaleFactor,
    int minNeighbors,
    int flags,
    CvSize minSize,
    CvSize maxSize,
    bool outputRejectLevels,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Rect> rects;
    std::vector<int> rejects;
    std::vector<double> weights;
    auto minsize = cv::Size(minSize.width, minSize.height);
    auto maxsize = cv::Size(maxSize.width, maxSize.height);
    self.ptr->detectMultiScale(
        CVDEREF(img),
        rects,
        rejects,
        weights,
        scaleFactor,
        minNeighbors,
        flags,
        minsize,
        maxsize,
        outputRejectLevels
    );
    *objects = vecrect_cpp2c(rects);
    *rejectLevels = vecint_cpp2c(rejects);
    *levelWeights = vecdouble_cpp2c(weights);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
bool cv_CascadeClassifier_empty(CascadeClassifier self) {
    return self.ptr->empty();
}
int cv_CascadeClassifier_getFeatureType(CascadeClassifier self) {
    return self.ptr->getFeatureType();
}
CvSize cv_CascadeClassifier_getOriginalWindowSize(CascadeClassifier self) {
    auto sz = self.ptr->getOriginalWindowSize();
    return CvSize{sz.width, sz.height};
}
bool cv_CascadeClassifier_isOldFormatCascade(CascadeClassifier self) {
    return self.ptr->isOldFormatCascade();
}

CvStatus* cv_HOGDescriptor_create(HOGDescriptor* rval) {
    BEGIN_WRAP
    *rval = {new cv::HOGDescriptor()};
    END_WRAP
}
CvStatus* cv_HOGDescriptor_create_1(const char* filename, HOGDescriptor* rval) {
    BEGIN_WRAP
    *rval = {new cv::HOGDescriptor(filename)};
    END_WRAP
}
void cv_HOGDescriptor_close(HOGDescriptorPtr self) {
    CVD_FREE(self);
}

CvStatus* cv_HOGDescriptor_load(HOGDescriptor self, const char* name, bool* rval) {
    BEGIN_WRAP
    *rval = self.ptr->load(name);
    END_WRAP
}
CvStatus* cv_HOGDescriptor_detect(
    HOGDescriptor self,
    Mat img,
    VecPoint* foundLocations,
    VecF64* weights,
    double hitThresh,
    CvSize winStride,
    CvSize padding,
    VecPoint* searchLocations,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Point> _foundLocations;
    std::vector<cv::Point> _searchLocations;
    std::vector<double> _weights;
    self.ptr->detect(
        CVDEREF(img),
        _foundLocations,
        _weights,
        hitThresh,
        cv::Point(winStride.width, winStride.height),
        cv::Point(padding.width, padding.height),
        _searchLocations
    );
    *foundLocations = vecpoint_cpp2c(_foundLocations);
    *weights = vecdouble_cpp2c(_weights);
    *searchLocations = vecpoint_cpp2c(_searchLocations);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_HOGDescriptor_detect2(
    HOGDescriptor self,
    Mat img,
    VecPoint* foundLocations,
    double hitThresh,
    CvSize winStride,
    CvSize padding,
    VecPoint* searchLocations,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Point> _foundLocations;
    std::vector<cv::Point> _searchLocations;
    self.ptr->detect(
        CVDEREF(img),
        _foundLocations,
        hitThresh,
        cv::Point(winStride.width, winStride.height),
        cv::Point(padding.width, padding.height),
        _searchLocations
    );
    *foundLocations = vecpoint_cpp2c(_foundLocations);
    *searchLocations = vecpoint_cpp2c(_searchLocations);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_HOGDescriptor_detectMultiScale(
    HOGDescriptor self, Mat img, VecRect* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Rect> rects = std::vector<cv::Rect>();
    self.ptr->detectMultiScale(CVDEREF(img), rects);
    *rval = vecrect_cpp2c(rects);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_HOGDescriptor_detectMultiScale_1(
    HOGDescriptor self,
    Mat img,
    double hitThresh,
    CvSize winStride,
    CvSize padding,
    double scale,
    double finalThreshold,
    bool useMeanshiftGrouping,
    VecRect* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Rect> rects;
    auto winstride = cv::Size(winStride.width, winStride.height);
    auto pad = cv::Size(padding.width, padding.height);
    self.ptr->detectMultiScale(
        CVDEREF(img), rects, hitThresh, winstride, pad, scale, finalThreshold, useMeanshiftGrouping
    );
    *rval = vecrect_cpp2c(rects);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_HOGDescriptor_getDefaultPeopleDetector(VecF32* rval) {
    BEGIN_WRAP
    *rval = vecfloat_cpp2c(cv::HOGDescriptor::getDefaultPeopleDetector());
    END_WRAP
}
CvStatus* cv_HOGDescriptor_setSVMDetector(HOGDescriptor self, VecF32 det) {
    BEGIN_WRAP
    self.ptr->setSVMDetector(vecfloat_c2cpp(det));
    END_WRAP
}
CvStatus* cv_HOGDescriptor_compute(
    HOGDescriptor self,
    Mat img,
    VecF32* descriptors,
    CvSize winStride,
    CvSize padding,
    VecPoint* locations,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<float> _descriptors;
    std::vector<cv::Point> _locations;
    self.ptr->compute(
        CVDEREF(img),
        _descriptors,
        cv::Size(winStride.width, winStride.height),
        cv::Size(padding.width, padding.height),
        _locations
    );
    *descriptors = vecfloat_cpp2c(_descriptors);
    *locations = vecpoint_cpp2c(_locations);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_HOGDescriptor_computeGradient(
    HOGDescriptor self,
    Mat img,
    Mat grad,
    Mat angleOfs,
    CvSize paddingTL,
    CvSize paddingBR,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    self.ptr->computeGradient(
        CVDEREF(img),
        CVDEREF(grad),
        CVDEREF(angleOfs),
        cv::Size(paddingTL.width, paddingTL.height),
        cv::Size(paddingBR.width, paddingBR.height)
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
// CvStatus *HOGDescriptor_detectMultiScaleROI(HOGDescriptor self, Mat img, VecRect *foundLocations,
//                                            DetectionROI *locations, int *lenLocations, double
//                                            hitThreshold, int groupThreshold)
// {
//   BEGIN_WRAP
//   auto _foundLocations = vecrect_cpp2c();
//   auto _locations = new std::vector<cv::DetectionROI>();
//   self.ptr->detectMultiScaleROI(CVDEREF(img), *_foundLocations, *_locations, hitThreshold,
//   groupThreshold); *foundLocations = {_foundLocations}; locations = _locations->data(); END_WRAP
// }
// CvStatus *HOGDescriptor_detectROI(HOGDescriptor self, Mat img, VecPoint *locations, VecPoint
// *foundLocations,
//                                  VecF64 *confidences, double hitThreshold, CvSize winStride,
//                                  CvSize padding)
// {
//   BEGIN_WRAP
//   auto _locations = vecpoint_cpp2c();
//   auto _foundLocations = vecpoint_cpp2c();
//   auto _confidences = vecdouble_cpp2c();
//   self.ptr->detectROI(CVDEREF(img), *_locations, *_foundLocations, *_confidences, hitThreshold,
//                       cv::CvSize(winStride.width, winStride.height), cv::CvSize(padding.width,
//                       padding.height));
//   *locations = {_locations};
//   *foundLocations = {_foundLocations};
//   *confidences = {_confidences};
//   END_WRAP
// }
CvStatus* cv_HOGDescriptor_getDaimlerPeopleDetector(VecF32* rval) {
    BEGIN_WRAP
    *rval = vecfloat_cpp2c(cv::HOGDescriptor::getDaimlerPeopleDetector());
    END_WRAP
}
size_t cv_HOGDescriptor_getDescriptorSize(HOGDescriptor self) {
    return self.ptr->getDescriptorSize();
}
double cv_HOGDescriptor_getWinSigma(HOGDescriptor self) {
    return self.ptr->getWinSigma();
}
CvStatus* cv_HOGDescriptor_groupRectangles(
    HOGDescriptor self,
    VecRect* rectList,
    VecF64* weights,
    int groupThreshold,
    double eps,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _rectList = vecrect_c2cpp(*rectList);
    auto _weights = vecdouble_c2cpp(*weights);
    self.ptr->groupRectangles(_rectList, _weights, groupThreshold, eps);
    vecrect_cpp2c(_rectList, rectList);
    vecdouble_cpp2c(_weights, weights);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_groupRectangles(
    VecRect* rects, int groupThreshold, double eps, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _rects = vecrect_c2cpp(*rects);
    cv::groupRectangles(_rects, groupThreshold, eps);
    vecrect_cpp2c(_rects, rects);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_QRCodeDetector_create(QRCodeDetector* rval) {
    BEGIN_WRAP
    *rval = {new cv::QRCodeDetector()};
    END_WRAP
}
CvStatus* cv_QRCodeDetector_detectAndDecode(
    QRCodeDetector self,
    Mat input,
    VecPoint* points,
    Mat* straight_qrcode,
    char** rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Point> points_;
    cv::Mat mat;
    auto info = self.ptr->detectAndDecode(CVDEREF(input), points_, mat);
    *rval = strdup(info.c_str());
    *points = vecpoint_cpp2c(points_);
    *straight_qrcode = {new cv::Mat(mat)};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_QRCodeDetector_detect(
    QRCodeDetector self, Mat input, VecPoint* points, bool* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Point> _points;
    *rval = self.ptr->detect(CVDEREF(input), _points);
    *points = vecpoint_cpp2c(_points);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_QRCodeDetector_decode(
    QRCodeDetector self,
    Mat input,
    VecPoint* points,
    Mat straight_qrcode,
    char** rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Point> _points;
    auto info = self.ptr->detectAndDecode(CVDEREF(input), _points, CVDEREF(straight_qrcode));
    *rval = strdup(info.c_str());
    *points = vecpoint_cpp2c(_points);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_QRCodeDetector_decodeCurved(
    QRCodeDetector self,
    Mat img,
    VecPoint points,
    CVD_OUT Mat* straight_qrcode,
    char** rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Mat _straight_qrcode;
    auto _points = vecpoint_c2cpp(points);
    auto ret = self.ptr->decodeCurved(CVDEREF(img), _points, _straight_qrcode);
    *rval = strdup(ret.c_str());
    *straight_qrcode = {new cv::Mat(_straight_qrcode)};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_QRCodeDetector_detectAndDecodeCurved(
    QRCodeDetector self,
    Mat img,
    VecPoint* points,
    CVD_OUT Mat* straight_qrcode,
    char** rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Mat _straight_qrcode;
    std::vector<cv::Point> _points;
    auto ret = self.ptr->detectAndDecodeCurved(CVDEREF(img), _points, _straight_qrcode);
    *rval = strdup(ret.c_str());
    *points = vecpoint_cpp2c(_points);
    *straight_qrcode = {new cv::Mat(_straight_qrcode)};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
void cv_QRCodeDetector_close(QRCodeDetectorPtr self) {
    CVD_FREE(self);
}

CvStatus* cv_QRCodeDetector_detectMulti(
    QRCodeDetector self, Mat input, VecPoint* points, bool* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::Point> _points;
    *rval = self.ptr->detectMulti(CVDEREF(input), _points);
    *points = vecpoint_cpp2c(_points);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_QRCodeDetector_detectAndDecodeMulti(
    QRCodeDetector self,
    Mat input,
    VecVecChar* decoded,
    VecPoint* points,
    VecMat* straight_code,
    bool* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    std::vector<cv::String> decodedCodes;
    std::vector<cv::Mat> straightQrCodes;
    std::vector<cv::Point> points_;

    *rval = self.ptr->detectAndDecodeMulti(CVDEREF(input), decodedCodes, points_, straightQrCodes);
    if (!*rval) {
        *decoded = {nullptr, 0};
        *straight_code = {nullptr, 0};
        *points = {nullptr, 0};
    } else {
        std::vector<std::vector<char>> vecvec;
        for (auto& decodedCode : decodedCodes) {
            vecvec.emplace_back(decodedCode.begin(), decodedCode.end());
        }
        *decoded = vecvecchar_cpp2c(vecvec);
        *straight_code = vecmat_cpp2c(straightQrCodes);
        *points = vecpoint_cpp2c(points_);
    }
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_QRCodeDetector_setEpsX(QRCodeDetector self, double epsX) {
    self.ptr->setEpsX(epsX);
}
void cv_QRCodeDetector_setEpsY(QRCodeDetector self, double epsY) {
    self.ptr->setEpsY(epsY);
}
void cv_QRCodeDetector_setUseAlignmentMarkers(QRCodeDetector self, bool useAlignmentMarkers) {
    self.ptr->setUseAlignmentMarkers(useAlignmentMarkers);
}
// FaceDetectorYN
CvStatus* cv_FaceDetectorYN_create(
    const char* model,
    const char* config,
    CvSize input_size,
    float score_threshold,
    float nms_threshold,
    int top_k,
    int backend_id,
    int target_id,
    FaceDetectorYN* rval
) {
    BEGIN_WRAP
    *rval = {new cv::Ptr<cv::FaceDetectorYN>(cv::FaceDetectorYN::create(
        model,
        config,
        cv::Size(input_size.width, input_size.height),
        score_threshold,
        nms_threshold,
        top_k,
        backend_id,
        target_id
    ))};
    END_WRAP
}

CvStatus* cv_FaceDetectorYN_create_1(
    const char* framework,
    VecUChar buffer,
    VecUChar buffer_config,
    CvSize input_size,
    float score_threshold,
    float nms_threshold,
    int top_k,
    int backend_id,
    int target_id,
    FaceDetectorYN* rval
) {
    BEGIN_WRAP
    auto _buffer = vecuchar_c2cpp(buffer);
    auto _buffer_config = vecuchar_c2cpp(buffer_config);
    *rval = {new cv::Ptr<cv::FaceDetectorYN>(cv::FaceDetectorYN::create(
        framework,
        _buffer,
        _buffer_config,
        cv::Size(input_size.width, input_size.height),
        score_threshold,
        nms_threshold,
        top_k,
        backend_id,
        target_id
    ))};
    END_WRAP
}

void cv_FaceDetectorYN_close(FaceDetectorYNPtr self) {
    self->ptr->reset();
    CVD_FREE(self);
}

CvStatus* cv_FaceDetectorYN_detect(
    FaceDetectorYN self, Mat img, Mat* faces, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Mat _faces;
    (CVDEREF(self))->detect(CVDEREF(img), _faces);
    *faces = {new cv::Mat(_faces)};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

void cv_FaceDetectorYN_setInputSize(FaceDetectorYN self, CvSize input_size) {
    (CVDEREF(self))->setInputSize(cv::Size(input_size.width, input_size.height));
}

CvSize cv_FaceDetectorYN_getInputSize(FaceDetectorYN self) {
    cv::Size sz = (CVDEREF(self))->getInputSize();
    return {sz.width, sz.height};
}

void cv_FaceDetectorYN_setScoreThreshold(FaceDetectorYN self, float score_threshold) {
    (CVDEREF(self))->setScoreThreshold(score_threshold);
}

float cv_FaceDetectorYN_getScoreThreshold(FaceDetectorYN self) {
    return (CVDEREF(self))->getScoreThreshold();
}
void cv_FaceDetectorYN_setNMSThreshold(FaceDetectorYN self, float nms_threshold) {
    (CVDEREF(self))->setNMSThreshold(nms_threshold);
}

float cv_FaceDetectorYN_getNMSThreshold(FaceDetectorYN self) {
    return (CVDEREF(self))->getNMSThreshold();
}

void cv_FaceDetectorYN_setTopK(FaceDetectorYN self, int top_k) {
    (CVDEREF(self))->setTopK(top_k);
}

int cv_FaceDetectorYN_getTopK(FaceDetectorYN self) {
    return (CVDEREF(self))->getTopK();
}
// FaceRecognizerSF
CvStatus* cv_FaceRecognizerSF_create(
    const char* model, const char* config, int backend_id, int target_id, FaceRecognizerSF* rval
) {
    BEGIN_WRAP
    *rval = {new cv::Ptr<cv::FaceRecognizerSF>(
        cv::FaceRecognizerSF::create(model, config, backend_id, target_id)
    )};
    END_WRAP
}
void cv_FaceRecognizerSF_close(FaceRecognizerSFPtr self) {
    self->ptr->reset();
    CVD_FREE(self);
}

CvStatus* cv_FaceRecognizerSF_alignCrop(
    FaceRecognizerSF self, Mat src_img, Mat face_box, Mat* aligned_img, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Mat _align;
    (CVDEREF(self))->alignCrop(CVDEREF(src_img), CVDEREF(face_box), _align);
    *aligned_img = {new cv::Mat(_align)};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_FaceRecognizerSF_feature(
    FaceRecognizerSF self, Mat aligned_img, bool clone, Mat* face_feature, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Mat _face_feature;
    (CVDEREF(self))->feature(CVDEREF(aligned_img), _face_feature);
    if (clone) {
        *face_feature = {new cv::Mat(_face_feature.clone())};
    } else {
        *face_feature = {new cv::Mat(_face_feature)};
    }
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_FaceRecognizerSF_match(
    FaceRecognizerSF self,
    Mat face_feature1,
    Mat face_feature2,
    int dis_type,
    double* distance,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    *distance = (CVDEREF(self))->match(CVDEREF(face_feature1), CVDEREF(face_feature2), dis_type);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
