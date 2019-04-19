#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char** argv){
    const char* filename = argc>=2 ? argv[1] : "../../data/wechat.jpg";
    Mat src = imread(filename);

    if(src.empty()){
        std::cout<<"can not find the picture!"<<endl;
        return 1;
    }

    Size sz(300,200);
    Mat dst;
    resize(src, dst, sz);
    imshow("dst", dst);
    imwrite("result/dst.jpg", dst);
    imwrite("result/dst.png", dst);
    imwrite("result/dst.bmp", dst);
    waitKey();
}
