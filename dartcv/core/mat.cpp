//
// Created by rainy on 2024/10/17.
//

#include "dartcv/core/mat.h"
#include <vector>

CvStatus* cv_Mat_create(Mat* rval) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat();
    END_WRAP
}

CvStatus* cv_Mat_create_1(int rows, int cols, int type, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(rows, cols, type);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_create_2(VecI32 sizes, int type, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(CVDEREF(sizes), type);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_create_3(VecI32 sizes, int type, Scalar ar, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::Scalar c = cv::Scalar(ar.val1, ar.val2, ar.val3, ar.val4);
    rval->ptr = new cv::Mat(CVDEREF(sizes), type, c);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_create_4(VecI32 sizes, int type, void* buf, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(CVDEREF(sizes), type, buf);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_create_5(
    const Scalar scalar, int rows, int cols, int type, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Scalar c = cv::Scalar(scalar.val1, scalar.val2, scalar.val3, scalar.val4);
    rval->ptr = new cv::Mat(rows, cols, type, c);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_create_6(
    int rows, int cols, int type, void* buf, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Mat m = cv::Mat(rows, cols, type);
    m.create(rows, cols, type);
    memcpy(m.data, buf, m.total() * m.elemSize());
    rval->ptr = new cv::Mat(m);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_create_6_no_copy(
    int rows, int cols, int type, void* buf, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Mat m = cv::Mat(rows, cols, type, buf);
    rval->ptr = new cv::Mat(m);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_create_7(VecPoint vec, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(CVDEREF(vec), true);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_Mat_create_8(VecPoint2f vec, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(CVDEREF(vec), true);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_Mat_create_9(VecPoint3f vec, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(CVDEREF(vec), true);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
CvStatus* cv_Mat_create_10(VecPoint3i vec, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(CVDEREF(vec), true);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

/**
 * @brief Create Mat with Mat::ptr
 */
CvStatus* cv_Mat_create_11(
    Mat self, int rows, int cols, int type, int prows, int pcols, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(rows, cols, type, self.ptr->ptr(prows, pcols));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

/*
 * @brief Create Mat from a range
 */
CvStatus* cv_Mat_create_12(
    Mat self, int rowStart, int rowEnd, int colStart, int colEnd, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr =
        new cv::Mat(CVDEREF(self), cv::Range(rowStart, rowEnd), cv::Range(colStart, colEnd));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_create_13(Mat self, CvRect roi, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::Rect _roi(roi.x, roi.y, roi.width, roi.height);
    rval->ptr = new cv::Mat(CVDEREF(self), _roi);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_eye(int rows, int cols, int type, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(cv::Mat::eye(rows, cols, type));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_zeros(int rows, int cols, int type, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(cv::Mat::zeros(rows, cols, type));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_ones(int rows, int cols, int type, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(cv::Mat::ones(rows, cols, type));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_toVecPoint(Mat self, VecPoint* vec, CvCallback_0 callback) {
    BEGIN_WRAP
    self.ptr->copyTo(CVDEREF_P(vec));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_toVecPoint2f(Mat self, VecPoint2f* vec, CvCallback_0 callback) {
    BEGIN_WRAP
    self.ptr->copyTo(CVDEREF_P(vec));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_toVecPoint3f(Mat self, VecPoint3f* vec, CvCallback_0 callback) {
    BEGIN_WRAP
    self.ptr->copyTo(CVDEREF_P(vec));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_toVecPoint3i(Mat self, VecPoint3i* vec, CvCallback_0 callback) {
    BEGIN_WRAP
    self.ptr->copyTo(CVDEREF_P(vec));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_toFmtString(
    Mat self,
    int fmtType,
    int f16Precision,
    int f32Precision,
    int f64Precision,
    bool multiLine,
    char** rval
) {
    BEGIN_WRAP
    auto fmt = cv::Formatter::get(static_cast<cv::Formatter::FormatType>(fmtType));
    fmt->set16fPrecision(f16Precision);
    fmt->set32fPrecision(f32Precision);
    fmt->set64fPrecision(f64Precision);
    fmt->setMultiline(multiLine);
    std::string fmtStr;
    fmtStr << fmt->format(CVDEREF(self));
    *rval = strdup(fmtStr.c_str());
    END_WRAP
}

void cv_Mat_close(MatPtr self) {
    self->ptr->release();
    CVD_FREE(self);
}

void cv_Mat_closeVoid(void* self) {
    auto p = reinterpret_cast<Mat*>(self);
    p->ptr->release();
    CVD_FREE(p);
}

CvStatus* cv_Mat_release(Mat self) {
    BEGIN_WRAP
    self.ptr->release();
    END_WRAP
}

int cv_Mat_flags(Mat self) {
    return self.ptr->flags;
}

bool cv_Mat_empty(Mat self) {
    return self.ptr->empty();
}

bool cv_Mat_isContinuous(Mat self) {
    return self.ptr->isContinuous();
}

bool cv_Mat_isSubmatrix(Mat self) {
    return self.ptr->isSubmatrix();
}

int cv_Mat_rows(Mat self) {
    return self.ptr->rows;
}

int cv_Mat_cols(Mat self) {
    return self.ptr->cols;
}

int cv_Mat_channels(Mat self) {
    return self.ptr->channels();
}

int cv_Mat_type(Mat self) {
    return self.ptr->type();
}

MatStep cv_Mat_step(Mat self) {
    auto step = self.ptr->step;
    return {{step.p[0], step.p[1], step.p[2]}};
}

size_t cv_Mat_total(Mat self) {
    return self.ptr->total();
}

VecI32* cv_Mat_size(Mat self) {
    auto size = self.ptr->size;
    return new VecI32{new std::vector<int32_t>(size.p, size.p + size.dims())};
}

size_t cv_Mat_elemSize(Mat self) {
    return self.ptr->elemSize();
}

size_t cv_Mat_elemSize1(Mat self) {
    return self.ptr->elemSize1();
}

int cv_Mat_dims(Mat self) {
    return self.ptr->dims;
}

uchar* cv_Mat_data(Mat self) {
    return (uchar*)self.ptr->data;
}
// CvStatus* cv_Mat_dataPtr(Mat self, uchar **data, int *length);

CvStatus* cv_Mat_adjustROI(
    Mat self, int dtop, int dbottom, int dleft, int dright, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->adjustROI(dtop, dbottom, dleft, dright));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_locateROI(Mat self, CvSize* wholeSize, CvPoint* ofs, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::Size sz;
    cv::Point pt;
    self.ptr->locateROI(sz, pt);
    *wholeSize = {sz.width, sz.height};
    *ofs = {pt.x, pt.y};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_clone(Mat self, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->clone());
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_col(Mat self, int x, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->col(x));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_row(Mat self, int y, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->row(y));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_rowRange(Mat self, int start, int end, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->rowRange(start, end));
    END_WRAP
}
CvStatus* cv_colRange(Mat self, int start, int end, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->colRange(start, end));
    END_WRAP
}

CvStatus* cv_Mat_copyTo(Mat self, Mat dst, CvCallback_0 callback) {
    BEGIN_WRAP
    self.ptr->copyTo(CVDEREF(dst));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_copyTo_1(Mat self, Mat dst, Mat mask, CvCallback_0 callback) {
    BEGIN_WRAP
    self.ptr->copyTo(CVDEREF(dst), CVDEREF(mask));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_convertTo(Mat self, Mat dst, int type, CvCallback_0 callback) {
    BEGIN_WRAP
    self.ptr->convertTo(CVDEREF(dst), type);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_convertTo_1(
    Mat self, Mat dst, int type, float alpha, float beta, CvCallback_0 callback
) {
    BEGIN_WRAP
    self.ptr->convertTo(CVDEREF(dst), type, alpha, beta);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_setTo(Mat self, Scalar value, Mat mask, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::Scalar c_val(value.val1, value.val2, value.val3, value.val4);
    self.ptr->setTo(c_val, CVDEREF(mask));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_toVecUChar(Mat self, VecUChar* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    if (self.ptr->isContinuous()) {
        *rval = {new std::vector<uchar>(self.ptr->begin<uchar>(), self.ptr->end<uchar>())};
    } else {
        throw cv::Exception(
            cv::Error::StsNotImplemented, "Mat is not continuous", __func__, __FILE__, __LINE__
        );
    }
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_toVecChar(Mat self, VecChar* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    if (self.ptr->isContinuous()) {
        *rval = {
            new std::vector<char>(self.ptr->ptr<char>(), self.ptr->ptr<char>() + self.ptr->step1())
        };
    } else {
        throw cv::Exception(
            cv::Error::StsNotImplemented, "Mat is not continuous", __func__, __FILE__, __LINE__
        );
    }
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_region(Mat self, CvRect r, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(CVDEREF(self), cv::Rect(r.x, r.y, r.width, r.height));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_reshape(Mat self, int cn, int rows, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->reshape(cn, rows));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_reshape_1(Mat self, int cn, VecI32 newshape, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->reshape(cn, CVDEREF(newshape)));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_patchNaNs(Mat self, double val, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::patchNaNs(CVDEREF(self), val);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_convertFp16(Mat self, Mat rval, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::convertFp16(CVDEREF(self), CVDEREF(rval));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_mean(Mat self, Scalar* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::Scalar c = cv::mean(CVDEREF(self));
    *rval = Scalar{c.val[0], c.val[1], c.val[2], c.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_mean_1(Mat self, Mat mask, Scalar* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::Scalar c = cv::mean(CVDEREF(self), CVDEREF(mask));
    *rval = Scalar{c.val[0], c.val[1], c.val[2], c.val[3]};
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_sqrt(Mat self, Mat rval, CvCallback_0 callback) {
    BEGIN_WRAP
    cv::sqrt(CVDEREF(self), CVDEREF(rval));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_Mat_t(Mat self, Mat* rval, CvCallback_0 callback) {
    BEGIN_WRAP
    rval->ptr = new cv::Mat(self.ptr->t());
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

uchar* cv_Mat_ptr_uchar_1(Mat self, int i) {
    return self.ptr->ptr(i);
}
uchar* cv_Mat_ptr_uchar_2(Mat self, int i, int j) {
    return self.ptr->ptr(i, j);
}
uchar* cv_Mat_ptr_uchar_3(Mat self, int i, int j, int k) {
    return self.ptr->ptr(i, j, k);
}

uint8_t cv_Mat_get_u8_1(Mat self, int i0) {
    return self.ptr->at<uint8_t>(i0);
}
uint8_t cv_Mat_get_u8_2(Mat self, int i0, int i1) {
    return self.ptr->at<uint8_t>(i0, i1);
}
uint8_t cv_Mat_get_u8_3(Mat self, int i0, int i1, int i2) {
    return self.ptr->at<uint8_t>(i0, i1, i2);
}
int8_t cv_Mat_get_i8_1(Mat self, int i0) {
    return self.ptr->at<int8_t>(i0);
}
int8_t cv_Mat_get_i8_2(Mat self, int i0, int i1) {
    return self.ptr->at<int8_t>(i0, i1);
}
int8_t cv_Mat_get_i8_3(Mat self, int i0, int i1, int i2) {
    return self.ptr->at<int8_t>(i0, i1, i2);
}
uint16_t cv_Mat_get_u16_1(Mat self, int i0) {
    return self.ptr->at<uint16_t>(i0);
}
uint16_t cv_Mat_get_u16_2(Mat self, int i0, int i1) {
    return self.ptr->at<uint16_t>(i0, i1);
}
uint16_t cv_Mat_get_u16_3(Mat self, int i0, int i1, int i2) {
    return self.ptr->at<uint16_t>(i0, i1, i2);
}
int16_t cv_Mat_get_i16_1(Mat self, int i0) {
    return self.ptr->at<int16_t>(i0);
}
int16_t cv_Mat_get_i16_2(Mat self, int i0, int i1) {
    return self.ptr->at<int16_t>(i0, i1);
}
int16_t cv_Mat_get_i16_3(Mat self, int i0, int i1, int i2) {
    return self.ptr->at<int16_t>(i0, i1, i2);
}
int32_t cv_Mat_get_i32_1(Mat self, int i0) {
    return self.ptr->at<int32_t>(i0);
}
int32_t cv_Mat_get_i32_2(Mat self, int i0, int i1) {
    return self.ptr->at<int32_t>(i0, i1);
}
int32_t cv_Mat_get_i32_3(Mat self, int i0, int i1, int i2) {
    return self.ptr->at<int32_t>(i0, i1, i2);
}
float_t cv_Mat_get_f32_1(Mat self, int i0) {
    return self.ptr->at<float_t>(i0);
}
float_t cv_Mat_get_f32_2(Mat self, int i0, int i1) {
    return self.ptr->at<float_t>(i0, i1);
}
float_t cv_Mat_get_f32_3(Mat self, int i0, int i1, int i2) {
    return self.ptr->at<float_t>(i0, i1, i2);
}
double_t cv_Mat_get_f64_1(Mat self, int i0) {
    return self.ptr->at<double_t>(i0);
}
double_t cv_Mat_get_f64_2(Mat self, int i0, int i1) {
    return self.ptr->at<double_t>(i0, i1);
}
double_t cv_Mat_get_f64_3(Mat self, int i0, int i1, int i2) {
    return self.ptr->at<double_t>(i0, i1, i2);
}

void cv_Mat_set_u8_1(Mat self, int i0, uint8_t val) {
    self.ptr->at<uint8_t>(i0) = val;
}
void cv_Mat_set_u8_2(Mat self, int i0, int i1, uint8_t val) {
    self.ptr->at<uint8_t>(i0, i1) = val;
}
void cv_Mat_set_u8_3(Mat self, int i0, int i1, int i2, uint8_t val) {
    self.ptr->at<uint8_t>(i0, i1, i2) = val;
}
void cv_Mat_set_i8_1(Mat self, int i0, int8_t val) {
    self.ptr->at<int8_t>(i0) = val;
}
void cv_Mat_set_i8_2(Mat self, int i0, int i1, int8_t val) {
    self.ptr->at<int8_t>(i0, i1) = val;
}
void cv_Mat_set_i8_3(Mat self, int i0, int i1, int i2, int8_t val) {
    self.ptr->at<int8_t>(i0, i1, i2) = val;
}
void cv_Mat_set_i16_1(Mat self, int i0, int16_t val) {
    self.ptr->at<int16_t>(i0) = val;
}
void cv_Mat_set_i16_2(Mat self, int i0, int i1, int16_t val) {
    self.ptr->at<int16_t>(i0, i1) = val;
}
void cv_Mat_set_i16_3(Mat self, int i0, int i1, int i2, int16_t val) {
    self.ptr->at<int16_t>(i0, i1, i2) = val;
}
void cv_Mat_set_u16_1(Mat self, int i0, uint16_t val) {
    self.ptr->at<uint16_t>(i0) = val;
}
void cv_Mat_set_u16_2(Mat self, int i0, int i1, uint16_t val) {
    self.ptr->at<uint16_t>(i0, i1) = val;
}
void cv_Mat_set_u16_3(Mat self, int i0, int i1, int i2, uint16_t val) {
    self.ptr->at<uint16_t>(i0, i1, i2) = val;
}
void cv_Mat_set_i32_1(Mat self, int i0, int32_t val) {
    self.ptr->at<int32_t>(i0) = val;
}
void cv_Mat_set_i32_2(Mat self, int i0, int i1, int32_t val) {
    self.ptr->at<int32_t>(i0, i1) = val;
}
void cv_Mat_set_i32_3(Mat self, int i0, int i1, int i2, int32_t val) {
    self.ptr->at<int32_t>(i0, i1, i2) = val;
}
void cv_Mat_set_f32_1(Mat self, int i0, float_t val) {
    self.ptr->at<float_t>(i0) = val;
}
void cv_Mat_set_f32_2(Mat self, int i0, int i1, float_t val) {
    self.ptr->at<float_t>(i0, i1) = val;
}
void cv_Mat_set_f32_3(Mat self, int i0, int i1, int i2, float_t val) {
    self.ptr->at<float_t>(i0, i1, i2) = val;
}
void cv_Mat_set_f64_1(Mat self, int i0, double_t val) {
    self.ptr->at<double_t>(i0) = val;
}
void cv_Mat_set_f64_2(Mat self, int i0, int i1, double_t val) {
    self.ptr->at<double_t>(i0, i1) = val;
}
void cv_Mat_set_f64_3(Mat self, int i0, int i1, int i2, double_t val) {
    self.ptr->at<double_t>(i0, i1, i2) = val;
}

Vec2b* cv_Mat_get_Vec2b(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec2b>(i0, i1);
    return new Vec2b{v.val[0], v.val[1]};
}
Vec3b* cv_Mat_get_Vec3b(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec3b>(i0, i1);
    return new Vec3b{v.val[0], v.val[1], v.val[2]};
}
Vec4b* cv_Mat_get_Vec4b(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec4b>(i0, i1);
    return new Vec4b{v.val[0], v.val[1], v.val[2], v.val[3]};
}
Vec2s* cv_Mat_get_Vec2s(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec2s>(i0, i1);
    return new Vec2s{v.val[0], v.val[1]};
}
Vec3s* cv_Mat_get_Vec3s(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec3s>(i0, i1);
    return new Vec3s{v.val[0], v.val[1], v.val[2]};
}
Vec4s* cv_Mat_get_Vec4s(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec4s>(i0, i1);
    return new Vec4s{v.val[0], v.val[1], v.val[2], v.val[3]};
}
Vec2w* cv_Mat_get_Vec2w(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec2w>(i0, i1);
    return new Vec2w{v.val[0], v.val[1]};
}
Vec3w* cv_Mat_get_Vec3w(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec3w>(i0, i1);
    return new Vec3w{v.val[0], v.val[1], v.val[2]};
}
Vec4w* cv_Mat_get_Vec4w(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec4w>(i0, i1);
    return new Vec4w{v.val[0], v.val[1], v.val[2], v.val[3]};
}
Vec2i* cv_Mat_get_Vec2i(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec2i>(i0, i1);
    return new Vec2i{v.val[0], v.val[1]};
}
Vec3i* cv_Mat_get_Vec3i(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec3i>(i0, i1);
    return new Vec3i{v.val[0], v.val[1], v.val[2]};
}
Vec4i* cv_Mat_get_Vec4i(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec4i>(i0, i1);
    return new Vec4i{v.val[0], v.val[1], v.val[2], v.val[3]};
}
Vec6i* cv_Mat_get_Vec6i(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec6i>(i0, i1);
    return new Vec6i{v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]};
}
Vec8i* cv_Mat_get_Vec8i(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec8i>(i0, i1);
    return new Vec8i{
        v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5], v.val[6], v.val[7]
    };
}
Vec2f* cv_Mat_get_Vec2f(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec2f>(i0, i1);
    return new Vec2f{v.val[0], v.val[1]};
}
Vec3f* cv_Mat_get_Vec3f(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec3f>(i0, i1);
    return new Vec3f{v.val[0], v.val[1], v.val[2]};
}
Vec4f* cv_Mat_get_Vec4f(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec4f>(i0, i1);
    return new Vec4f{v.val[0], v.val[1], v.val[2], v.val[3]};
}
Vec6f* cv_Mat_get_Vec6f(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec6f>(i0, i1);
    return new Vec6f{v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]};
}
Vec2d* cv_Mat_get_Vec2d(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec2d>(i0, i1);
    return new Vec2d{v.val[0], v.val[1]};
}
Vec3d* cv_Mat_get_Vec3d(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec3d>(i0, i1);
    return new Vec3d{v.val[0], v.val[1], v.val[2]};
}
Vec4d* cv_Mat_get_Vec4d(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec4d>(i0, i1);
    return new Vec4d{v.val[0], v.val[1], v.val[2], v.val[3]};
}
Vec6d* cv_Mat_get_Vec6d(Mat self, int i0, int i1) {
    auto v = self.ptr->at<cv::Vec6d>(i0, i1);
    return new Vec6d{v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]};
}

void cv_Mat_set_Vec2b(Mat self, int i0, int i1, Vec2b val) {
    self.ptr->at<cv::Vec2b>(i0, i1) = cv::Vec2b(val.val1, val.val2);
}
void cv_Mat_set_Vec3b(Mat self, int i0, int i1, Vec3b val) {
    self.ptr->at<cv::Vec3b>(i0, i1) = cv::Vec3b(val.val1, val.val2, val.val3);
}
void cv_Mat_set_Vec4b(Mat self, int i0, int i1, Vec4b val) {
    self.ptr->at<cv::Vec4b>(i0, i1) = cv::Vec4b(val.val1, val.val2, val.val3, val.val4);
}
void cv_Mat_set_Vec2s(Mat self, int i0, int i1, Vec2s val) {
    self.ptr->at<cv::Vec2s>(i0, i1) = cv::Vec2s(val.val1, val.val2);
}
void cv_Mat_set_Vec3s(Mat self, int i0, int i1, Vec3s val) {
    self.ptr->at<cv::Vec3s>(i0, i1) = cv::Vec3s(val.val1, val.val2, val.val3);
}
void cv_Mat_set_Vec4s(Mat self, int i0, int i1, Vec4s val) {
    self.ptr->at<cv::Vec4s>(i0, i1) = cv::Vec4s(val.val1, val.val2, val.val3, val.val4);
}
void cv_Mat_set_Vec2w(Mat self, int i0, int i1, Vec2w val) {
    self.ptr->at<cv::Vec2w>(i0, i1) = cv::Vec2w(val.val1, val.val2);
}
void cv_Mat_set_Vec3w(Mat self, int i0, int i1, Vec3w val) {
    self.ptr->at<cv::Vec3w>(i0, i1) = cv::Vec3w(val.val1, val.val2, val.val3);
}
void cv_Mat_set_Vec4w(Mat self, int i0, int i1, Vec4w val) {
    self.ptr->at<cv::Vec4w>(i0, i1) = cv::Vec4w(val.val1, val.val2, val.val3, val.val4);
}
void cv_Mat_set_Vec2i(Mat self, int i0, int i1, Vec2i val) {
    self.ptr->at<cv::Vec2i>(i0, i1) = cv::Vec2i(val.val1, val.val2);
}
void cv_Mat_set_Vec3i(Mat self, int i0, int i1, Vec3i val) {
    self.ptr->at<cv::Vec3i>(i0, i1) = cv::Vec3i(val.val1, val.val2, val.val3);
}
void cv_Mat_set_Vec4i(Mat self, int i0, int i1, Vec4i val) {
    self.ptr->at<cv::Vec4i>(i0, i1) = cv::Vec4i(val.val1, val.val2, val.val3, val.val4);
}
void cv_Mat_set_Vec6i(Mat self, int i0, int i1, Vec6i val) {
    self.ptr->at<cv::Vec6i>(i0, i1) =
        cv::Vec6i(val.val1, val.val2, val.val3, val.val4, val.val5, val.val6);
}
void cv_Mat_set_Vec8i(Mat self, int i0, int i1, Vec8i val) {
    self.ptr->at<cv::Vec8i>(i0, i1) =
        cv::Vec8i(val.val1, val.val2, val.val3, val.val4, val.val5, val.val6, val.val7, val.val8);
}
void cv_Mat_set_Vec2f(Mat self, int i0, int i1, Vec2f val) {
    self.ptr->at<cv::Vec2f>(i0, i1) = cv::Vec2f(val.val1, val.val2);
}
void cv_Mat_set_Vec3f(Mat self, int i0, int i1, Vec3f val) {
    self.ptr->at<cv::Vec3f>(i0, i1) = cv::Vec3f(val.val1, val.val2, val.val3);
}
void cv_Mat_set_Vec4f(Mat self, int i0, int i1, Vec4f val) {
    self.ptr->at<cv::Vec4f>(i0, i1) = cv::Vec4f(val.val1, val.val2, val.val3, val.val4);
}
void cv_Mat_set_Vec6f(Mat self, int i0, int i1, Vec6f val) {
    self.ptr->at<cv::Vec6f>(i0, i1) =
        cv::Vec6f(val.val1, val.val2, val.val3, val.val4, val.val5, val.val6);
}
void cv_Mat_set_Vec2d(Mat self, int i0, int i1, Vec2d val) {
    self.ptr->at<cv::Vec2d>(i0, i1) = cv::Vec2d(val.val1, val.val2);
}
void cv_Mat_set_Vec3d(Mat self, int i0, int i1, Vec3d val) {
    self.ptr->at<cv::Vec3d>(i0, i1) = cv::Vec3d(val.val1, val.val2, val.val3);
}
void cv_Mat_set_Vec4d(Mat self, int i0, int i1, Vec4d val) {
    self.ptr->at<cv::Vec4d>(i0, i1) = cv::Vec4d(val.val1, val.val2, val.val3, val.val4);
}
void cv_Mat_set_Vec6d(Mat self, int i0, int i1, Vec6d val) {
    self.ptr->at<cv::Vec6d>(i0, i1) =
        cv::Vec6d(val.val1, val.val2, val.val3, val.val4, val.val5, val.val6);
}

CvStatus* cv_Mat_op_add_mat(Mat self, Mat val) {
    BEGIN_WRAP
    CVDEREF(self) += CVDEREF(val);
    END_WRAP
}
CvStatus* cv_Mat_op_sub_mat(Mat self, Mat val) {
    BEGIN_WRAP
    CVDEREF(self) -= CVDEREF(val);
    END_WRAP
}
CvStatus* cv_Mat_op_mul_mat(Mat self, Mat val) {
    BEGIN_WRAP
    CVDEREF(self) *= CVDEREF(val);
    END_WRAP
}
CvStatus* cv_Mat_op_div_mat(Mat self, Mat val) {
    BEGIN_WRAP
    CVDEREF(self) /= CVDEREF(val);
    END_WRAP
}

CvStatus* cv_Mat_op_add_u8(Mat self, uint8_t val) {
    BEGIN_WRAP
    CVDEREF(self) += val;
    END_WRAP
}
CvStatus* cv_Mat_op_sub_u8(Mat self, uint8_t val) {
    BEGIN_WRAP
    CVDEREF(self) -= val;
    END_WRAP
}
CvStatus* cv_Mat_op_mul_u8(Mat self, uint8_t val) {
    BEGIN_WRAP
    CVDEREF(self) *= val;
    END_WRAP
}
CvStatus* cv_Mat_op_div_u8(Mat self, uint8_t val) {
    BEGIN_WRAP
    CVDEREF(self) /= val;
    END_WRAP
}

CvStatus* cv_Mat_op_add_i8(Mat self, int8_t val) {
    BEGIN_WRAP
    CVDEREF(self) += val;
    END_WRAP
}
CvStatus* cv_Mat_op_sub_i8(Mat self, int8_t val) {
    BEGIN_WRAP
    CVDEREF(self) -= val;
    END_WRAP
}
CvStatus* cv_Mat_op_mul_i8(Mat self, int8_t val) {
    BEGIN_WRAP
    CVDEREF(self) *= val;
    END_WRAP
}
CvStatus* cv_Mat_op_div_i8(Mat self, int8_t val) {
    BEGIN_WRAP
    CVDEREF(self) /= val;
    END_WRAP
}

CvStatus* cv_Mat_op_add_i16(Mat self, int16_t val) {
    BEGIN_WRAP
    CVDEREF(self) += val;
    END_WRAP
}
CvStatus* cv_Mat_op_sub_i16(Mat self, int16_t val) {
    BEGIN_WRAP
    CVDEREF(self) -= val;
    END_WRAP
}
CvStatus* cv_Mat_op_mul_i16(Mat self, int16_t val) {
    BEGIN_WRAP
    CVDEREF(self) *= val;
    END_WRAP
}
CvStatus* cv_Mat_op_div_i16(Mat self, int16_t val) {
    BEGIN_WRAP
    CVDEREF(self) /= val;
    END_WRAP
}

CvStatus* cv_Mat_op_add_u16(Mat self, uint16_t val) {
    BEGIN_WRAP
    CVDEREF(self) += val;
    END_WRAP
}
CvStatus* cv_Mat_op_sub_u16(Mat self, uint16_t val) {
    BEGIN_WRAP
    CVDEREF(self) -= val;
    END_WRAP
}
CvStatus* cv_Mat_op_mul_u16(Mat self, uint16_t val) {
    BEGIN_WRAP
    CVDEREF(self) *= val;
    END_WRAP
}
CvStatus* cv_Mat_op_div_u16(Mat self, uint16_t val) {
    BEGIN_WRAP
    CVDEREF(self) /= val;
    END_WRAP
}

CvStatus* cv_Mat_op_add_i32(Mat self, int32_t val) {
    BEGIN_WRAP
    CVDEREF(self) += val;
    END_WRAP
}
CvStatus* cv_Mat_op_sub_i32(Mat self, int32_t val) {
    BEGIN_WRAP
    CVDEREF(self) -= val;
    END_WRAP
}
CvStatus* cv_Mat_op_mul_i32(Mat self, int32_t val) {
    BEGIN_WRAP
    CVDEREF(self) *= val;
    END_WRAP
}
CvStatus* cv_Mat_op_div_i32(Mat self, int32_t val) {
    BEGIN_WRAP
    CVDEREF(self) /= val;
    END_WRAP
}

CvStatus* cv_Mat_op_add_f32(Mat self, float_t val) {
    BEGIN_WRAP
    CVDEREF(self) += val;
    END_WRAP
}
CvStatus* cv_Mat_op_sub_f32(Mat self, float_t val) {
    BEGIN_WRAP
    CVDEREF(self) -= val;
    END_WRAP
}
CvStatus* cv_Mat_op_mul_f32(Mat self, float_t val) {
    BEGIN_WRAP
    CVDEREF(self) *= val;
    END_WRAP
}
CvStatus* cv_Mat_op_div_f32(Mat self, float_t val) {
    BEGIN_WRAP
    CVDEREF(self) /= val;
    END_WRAP
}

CvStatus* cv_Mat_op_add_f64(Mat self, double_t val) {
    BEGIN_WRAP
    CVDEREF(self) += val;
    END_WRAP
}
CvStatus* cv_Mat_op_sub_f64(Mat self, double_t val) {
    BEGIN_WRAP
    CVDEREF(self) -= val;
    END_WRAP
}
CvStatus* cv_Mat_op_mul_f64(Mat self, double_t val) {
    BEGIN_WRAP
    CVDEREF(self) *= val;
    END_WRAP
}
CvStatus* cv_Mat_op_div_f64(Mat self, double_t val) {
    BEGIN_WRAP
    CVDEREF(self) /= val;
    END_WRAP
}

/*
 * element-wise
 */
CvStatus* cv_Mat_mul(Mat self, Mat value, Mat* dst, double scale) {
    BEGIN_WRAP
    dst->ptr = new cv::Mat((CVDEREF(self)).mul(CVDEREF(value), scale));
    END_WRAP
}
