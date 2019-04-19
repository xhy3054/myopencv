#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(){
    Mat img1 = imread("../data/01.jpg");
    Mat img2 = imread("../data/02.jpg");
    vector<KeyPoint> kp1, kp2;
    Mat ds1, ds2;
    Ptr<ORB> orb = ORB::create(100);
    orb->setFastThreshold(0);
    cout<<"此处提取orb特征点100个"<<endl;

    orb->detectAndCompute(img1, Mat(), kp1, ds1);
    cout<< "第一幅图像上的描述子Mat ds1的属性如下：" << endl << "rows = " << ds1.rows << endl << "cols =" << ds1.cols << endl << "dims = " << ds1.dims << endl << "size = " << ds1.size << endl << "type() = " << ds1.type() << endl ;
    orb->detectAndCompute(img2, Mat(), kp2, ds2);
    cout<< "第二幅图像上的描述子Mat ds2的属性如下：" << endl << "rows = " << ds2.rows << endl << "cols =" << ds2.cols << endl << "dims = " << ds2.dims << endl << "size = " << ds2.size << endl << "type() = " << ds2.type() << endl ;
    
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::BRUTEFORCE);
    vector<DMatch> matches;
    matcher->match(ds1,ds2,matches);
   
    Mat img_matches;
    drawMatches(img1, kp1, img2, kp2, matches, img_matches);
    imshow("Matches", img_matches);
    waitKey();
    
    return 0;

}
