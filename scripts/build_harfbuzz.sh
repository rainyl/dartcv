#!/bin/bash

# Define some global variables
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
WORK_DIR=$(pwd)
BUILD_DIR=$WORK_DIR/build-apple/harfbuzz
FRAMEWORK_OUTPUT_DIR=$WORK_DIR/Frameworks
HB_VERSION='11.2.1'
HB_SOURCE_DIR=$BUILD_DIR/harfbuzz-$HB_VERSION

freetype_framework_path="$FRAMEWORK_OUTPUT_DIR/FreeType.xcframework"
platforms_path='/Applications/Xcode.app/Contents/Developer/Platforms'
# Your signing identity to sign the xcframework. Execute "security find-identity -v -p codesigning" and select one from the list
identity=YOUR_SIGNING_IDENTITY


# Console output formatting
# https://stackoverflow.com/a/2924755
bold=$(tput bold)
normal=$(tput sgr0)


# Create the build directory if not exists
mkdir -p $BUILD_DIR

if [ ! -d "$HB_SOURCE_DIR" ]; then
  echo "Download HarfBuzz"
  wget -O $BUILD_DIR/harfbuzz.tar.gz https://github.com/harfbuzz/harfbuzz/archive/refs/tags/$HB_VERSION.tar.gz
  tar -zxf $BUILD_DIR/harfbuzz.tar.gz -C $BUILD_DIR
fi

exit_if_error() {
  local result=$?
  if [ $result -ne 0 ] ; then
    echo "Received an exit code $result, aborting"
    exit 1
  fi
}


