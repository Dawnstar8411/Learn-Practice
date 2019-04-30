#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main()
{
	Mat girl = imread("girl.jpg");
	namedWindow("动漫图");
	imshow("动漫图", girl);

	Mat image = imread("dota.jpg");
	Mat logo = imread("dota_logo.jpg");
	namedWindow("原画图");
	imshow("原画图", image);

	namedWindow("logo图");
	imshow("logo图", logo);

	Mat imageROI;
	imageROI = image(Rect(800, 350, logo.cols, logo.rows));
	imageROI=image(Range(350,350+logo.rows),Range(800,800+logo.cols));
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);
	namedWindow("原图+logo图");
	imshow("原图+logo图", image);

	imwrite("由imwrite生成的图片.jpg", image);
	waitKey();
	return 0;
}