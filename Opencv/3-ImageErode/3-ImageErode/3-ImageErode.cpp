#include <opencv2/highgui/highgui.hpp> //OpenCV highguiģ��ͷ�ļ�
#include <opencv2/imgproc/imgproc.hpp> //OpenCV ͼ����ͷ�ļ�
using namespace cv; //����cv�����ռ�

int main()
{
	Mat srcImage = imread("1.jpg");
	imshow("ԭͼ��ʴ����", srcImage);
	//���и�ʴ����
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));// ָ����״�ͳߴ�Ľṹ�ߴ磨�ں˾���
	Mat dstImage;
	erode(srcImage, dstImage, element);
	imshow("Ч��ͼ��ʴ����", dstImage);
	waitKey(0);

	return 0;
}
