#include"test.h"

void function1_6_1()
{
    VideoCapture capture;
    //capture.open("H:\\TDDOWNLOAD\\影视\\OnePlus_3T媒体见面会_一加3T发布会.mp4");
    capture.open(0);
    while (1)
    {
        Mat frame;
        capture >> frame;
        imshow("窗口",frame);
        waitKey(41);
    }
}