# dartcv

C wrappers for opencv, used for [opencv_dart](https://github.com/rainyl/opencv_dart)

## build
#### 1. Install dependencies

- Windows: Install Visual Studio 2019 or Later, cmake
- Linux: Ubuntu as example

```bash
sudo apt-get install build-essential libgtk-3-dev cmake
```

- macOS: XCode, cmake

#### 2. clone this repo

```bash
git clone https://github.com/rainyl/dartcv.git
cd dartcv
```

#### 3. compile

- Windows:

```pwsh
mkdir -Force build && cd build
cmake -S .. `
  -DFFMPEG_USE_STATIC_LIBS=OFF `
  -DCMAKE_INSTALL_PREFIX=install `
  -DDARTCV_ENABLE_INSTALL=ON `
  -DCMAKE_BUILD_TYPE=Release `
  -DDARTCV_WITH_VIDEOIO=ON `
  -DDARTCV_WITH_HIGHGUI=ON

cmake --build . --config Release --target install
```

- Linux

```bash
mkdir -p build && cd build
cmake -S .. \
  -DCMAKE_INSTALL_PREFIX=install \
  -DDARTCV_WITH_VIDEOIO=ON \
  -DDARTCV_ENABLE_INSTALL=ON \
  -DCMAKE_BUILD_TYPE=Release

cmake --build . --config Release --target install
```

- android

If you want to use your own NDK instead of conan maintained one, please set `ANDROID_NDK_HOME`
or `ANDROID_NDK_ROOT` environment variable, e.g., `export ANDROID_NDK_HOME=/opt/android-ndk-r26c`

```bash
mkdir -p build && cd build
cmake -S .. \
  -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake \
  -DANDROID_USE_LEGACY_TOOLCHAIN_FILE=False \
  -DANDROID_PLATFORM=android-24 \
  -DCMAKE_BUILD_TYPE=Release \
  -DANDROID_STL=c++_static \
  -DANDROID_ARM_NEON=ON \
  -DDARTCV_WITH_VIDEOIO=ON \
  -DDARTCV_ENABLE_INSTALL=ON \
  -DANDROID_ABI="armeabi-v7a" \
  -DCMAKE_INSTALL_PREFIX="install"

cmake --build . --config Release --target install
```

- MacOS: use [DartCvMacOS](https://cocoapods.org/pods/DartCvMacOS) from cocoapods or build `.dylib` using:
```bash
mkdir -p build && cd build
cmake -S .. \
  -DCMAKE_TOOLCHAIN_FILE=../cmake/ios.toolchain.cmake \
  -DPLATFORM=MAC \
  -DDEPLOYMENT_TARGET="10.15" \
  -DENABLE_BITCODE=OFF \
  -DENABLE_ARC=OFF \
  -DENABLE_VISIBILITY=OFF \
  -DCMAKE_INSTALL_PREFIX=install \
  -DDARTCV_WITH_VIDEOIO=ON \
  -DDARTCV_WITH_HIGHGUI=ON \
  -DDARTCV_ENABLE_INSTALL=ON \
  -DCMAKE_BUILD_TYPE=Release

cmake --build . --config Release --target install
```

- ios: use [DartCvIOS](https://cocoapods.org/pods/DartCvIOS) from cocoapods

#### 4. test

- Set `DARTCV_LIB_PATH` environment variable to the path of the compiled dynamic library,
  e.g., `export DARTCV_LIB_PATH=`pwd`/linux/libdartcv.so`
  or `$ENV:DARTCV_LIB_PATH=$PWD\windows\dartcv.dll`
- or append the lib path to the library search path of your system
- If you want to test using vscode, add above variable to `"dart.env"` in `settings.json`

## Note

- windows: use Visual Studio 2019 and above
- more options refer to CMakeLists.txt
- set `-DDARTCV_DISABLE_DOWNLOAD_OPENCV=ON` to disable download prebuilt opencv sdk from [opencv.full](https://github.com/rainyl/opencv.full.git), you need to explicitly set `OpenCV_DIR`
- set `OPENCV_VERSION` to change the version of `opencv.full`, e.g., `-DOPENCV_VERSION="4.10.0+9"`
- set `DARTCV_CACHE_DIR` to cache opencv sdk and avoid downloading every time
- `videoio`, `highgui` requires FFMPEG, they were attached in the `libopencv` downloaded from opencv.full
