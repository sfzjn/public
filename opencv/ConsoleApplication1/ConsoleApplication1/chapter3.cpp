#include "test.h"

void createAlphaMat(Mat &mat)
{
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j = 0; j < mat.cols; ++j)
		{
			Vec4b &rgba = mat.at<Vec4b>(i, j);
			rgba[0] = UCHAR_MAX;
			float a = (float(mat.cols - j)) / ((float)mat.cols)*UCHAR_MAX;
			rgba[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols)*UCHAR_MAX);
			rgba[2] = saturate_cast<uchar>((float(mat.rows - i)) / ((float)mat.rows)*UCHAR_MAX);
			rgba[3] = saturate_cast<uchar>(0.5*(rgba[1] + rgba[2]));
		}
	}
}

void function3_1_8()
{
	Mat mat(480, 640, CV_8UC4);
	createAlphaMat(mat);
	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	try {
		imwrite("透明Alpha.png", mat, compression_params);
		imshow("test", mat);
		fprintf(stdout, "save over.\n");
		waitKey(0);
	}
	catch (runtime_error& ex) {
		fprintf(stderr, "error:%s\n", ex.what());
	}
}

void function3_1_9()
{
	Mat img = imread("c://img27.jpg");
	Mat logo = imread("c://facedetect.jpg");
	//imshow("img", img);
	//imshow("logo", logo);
	Mat imageROI = img(Rect(0, 0, logo.cols, logo.rows));	//imageROI指向img
	imshow("imageROI1", imageROI);
	addWeighted(imageROI, 0.5, logo, 0.3, 0, imageROI);
	imshow("image", img);
	waitKey(0);
}

//----------function3_2_1------------
#define WINDOW_NAME "[线性混合示例]"

const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;

double g_dBetaValue;

Mat g_srcImage1, g_srcImage2, g_dstImage;

void on_Trackbar(int, void*)
{
	double g_dAlphaValue;
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	g_dBetaValue = (1.0 - g_dAlphaValue);
	try
	{
		addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);
	}
	catch (runtime_error& ex) {
		fprintf(stderr, "error:%s\n", ex.what());
	}
	printf("TrackPos:%d\n", getTrackbarPos("value:100", WINDOW_NAME));

	imshow(WINDOW_NAME, g_dstImage);
}

void function3_2_1()
{
	g_srcImage1 = imread("C://opencv//sources//samples//data//WindowsLogo.jpg");
	g_srcImage2 = imread("C://opencv//sources//samples//data//LinuxLogo.jpg");
	g_nAlphaValueSlider = 70;

	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);

	char TrackbarName[50];
	sprintf(TrackbarName, "value:%d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
	on_Trackbar(g_nAlphaValueSlider, 0);
	waitKey(0);
}

//---------------------------------

//---------function3_3-------------
Rect g_rectangle;
bool g_bDrawingBox = false;
RNG g_rng(12345);	//random

void DrawRectangle(Mat& img, Rect& box)
{
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));
}

void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(cv::Mat*)param;
	switch (event)
	{
	case EVENT_MOUSEMOVE:
	{
		if (g_bDrawingBox)
		{
			g_rectangle.width = x - g_rectangle.x;
			g_rectangle.height = y - g_rectangle.y;
			printf("x:%d,y:%d,rect.x:%d,rect.y:%d,width:%d,height:%d\n",
				x, y, g_rectangle.x, g_rectangle.y, g_rectangle.width, g_rectangle.height);
		}
	}
	break;
	case EVENT_LBUTTONDOWN:
	{
		g_bDrawingBox = true;
		g_rectangle = Rect(x, y, 0, 0);
	}
	break;
	case EVENT_LBUTTONUP:
	{
		g_bDrawingBox = false;
		if (g_rectangle.width < 0)
		{
			g_rectangle.x += g_rectangle.width;
			g_rectangle.width *= -1;
		}
		if (g_rectangle.height < 0)
		{
			g_rectangle.y += g_rectangle.height;
			g_rectangle.height *= -1;
		}
		DrawRectangle(image, g_rectangle);
	}
	break;
	}
}

void function3_3()
{
	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	Mat test = srcImage;
	srcImage.copyTo(tempImage);
	srcImage = Scalar::all(0);
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);

	while (1)
	{
		srcImage.copyTo(tempImage);
		if (g_bDrawingBox)
		{
			DrawRectangle(tempImage, g_rectangle);
		}
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10) == 27)
			break;
	}
}

//---------------------------------