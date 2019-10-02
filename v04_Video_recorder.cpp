#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
    VideoCapture capture(0);
    VideoWriter writer("/home/ming/git/opencv_learning/VideoTest.avi", ('M', 'J', 'P', 'G'), 25.0, Size(640, 480));
    Mat frame;

    while (capture.isOpened())
    {
        capture >> frame;
        writer << frame;
        imshow("video", frame);
        if (waitKey(20) == 27)
        {
            break;
        }
    }
}