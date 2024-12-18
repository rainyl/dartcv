/*
    This file is originally from gocv project
    Licensed: Apache 2.0 license. Copyright (c) 2017-2021 The Hybrid Group.

    Modified by Rainyl.
    Licensed: Apache 2.0 license. Copyright (c) 2024 Rainyl.
*/

#ifndef CVD_CALIB_H_
#define CVD_CALIB_H_

#ifdef __cplusplus
#include <opencv2/calib3d.hpp>
extern "C" {
#endif
#include "dartcv/core/types.h"
#include <stddef.h>

// Calib
CvStatus* cv_fisheye_undistortImage(
    Mat distorted, Mat undistorted, Mat k, Mat d, CvCallback_0 callback
);
CvStatus* cv_fisheye_undistortImage_1(
    Mat distorted, Mat undistorted, Mat k, Mat d, Mat knew, CvSize size, CvCallback_0 callback
);
CvStatus* cv_fisheye_undistortPoints(
    Mat distorted, Mat undistorted, Mat k, Mat d, Mat R, Mat P, CvCallback_0 callback
);
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
);

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
);
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
);
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
);
CvStatus* cv_undistort(
    Mat src, Mat dst, Mat cameraMatrix, Mat distCoeffs, Mat newCameraMatrix, CvCallback_0 callback
);
CvStatus* cv_undistortPoints(
    Mat distorted,
    Mat undistorted,
    Mat k,
    Mat d,
    Mat r,
    Mat p,
    TermCriteria criteria,
    CvCallback_0 callback
);
CvStatus* cv_findChessboardCorners(
    Mat image, CvSize patternSize, VecPoint2f* corners, int flags, bool* rval, CvCallback_0 callback
);
CvStatus* cv_findChessboardCornersSB(
    Mat image, CvSize patternSize, VecPoint2f* out_corners, int flags, bool* rval, CvCallback_0 callback
);
CvStatus* cv_findChessboardCornersSB_1(
    Mat image,
    CvSize patternSize,
    VecPoint2f* out_corners,
    int flags,
    Mat meta,
    bool* rval,
    CvCallback_0 callback
);
CvStatus* cv_drawChessboardCorners(
    Mat image, CvSize patternSize, VecPoint2f corners, bool patternWasFound, CvCallback_0 callback
);
CvStatus* cv_estimateAffinePartial2D(
    VecPoint2f from, VecPoint2f to, Mat* rval, CvCallback_0 callback
);
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
);
CvStatus* cv_estimateAffine2D(VecPoint2f from, VecPoint2f to, Mat* rval, CvCallback_0 callback);
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
);
CvStatus* cv_findHomography(
    Mat src,
    Mat dst,
    int method,
    double ransacReprojThreshold,
    Mat mask,
    int maxIters,
    double confidence,
    Mat* rval,
    CvCallback_0 callback
);
#ifdef __cplusplus
}
#endif

#endif  //_OPENCV3_CALIB_H
