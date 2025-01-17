#include <core/mat.h>
#include <dartcv/highgui/highgui.h>
#include <opencv2/core/hal/interface.h>

int main(int argc, const char** argv) {
    cv_namedWindow("AAA", 0);
    Mat m;
    CvStatus* status = cv_Mat_ones(300, 300, CV_8UC3, &m, NULL);
    cv_imshow("AAA", m);
    cv_waitKey(2000);
    cv_destroyAllWindows();
    return 0;
}