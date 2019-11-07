//为了把图片变白，张家馨编写了这个文档

//用到了以下三个函数库：
//	opencv_core 
//	opencv_imgcodecs 
//	opencv_highgui

//当前的问题是：图片B变成白板了
#include <stdio.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
using namespace std;

//全局变量
cv::Mat A,B;

bool PicLoad()
{
	//载入图片
	printf("程序开始。\n");
	A = cv::imread("./A.png", cv::IMREAD_COLOR);
	B = cv::imread("./B.png", cv::IMREAD_COLOR);
	printf("    已经打开图片A和图片B。\n");
	return 0;
}

bool PicHand()
{
	//操作图片 A
	for(int i=0; i<A.rows; i++)
	{
		for(int j=0; j<A.cols; j++)
		{
			//把灰色变成洁白色
			if(A.at<cv::Vec3b>(i,j)[0] > 240 && A.at<cv::Vec3b>(i,j)[1] > 240 && A.at<cv::Vec3b>(i,j)[2] > 240)
			{
				A.at<cv::Vec3b>(i,j)[0] = 255;
				A.at<cv::Vec3b>(i,j)[1] = 255;
				A.at<cv::Vec3b>(i,j)[2] = 255;
			}
			//把灰色变成纯黑色
			if(A.at<cv::Vec3b>(i,j)[0] < 25 && A.at<cv::Vec3b>(i,j)[1] < 25 && A.at<cv::Vec3b>(i,j)[2] < 25)
			{
				A.at<cv::Vec3b>(i,j)[0] = 0;
				A.at<cv::Vec3b>(i,j)[1] = 0;
				A.at<cv::Vec3b>(i,j)[2] = 0;
			}
		}
	}
	//调试信息
	printf("    图片A操作完成。\n");
		
	

	//操作图片 B
	for(int i=0; i<B.rows; i++)
	{
		for(int j=0; j<B.rows; j++)
		{
			//把红色变成最红
			if(/*B.at<cv::Vec3b>(i,j)[0] > 220 && B.at<cv::Vec3b>(i,j)[1] > 220 &&*/ B.at<cv::Vec3b>(i,j)[2] >= 1)
			{
				B.at<cv::Vec3b>(i,j)[0] = 0;
				B.at<cv::Vec3b>(i,j)[1] = 0;
				B.at<cv::Vec3b>(i,j)[2] = 255;
			}
			//把非红色变成白色
			//if(/*B.at<cv::Vec3b>(i,j)[0] < 25 && B.at<cv::Vec3b>(i,j)[1] < 25 &&*/ B.at<cv::Vec3b>(i,j)[2] < 25)
			else
			{
				B.at<cv::Vec3b>(i,j)[0] = 255;
				B.at<cv::Vec3b>(i,j)[1] = 255;
				B.at<cv::Vec3b>(i,j)[2] = 255;
			}
		}
	}
	//调试信息
	printf("    图片B操作完成。\n");
	

	printf("处理完成。\n");
	return 0;
}

bool PicSave()
{
	//保存图片
	cv::imshow("A", A);
	cv::imshow("B", B);
        cv::waitKey(30);
	printf("    对处理结果满意吗？按'y'保存，按'n'退出。\n");
	char answer;
	scanf("%c", &answer);
	if(answer == 'y')
	{
		cv::imwrite(".A.png",A);
		cv::imwrite(".B.png",B);
	}
	else if(answer == 'n')
		return 0;
	else
		printf("    输入错误！按'y'保存，按'n'退出。");
	printf("保存完成。");
	return 0;
}

int main()
{
	//打开图片
	PicLoad();
	//处理图片
	PicHand();
	//保存图片
	PicSave();
	
	return 0;
}
