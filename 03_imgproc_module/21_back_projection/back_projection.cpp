/**
 * @file BackProject_Demo1.cpp
 * @brief Sample code for backproject function usage
 * @author OpenCV team
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

/// Global Variables
Mat hue;
int bins = 25;

/// Function Headers
void Hist_and_Backproj(int, void* );

/**
 * @function main
 */
int main( int argc, char* argv[] )
{
    //! [Read the image]
    CommandLineParser parser( argc, argv, "{@input |  | input image}" );
    Mat src = imread( parser.get<String>( "@input" ) );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    //! [Read the image]

    //! [Transform it to HSV]
    Mat hsv;
    cvtColor( src, hsv, COLOR_BGR2HSV );
    //! [Transform it to HSV]

    // 将原图hsv的0通道映射到hue的0通道
    hue.create(hsv.size(), hsv.depth());
    int ch[] = { 0, 0 };
    mixChannels( &hsv, 1, &hue, 1, ch, 1 );
    //! [Use only the Hue value]

    // 放一个滑动条，用来修改生成直方图的bin数量
    const char* window_image = "Source image";
    namedWindow( window_image );
    createTrackbar("* Hue  bins: ", window_image, &bins, 180, Hist_and_Backproj );
    Hist_and_Backproj(0, 0);
    //! [Create Trackbar to enter the number of bins]

    //! [Show the image]
    imshow( window_image, src );
    // Wait until user exits the program
    waitKey();
    //! [Show the image]

    return 0;
}

/**
 * @function Hist_and_Backproj
 * @brief Callback to Trackbar
 */
void Hist_and_Backproj(int, void* )
{
    //! [initialize]
    int histSize = MAX( bins, 2 );
    float hue_range[] = { 0, 180 };
    const float* ranges = { hue_range };
    //! [initialize]

    // 生成hue的直方图，并标准化范围到0~255
    Mat hist;
    calcHist( &hue, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false );
    normalize( hist, hist, 0, 255, NORM_MINMAX, -1, Mat() );
    //! [Get the Histogram and normalize it]

    // 背投影操作
    Mat backproj;
    calcBackProject( &hue, 1, 0, hist, backproj, &ranges, 1, true );
    //! [Get Backprojection]

    // 显示背投影结果
    imshow( "BackProj", backproj );
    //! [Draw the backproj]

    // 显示直方图
    int w = 400, h = 400;
    int bin_w = cvRound( (double) w / histSize );
    Mat histImg = Mat::zeros( h, w, CV_8UC3 );

    for (int i = 0; i < bins; i++)
    {
        rectangle( histImg, Point( i*bin_w, h ), Point( (i+1)*bin_w, h - cvRound( hist.at<float>(i)*h/255.0 ) ),
                   Scalar( 0, 0, 255 ), FILLED );
    }

    imshow( "Histogram", histImg );
    //! [Draw the histogram]
}
