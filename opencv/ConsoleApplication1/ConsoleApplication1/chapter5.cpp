#include "chapter5.h"

void function5_1_3()
{
	double time0 = static_cast<double>(getTickCount());
	int i = 0;
	Mat img1 = imread("c://1.png");
	Mat img2;
	Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.data;
	for (i = 0; i < 256;++i)
	{
		p[i] = i / 10 * 10;
		//printf("%d\n", p[i]);
	}
	printf("%d\n", img1.channels());
	//for (i = 0; i < img1.depth(); i++)
	{
		LUT(img1, lookUpTable, img2);
	}
	imshow("", img2);

	//waitKey();
	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << time0 << endl;
	system("pause");
}

bool ROI_AddImage()
{
	Mat srcImage1 = imread("C://img27.jpg");
	Mat logoImage = imread("c://2.png");
	Mat imgeROI = srcImage1(Rect(200, 250, logoImage.cols, logoImage.rows));
	Mat mask = imread("c://2.png", IMREAD_GRAYSCALE);
	logoImage.copyTo(imgeROI,mask);  //掩码只复制非0项
	namedWindow("test");
	imshow("test", srcImage1);
	return true;
}

void function5_2_1()
{
	ROI_AddImage();
}

void function5_3()
{
	Mat srcImage = imread("c://img27.jpg");
	Mat logoImage = imread("c://1.png");
	vector<Mat> channels;
	split(logoImage, channels);
	Mat srcBlue(logoImage.rows,logoImage.cols,CV_8UC3,Scalar(0,0,0)), srcGreen(logoImage.rows, logoImage.cols, CV_8UC3, Scalar(0, 0, 0)), srcRed(logoImage.rows, logoImage.cols, CV_8UC3, Scalar(0, 0, 0));
	//imshow("Blue", channels.at(0));
	//imshow("Green", channels.at(1));
	//imshow("Red", channels.at(2));
	for (int i = 0; i < logoImage.rows;i++)
	{
		for (int j = 0; j < logoImage.cols; j++)
		{
			//printf("<%d,%d>:%d\n", i, j, channels.at(0).at<uchar>(i, j));
			srcBlue.at<Vec3b>(i, j)[0] = channels.at(0).at<uchar>(i,j);
			srcGreen.at<Vec3b>(i, j)[1] = channels.at(1).at<uchar>(i, j);
			srcRed.at<Vec3b>(i, j)[2] = channels.at(2).at<uchar>(i, j);
		}
	}
	imshow("BB", srcBlue);
	imshow("GG", srcGreen);
	imshow("RR", srcRed);
	waitKey(0);
}

//=========================function5_4=======================================

int g_MaxValue = 255;
int g_nContrastValue = 150;
int g_nBrightValue = 150;
Mat g_Img;
Mat g_LookUpTable(1, 256, CV_8U);
#define WINDOW_NAME "调节亮度/对比度"
 
void on_TrackBar(int,void*)
{
	Mat tmp_Img = g_Img.clone();
	uchar* p = g_LookUpTable.data;
	for (int i = 0; i < 256;i++)
	{
		p[i] = saturate_cast<uchar>(i * g_nContrastValue*0.01 + g_nBrightValue);
	}
	LUT(g_Img, g_LookUpTable, tmp_Img);
	imshow(WINDOW_NAME, tmp_Img);
}

void function5_4()
{
	g_Img = imread("c://2.png");
	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	char contrastTrackBar[50],brightTrackBar[50];
	sprintf(contrastTrackBar, "valueC");
	sprintf(brightTrackBar, "valueB");
	createTrackbar(contrastTrackBar, WINDOW_NAME, &g_nContrastValue, g_MaxValue, on_TrackBar);
	createTrackbar(brightTrackBar, WINDOW_NAME, &g_nBrightValue, g_MaxValue, on_TrackBar);
	on_TrackBar(0, 0);
	waitKey(0);

}

//=========================================================================