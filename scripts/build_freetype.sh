#!/bin/bash

# Get some help
# meson configure >> help-meson.txt

# Define some global variables
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
WORK_DIR=$(pwd)
BUILD_DIR=$WORK_DIR/build-apple/freetype
FRAMEWORK_OUTPUT_DIR=$WORK_DIR/Frameworks
FT_VERSION='2.12.1'
FT_SOURCE_DIR=$BUILD_DIR/freetype-$FT_VERSION

platforms_path='/Applications/Xcode.app/Contents/Developer/Platforms'
# Your signing identity to sign the xcframework. Execute "security find-identity -v -p codesigning" and select one from the list
signing_identity=YOUR_SIGNING_IDENTITY

# Console output formatting
# https://stackoverflow.com/a/2924755
bold=$(tput bold)
normal=$(tput sgr0)

# Create the build directory if not exists
mkdir -p $BUILD_DIR

if [ ! -d "$FT_SOURCE_DIR" ]; then
  echo "Download FreeType"
  wget -O $BUILD_DIR/freetype.tar.xz https://sourceforge.net/projects/freetype/files/freetype2/$FT_VERSION/freetype-$FT_VERSION.tar.xz
  tar -xf $BUILD_DIR/freetype.tar.xz -C $BUILD_DIR
fi

exit_if_error() {
  local result=$?
  if [ $result -ne 0 ]; then
    echo "Received an exit code $result, aborting"
    exit 1
  fi
}

build_library() {
  local platform_name=$1
  local arch=$2
  local target_os=$3

  local config_name="$platform_name/$arch"

  if [[ "$arch" == "arm64" ]]; then
    local meson_cpu="arm64"
    local meson_cpu_family="aarch64"
  elif [[ "$arch" == "x86_64" ]]; then
    local meson_cpu="x86"
    local meson_cpu_family="x86_64"
  else
    echo "Unknown architecture"
    exit 1
  fi

  echo "Build for ${bold}$config_name${normal}"
  mkdir -p $BUILD_DIR/$config_name

  # Remove config file if exists
  rm -f "$BUILD_DIR/$config_name.txt"
  exit_if_error

  # Generate meson config file for cross-compile
  mkdir -p $BUILD_DIR/$config_name/pkg-config
  echo \
    "[binaries]
c = 'clang'
cpp = 'clang++'
ar = 'ar'
strip = 'strip'
pkg-config = 'pkg-config'

[host_machine]
system = 'darwin'
cpu_family = '$meson_cpu_family'
cpu = '$meson_cpu'
endian = 'little'" \
    >>"$BUILD_DIR/$config_name.txt"
  exit_if_error

  # Setup meson build
  meson setup $BUILD_DIR/$config_name $FT_SOURCE_DIR \
    --cross-file $BUILD_DIR/$config_name.txt \
    -Dprefix=$BUILD_DIR/$config_name/install \
    -Dauto_features=disabled \
    -Dbuildtype=minsize \
    -Ddebug=false \
    -Ddefault_library=static \
    -Dlayout=mirror \
    -Doptimization=2 \
    -Dprefer_static=false \
    -Dstrip=true \
    -Dpkg_config_path="$BUILD_DIR/$config_name/pkg-config" \
    -Dc_args="-isysroot '$platforms_path/$platform_name.platform/Developer/SDKs/$platform_name.sdk' -arch $arch -mtargetos=$target_os" \
    -Dc_link_args="-arch $arch -mtargetos=$target_os" \
    -Dc_std=c17 \
    -Dbrotli=disabled \
    -Dbzip2=disabled \
    -Dharfbuzz=disabled \
    -Dmmap=enabled \
    -Dpng=disabled \
    -Dtests=disabled \
    -Dzlib=system
  exit_if_error

  # Build
  echo "Build"
  ninja -C $BUILD_DIR/$config_name
  exit_if_error

  # Install compiled libraries and headers into the install folder
  ninja -C $BUILD_DIR/$config_name install
  exit_if_error

  # Copy custom umbrella header
  echo \
  "#ifndef LibFreeType_h
#define LibFreeType_h

#include <ft2build.h>
#include <freetype/freetype.h>

#endif // LibFreeType_h" > $BUILD_DIR/$config_name/install/include/freetype2/libfreetype.h
  exit_if_error

  # About modules
  # https://clang.llvm.org/docs/Modules.html
  # Without module.modulemap FreeType is not exposed to Swift
  # Copy the module map into the directory with installed header files
  mkdir -p $BUILD_DIR/$config_name/install/include/freetype2/FreeType-Module
  echo \
  "module FreeType {
    header \"../libfreetype.h\"

    export *
}" > $BUILD_DIR/$config_name/install/include/freetype2/FreeType-Module/module.modulemap
  exit_if_error
}

