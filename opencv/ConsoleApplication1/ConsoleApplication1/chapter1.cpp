#include"test.h"

void function1_6_1()
{
    VideoCapture capture;
    //capture.open("H:\\TDDOWNLOAD\\Ӱ��\\OnePlus_3Tý������_һ��3T������.mp4");
    capture.open(0);
    while (1)
    {
        Mat frame;
        capture >> frame;
        imshow("����",frame);
        waitKey(41);
    }
}