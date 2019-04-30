#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
    VideoCapture capture("1.avi"); //读取文件夹中的视频
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("读取视频", frame);
		waitKey(20.5);
	}
}