/*
    This file is originally from gocv project
    Licensed: Apache 2.0 license. Copyright (c) 2017-2021 The Hybrid Group.

    Modified by Rainyl.
    Licensed: Apache 2.0 license. Copyright (c) 2024 Rainyl.
*/
#pragma warning(disable : 4996)
#include "dartcv/calib3d/calib3d.h"
#include "dartcv/core/vec.hpp"

CvStatus* cv_fisheye_undistortImage(
    Mat distorted, Mat undistorted, Mat k, Mat d, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::fisheye::undistortImage(
        CVDEREF(distorted), CVDEREF(undistorted), CVDEREF(k), CVDEREF(d)
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_fisheye_undistortImage_1(
    Mat distorted,
    Mat undistorted,
    Mat k,
    Mat d,
    Mat knew,
    CvSize size,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(size.width, size.height);
    cv::fisheye::undistortImage(
        CVDEREF(distorted),
        CVDEREF(undistorted),
        CVDEREF(k),
        CVDEREF(d),
        CVDEREF(knew),
        sz
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_fisheye_undistortPoints(
    Mat distorted, Mat undistorted, Mat k, Mat d, Mat R, Mat P, CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::fisheye::undistortPoints(
        CVDEREF(distorted),
        CVDEREF(undistorted),
        CVDEREF(k),
        CVDEREF(d),
        CVDEREF(R),
        CVDEREF(P)
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_fisheye_estimateNewCameraMatrixForUndistortRectify(
    Mat k,
    Mat d,
    CvSize imgSize,
    Mat r,
    Mat p,
    double balance,
    CvSize newSize,
    double fovScale,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size newSz(newSize.width, newSize.height);
    cv::Size imgSz(imgSize.width, imgSize.height);
    cv::fisheye::estimateNewCameraMatrixForUndistortRectify(
        CVDEREF(k), CVDEREF(d), imgSz, CVDEREF(r), CVDEREF(p), balance, newSz, fovScale
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_initUndistortRectifyMap(
    Mat cameraMatrix,
    Mat distCoeffs,
    Mat r,
    Mat newCameraMatrix,
    CvSize size,
    int m1type,
    Mat map1,
    Mat map2,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(size.width, size.height);
    cv::initUndistortRectifyMap(
        CVDEREF(cameraMatrix),
        CVDEREF(distCoeffs),
        CVDEREF(r),
        CVDEREF(newCameraMatrix),
        sz,
        m1type,
        CVDEREF(map1),
        CVDEREF(map2)
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_getOptimalNewCameraMatrix(
    Mat cameraMatrix,
    Mat distCoeffs,
    CvSize size,
    double alpha,
    CvSize newImgSize,
    CvRect* validPixROI,
    bool centerPrincipalPoint,
    Mat* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(size.width, size.height);
    cv::Size newSize(newImgSize.width, newImgSize.height);
    cv::Rect rect(
        validPixROI->x, validPixROI->y, validPixROI->width, validPixROI->height
    );
    auto mat = cv::getOptimalNewCameraMatrix(
        CVDEREF(cameraMatrix),
        CVDEREF(distCoeffs),
        sz,
        alpha,
        newSize,
        &rect,
        centerPrincipalPoint
    );
    validPixROI->x = rect.x;
    validPixROI->y = rect.y;
    validPixROI->width = rect.width;
    validPixROI->height = rect.height;
    rval->ptr = new cv::Mat(mat);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_calibrateCamera(
    VecVecPoint3f objectPoints,
    VecVecPoint2f imagePoints,
    CvSize imageSize,
    Mat cameraMatrix,
    Mat distCoeffs,
    Mat rvecs,
    Mat tvecs,
    int flag,
    TermCriteria criteria,
    double* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    auto tc = cv::TermCriteria(criteria.type, criteria.maxCount, criteria.epsilon);
    auto _objectPoints = vecvecpoint3f_c2cpp(objectPoints);
    auto _imagePoints = vecvecpoint2f_c2cpp(imagePoints);
    *rval = cv::calibrateCamera(
        _objectPoints,
        _imagePoints,
        cv::Size(imageSize.width, imageSize.height),
        CVDEREF(cameraMatrix),
        CVDEREF(distCoeffs),
        CVDEREF(rvecs),
        CVDEREF(tvecs),
        flag,
        tc
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_undistort(
    Mat src,
    Mat dst,
    Mat cameraMatrix,
    Mat distCoeffs,
    Mat newCameraMatrix,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::undistort(
        CVDEREF(src),
        CVDEREF(dst),
        CVDEREF(cameraMatrix),
        CVDEREF(distCoeffs),
        CVDEREF(newCameraMatrix)
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_undistortPoints(
    Mat distorted,
    Mat undistorted,
    Mat k,
    Mat d,
    Mat r,
    Mat p,
    TermCriteria criteria,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    auto tc = cv::TermCriteria(criteria.type, criteria.maxCount, criteria.epsilon);
    cv::undistortPoints(
        CVDEREF(distorted),
        CVDEREF(undistorted),
        CVDEREF(k),
        CVDEREF(d),
        CVDEREF(r),
        CVDEREF(p),
        tc
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_findChessboardCorners(
    Mat image,
    CvSize patternSize,
    Mat corners,
    int flags,
    bool* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(patternSize.width, patternSize.height);
    *rval = cv::findChessboardCorners(CVDEREF(image), sz, CVDEREF(corners), flags);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_findChessboardCornersSB(
    Mat image,
    CvSize patternSize,
    Mat corners,
    int flags,
    bool* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(patternSize.width, patternSize.height);
    *rval = cv::findChessboardCornersSB(CVDEREF(image), sz, CVDEREF(corners), flags);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_FindChessboardCornersSB_1(
    Mat image,
    CvSize patternSize,
    Mat corners,
    int flags,
    Mat meta,
    bool* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(patternSize.width, patternSize.height);
    *rval = cv::findChessboardCornersSB(
        CVDEREF(image), sz, CVDEREF(corners), flags, CVDEREF(meta)
    );
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_drawChessboardCorners(
    Mat image,
    CvSize patternSize,
    Mat corners,
    bool patternWasFound,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    cv::Size sz(patternSize.width, patternSize.height);
    cv::drawChessboardCorners(CVDEREF(image), sz, CVDEREF(corners), patternWasFound);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_estimateAffinePartial2D(
    VecPoint2f from, VecPoint2f to, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _from = vecpoint2f_c2cpp(from);
    auto _to = vecpoint2f_c2cpp(to);
    rval->ptr = new cv::Mat(cv::estimateAffinePartial2D(_from, _to));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_estimateAffinePartial2D_1(
    VecPoint2f from,
    VecPoint2f to,
    Mat inliers,
    int method,
    double ransacReprojThreshold,
    size_t maxIters,
    double confidence,
    size_t refineIters,
    Mat* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _from = vecpoint2f_c2cpp(from);
    auto _to = vecpoint2f_c2cpp(to);
    auto m = cv::estimateAffinePartial2D(
        _from,
        _to,
        CVDEREF(inliers),
        method,
        ransacReprojThreshold,
        maxIters,
        confidence,
        refineIters
    );
    rval->ptr = new cv::Mat(m);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_estimateAffine2D(
    VecPoint2f from, VecPoint2f to, Mat* rval, CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _from = vecpoint2f_c2cpp(from);
    auto _to = vecpoint2f_c2cpp(to);
    rval->ptr = new cv::Mat(cv::estimateAffine2D(_from, _to));
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_estimateAffine2D_1(
    VecPoint2f from,
    VecPoint2f to,
    Mat inliers,
    int method,
    double ransacReprojThreshold,
    size_t maxIters,
    double confidence,
    size_t refineIters,
    Mat* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    auto _from = vecpoint2f_c2cpp(from);
    auto _to = vecpoint2f_c2cpp(to);
    auto m = cv::estimateAffine2D(
        _from,
        _to,
        CVDEREF(inliers),
        method,
        ransacReprojThreshold,
        maxIters,
        confidence,
        refineIters
    );
    rval->ptr = new cv::Mat(m);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}

CvStatus* cv_findHomography(
    Mat src,
    Mat dst,
    int method,
    double ransacReprojThreshold,
    Mat mask,
    const int maxIters,
    const double confidence,
    Mat* rval,
    CvCallback_0 callback
) {
    BEGIN_WRAP
    auto m = cv::findHomography(
        CVDEREF(src),
        CVDEREF(dst),
        method,
        ransacReprojThreshold,
        CVDEREF(mask),
        maxIters,
        confidence
    );
    rval->ptr = new cv::Mat(m);
    if (callback != nullptr) {
        callback();
    }
    END_WRAP
}
