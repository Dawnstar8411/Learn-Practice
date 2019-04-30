#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main()
{
	Mat srcImage = imread("1.jpg");
	imshow("Canny边缘检测原始图", srcImage);
	Mat dstImage, edge, grayImage; //声明变量
	dstImage.create(srcImage.size(), srcImage.type());
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY); // 将RGB图转换成灰度图
	blur(grayImage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("Canny边缘检测效果图", edge);
	waitKey(0);
	return 0;
}