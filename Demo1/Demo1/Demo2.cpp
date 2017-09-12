#include<opencv2\core\core.hpp>
#include<opencv2\highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void onMouse(int event,int x,int y,int flags,void *param)
{
	if(event==CV_EVENT_LBUTTONDOWN)
	{
		Mat *pImag=(Mat *)param;
		if(pImag->channels()==1)
		{
			cout<<"图像的位置坐标："<<x <<"*"<<y <<",图像的灰度值："<<(int) pImag->at<uchar>(y,x) <<endl;
		}
		else if(pImag->channels()==3)
		{
			Vec3b p=pImag->at<Vec3b>(y,x);
			cout<<"图像的位置坐标："<<x <<"*"<<y <<",图像的灰度值："<<"R "<<(int) p[2]<<",G "<<(int) p[1]<<",B "<<(int) p[0] <<endl;
		}
	}

}

int main()
{
	Mat image,result;
	image= imread("puppy.jpg");
	if(image.empty())
	{
		cout<<"图像读取失败！"<<endl;
	}
	else
	{
		circle(image,Point(386, 325),300,0,3);
		putText(image,"I am not a dog!",Point(600, 592),FONT_HERSHEY_PLAIN,2.0,255,2);

		namedWindow("原始图像");
		imshow("原始图像",image);
		setMouseCallback("原始图像",onMouse,&image);
		cout<< image.rows<<"*"<<image.cols<<endl;

		flip(image,result,2);
		imwrite("result.jpg",result);
		namedWindow("结果图像");
		imshow("结果图像",result);
		cout<< result.rows<<"*"<<result.cols<<endl;

	}
	waitKey(0);
	return 0;
}
