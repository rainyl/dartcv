cmake_minimum_required(VERSION 3.15)

project(dartcv_library VERSION 1.0.0 LANGUAGES C CXX)
set(LIBRARY_NAME "dartcv")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# must include
# option(DARTCV_WITH_CORE "Include core, imgcodecs models of opencv" ON)
option(DARTCV_WITH_CALIB3D "Include calib3d module of opencv" ON)
option(DARTCV_WITH_CONTRIB "Include contrib module of opencv" ON)
option(DARTCV_WITH_DNN "Include dnn module of opencv" ON)
option(DARTCV_WITH_FEATURES2D "Include features2d module of opencv" ON)
option(DARTCV_WITH_HIGHGUI "Include highgui module of opencv" OFF)
option(DARTCV_WITH_IMGPROC "Include imgproc module of opencv" ON)
option(DARTCV_WITH_OBJDETECT "Include objdetect module of opencv" ON)
option(DARTCV_WITH_PHOTO "Include photo module of opencv" ON)
option(DARTCV_WITH_STITCHING "Include stitching module of opencv" ON)
option(DARTCV_WITH_VIDEO "Include video module of opencv" ON)
option(DARTCV_WITH_VIDEOIO "Include objdetect module of opencv" OFF)
option(DARTCV_WITH_GAPI "Include gapi of opencv" OFF) # TODO: not finished
option(DARTCV_WORLD "Include all modules" OFF) # world means build all modules

option(DARTCV_ENABLE_INSTALL "Enable install" OFF)
option(DARTCV_ENABLE_TEST "Enable tests" OFF)

option(BUILD_WITH_STATIC_CRT "Build with static CRT" ON)
option(DARTCV_DISABLE_DOWNLOAD_OPENCV "Download opencv sdk from opencv.full" OFF)

#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE INTERNAL "")

if (${DARTCV_WITH_HIGHGUI} OR ${DARTCV_WITH_VIDEOIO} OR ${DARTCV_WORLD})
  set(DARTCV_WITH_FFMPEG ON CACHE BOOL "")
else ()
  set(DARTCV_WITH_FFMPEG OFF CACHE BOOL "")
endif ()

if (NOT OPENCV_VERSION)
  set(OPENCV_VERSION "4.11.0+1")
endif ()

# ============ download and prepare OpenCV =========
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif ()

include(cmake/download_setup_opencv.cmake)

if (UNIX AND NOT ANDROID)
  find_package(Iconv REQUIRED)
endif ()

# ============ download and prepare OpenCV_DIR finished ==============
find_package(OpenCV REQUIRED)

if (DARTCV_WITH_HIGHGUI OR DARTCV_WITH_VIDEOIO OR DARTCV_WORLD)
  find_package(FFMPEG REQUIRED)
endif ()

set(DARTCV_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "DARTCV_INCLUDE_DIRS")

add_subdirectory(dartcv)

if (DARTCV_ENABLE_INSTALL)
  set(ROOT_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

  if (ANDROID)
    message(STATUS "Installing ${FFMPEG_LIB_PATHS} to ${CMAKE_INSTALL_PREFIX}")
    file(COPY ${FFMPEG_LIB_PATHS} DESTINATION ${CMAKE_INSTALL_PREFIX}/${ANDROID_ABI})
  endif ()

  # install
  install(DIRECTORY ${ROOT_PROJECT_DIR}/dartcv
          DESTINATION ${CMAKE_INSTALL_PREFIX}/include
          COMPONENT header_files
          FILES_MATCHING
          PATTERN "*.h"
          PATTERN "t.h" EXCLUDE
          PATTERN "test" EXCLUDE
          PATTERN "build" EXCLUDE
  )
  install(FILES "${ROOT_PROJECT_DIR}/README.md" "${ROOT_PROJECT_DIR}/LICENSE"
          DESTINATION ${CMAKE_INSTALL_PREFIX}
          COMPONENT asset_files
  )
  install(TARGETS dartcv
          DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
          COMPONENT target_libs
  )

  install(FILES ${FFMPEG_LIB_PATHS}
          DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
          COMPONENT ffmpeg_libs
  )
endif ()

if (DARTCV_ENABLE_TEST)
  add_subdirectory(test)
endif ()
