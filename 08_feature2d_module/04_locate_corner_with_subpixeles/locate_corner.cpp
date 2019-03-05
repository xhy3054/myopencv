/**
 * @function cornerSubPix_Demo.cpp
 * @brief Demo code for refining corner locations
 * @author OpenCV team
 */

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/// Global variables
Mat src, src_gray;

int maxCorners = 10;
int maxTrackbar = 25;

RNG rng(12345);
const char* source_window = "Image";

/// Function header
void goodFeaturesToTrack_Demo( int, void* );

/**
 * @function main
 */
int main( int argc, char** argv )
{
    /// Load source image and convert it to gray 加载图片并转成灰度图
    CommandLineParser parser( argc, argv, "{@input | ../../data/rabbit.jpg | input image}" );
    src = imread( parser.get<String>( "@input" ) );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    cvtColor( src, src_gray, COLOR_BGR2GRAY );

    /// Create Window
    namedWindow( source_window );

    /// Create Trackbar to set the number of corners　创建滑动棒调整提取的角点数量
    createTrackbar( "Max corners:", source_window, &maxCorners, maxTrackbar, goodFeaturesToTrack_Demo );

    imshow( source_window, src );

    goodFeaturesToTrack_Demo( 0, 0 );

    waitKey();
    return 0;
}

/**
 * @function goodFeaturesToTrack_Demo.cpp
 * @brief Apply Shi-Tomasi corner detector
 */
void goodFeaturesToTrack_Demo( int, void* )
{
    /// Parameters for Shi-Tomasi algorithm
    maxCorners = MAX(maxCorners, 1);
    vector<Point2f> corners;
    double qualityLevel = 0.01;
    double minDistance = 10;
    int blockSize = 3, gradientSize = 3;
    bool useHarrisDetector = false;
    double k = 0.04;

    /// Copy the source image
    Mat copy = src.clone();

    /// Apply corner detection　shi-tomati角点
    goodFeaturesToTrack( src_gray,
                         corners,
                         maxCorners,
                         qualityLevel,
                         minDistance,
                         Mat(),
                         blockSize,
                         gradientSize,
                         useHarrisDetector,
                         k );


    /// Draw corners detected　画出角点
    cout << "** Number of corners detected: " << corners.size() << endl;
    int radius = 4;
    for( size_t i = 0; i < corners.size(); i++ )
    {
        circle( copy, corners[i], radius, Scalar(rng.uniform(0,255), rng.uniform(0, 256), rng.uniform(0, 256)), FILLED );
    }

    /// Show what you got
    namedWindow( source_window );
    imshow( source_window, copy );

    /// Set the needed parameters to find the refined corners　参数准备
    Size winSize = Size( 5, 5 );
    Size zeroZone = Size( -1, -1 );
    TermCriteria criteria = TermCriteria( TermCriteria::EPS + TermCriteria::COUNT, 40, 0.001 );

    /// Calculate the refined corner locations　使用这个函数优化角点位置
    cornerSubPix( src_gray, corners, winSize, zeroZone, criteria );

    /// Write them down　将优化后的角点与位置输出
    for( size_t i = 0; i < corners.size(); i++ )
    {
        cout << " -- Refined Corner [" << i << "]  (" << corners[i].x << "," << corners[i].y << ")" << endl;
    }
}