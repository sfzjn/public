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

//===========================================================
void on_MedianBlur(int value, void*)
{
    if (value > 0)
    {
        Mat img;
        medianBlur(g_img, img, value*2+1);
        imshow("中值滤波", img);
    }
}

void on_BilateralBlur(int value, void*)
{
    if (value > 0)
    {
        Mat img;
        bilateralFilter(g_img, img, value, value * 2, value / 2);
        imshow("双边滤波", img);
    }
}

void function6_2_4()
{
    int medianValue = 3, bilateralValue=3;
    Mat img = imread("c:\\baboon.jpg");
    g_img = img.clone();
    imshow("原图", img);

    namedWindow("中值滤波", WINDOW_AUTOSIZE);
    createTrackbar("参数", "中值滤波", &medianValue, 20, on_MedianBlur);
    on_MedianBlur(medianValue, 0);

    /*namedWindow("双边滤波");
    createTrackbar("参数", "双边滤波", &bilateralValue, 20, on_BilateralBlur);
    on_BilateralBlur(bilateralValue, 0);*/
    
}