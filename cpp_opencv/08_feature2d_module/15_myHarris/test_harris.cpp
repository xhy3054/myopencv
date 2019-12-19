/**
 * @function cornerHarris_Demo.cpp
 * @brief Demo code for detecting corners using Harris-Stephens method
 * @author OpenCV team
 */

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "myharris.h"
#include <iostream>

using namespace cv;
using namespace std;

/// Global variables
Mat src;
//, src_gray;
int thresh = 50;
int max_thresh = 100;
RNG rng(12345);

const char* source_window = "Source image";
const char* corners_window = "Corners detected";

/// Function header
void cornerHarris_demo( int, void* );

/**
 * @function main
 */
int main( int argc, char** argv )
{
    /// Load source image and convert it to gray
    CommandLineParser parser( argc, argv, "{@input | ../1.png | input image}" );
    src = imread( parser.get<String>( "@input" ) );
    if ( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    //cvtColor( src, src_gray, COLOR_BGR2GRAY );

    /// Create a window and a trackbar
    namedWindow( source_window );
    createTrackbar( "Threshold: ", source_window, &thresh, max_thresh, cornerHarris_demo );
    imshow( source_window, src );

    cornerHarris_demo( 0, 0 );

    waitKey();
    return 0;
}

/**
 * @function cornerHarris_demo
 * @brief Executes the corner detection and draw a circle around the possible corners
 */
void cornerHarris_demo( int, void* )
{
    /// Detector parameters　，参数
    double k = 0.001;

    /// Detecting corners　检测角点
    Mat dst ;
    mycv::detectHarrisCorners( src, dst, k*thresh );

    /// Normalizing　将响应值标准化到0~255
    Mat dst_norm, dst_norm_scaled;
    //在最大最小元素之间均匀标准化，当前元素为 255*(value-min)/(max-min) 取整
    normalize( dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
    //在0到最大元素之间均匀标准化，当前元素为 255*value/max
    //normalize( dst, dst_norm, 0, 255, NORM_INF, CV_32FC1, Mat() );
    //normalize( dst, dst_norm, 255, 0, NORM_INF, CV_32FC1, Mat() );
    //取绝对值，然后转为8比特
    convertScaleAbs( dst_norm, dst_norm_scaled );

    Mat src_copy = src.clone();
    /// Drawing a circle around corners　每个响应值大于阈值的点画一个圆
    for( int i = 0; i < dst_norm.rows ; i++ )
    {
        for( int j = 0; j < dst_norm.cols; j++ )
        {
            if( (int) dst_norm.at<float>(i,j) > 150 )
            {
                //circle( dst_norm_scaled, Point(j,i), 5,  Scalar(0), 2, 8, 0 );
                circle( src_copy, Point(j,i), 1,  Scalar(0), 2, 8, 0 );
                //circle( src_copy, Point(j,i), 1, Scalar(rng.uniform(0,255), rng.uniform(0, 256), rng.uniform(0, 256)), FILLED );
            }
        }
    }
 

    /// Showing the result　显示结果
    namedWindow( corners_window );
    imshow( corners_window, dst );

    namedWindow( source_window );
    imshow( source_window, src_copy );
}
