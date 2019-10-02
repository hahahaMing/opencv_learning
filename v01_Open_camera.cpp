#include<opencv2/opencv.hpp>
#include<iostream>
#include "qsort.hpp"
 
using namespace std;
using namespace cv;
 
int main(int argc,char **argv)
{
	VideoCapture capture(0);
	namedWindow("hhh");
	while(true)
	{
		Mat frame;
		capture>>frame;
		imshow("hhh",frame);
		waitKey(30);
	}

}
