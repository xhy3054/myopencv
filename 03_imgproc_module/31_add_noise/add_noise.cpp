//给图像添加高斯噪声
#include <cmath>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
 
using namespace cv;
using namespace std;
 
double generateGaussianNoise(double m, double sigma);
Mat addGaussianNoise(Mat &srcImag);
 
int main()
{
	Mat srcImage = imread("../data/06.jpg");
	if (!srcImage.data)
	{
		cout << "读入图片错误！" << endl;
		system("pause");
		return -1;
	}
	imshow("原图像", srcImage);
	Mat dstImage = addGaussianNoise(srcImage);
    imwrite("noise_06.jpg", dstImage);
	imshow("添加高斯噪声后的图像", dstImage);
	waitKey();
	return 0;
}
 
//生成高斯噪声
double generateGaussianNoise(double mu, double sigma)
{
	//定义小值
	const double epsilon = numeric_limits<double>::min();
	static double z0, z1;
	static bool flag = false;
	flag = !flag;
	//flag为假构造高斯随机变量X
	if (!flag)
		return z1 * sigma + mu;
	double u1, u2;
	//构造随机变量
	do
	{
		u1 = rand() * (1.0 / RAND_MAX);
		u2 = rand() * (1.0 / RAND_MAX);
	} while (u1 <= epsilon);
	//flag为真构造高斯随机变量
	z0 = sqrt(-2.0*log(u1))*cos(2 * CV_PI*u2);
	z1 = sqrt(-2.0*log(u1))*sin(2 * CV_PI*u2);
	return z0*sigma + mu;
}
 
//为图像添加高斯噪声
Mat addGaussianNoise(Mat &srcImag)
{
	Mat dstImage = srcImag.clone();
	int channels = dstImage.channels();
	int rowsNumber = dstImage.rows;
	int colsNumber = dstImage.cols*channels;
	//判断图像的连续性
	if (dstImage.isContinuous())
	{
		colsNumber *= rowsNumber;
		rowsNumber = 1;
	}
	for (int i = 0; i < rowsNumber; i++)
	{
		for (int j = 0; j < colsNumber; j++)
		{
			//添加高斯噪声
			int val = dstImage.ptr<uchar>(i)[j] +
				generateGaussianNoise(2, 0.8) * 32;
			if (val < 0)
				val = 0;
			if (val>255)
				val = 255;
			dstImage.ptr<uchar>(i)[j] = (uchar)val;
		}
	}
	return dstImage;
}

