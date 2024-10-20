/*
    This file is originally from gocv project
    Licensed: Apache 2.0 license. Copyright (c) 2017-2021 The Hybrid Group.

    Modified by Rainyl.
    Licensed: Apache 2.0 license. Copyright (c) 2024 Rainyl.
*/
#ifndef _OPENCV3_ARUCO_H_
#define _OPENCV3_ARUCO_H_

#ifdef __cplusplus
#include <opencv2/aruco.hpp>
extern "C" {
#endif

#include "dartcv/core/types.h"

#ifdef __cplusplus
CVD_TYPEDEF(cv::aruco::Dictionary, ArucoDictionary);
CVD_TYPEDEF(cv::aruco::DetectorParameters, ArucoDetectorParams);
CVD_TYPEDEF(cv::aruco::ArucoDetector, ArucoDetector);
#else
CVD_TYPEDEF(void, ArucoDictionary);
CVD_TYPEDEF(void, ArucoDetectorParams);
CVD_TYPEDEF(void, ArucoDetector);
#endif

CvStatus* cv_aruco_detectorParameters_create(ArucoDetectorParams* rval);
void cv_aruco_detectorParameters_close(ArucoDetectorParamsPtr ap);
void cv_aruco_detectorParameters_set_adaptiveThreshWinSizeMin(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_adaptiveThreshWinSizeMin(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_adaptiveThreshWinSizeMax(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_adaptiveThreshWinSizeMax(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_adaptiveThreshWinSizeStep(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_adaptiveThreshWinSizeStep(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_adaptiveThreshConstant(ArucoDetectorParams self, double value);
double cv_aruco_detectorParameters_get_adaptiveThreshConstant(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_minMarkerPerimeterRate(ArucoDetectorParams self, double value);
double cv_aruco_detectorParameters_get_minMarkerPerimeterRate(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_maxMarkerPerimeterRate(ArucoDetectorParams self, double value);
double cv_aruco_detectorParameters_get_maxMarkerPerimeterRate(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_polygonalApproxAccuracyRate(
    ArucoDetectorParams self, double value
);
double cv_aruco_detectorParameters_get_polygonalApproxAccuracyRate(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_minCornerDistanceRate(ArucoDetectorParams self, double value);
double cv_aruco_detectorParameters_get_minCornerDistanceRate(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_minDistanceToBorder(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_minDistanceToBorder(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_minMarkerDistanceRate(ArucoDetectorParams self, double value);
double cv_aruco_detectorParameters_get_minMarkerDistanceRate(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_cornerRefinementMethod(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_cornerRefinementMethod(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_cornerRefinementWinSize(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_cornerRefinementWinSize(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_cornerRefinementMaxIterations(
    ArucoDetectorParams self, int value
);
int cv_aruco_detectorParameters_get_cornerRefinementMaxIterations(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_cornerRefinementMinAccuracy(
    ArucoDetectorParams self, double value
);
double cv_aruco_detectorParameters_get_cornerRefinementMinAccuracy(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_markerBorderBits(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_markerBorderBits(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_perspectiveRemovePixelPerCell(
    ArucoDetectorParams self, int value
);
int cv_aruco_detectorParameters_get_perspectiveRemovePixelPerCell(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_perspectiveRemoveIgnoredMarginPerCell(
    ArucoDetectorParams self, double value
);
double cv_aruco_detectorParameters_get_perspectiveRemoveIgnoredMarginPerCell(
    ArucoDetectorParams self
);
void cv_aruco_detectorParameters_set_maxErroneousBitsInBorderRate(
    ArucoDetectorParams self, double value
);
double cv_aruco_detectorParameters_get_maxErroneousBitsInBorderRate(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_minOtsuStdDev(ArucoDetectorParams self, double value);
double cv_aruco_detectorParameters_get_minOtsuStdDev(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_errorCorrectionRate(ArucoDetectorParams self, double value);
double cv_aruco_detectorParameters_get_errorCorrectionRate(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_aprilTagQuadDecimate(ArucoDetectorParams self, float value);
float cv_aruco_detectorParameters_get_aprilTagQuadDecimate(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_aprilTagQuadSigma(ArucoDetectorParams self, float value);
float cv_aruco_detectorParameters_get_aprilTagQuadSigma(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_aprilTagMinClusterPixels(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_aprilTagMinClusterPixels(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_aprilTagMaxNmaxima(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_aprilTagMaxNmaxima(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_aprilTagCriticalRad(ArucoDetectorParams self, float value);
float cv_aruco_detectorParameters_get_aprilTagCriticalRad(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_aprilTagMaxLineFitMse(ArucoDetectorParams self, float value);
float cv_aruco_detectorParameters_get_aprilTagMaxLineFitMse(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_aprilTagMinWhiteBlackDiff(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_aprilTagMinWhiteBlackDiff(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_aprilTagDeglitch(ArucoDetectorParams self, int value);
int cv_aruco_detectorParameters_get_aprilTagDeglitch(ArucoDetectorParams self);
void cv_aruco_detectorParameters_set_detectInvertedMarker(ArucoDetectorParams self, bool value);
bool cv_aruco_detectorParameters_get_detectInvertedMarker(ArucoDetectorParams self);

CvStatus* cv_aruco_getPredefinedDictionary(int dictionaryId, ArucoDictionary* rval);
void cv_aruco_arucoDictionary_close(ArucoDictionaryPtr self);

CvStatus* cv_aruco_arucoDetector_create(ArucoDetector* rval);
CvStatus* cv_aruco_arucoDetector_create_1(
    ArucoDictionary dictionary,
    ArucoDetectorParams params,
    ArucoDetector* rval,
    CvCallback_0 callback
);
void cv_aruco_arucoDetector_close(ArucoDetectorPtr ad);
CvStatus* cv_aruco_arucoDetector_detectMarkers(
    ArucoDetector ad,
    Mat inputArr,
    VecVecPoint2f* markerCorners,
    VecI32* markerIds,
    VecVecPoint2f* rejectedCandidates,
    CvCallback_0 callback
);

CvStatus* cv_aruco_drawDetectedMarkers(
    Mat image,
    VecVecPoint2f markerCorners,
    VecI32 markerIds,
    Scalar borderColor,
    CvCallback_0 callback
);
CvStatus* cv_aruco_generateImageMarker(
    int dictionaryId, int id, int sidePixels, int borderBits, Mat dst, CvCallback_0 callback
);

#ifdef __cplusplus
}
#endif

#endif  //_OPENCV3_ARUCO_H_
