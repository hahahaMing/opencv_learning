#include<opencv2/opencv.hpp>
#include<iostream>
#include "qsort.hpp"
 
using namespace std;
using namespace cv;
 
int main(int argc,char **argv)
{

//	VideoCapture capture(0);//读入摄像头
    VideoCapture capture("/home/ming/Documents/jy01.mp4");//读入视频
    if(!capture.isOpened())
    {
        cout<<"Camera does not work correctly!\n"<<endl;
    }
    else
    {
        while(true)
        {
            Mat frame;
            capture>>frame;
            imshow("hhh",frame);
            //canny边缘检测
//            Mat dst3,gray_image,edge;
//            dst3.create(frame.size(),frame.type());
//            cvtColor(frame,gray_image,COLOR_BGR2GRAY);//转为灰度图
//            blur(gray_image,edge,Size(3,3));//用3*3的内核降噪
//            Canny(edge,edge,3,9,3);
//            imshow("canny",edge);
            //二值化
            Mat dst = Mat(frame.size(),frame.type());
            Mat gray = Mat(frame.size(),frame.type());
            cvtColor(frame,gray,COLOR_BGR2GRAY);//转为灰度图
            threshold(gray,dst,127,255,THRESH_BINARY);
            namedWindow("output image");
            imshow("output image", dst);
            waitKey(30);
        }
    }
}
