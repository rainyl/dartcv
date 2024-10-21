#include "dartcv/imgproc/imgproc.h"
#include "dartcv/core/core.h"
#include "dartcv/imgcodecs/imgcodecs.h"
#include <gtest/gtest.h>

#include <stdint.h>
#include <vector>

TEST(ImgProc, cornerSubPix)
{
  Mat       img;
  CvStatus *status = Image_IMRead("test/images/circles.jpg", cv::ImreadModes::IMREAD_GRAYSCALE, &img);
  ASSERT_EQ(status->code, 0);
  ASSERT_EQ(img.ptr->empty(), false);
  Mat          mask = {new cv::Mat()};
  VecPoint2f   corners = {vecpoint2f_cpp2c()};
  TermCriteria criteria = {cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 30, 0.1};
  status = GoodFeaturesToTrack(img, &corners, 10, 0.01, 10, mask, 3, false, 0.04);
  ASSERT_EQ(status->code, 0);
  status = CornerSubPix(img, corners, {10, 10}, {-1, -1}, criteria);
  ASSERT_EQ(status->code, 0);
  status = CornerSubPix(img, corners, {10, 10}, {-1, -1}, criteria);
  ASSERT_EQ(status->code, 0);
  std::cout << *corners.ptr << std::endl;
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
