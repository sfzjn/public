#include "chapter6.h"

//int g_nMeanValue = 3, g_nGaussianValue=5;
Mat g_img;


void on_Blur(int value, void *)
{
	Mat img1;
	if (value>0)
	{
		blur(g_img, img1, Size(value, value));
		imshow("均值滤波", img1);
	}
}

void on_GaussianBlur(int value, void*)
{
	Mat img1;

	GaussianBlur(g_img, img1, Size(value*2+1, value*2+1), 0, 0);
	imshow("高斯滤波", img1);
	

}

void function6_1_11()
{
	//system("color5E");

	Mat img = imread("c://baboon.jpg");
	imshow("原图", img);
	g_img = img.clone();
	Mat outBox,outBlur,outGaussian;
	int meanValue = 3, gaussianValue = 3;
	boxFilter(img, outBox, -1, Size(5, 5),Point(-1,-1),false);
	imshow("方框滤波", outBox);

	namedWindow("均值滤波");
	createTrackbar("内核值", "均值滤波", &meanValue, 40, on_Blur);
	on_Blur(meanValue, 0);
	
	namedWindow("高斯滤波");
	createTrackbar("内核值", "高斯滤波", &gaussianValue, 40, on_GaussianBlur);
	on_GaussianBlur(gaussianValue, 0);
}

void function6_2_5()
{

}