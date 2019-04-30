#include <opencv2/highgui/highgui.hpp> //OpenCV highgui模块头文件
#include <opencv2/imgproc/imgproc.hpp> //OpenCV 图像处理头文件
using namespace cv; //包含cv命名空间

int main()
{
	Mat srcImage = imread("1.jpg");
	imshow("原图腐蚀操作", srcImage);
	//进行腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));// 指定形状和尺寸的结构尺寸（内核矩阵）
	Mat dstImage;
	erode(srcImage, dstImage, element);
	imshow("效果图腐蚀操作", dstImage);
	waitKey(0);

	return 0;
}
