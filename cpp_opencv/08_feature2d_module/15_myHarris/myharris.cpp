#include "myharris.h"
using namespace cv;
// 这个函数功能模仿opencv库函数，只计算了harris响应值矩阵
void mycv::detectHarrisCorners(const Mat& imgSrc, Mat& imgDst, double alpha){
    Mat gray;
    if(imgSrc.channels() == 3){
        cvtColor(imgSrc, gray, CV_BGR2GRAY);
    }
    else gray = imgSrc.clone();
    gray.convertTo(gray, CV_64F);

    Matx<double,1,3> xkernel(-1,0,1);
    Matx<double,3,1> ykernel(-1,0,1);
	// Mat xkernel = (Mat_<double>(1,3) << -1, 0, 1);
	// Mat ykernel = xkernel.t();

    Mat Ix, Iy;
    //filter2D函数就是简单的滤波操作，将图像与卷积核进行卷积，并得到结果
    filter2D(gray, Ix, CV_64F, xkernel);    //水平求导
    filter2D(gray, Iy, CV_64F, ykernel);    //垂直求导

    // 两个矩阵逐元素的乘法
    Mat Ix2, Iy2, Ixy;
    Ix2 = Ix.mul(Ix);
    Iy2 = Iy.mul(Iy);
    Ixy = Ix.mul(Iy);

    // 生成高斯核
    Mat gausskernel = getGaussianKernel(7,1);  
    filter2D(Ix2, Ix2, CV_64F, gausskernel);
    filter2D(Iy2, Iy2, CV_64F, gausskernel);
    filter2D(Ixy, Ixy, CV_64F, gausskernel);

    Mat cornerStrength(gray.size(), gray.type());
    for(int i=0; i<gray.rows; ++i){
        for(int j=0; j<gray.cols; ++j){
            double det_m = Ix2.at<double>(i,j) * Iy2.at<double>(i,j) - Ixy.at<double>(i,j) * Ixy.at<double>(i,j);
            double trace_m = Ix2.at<double>(i,j) + Iy2.at<double>(i,j);
            cornerStrength.at<double>(i,j) = det_m - alpha * trace_m*trace_m;
        }
    }
    
    imgDst =cornerStrength.clone();
    
}
