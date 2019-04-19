/*
 * generalContours_demo1.cpp
 * @brief Demo code to find contours in an image
 * @author OpenCV team
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat src_gray;
int thresh = 100;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );

/**
 * @function main
 */
int main( int argc, char** argv )
{
    //! [setup]
    /// Load source image
    CommandLineParser parser( argc, argv, "{@input | ../../data/ball.jpg | input image}" );
    Mat src = imread( parser.get<String>( "@input" ) );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    /// Convert image to gray and blur it
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );
    //! [setup]

    //! [createWindow]
    /// Create Window
    const char* source_window = "Source";
    namedWindow( source_window );
    imshow( source_window, src );
    //! [createWindow]

    // 滑动条，调整canny边缘检测的下阈值，上阈值是其两倍
    const int max_thresh = 255;
    createTrackbar( "Canny thresh:", source_window, &thresh, max_thresh, thresh_callback );
    thresh_callback( 0, 0 );
    //! [trackbar]

    waitKey();
    return 0;
}

/**
 * @function thresh_callback
 */
void thresh_callback(int, void* )
{
    //　canny边缘检测
    /// Detect edges using Canny
    Mat canny_output;
    Canny( src_gray, canny_output, thresh, thresh*2 );
    //! [Canny]

    // 在canny检测的边缘上寻找轮廓点集
    /// Find contours
    vector<vector<Point> > contours;
    findContours( canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE );
    //! [findContours]

    //　对于每一个找到的轮廓，我们现在应用近似多边形精度+-3，并声明曲线必须关闭。
    /// Approximate contours to polygons + get bounding rects and circles
    vector<vector<Point> > contours_poly( contours.size() );
    vector<Rect> boundRect( contours.size() );
    vector<Point2f>centers( contours.size() );
    vector<float>radius( contours.size() );

    for( size_t i = 0; i < contours.size(); i++ )
    {
		// 对于每一个找到的轮廓，我们现在应用近似多边形精度+-3，并声明曲线必须关闭。
        approxPolyDP( contours[i], contours_poly[i], 3, true );
		// 为每个多边形找到一个边界矩形
        boundRect[i] = boundingRect( contours_poly[i] );
		// 为每个多边形找到一个最小包围圆，并将其半径与圆心位置存储起来
        minEnclosingCircle( contours_poly[i], centers[i], radius[i] );
    }
    //! [allthework]

    //! [zeroMat]
    Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    //! [zeroMat]

    //! [forContour]
    /// Draw polygonal contour + bonding rects + circles
    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
        drawContours( drawing, contours_poly, (int)i, color );
        rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2 );
        circle( drawing, centers[i], (int)radius[i], color, 2 );
    }
    //! [forContour]

    //! [showDrawings]
    /// Show in a window
    imshow( "Contours", drawing );
    //! [showDrawings]
}
