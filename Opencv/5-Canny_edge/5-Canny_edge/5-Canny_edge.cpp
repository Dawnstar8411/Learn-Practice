#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main()
{
	Mat srcImage = imread("1.jpg");
	imshow("Canny��Ե���ԭʼͼ", srcImage);
	Mat dstImage, edge, grayImage; //��������
	dstImage.create(srcImage.size(), srcImage.type());
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY); // ��RGBͼת���ɻҶ�ͼ
	blur(grayImage, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("Canny��Ե���Ч��ͼ", edge);
	waitKey(0);
	return 0;
}