# Compile the library for specific OS and architecture
build_library() {
  local platform_name=$1
  local arch=$2
  local target_os=$3

  # Determine config name
  local config_name="$platform_name/$arch"

  # Determine meson cpu settings
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


  # Remove build directory for the current platform if exists
  rm -rf $BUILD_DIR/$config_name
  exit_if_error

  # Welcome message
  echo "Build for ${bold}$config_name${normal}"
  mkdir -p $BUILD_DIR/$config_name

  # Remove config file if exists
  rm -f "$BUILD_DIR/$config_name.txt"
  exit_if_error

  # Generate meson config file for cross-compile
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
endian = 'little'

[built-in options]
c_args = ['-isysroot', '$platforms_path/$platform_name.platform/Developer/SDKs/$platform_name.sdk', '-arch', '$arch', '-mtargetos=$target_os', '-O2']
cpp_args = ['-isysroot', '$platforms_path/$platform_name.platform/Developer/SDKs/$platform_name.sdk', '-arch', '$arch', '-mtargetos=$target_os', '-O2']
c_link_args = ['-arch', '$arch', '-mtargetos=$target_os']
cpp_link_args = ['-arch', '$arch', '-mtargetos=$target_os']" \
>> "$BUILD_DIR/$config_name.txt"
  exit_if_error


  # Create custom pkg-config file for freetype to target specific platform and architecture
  mkdir -p $BUILD_DIR/$config_name/
  if [[ "$platform_name" == "MacOSX" ]]; then
    local freetype_target="macos-arm64_x86_64"
  elif [[ "$platform_name" == "iPhoneOS" ]]; then
    local freetype_target="ios-$arch"
  elif [[ "$platform_name" == "iPhoneSimulator" ]]; then
    local freetype_target="ios-arm64_x86_64-simulator"
  elif [[ "$platform_name" == "AppleTVOS" ]]; then
    local freetype_target="tvos-$arch"
  elif [[ "$platform_name" == "AppleTVSimulator" ]]; then
    local freetype_target="tvos-arm64_x86_64-simulator"
  elif [[ "$platform_name" == "WatchOS" ]]; then
    local freetype_target="watchos-$arch"
  elif [[ "$platform_name" == "WatchSimulator" ]]; then
    local freetype_target="watchos-arm64_x86_64-simulator"
  elif [[ "$platform_name" == "XROS" ]]; then
    local freetype_target="xros-$arch"
  elif [[ "$platform_name" == "XRSimulator" ]]; then
    local freetype_target="xros-arm64_x86_64-simulator"
  else
    echo "Unknown platform $platform_name"
    exit 1
  fi
  local freetype_path="$freetype_framework_path/$freetype_target"
  mkdir -p $BUILD_DIR/$config_name/pkg-config
  rm -f   "$BUILD_DIR/$config_name/pkg-config/freetype2.pc"
  # idk wtf meson.build expects freetype version to be at least 12.0.6 when the latest official version is 2.13.3, so we just define our own version
  echo \
"prefix=\"$freetype_path\"
exec_prefix=\${prefix}
libdir=\${exec_prefix}
includedir=\${prefix}/Headers

Name: FreeType 2
Description: A free, high-quality, and portable font engine.
Version: 1000.0.0
Requires: zlib, bzip2
Libs: -L\${libdir} -llibfreetype
Libs.private: -lz
Cflags: -I\"\${includedir}\"
" \
>> "$BUILD_DIR/$config_name/pkg-config/freetype2.pc"
  exit_if_error

  # Setup meson build
  echo "Configure meson"
  meson setup $BUILD_DIR/$config_name $HB_SOURCE_DIR \
    --cross-file $BUILD_DIR/$config_name.txt \
    --prefix=$BUILD_DIR/$config_name/install \
    --strip \
    -Dpkg_config_path="$BUILD_DIR/$config_name/pkg-config" \
    -Dcpp_std=c++20 \
    -Ddefault_library=static \
    -Dicu=disabled \
    -Dglib=disabled \
    -Dgobject=disabled \
    -Dcairo=disabled \
    -Dchafa=disabled \
    -Dfreetype=enabled \
    -Dtests=disabled \
    -Dutilities=disabled \
    -Dintrospection=disabled \
    -Ddocs=disabled \
    -Dbuildtype=minsize
  exit_if_error

  # Build
  echo "Build"
  ninja -C $BUILD_DIR/$config_name
  exit_if_error

  # Install compiled libraries and headers into the install folder
  ninja -C $BUILD_DIR/$config_name install
  exit_if_error

  # cairo, gobject and subset are not included (maybe for now) - remove those headers to not confuse users
  rm -rf $BUILD_DIR/$config_name/install/include/harfbuzz/hb-cairo.h
  rm -rf $BUILD_DIR/$config_name/install/include/harfbuzz/hb-gobject.h
  rm -rf $BUILD_DIR/$config_name/install/include/harfbuzz/hb-gobject-enums.h
  rm -rf $BUILD_DIR/$config_name/install/include/harfbuzz/hb-gobject-structs.h
  rm -rf $BUILD_DIR/$config_name/install/include/harfbuzz/hb-subset.h
  rm -rf $BUILD_DIR/$config_name/install/include/harfbuzz/hb-subset-serialize.h

  # About modules
  # https://clang.llvm.org/docs/Modules.html
  # Without module.modulemap HarfBuzz is not exposed to Swift
  # Copy the module map into the directory with installed header files
#   mkdir -p $BUILD_DIR/$config_name/install/include/harfbuzz/HarfBuzz-Module
#   # cp module.modulemap $BUILD_DIR/$config_name/install/include/harfbuzz/HarfBuzz-Module/module.modulemap
#   echo \
#   "module HarfBuzz {
#     header \"../hb.h\"

#     export *
# }" > $BUILD_DIR/$config_name/install/include/harfbuzz/HarfBuzz-Module/module.modulemap
#   exit_if_error

  # Strip installed library
  strip -S $BUILD_DIR/$config_name/install/lib/libharfbuzz.a
  exit_if_error
}


build_library MacOSX           arm64  macos11
build_library MacOSX           x86_64 macos10.13
build_library iPhoneOS         arm64  ios12
build_library iPhoneSimulator  arm64  ios14-simulator
build_library iPhoneSimulator  x86_64 ios12-simulator
# build_library AppleTVOS        arm64  tvos12
# build_library AppleTVSimulator arm64  tvos12-simulator
# build_library AppleTVSimulator x86_64 tvos12-simulator
# build_library WatchOS          arm64  watchos8
# build_library WatchSimulator   arm64  watchos8-simulator
# build_library WatchSimulator   x86_64 watchos8-simulator
# build_library XROS             arm64  xros1
# build_library XRSimulator      arm64  xros1-simulator
# build_library XRSimulator      x86_64 xros1-simulator