build_library MacOSX arm64 macos11
build_library MacOSX x86_64 macos10.13
build_library iPhoneOS arm64 ios12
build_library iPhoneSimulator arm64 ios14-simulator
build_library iPhoneSimulator x86_64 ios12-simulator
# build_library AppleTVOS arm64 tvos12
# build_library AppleTVSimulator arm64 tvos12-simulator
# build_library AppleTVSimulator x86_64 tvos12-simulator
# build_library WatchOS arm64 watchos8
# build_library WatchSimulator arm64 watchos8-simulator
# build_library WatchSimulator x86_64 watchos8-simulator
# build_library XROS arm64 xros1
# build_library XRSimulator arm64 xros1-simulator
# build_library XRSimulator x86_64 xros1-simulator

create_framework() {
  # Remove previously created framework if exists
  rm -rf $FRAMEWORK_OUTPUT_DIR/FreeType.xcframework
  exit_if_error

  # Merge macOS arm and x86 binaries
  mkdir -p $BUILD_DIR/MacOSX
  exit_if_error
  lipo -create -output $BUILD_DIR/MacOSX/libfreetype.a \
    $BUILD_DIR/MacOSX/arm64/install/lib/libfreetype.a \
    $BUILD_DIR/MacOSX/x86_64/install/lib/libfreetype.a
  exit_if_error

  # Merge iOS simulator arm and x86 binaries
  mkdir -p $BUILD_DIR/iPhoneSimulator
  exit_if_error
  lipo -create -output $BUILD_DIR/iPhoneSimulator/libfreetype.a \
    $BUILD_DIR/iPhoneSimulator/arm64/install/lib/libfreetype.a \
    $BUILD_DIR/iPhoneSimulator/x86_64/install/lib/libfreetype.a
  exit_if_error

  # # Merge tvOS simulator arm and x86 binaries
  # mkdir -p $BUILD_DIR/AppleTVSimulator
  # exit_if_error
  # lipo -create -output $BUILD_DIR/AppleTVSimulator/libfreetype.a \
  #   $BUILD_DIR/AppleTVSimulator/arm64/install/lib/libfreetype.a \
  #   $BUILD_DIR/AppleTVSimulator/x86_64/install/lib/libfreetype.a
  # exit_if_error

  # # Merge watchOS simulator arm and x86 binaries
  # mkdir -p $BUILD_DIR/WatchSimulator
  # exit_if_error
  # lipo -create -output $BUILD_DIR/WatchSimulator/libfreetype.a \
  #   $BUILD_DIR/WatchSimulator/arm64/install/lib/libfreetype.a \
  #   $BUILD_DIR/WatchSimulator/x86_64/install/lib/libfreetype.a
  # exit_if_error

  # # Merge visionOS simulator arm and x86 binaries
  # mkdir -p $BUILD_DIR/XRSimulator
  # exit_if_error
  # lipo -create -output $BUILD_DIR/XRSimulator/libfreetype.a \
  #   $BUILD_DIR/XRSimulator/arm64/install/lib/libfreetype.a \
  #   $BUILD_DIR/XRSimulator/x86_64/install/lib/libfreetype.a
  # exit_if_error

  # Create the framework with multiple platforms
  xcodebuild -create-xcframework \
    -library $BUILD_DIR/MacOSX/libfreetype.a -headers $BUILD_DIR/MacOSX/arm64/install/include/freetype2 \
    -library $BUILD_DIR/iPhoneOS/arm64/install/lib/libfreetype.a -headers $BUILD_DIR/iPhoneOS/arm64/install/include/freetype2 \
    -library $BUILD_DIR/iPhoneSimulator/libfreetype.a -headers $BUILD_DIR/iPhoneSimulator/arm64/install/include/freetype2 \
    -output $FRAMEWORK_OUTPUT_DIR/FreeType.xcframework
    # -library $BUILD_DIR/AppleTVOS/arm64/install/lib/libfreetype.a -headers $BUILD_DIR/AppleTVOS/arm64/install/include/freetype2 \
    # -library $BUILD_DIR/AppleTVSimulator/libfreetype.a -headers $BUILD_DIR/AppleTVSimulator/arm64/install/include/freetype2 \
    # -library $BUILD_DIR/WatchOS/arm64/install/lib/libfreetype.a -headers $BUILD_DIR/WatchOS/arm64/install/include/freetype2 \
    # -library $BUILD_DIR/WatchSimulator/libfreetype.a -headers $BUILD_DIR/WatchSimulator/arm64/install/include/freetype2 \
    # -library $BUILD_DIR/XROS/arm64/install/lib/libfreetype.a -headers $BUILD_DIR/XROS/arm64/install/include/freetype2 \
    # -library $BUILD_DIR/XRSimulator/libfreetype.a -headers $BUILD_DIR/XRSimulator/arm64/install/include/freetype2 \
  exit_if_error

  # And sign the framework
  #codesign --timestamp -s $signing_identity $FRAMEWORK_OUTPUT_DIR/FreeType.xcframework
  #exit_if_error
}
create_framework

# fin
