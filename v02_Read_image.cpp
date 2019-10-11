//
// Created by ming on 2019/10/2.
//

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
//    Mat image = imread("/home/ming/git/opencv_learning/test.jpg");
    Mat image = imread("/home/ming/git/opencv_learning/data/Camera Roll/WIN_20190710_21_25_29_Pro.jpg");
    namedWindow("My Test");
    imshow("My Test", image);
    //腐蚀
    Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
    Mat dst1;
    erode(image,dst1,element);
    imshow("腐蚀后",dst1);
    //均值滤波
    Mat dst2;
    blur(image,dst2,Size(7,7));
    imshow("均值滤波后",dst2);
    //canny边缘检测
    Mat dst3,gray_image,edge;
    dst3.create(image.size(),image.type());
    cvtColor(image,gray_image,COLOR_BGR2GRAY);//转为灰度图
    blur(gray_image,edge,Size(3,3));//用3*3的内核降噪
    Canny(edge,edge,3,9,3);
    imshow("canny",edge);



    waitKey(0);
    destroyWindow("My Test");
    return 0;
}