create_framework() {
  # Remove previously created framework if exists
  rm -rf $FRAMEWORK_OUTPUT_DIR/HarfBuzz.xcframework
  exit_if_error

  # Merge macOS arm and x86 binaries
  mkdir -p $BUILD_DIR/MacOSX
  exit_if_error
  lipo -create -output $BUILD_DIR/MacOSX/libharfbuzz.a \
    $BUILD_DIR/MacOSX/arm64/install/lib/libharfbuzz.a \
    $BUILD_DIR/MacOSX/x86_64/install/lib/libharfbuzz.a
  exit_if_error

  # Merge iOS simulator arm and x86 binaries
  mkdir -p $BUILD_DIR/iPhoneSimulator
  exit_if_error
  lipo -create -output $BUILD_DIR/iPhoneSimulator/libharfbuzz.a \
    $BUILD_DIR/iPhoneSimulator/arm64/install/lib/libharfbuzz.a \
    $BUILD_DIR/iPhoneSimulator/x86_64/install/lib/libharfbuzz.a
  exit_if_error

  # # Merge tvOS simulator arm and x86 binaries
  # mkdir -p $BUILD_DIR/AppleTVSimulator
  # exit_if_error
  # lipo -create -output $BUILD_DIR/AppleTVSimulator/libharfbuzz.a \
  #   $BUILD_DIR/AppleTVSimulator/arm64/install/lib/libharfbuzz.a \
  #   $BUILD_DIR/AppleTVSimulator/x86_64/install/lib/libharfbuzz.a
  # exit_if_error

  # # Merge watchOS simulator arm and x86 binaries
  # mkdir -p $BUILD_DIR/WatchSimulator
  # exit_if_error
  # lipo -create -output $BUILD_DIR/WatchSimulator/libharfbuzz.a \
  #   $BUILD_DIR/WatchSimulator/arm64/install/lib/libharfbuzz.a \
  #   $BUILD_DIR/WatchSimulator/x86_64/install/lib/libharfbuzz.a
  # exit_if_error

  # # Merge visionOS simulator arm and x86 binaries
  # mkdir -p $BUILD_DIR/XRSimulator
  # exit_if_error
  # lipo -create -output $BUILD_DIR/XRSimulator/libharfbuzz.a \
  #   $BUILD_DIR/XRSimulator/arm64/install/lib/libharfbuzz.a \
  #   $BUILD_DIR/XRSimulator/x86_64/install/lib/libharfbuzz.a
  # exit_if_error

  # Create the framework with multiple platforms
  xcodebuild -create-xcframework \
    -library $BUILD_DIR/MacOSX/libharfbuzz.a                      -headers $BUILD_DIR/MacOSX/arm64/install/include/harfbuzz \
    -library $BUILD_DIR/iPhoneOS/arm64/install/lib/libharfbuzz.a  -headers $BUILD_DIR/iPhoneOS/arm64/install/include/harfbuzz \
    -library $BUILD_DIR/iPhoneSimulator/libharfbuzz.a             -headers $BUILD_DIR/iPhoneSimulator/arm64/install/include/harfbuzz \
    -output $FRAMEWORK_OUTPUT_DIR/HarfBuzz.xcframework
    # -library $BUILD_DIR/AppleTVOS/arm64/install/lib/libharfbuzz.a -headers $BUILD_DIR/AppleTVOS/arm64/install/include/harfbuzz \
    # -library $BUILD_DIR/AppleTVSimulator/libharfbuzz.a            -headers $BUILD_DIR/AppleTVSimulator/arm64/install/include/harfbuzz \
    # -library $BUILD_DIR/WatchOS/arm64/install/lib/libharfbuzz.a   -headers $BUILD_DIR/WatchOS/arm64/install/include/harfbuzz \
    # -library $BUILD_DIR/WatchSimulator/libharfbuzz.a              -headers $BUILD_DIR/WatchSimulator/arm64/install/include/harfbuzz \
    # -library $BUILD_DIR/XROS/arm64/install/lib/libharfbuzz.a      -headers $BUILD_DIR/XROS/arm64/install/include/harfbuzz \
    # -library $BUILD_DIR/XRSimulator/libharfbuzz.a                 -headers $BUILD_DIR/XRSimulator/arm64/install/include/harfbuzz \
  exit_if_error

  # And sign the framework
  # codesign --timestamp -s $identity $FRAMEWORK_OUTPUT_DIR/HarfBuzz.xcframework
  # exit_if_error
}
create_framework
