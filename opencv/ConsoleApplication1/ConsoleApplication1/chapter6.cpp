#include "chapter6.h"

//int g_nMeanValue = 3, g_nGaussianValue=5;
Mat g_img;


void on_Blur(int value, void *)
{
	Mat img1;
	if (value>0)
	{
		blur(g_img, img1, Size(value, value));
		imshow("��ֵ�˲�", img1);
	}
}

void on_GaussianBlur(int value, void*)
{
	Mat img1;

	GaussianBlur(g_img, img1, Size(value*2+1, value*2+1), 0, 0);
	imshow("��˹�˲�", img1);
	

}

void function6_1_11()
{
	//system("color5E");

	Mat img = imread("c://baboon.jpg");
	imshow("ԭͼ", img);
	g_img = img.clone();
	Mat outBox,outBlur,outGaussian;
	int meanValue = 3, gaussianValue = 3;
	boxFilter(img, outBox, -1, Size(5, 5),Point(-1,-1),false);
	imshow("�����˲�", outBox);

	namedWindow("��ֵ�˲�");
	createTrackbar("�ں�ֵ", "��ֵ�˲�", &meanValue, 40, on_Blur);
	on_Blur(meanValue, 0);
	
	namedWindow("��˹�˲�");
	createTrackbar("�ں�ֵ", "��˹�˲�", &gaussianValue, 40, on_GaussianBlur);
	on_GaussianBlur(gaussianValue, 0);
}

//===========================================================
void on_MedianBlur(int value, void*)
{
    if (value > 0)
    {
        Mat img;
        medianBlur(g_img, img, value*2+1);
        imshow("��ֵ�˲�", img);
    }
}

void on_BilateralBlur(int value, void*)
{
    if (value > 0)
    {
        Mat img;
        bilateralFilter(g_img, img, value, value * 2, value / 2);
        imshow("˫���˲�", img);
    }
}

void function6_2_4()
{
    int medianValue = 3, bilateralValue=3;
    Mat img = imread("c:\\baboon.jpg");
    g_img = img.clone();
    imshow("ԭͼ", img);

    namedWindow("��ֵ�˲�", WINDOW_AUTOSIZE);
    createTrackbar("����", "��ֵ�˲�", &medianValue, 20, on_MedianBlur);
    on_MedianBlur(medianValue, 0);

    /*namedWindow("˫���˲�");
    createTrackbar("����", "˫���˲�", &bilateralValue, 20, on_BilateralBlur);
    on_BilateralBlur(bilateralValue, 0);*/
    
}