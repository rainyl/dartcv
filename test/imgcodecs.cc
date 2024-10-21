#include "dartcv/imgcodecs/imgcodecs.h"
#include "dartcv/core/core.h"
#include <gtest/gtest.h>

// #include <opencv/opencv.hpp>
#include <stdint.h>

TEST(ImgCodecs, Read)
{
  Mat       im;
  CvStatus *status = Image_IMRead("test/images/circles.jpg", 0, &im);
  ASSERT_EQ(status->code, 0);
  ASSERT_EQ(im.ptr->empty(), false);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
