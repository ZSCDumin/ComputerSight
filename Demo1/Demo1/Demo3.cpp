#include<opencv2\core\core.hpp>
#include<opencv2\highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void salt(Mat image, int n)
{
	for (int i = 0; i < n; i++)
	{
		int row = rand() % image.rows;
		int col = rand() % image.cols;
		if (image.type() == CV_8U)
		{
			image.at<uchar>(row, col) = 255;
		}
		else if (image.type() == CV_8UC3)
		{
			image.at<Vec3b>(row, col) = Vec3b(255, 255, 255);
		}
	}
}
int main()
{
	Mat image = imread("puppy.jpg");
	//Mat logo=imread("logo.bmp");
	//Mat RIO = Mat(image,Rect(image.cols-logo.cols,image.rows-logo.rows,logo.cols,logo.rows));
	//logo.copyTo(RIO,logo);
	salt(image, 10000);
	imshow("Result", image);
	waitKey(0);
}