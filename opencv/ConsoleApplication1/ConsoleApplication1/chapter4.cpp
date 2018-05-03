#include "test.h"


void test()
{
	int sz[3] = { 2,2,2 };
	Point point;
	point.x= 10;
	point.y= 8;
	Size s(5, 5);
	Rect rect(1, 2, 3, 4);
	Rect rect1 = rect + point,rect2=rect+s;
	Mat img1 = imread("c://1.png");
	Mat dstImg1,dstImg2;
	cvtColor(img1, dstImg1, COLOR_BGR2GRAY);
	cvtColor(dstImg1, dstImg2, COLOR_GRAY2BGR);
	imshow("img1", img1);
	imshow("dstImg1", dstImg1);
	imshow("dstImg2", dstImg2);
	/*Mat img(200,200, CV_8UC3,Scalar(126,34,54));
	namedWindow("test", WINDOW_AUTOSIZE);
	imshow("test", img);
	waitKey(0);
	img.create(300, 200, CV_8UC3);
	imshow("test", img);*/
	waitKey();
}