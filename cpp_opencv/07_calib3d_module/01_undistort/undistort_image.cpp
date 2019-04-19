#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv){
    /// Load the source image
    const char* filename = argc >=2 ? argv[1] : "../../data/wechat.jpg";

    Mat src = imread( filename, IMREAD_COLOR );
    if(src.empty())
    {
        printf(" Error opening image\n");
        printf(" Usage: ./Smoothing [image_name -- default ../../data/wechat.jpg] \n");
        return -1;
    }

    Mat cameraMatrix = Mat::eye(3, 3, CV_64F);
    Mat distCoeffs = Mat::zeros(5, 1, CV_64F);    
}

void undistortPoints(){
    
}
