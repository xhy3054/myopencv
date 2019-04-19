/**
 * @function cornerDetector_Demo.cpp
 * @brief Demo code for detecting corners using OpenCV built-in functions
 * @author OpenCV team
 */

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/// Global variables
Mat src, src_gray;
Mat myHarris_dst, myHarris_copy, Mc;
Mat myShiTomasi_dst, myShiTomasi_copy;

int myShiTomasi_qualityLevel = 50;
int myHarris_qualityLevel = 50;
int max_qualityLevel = 100;

double myHarris_minVal, myHarris_maxVal;
double myShiTomasi_minVal, myShiTomasi_maxVal;

RNG rng(12345);

const char* myHarris_window = "My Harris corner detector";
const char* myShiTomasi_window = "My Shi Tomasi corner detector";

/// Function headers
void myShiTomasi_function( int, void* );
void myHarris_function( int, void* );

/**
 * @function main
 */
int main( int argc, char** argv )
{
    /// Load source image and convert it to gray 载入图片并转成灰度图
    CommandLineParser parser( argc, argv, "{@input | ../../data/rabbit.jpg | input image}" );
    src = imread( parser.get<String>( "@input" ) );
    if ( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    cvtColor( src, src_gray, COLOR_BGR2GRAY );

    /// Set some parameters
    int blockSize = 3, apertureSize = 3;

    /// My Harris matrix -- Using cornerEigenValsAndVecs　计算特征值与特征向量生成myHarris_dst
    cornerEigenValsAndVecs( src_gray, myHarris_dst, blockSize, apertureSize );

    /* calculate Mc 计算harris响应值矩阵*/
    Mc = Mat( src_gray.size(), CV_32FC1 );
    for( int i = 0; i < src_gray.rows; i++ )
    {
        for( int j = 0; j < src_gray.cols; j++ )
        {
            float lambda_1 = myHarris_dst.at<Vec6f>(i, j)[0];
            float lambda_2 = myHarris_dst.at<Vec6f>(i, j)[1];
            // 计算harris响应值
            Mc.at<float>(i, j) = lambda_1*lambda_2 - 0.04f*pow( ( lambda_1 + lambda_2 ), 2 );
        }
    }

    // 找到最大值与最小值并存入myHarris_maxVal与myHarris_minVal
    minMaxLoc( Mc, &myHarris_minVal, &myHarris_maxVal );

    /* Create Window and Trackbar */ //调整harris角点检测的滑动棒
    namedWindow( myHarris_window );
    createTrackbar( "Quality Level:", myHarris_window, &myHarris_qualityLevel, max_qualityLevel, myHarris_function );
    myHarris_function( 0, 0 );

    /// My Shi-Tomasi -- Using cornerMinEigenVal　计算最小特征值矩阵myShiTomasi_dst
    cornerMinEigenVal( src_gray, myShiTomasi_dst, blockSize, apertureSize );
    // 在矩阵myShiTomasi_dst中找到最小与最大值
    minMaxLoc( myShiTomasi_dst, &myShiTomasi_minVal, &myShiTomasi_maxVal );

    /* Create Window and Trackbar */ //　调整shi-tomasi角点检测的滑动棒
    namedWindow( myShiTomasi_window );
    createTrackbar( "Quality Level:", myShiTomasi_window, &myShiTomasi_qualityLevel, max_qualityLevel, myShiTomasi_function );
    myShiTomasi_function( 0, 0 );

    waitKey();
    return 0;
}

/**
 * @function myShiTomasi_function　shi-tomasi角点检测功能
 */
void myShiTomasi_function( int, void* )
{
    myShiTomasi_copy = src.clone();
    myShiTomasi_qualityLevel = MAX(myShiTomasi_qualityLevel, 1);

    for( int i = 0; i < src_gray.rows; i++ )
    {
        for( int j = 0; j < src_gray.cols; j++ )
        {
            // 通过上面计算的每个像素点处的最小的特征值判断这个点是否是shi-tomasi角点
            if( myShiTomasi_dst.at<float>(i,j) > myShiTomasi_minVal + ( myShiTomasi_maxVal - myShiTomasi_minVal )*myShiTomasi_qualityLevel/max_qualityLevel )
            {
                circle( myShiTomasi_copy, Point(j,i), 4, Scalar( rng.uniform(0,256), rng.uniform(0,256), rng.uniform(0,256) ), FILLED );
            }
        }
    }
    imshow( myShiTomasi_window, myShiTomasi_copy );
}

/**
 * @function myHarris_function　harris角点检测功能
 */
void myHarris_function( int, void* )
{
    myHarris_copy = src.clone();
    myHarris_qualityLevel = MAX(myHarris_qualityLevel, 1);

    for( int i = 0; i < src_gray.rows; i++ )
    {
        for( int j = 0; j < src_gray.cols; j++ )
        {
            // 通过上面计算的harris响应值与滑动棒的值确定这个点是否是角点
            if( Mc.at<float>(i,j) > myHarris_minVal + ( myHarris_maxVal - myHarris_minVal )*myHarris_qualityLevel/max_qualityLevel )
            {
                circle( myHarris_copy, Point(j,i), 4, Scalar( rng.uniform(0,256), rng.uniform(0,256), rng.uniform(0,256) ), FILLED );
            }
        }
    }
    imshow( myHarris_window, myHarris_copy );
}
