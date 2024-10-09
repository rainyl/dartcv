#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint DartCvIOS.podspec` to validate before publishing.
#

pod_dir = File.dirname(__FILE__, 1)

Pod::Spec.new do |s|
  s.name             = 'DartCvIOS'
  s.version          = '4.10.0+9'
  s.summary          = 'dartcv for ios'
  s.description      = <<-DESC
  OpenCV bindings for Dart.
                       DESC
  s.homepage         = 'https://github.com/rainyl/dartcv'
  s.license          = { :type => 'Apache License v2.0', :file => 'LICENSE' }
  s.author           = { 'Rainyl' => 'rainyliusy3@gmail.com' }

  # This will ensure the source files in Classes/ are included in the native
  # builds of apps using this FFI plugin. Podspec does not support relative
  # paths, so Classes contains a forwarder C file that relatively imports
  # `../src/*` so that the C sources can be shared among all target platforms.
  s.source = { :path => '.' }
  s.preserve_paths = 'dartcv/**', 'libopencv/**'
  # s.source_files = 'dartcv/**/*.h'
  s.libraries = 'c++'
  s.requires_arc = false

  s.ios.deployment_target = '12.0'
  s.vendored_libraries = 'libopencv/libopencv.a'
  s.frameworks = [
    'Accelerate', 'AssetsLibrary', 'AVFoundation',
    'CoreGraphics', 'CoreImage', 'CoreMedia',
    'CoreVideo', 'Foundation', 'QuartzCore',
    'UIKit'
  ]

  s.pod_target_xcconfig = {
    'DEFINES_MODULE' => 'YES',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'HEADER_SEARCH_PATHS' => '"$(inherited)" "${PODS_TARGET_SRCROOT}/libopencv/include/opencv4"',
    'USER_HEADER_SEARCH_PATHS' => '"$(PODS_TARGET_SRCROOT)"'\
        ' "$(PODS_TARGET_SRCROOT)/dartcv"',
    'GCC_PREPROCESSOR_DEFINITIONS' => '"$(inherited)" "COCOAPODS=1"',
    'CLANG_WARN_STRICT_PROTOTYPES' => 'NO',
    'CLANG_WARN_DOCUMENTATION_COMMENTS' => 'NO',
    'CLANG_CXX_LANGUAGE_STANDARD' => 'c++14',
    # https://wadetregaskis.com/no-platform-load-command-found-in-libxyz-a-assuming-macos/
    'OTHER_LDFLAGS' => '-Wl,-ld_classic'
  }
  s.swift_version = '5.0'

  s.prepare_command = <<-CMD
    if [ ! -f #{pod_dir}/libopencv/libopencv.a ]; then
      if [ ! -f #{pod_dir}/libopencv.zip ]; then
        echo "libopencv.a and libopencv.zip not found, downloading...";
        curl -L "https://github.com/rainyl/opencv.full/releases/download/#{s.version.to_s}/libopencv-ios.zip" > libopencv.zip;
      else
        echo "found libopencv.zip";
      fi
      echo "extracting...";
      unzip -q -o libopencv.zip;
      echo "cleaning...";
      rm -f libopencv.zip;
    else
      echo "found libopencv.a, continue...";
    fi
  CMD

  s.default_subspec = [
    "core", "calib3d", "contrib", "features2d", "imgproc",
    "objdetect", "photo", "stitching", "video"
  ]

  s.subspec 'core' do |ss|
    # cocoapods doesn't support keep folder structures, so do not include *.h here
    # https://github.com/CocoaPods/CocoaPods/issues/8873
    ss.source_files = 'dartcv/{core,imgcodecs}/*.{c,cpp}'
    ss.public_header_files = ''
    ss.vendored_libraries = 'libopencv/libopencv.a'
  end

  s.subspec 'calib3d' do |ss|
    ss.source_files = "dartcv/calib3d/*.{c,cpp}"
    ss.public_header_files = ""
    ss.dependency "DartCvIOS/core"
  end

  s.subspec 'contrib' do |ss|
    ss.source_files = 'dartcv/contrib/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end

  s.subspec 'dnn' do |ss|
    ss.source_files = 'dartcv/dnn/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end

  s.subspec 'features2d' do |ss|
    ss.source_files = 'dartcv/features2d/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end

  # s.subspec 'gapi' do |ss|
  #   ss.source_files = 'dartcv/gapi/*.{c,cpp}'
  #   ss.dependency "DartCvIOS/core"
  # end

  s.subspec 'imgproc' do |ss|
    ss.source_files = 'dartcv/imgproc/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end

  s.subspec 'objdetect' do |ss|
    ss.source_files = 'dartcv/objdetect/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end

  s.subspec 'photo' do |ss|
    ss.source_files = 'dartcv/photo/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end

  s.subspec 'stitching' do |ss|
    ss.source_files = 'dartcv/stitching/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end

  s.subspec 'video' do |ss|
    ss.source_files = 'dartcv/video/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end

  s.subspec 'videoio' do |ss|
    ss.source_files = 'dartcv/videoio/*.{c,cpp}'
    ss.dependency "DartCvIOS/core"
  end
end
