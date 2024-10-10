# dartcv

C wrappers for opencv, used for [opencv_dart](https://github.com/rainyl/opencv_dart)

## build

1. git clone https://github.com/rainyl/dartcv.git
2. cd dartcv
3. mkdir build && cd build
4. cmake .. -DCMAKE_INSTALL_PREFIX=install
5. cmake --build . --config Release --target install

## Note

- windows: use Visual Studio 2019 and above
- more options, see CMakeLists.txt
- set `-DDARTCV_DISABLE_DOWNLOAD_OPENCV=ON` to disable download prebuilt opencv sdk from [opencv.full](https://github.com/rainyl/opencv.full.git), you need to explicitly set `OpenCV_DIR`
- set `OPENCV_VERSION` to change the version of opencv.full, e.g., `-DOPENCV_VERSION="4.10.0+9"`
