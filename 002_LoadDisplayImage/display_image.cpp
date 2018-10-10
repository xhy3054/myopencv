#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
/*
core section, as here are defined the basic building blocks of the library
highgui module, as this contains the functions for input and output operations
*/
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    String imageName( "../data/HappyFish.jpg" ); // by default
    if( argc > 1)
    {
        imageName = argv[1];
    }
    Mat image;
/*
Mat cv::imread  (   const String &  filename,
int     flags = IMREAD_COLOR 
)   
*/
    image = imread( imageName, IMREAD_COLOR ); // Read the file, 没有第二个参数也行，默认就是IMREAD_COLOR

    if( image.empty() )                      // Check for invalid input，如果读入失败则返回mat会为空
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
/*
void cv::namedWindow    (   const String &  winname,
int     flags = WINDOW_AUTOSIZE 
)       
*/
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
/*
void cv::imshow (   const String &  winname,
InputArray  mat 
)   
*/
    imshow( "Display window", image );                // Show our image inside it.

//int cv::waitKey(int delay = 0 )   
    waitKey(0); // Wait for a keystroke in the window参数小于等于０代表永远等待，否则毫秒为单位
    return 0;
}
