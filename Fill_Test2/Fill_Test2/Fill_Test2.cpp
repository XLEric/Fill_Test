// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//������Ҫ�õ�������
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

	//��������
	CvMat *Mat = cvCreateMat(nMatWidth, nMatHeight, CV_8UC3);
	assert(Mat != NULL);

	//���ƶ����
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
	
	//��ʾͼ��
	cvNamedWindow("Show_Result");
	cvShowImage("Show_Result", Mat);

	cvWaitKey();

	//�ͷ���Դ
	cvReleaseMat(&Mat);
	cvDestroyWindow("Show_Resulst");

	return 0;
}// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//
