/**
 * @file CannyDetector_Demo.cpp
 * @brief Sample code showing how to detect edges using the Canny Detector
 * @author OpenCV team
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;

//![variables]
Mat src, src_gray;
Mat dst, detected_edges;

int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;
const char* window_name = "Edge Map";
//![variables]

/**
 * @function CannyThreshold
 * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
 */
static void CannyThreshold(int, void*)
{
    //滤掉噪声
    /// Reduce noise with a kernel 3x3
    blur( src_gray, detected_edges, Size(3,3) );
    //![reduce_noise]

    //![canny]
    /// Canny detector
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    //![canny]

    /// 将dst赋值为全零Using Canny's output as a mask, we display our result
    //![fill]
    dst = Scalar::all(0);
    //![fill]

    //重载的功能，将第二个参数不为0的位置处的src的值拷贝到dst
	//此处作用是生成彩色的轮廓信息
    src.copyTo( dst, detected_edges);
    //![copyto]

    //![display]
    imshow( window_name, dst );
    //![display] 
	imshow("canny_result", detected_edges);
}


/**
 * @function main
 */
int main( int argc, char** argv )
{
  //![load]
  CommandLineParser parser( argc, argv, "{@input | /home/xianghengyong/Dataset/sample.png | input image}" );
  src = imread( parser.get<String>( "@input" ), IMREAD_COLOR ); // Load an image

  if( src.empty() )
  {
    std::cout << "Could not open or find the image!\n" << std::endl;
    std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
    return -1;
  }
  //![load]

  // 生成一个与原图src大小类型都相同的矩阵
  /// Create a matrix of the same type and size as src (for dst)
  dst.create( src.size(), src.type() );
  //![create_mat]
  imshow("src_image", src);
  // 生成原图的灰度图
  cvtColor( src, src_gray, COLOR_BGR2GRAY );
  //![convert_to_gray]

  //![create_window]
  namedWindow( window_name, WINDOW_AUTOSIZE );
  //![create_window]

  //![create_trackbar]
  /// Create a Trackbar for user to enter threshold
  createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );
  //![create_trackbar]

  /// Show the image
  CannyThreshold(0, 0);

  /// Wait until user exit program by pressing a key
  waitKey(0);

  return 0;
}
