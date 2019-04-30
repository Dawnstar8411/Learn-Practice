#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

#define WINDOW_NAME "线性混合示例"
//全局变量声明

const int g_nMaxAlphaValue = 100; //Alpha值的最大值
int g_nAlphaValueSlider; //滑动条对应的变量
double g_dAlphaValue;
double g_dBetaValue;

//声明存储图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

void on_Trackbar(int, void*)
{
	//求出当前alpha值相对于最大值的比例
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	g_dBetaValue = (1.0 - g_dAlphaValue);

	//根据alpha和beta值进行线性混合
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);
	imshow(WINDOW_NAME, g_dstImage);
}


int main(int argc, char** argv)
{
	g_srcImage1 = imread("1.jpg");
	g_srcImage2 = imread("2.jpg");
	if (!g_srcImage1.data)
	{
		printf("读取第一幅图片错误，请确定目录下是否有imrad函数指定图片存在\n");
		return -1;
	}
	if (!g_srcImage2.data)
	{
		printf("读取第二幅图片错误，请确定目录下是否有imrad函数指定图片存在\n");
		return -1;
	}
	g_nAlphaValueSlider = 70; //滑动条初始值设为70
	namedWindow(WINDOW_NAME, 1);
	//在创建的窗体中创建一个滑动条控件
	char TrackbarName[50];
	sprintf(TrackbarName, "透明质 %d", g_nMaxAlphaValue);
	
	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);

	//结果在回调函数中显示
	on_Trackbar(g_nAlphaValueSlider, 0);
	waitKey(0);
	return 0;
}