#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(){
    Mat img1 = imread("../data/01.jpg");
    vector<KeyPoint> kp1, kp2;
    Mat ds1, ds2;
    Ptr<ORB> orb = ORB::create(100);
    orb->setFastThreshold(0);
    cout<<"此处提取orb特征点100个"<<endl;
    

    orb->detectAndCompute(img1, Mat(), kp1, ds1);
    for(int i=0;i<100;++i)
        cout<<"第"<< i+1 <<"个关键点的属性如下："< endl << "坐标为：" << kp1[i].pt << endl << "size  = " << kp1[i].size << endl << "angle = " << kp1[i].angle << endl << "response =  "<< kp1[i].response << endl << "提取自哪一层金字塔　octave = "<< kp1[i].octave << endl << "class_id = " << kp1[i].class_id << endl ;
    cout<< "第一幅图像上的描述子Mat ds1的属性如下：" << endl << "rows = " << ds1.rows << endl << "cols =" << ds1.cols << endl << "dims = " << ds1.dims << endl << "size = " << ds1.size << endl << "type() = " << ds1.type() << endl ;

    Mat show;
    drawKeypoints(img1, kp1, show);
    imshow("show", show);
    waitKey();
    
    return 0;

}
