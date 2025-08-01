/* Created by Abdelaziz Mahdy. Licensed: Apache 2.0 license. Copyright (c) 2024 Abdelaziz Mahdy. */
#ifndef _OPENCV3_LOGGING_H_
#define _OPENCV3_LOGGING_H_

#ifdef __cplusplus
#include <opencv2/core.hpp>
extern "C" {
#endif

#include "dartcv/core/core.h"

typedef void (*LogCallbackEx)(
    int logLevel, const char* tag, const char* file, int line, const char* func, const char* message
);

CvStatus* setLogLevel(int logLevel);
CvStatus* getLogLevel(int* logLevel);
CvStatus* replaceWriteLogMessageEx(LogCallbackEx);

#ifdef __cplusplus
}
#endif

#endif  //_OPENCV3_LOGGING_H_
