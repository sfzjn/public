#include "test.h"
#include "chapter1.h"
#include "chapter3.h"
#include "chapter4.h"
#include "chapter5.h"
#include "chapter6.h"

int main()
{
	printf("Version:%s\n",CV_VERSION);
	/*Mat img = imread("c://1.jpg",0);
	namedWindow("ÐéÄâ»ú",WINDOW_AUTOSIZE);
	imshow("ÐéÄâ»ú", img);
	imwrite("2.jpg", img);*/
	//function3_1_8();
	//function3_1_9();
	//function3_2_1();
	//function3_3();
	function1_6_1();
	waitKey(0);
    system("pause");
}
