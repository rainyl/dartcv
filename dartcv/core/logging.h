/* Created by Abdelaziz Mahdy. Licensed: Apache 2.0 license. Copyright (c) 2024 Abdelaziz Mahdy. */
#ifndef _OPENCV3_LOGGING_H_
#define _OPENCV3_LOGGING_H_

#ifdef __cplusplus
#include <opencv2/core.hpp>
extern "C" {
#endif

#include "dartcv/core/core.h"

typedef void (*LogCallback)(
    int logLevel,
    const char* tag,
    size_t tagLen,
    const char* file,
    size_t fileLen,
    int line,
    const char* func,
    size_t funcLen,
    const char* message,
    size_t msgLen
);

LogCallback logCallback = NULL;

CvStatus* setLogLevel(int logLevel);
CvStatus* getLogLevel(int* logLevel);

void setLogCallback(LogCallback callback);
LogCallback getLogCallback();

CvStatus* replaceWriteLogMessageEx(LogCallback callback);

#ifdef __cplusplus
}
#endif

#endif  //_OPENCV3_LOGGING_H_
