#include "dartcv/calib3d/calib3d.h"
#include "dartcv/core/core.h"
#include "dartcv/core/mat.h"
#include "dartcv/imgcodecs/imgcodecs.h"
#include <gtest/gtest.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/calib3d.hpp>
#include <stdint.h>

TEST(calib3d, findChessboardCornersSB) {
    Mat img;
    CvStatus* s = cv_imread("images/chessboard_4x6.png", 0, &img, NULL);
    EXPECT_EQ(s->code, 0);
    EXPECT_EQ(img.ptr->empty(), false);
    VecPoint2f corners;
    bool rval;
    s = cv_findChessboardCornersSB(img, {4, 6}, &corners, 0, &rval, NULL);
    EXPECT_EQ(s->code, 0);
    EXPECT_EQ(rval, true);
}

TEST(calib3d, findChessboardCornersSBCPP) {
    cv::Mat img = cv::imread("images/chessboard_4x6.png", 0);
    std::vector<cv::Point2f> corners;
    auto rval = cv::findChessboardCornersSB(img, cv::Size(4, 6), corners, 0);
    EXPECT_EQ(rval, true);
    std::cout << corners << std::endl;
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
