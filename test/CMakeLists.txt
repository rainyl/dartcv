cmake_minimum_required(VERSION 3.15)

project(DartCvTest)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif ()

include(CTest)
enable_testing()

### test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
if (WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif (WIN32)
FetchContent_MakeAvailable(googletest)
# copy test images
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/test)
file(COPY
        "${CMAKE_CURRENT_SOURCE_DIR}/images"
        DESTINATION ${CMAKE_BINARY_DIR}/test
)
# model files for DNN test
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/models")
  file(COPY
          "${CMAKE_CURRENT_SOURCE_DIR}/models"
          DESTINATION ${CMAKE_BINARY_DIR}/test
  )
endif ()

macro(add_dartcv_test executable_name source_file)
  add_executable(
          ${executable_name}
          "${source_file}"
  )

  target_include_directories(${executable_name} PUBLIC ${DARTCV_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})

  target_link_libraries(
          ${executable_name}
          PUBLIC
          ${OpenCV_LIBS}
          dartcv
          GTest::gtest_main
  )


  if (WIN32)
    set_target_properties(${executable_name} PROPERTIES
            COMPILE_FLAGS "/EHsc"
    )
#    if (BUILD_WITH_STATIC_CRT)
#      target_compile_options(${executable_name} PRIVATE "/MT")
#    endif ()
  endif (WIN32)
endmacro()

#add_dartcv_test(dartcv_test_vec "vec.cc")
#add_dartcv_test(dartcv_test_core "core.cc")
add_dartcv_test(dartcv_test_calib3d "calib3d.cc")
#add_dartcv_test(dartcv_test_dnn "dnn.cc")
#add_dartcv_test(dartcv_test_imgcodecs "imgcodecs.cc")
#add_dartcv_test(dartcv_test_imgproc "imgproc.cc")
#add_dartcv_test(dartcv_test_video "video.cc")

include(GoogleTest)
#gtest_discover_tests(dartcv_test_vec)
#gtest_discover_tests(dartcv_test_core)
gtest_discover_tests(dartcv_test_calib3d)
#gtest_discover_tests(dartcv_test_dnn)
#gtest_discover_tests(dartcv_test_imgcodecs)
#gtest_discover_tests(dartcv_test_imgproc)
#gtest_discover_tests(dartcv_test_video)
