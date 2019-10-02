//
// Created by ming on 2019/10/2.
//

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
    Mat src, dst;
    src = imread("/home/ming/git/opencv_learning/test.jpg");
    if (!src.data) {
        printf("could not load image...\n");
        return -1;
    }
    namedWindow("input image");
    imshow("input image", src);
    // todo: 新图像二值化
    dst = Mat(src.size(),src.type());
    threshold(src,dst,127,255,THRESH_BINARY);
    namedWindow("output image");
    imshow("output image", dst);





    waitKey(0);

    return 0;
}