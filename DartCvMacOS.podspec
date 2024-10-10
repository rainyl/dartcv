#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint DartCvMacOS.podspec` to validate before publishing.
#

Pod::Spec.new do |s|
  s.name             = 'DartCvMacOS'
  s.version          = '4.10.0+9'
  s.summary          = 'dartcv for macos'
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
  # s.source = { :path => '.' }
  s.source = { :git => 'https://github.com/rainyl/dartcv.git', :tag => "main" }
  s.preserve_paths = 'dartcv/**', 'libopencv/{include,lib,share}'
  # s.source_files = 'include/*.h'
  s.libraries = 'c++'
  s.requires_arc = false

  s.osx.deployment_target = '10.15'
  s.vendored_libraries = 'libopencv/libopencv.a'
  s.frameworks = [
    'Accelerate', 'AVFoundation', 'CoreGraphics',
    'CoreImage', 'CoreMedia', 'CoreVideo',
    'Foundation', 'QuartzCore', 'OpenCL'
  ]

  s.pod_target_xcconfig = {
    'DEFINES_MODULE' => 'YES',
    'HEADER_SEARCH_PATHS' => '"$(inherited)" "${PODS_TARGET_SRCROOT}/libopencv/include/opencv4"',
    'USER_HEADER_SEARCH_PATHS' => '"$(PODS_TARGET_SRCROOT)" "$(PODS_TARGET_SRCROOT)/dartcv"',
    'CLANG_WARN_STRICT_PROTOTYPES' => 'NO',
    'CLANG_WARN_DOCUMENTATION_COMMENTS' => 'NO',
    'CLANG_CXX_LANGUAGE_STANDARD' => 'c++14',
    # https://wadetregaskis.com/no-platform-load-command-found-in-libxyz-a-assuming-macos/
    'OTHER_LDFLAGS' => '-Wl,-ld_classic'
  }
  s.swift_version = '5.0'

  s.prepare_command = <<-CMD
    if [ ! -f libopencv/libopencv.a ]; then
      if [ ! -f libopencv.zip ]; then
        echo "libopencv.a and libopencv.zip not found, downloading...";
        curl -L "https://github.com/rainyl/opencv.full/releases/download/#{s.version.to_s}/libopencv-macos.zip" > libopencv.zip;
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
    "core",
    "calib3d", "contrib", "features2d", "imgproc",
    "objdetect", "photo", "stitching", "video"
  ]

  s.subspec 'core' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/{core,imgcodecs}/*.{h,c,cpp}'
    ss.vendored_libraries = 'libopencv/libopencv.a'
  end

  s.subspec 'calib3d' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = "dartcv/calib3d/*.{h,c,cpp}"
    ss.dependency "DartCvMacOS/core"
  end

  s.subspec 'contrib' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/contrib/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
  end

  s.subspec 'dnn' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/dnn/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
  end

  s.subspec 'features2d' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/features2d/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
  end

  # s.subspec 'gapi' do |ss|
  #   ss.header_mappings_dir = '.'
  #   ss.source_files = 'dartcv/gapi/*.{h,c,cpp}'
  #   ss.dependency "DartCvMacOS/core"
  # end

  s.subspec 'highgui' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/highgui/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
    ss.vendored_libraries = "libopencv/ffmpeg/lib/libffmpeg.dylib"
  end

  s.subspec 'imgproc' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/imgproc/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
  end

  s.subspec 'objdetect' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/objdetect/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
  end

  s.subspec 'photo' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/photo/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
  end

  s.subspec 'stitching' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/stitching/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
  end

  s.subspec 'video' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/video/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
  end

  s.subspec 'videoio' do |ss|
    ss.header_mappings_dir = '.'
    ss.source_files = 'dartcv/videoio/*.{h,c,cpp}'
    ss.dependency "DartCvMacOS/core"
    ss.vendored_libraries = "libopencv/ffmpeg/lib/libffmpeg.dylib"
  end
end
