#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main()
{
	Mat girl = imread("girl.jpg");
	namedWindow("����ͼ");
	imshow("����ͼ", girl);

	Mat image = imread("dota.jpg");
	Mat logo = imread("dota_logo.jpg");
	namedWindow("ԭ��ͼ");
	imshow("ԭ��ͼ", image);

	namedWindow("logoͼ");
	imshow("logoͼ", logo);

	Mat imageROI;
	imageROI = image(Rect(800, 350, logo.cols, logo.rows));
	imageROI=image(Range(350,350+logo.rows),Range(800,800+logo.cols));
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);
	namedWindow("ԭͼ+logoͼ");
	imshow("ԭͼ+logoͼ", image);

	imwrite("��imwrite���ɵ�ͼƬ.jpg", image);
	waitKey();
	return 0;
}