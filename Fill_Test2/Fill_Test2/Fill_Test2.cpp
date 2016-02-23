// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// TestFillPoly.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#define nMatWidth 400
#define nMatHeight 400

int main(int argc, char* argv[])
{
	//假设需要用到的数据
	CvPoint *szPoint1 = new CvPoint[5];

	szPoint1[0] = { 78, 65 };

	szPoint1[1] = { 45, 164 };

	szPoint1[2] = { 102, 234 };

	szPoint1[3] = { 368, 173 };

	szPoint1[4] = { 126, 32 };

	

	CvPoint szPoint2[6] = { { 89, 323 }, { 0, 134 }, { 171, 262 }, { 126, 32 }, { 85, 85 }, { 75, 69 } };
	CvPoint szPoint3[7] = { { 78, 65 }, { 102, 234 }, { 368, 173 }, { 126, 32 }, { 12, 56 }, { 320, 172 }, { 95, 32 } };

	CvPoint *pSzArray[] = { szPoint1};
	int nArrayNumber[] = { 5 };

	//创建矩阵
	CvMat *Mat = cvCreateMat(nMatWidth, nMatHeight, CV_8UC3);
	assert(Mat != NULL);

	//绘制多边形
	cvFillPoly(Mat, pSzArray, nArrayNumber, 1, CV_RGB(255, 0, 0));

	CvFont font;
	char buf_T[256];
	cvInitFont(&font, CV_FONT_VECTOR0, 0.65, 0.65, 0, 2, 2);
	for (int i = 0; i < 5; i++)
	{
		sprintf_s(buf_T, 256, "%d", i + 1);
		cvPutText(Mat, buf_T, szPoint1[i], &font, CV_RGB(255, 0, 255));
		cvCircle(Mat,szPoint1[i],4,CV_RGB(0,255,0),-1);
	}

	delete[] szPoint1;
	
	//显示图像
	cvNamedWindow("Show_Result");
	cvShowImage("Show_Result", Mat);

	cvWaitKey();

	//释放资源
	cvReleaseMat(&Mat);
	cvDestroyWindow("Show_Resulst");

	return 0;
}// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
