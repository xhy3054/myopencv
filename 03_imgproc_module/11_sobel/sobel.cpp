/**
 * @file Sobel_Demo.cpp
 * @brief Sample code uses Sobel or Scharr OpenCV functions for edge detection
 * @author OpenCV team
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

/**
 * @function main
 */
int main( int argc, char** argv )
{
//
  cv::CommandLineParser parser(argc, argv,
                               "{@input   |../../data/wechat.jpg|input image}"
                               "{ksize   k|1|ksize (hit 'K' to increase its value)}"
                               "{scale   s|1|scale (hit 'S' to increase its value)}"
                               "{delta   d|0|delta (hit 'D' to increase its value)}"
                               "{help    h|false|show help message}");

  cout << "The sample uses Sobel or Scharr OpenCV functions for edge detection\n\n";
//输出参数信息
  parser.printMessage();
  cout << "\nPress 'R' to reset values ( ksize will be -1 equal to Scharr function )";
  cout << "\nPress 'ESC' to exit program.\n";

  //![variables]
  // First we declare the variables we are going to use
  Mat image,src, src_gray;
  Mat grad;
  const String window_name = "Sobel Demo - Simple Edge Detector";
//获取必要参数，默认的或者运行程序时输入的
  int ksize = parser.get<int>("ksize");
  int scale = parser.get<int>("scale");
  int delta = parser.get<int>("delta");
  int ddepth = CV_16S;
  //![variables]

  //![load]
  String imageName = parser.get<String>("@input");
  // As usual we load our source image (src)
  image = imread( imageName, IMREAD_COLOR ); // Load an image

  // Check if image is loaded fine
  if( image.empty() )
  {
    printf("Error opening image: %s\n", imageName.c_str());
    return 1;
  }
  //![load]

//一直循环
  for (;;)
  {
    // 使用高斯滤波器滤掉噪声
    // Remove noise by blurring with a Gaussian filter ( kernel size = 3 )
    GaussianBlur(image, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
    //![reduce_noise]

    // 生成灰度图
    // Convert the image to grayscale
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    //![convert_to_gray]

    // 生成水平梯度与垂直梯度信息mat
    /// Generate grad_x and grad_y
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    /// Gradient X
	//Scharr(src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT);
    Sobel(src_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);

    /// Gradient Y
	//Scharr(src_gray, grad_x, ddepth, 0, 1, scale, delta, BORDER_DEFAULT);
    Sobel(src_gray, grad_y, ddepth, 0, 1, ksize, scale, delta, BORDER_DEFAULT);
    //![sobel]

    // 通过取绝对值将梯度信息转成八位像素强度值
    // converting back to CV_8U
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);
    //![convert]

    //　通过将一个点水平梯度的绝对值与垂直梯度的绝对值相加来近似该点的梯队
    /// Total Gradient (approximate)
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    //![blend]

    //![display]
    imshow(window_name, grad);
    char key = (char)waitKey(0);
    //![display]

    if(key == 27)
    {
      return 0;
    }

    if (key == 'k' || key == 'K')
    {
      ksize = ksize < 30 ? ksize+2 : -1;
    }

    if (key == 's' || key == 'S')
    {
      scale++;
    }

    if (key == 'd' || key == 'D')
    {
      delta++;
    }

    if (key == 'r' || key == 'R')
    {
      scale =  1;
      ksize = -1;
      delta =  0;
    }
  }
  return 0;
}
