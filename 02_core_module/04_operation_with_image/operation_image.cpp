//#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
int main(){
	//读取图片
    Mat img = imread("../../data/village.jpg");
    namedWindow("img",WINDOW_AUTOSIZE);
    imshow("img", img);
    
	//转成灰度图
    Mat grey;
    cvtColor(img, grey, COLOR_BGR2GRAY);
    namedWindow("grey", WINDOW_AUTOSIZE);
    imshow("grey", grey);

	//计算索贝尔算子
    Mat sobelx;
    Sobel(grey, sobelx, CV_32F, 1, 0);
    namedWindow("sobelx", WINDOW_AUTOSIZE);
    imshow("sobelx", sobelx);
    
	//取出计算出的索贝尔算子的最大最小值
    double minVal, maxVal;
    minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
    std::cout<<"minval = "<<minVal<<std::endl;
    std::cout<<"maxval = "<<maxVal<<std::endl;
      
	//灰度值平均一下，进行显示
    Mat draw;
    sobelx.convertTo(draw, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));
    namedWindow("draw", WINDOW_AUTOSIZE);
    imshow("draw", draw);
    waitKey();
    
}

