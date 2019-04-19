#include <iostream>
//#ifdef HAVE_OPENCV_XFEATURES2D
#include <opencv2/opencv.hpp>
#include "opencv2/xfeatures2d.hpp"
using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;
int main(int argc, char** argv){
    if(argc != 2){
        cerr<<"Error introducing input arguments!"<<endl;
        cerr<<"the format needs to be : ./feature_compare img"<<endl;
        return -1;
    }
    
    Mat img;
    string imgfile = argv[1];
    
    img = imread(imgfile, 1);

    double t1 = 0.0, t2 = 0.0;

    // kaze
    Ptr<KAZE> pkaze = KAZE::create();
    double tkaze = 0.0;
    vector<KeyPoint> kpts_kaze;    
    t1 = cv::getTickCount();
    pkaze->detect(img, kpts_kaze, cv::noArray());
    t2 = cv::getTickCount();
    tkaze = 1000.0*(t2-t1)/cv::getTickFrequency();

    int n_kaze = kpts_kaze.size();

    cout<<"KAZE Results"<<endl;
    cout<<"**********************"<<endl;
    cout<<"# KeyPoints:     \t"<<n_kaze<<endl;
    cout<<"Time(ms):        \t"<<tkaze<<endl;
    cout<<endl;
    

    // akaze
    Ptr<AKAZE> pakaze = AKAZE::create();
    double takaze = 0.0;
    vector<KeyPoint> kpts_akaze;    
    t1 = cv::getTickCount();
    pakaze->detect(img, kpts_akaze, cv::noArray());
    t2 = cv::getTickCount();
    takaze = 1000.0*(t2-t1)/cv::getTickFrequency();

    int n_akaze = kpts_akaze.size();

    cout<<"AKAZE Results"<<endl;
    cout<<"**********************"<<endl;
    cout<<"# KeyPoints:     \t"<<n_akaze<<endl;
    cout<<"Time(ms):        \t"<<takaze<<endl;
    cout<<endl;
    
    // orb
    Ptr<ORB> porb = ORB::create(3000);
    double torb = 0.0;
    vector<KeyPoint> kpts_orb;    
    t1 = cv::getTickCount();
    porb->detect(img, kpts_orb, cv::noArray());
    t2 = cv::getTickCount();
    torb = 1000.0*(t2-t1)/cv::getTickFrequency();

    int n_orb = kpts_orb.size();

    cout<<"orb Results"<<endl;
    cout<<"**********************"<<endl;
    cout<<"# KeyPoints:     \t"<<n_orb<<endl;
    cout<<"Time(ms):        \t"<<torb<<endl;
    cout<<endl;
    
    
    // surf
    Ptr<SURF> psurf = SURF::create();
    double tsurf = 0.0;
    vector<KeyPoint> kpts_surf;    
    t1 = cv::getTickCount();
    psurf->detect(img, kpts_surf, cv::noArray());
    t2 = cv::getTickCount();
    tsurf = 1000.0*(t2-t1)/cv::getTickFrequency();

    int n_surf = kpts_surf.size();

    cout<<"SURF Results"<<endl;
    cout<<"**********************"<<endl;
    cout<<"# KeyPoints:     \t"<<n_surf<<endl;
    cout<<"Time(ms):        \t"<<tsurf<<endl;
    cout<<endl;
    return 0;
}
