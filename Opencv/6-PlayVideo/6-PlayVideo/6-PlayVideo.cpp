#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    VideoCapture capture("1.avi"); //��ȡ�ļ����е���Ƶ
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("��ȡ��Ƶ", frame);
		waitKey(20.5);
	}
}