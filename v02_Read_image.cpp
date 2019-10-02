//
// Created by ming on 2019/10/2.
//

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
    Mat image = imread("/home/ming/git/opencv_learning/1.png");
    namedWindow("My Test");
    imshow("My Test", image);
    waitKey(0);
    destroyWindow("My Test");
    return 0;
}