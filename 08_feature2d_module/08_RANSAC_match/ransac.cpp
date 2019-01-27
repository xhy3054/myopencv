#include <opencv2/opencv.hpp>
//#include "opencv2/nonfree/nonfree.hpp"  
//#include "opencv2/nonfree/features2d.hpp"  
//#include "opencv2/legacy/legacy.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace cv;
Mat img1;
Mat img2;
void readimg(){
    img1 = imread("../data/05.jpg");
    img2 = imread("../data/06.jpg");
}
void getFeature(vector<KeyPoint> &kp1, vector<KeyPoint> &kp2, Mat &ds1, Mat &ds2);
void matchBf(Mat &ds1, Mat &ds2, vector<DMatch> &matches_bf);
void matchRansac(vector<KeyPoint> &kp1, vector<KeyPoint> &kp2, vector<DMatch> &matches_bf, vector<DMatch> &matches_ransac);
Mat DrawInlier(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type);
Mat DrawInlier1(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type);
int main(){
    readimg();
    // 提取orb特征并计算描述子
    vector<KeyPoint> kp1, kp2;
    Mat ds1, ds2;
    getFeature(kp1, kp2, ds1, ds2);
    
    //　暴力匹配    
    vector<DMatch> matches_bf;
    matchBf(ds1, ds2, matches_bf);

    // 画出匹配对
    Mat img_matches_bf = DrawInlier1(img1, img2, kp1, kp2, matches_bf, 1);    
    imshow("Matches_bf", img_matches_bf);

    // RANSAC筛选
    vector<DMatch> matches_ransac;
    matchRansac(kp1, kp2, matches_bf, matches_ransac);
    // 画出筛选后的匹配    
    Mat img_matches_ransac = DrawInlier1(img1, img2, kp1, kp2, matches_ransac, 1);    
    imshow("Matches_ransac", img_matches_ransac);
    waitKey();
    
    return 0;
}

void getFeature(vector<KeyPoint> &kp1, vector<KeyPoint> &kp2, Mat &ds1, Mat &ds2){
    double t;
    t = (double)getTickCount();
    // 设置提取器
    Ptr<ORB> orb = ORB::create(1000);
    orb->setFastThreshold(0);
    // 提取特征点并计算描述子
    orb->detectAndCompute(img1, Mat(), kp1, ds1);
    orb->detectAndCompute(img2, Mat(), kp2, ds2);

    t = 1000*((double)getTickCount() - t)/getTickFrequency();

    cout << "提取关键点与计算描述子一共使用了"
         << t << " milliseconds."<< endl;
}

void matchBf(Mat &ds1, Mat &ds2, vector<DMatch> &matches_bf){
    // 特征匹配方法一，暴力匹配，汉明距离
    double t;
    t = (double)getTickCount();

	BFMatcher bfmatcher(NORM_HAMMING);
	bfmatcher.match(ds1, ds2, matches_bf);

    t = 1000*((double)getTickCount() - t)/getTickFrequency();

    cout << "暴力匹配方法使用了"
         << t << " milliseconds."<< endl;
}

void matchRansac(vector<KeyPoint> &kp1, vector<KeyPoint> &kp2, vector<DMatch> &matches_bf, vector<DMatch> &matches_ransac){
    double t;
    t = (double)getTickCount();

    vector<Point2f> obj;
    vector<Point2f> scene;
    // 将匹配对中的对应的点坐标信息提取出来
    for(size_t i=0; i<matches_bf.size(); ++i){
        obj.push_back(kp1[matches_bf[i].queryIdx].pt);
        scene.push_back(kp2[matches_bf[i].trainIdx].pt);    
    }    


    // 利用基础矩阵剔除错误的匹配
    vector<unsigned char> ransac_status;
    Mat fundamental = findFundamentalMat(obj, scene, ransac_status, FM_RANSAC);
    for(size_t i=0; i<matches_bf.size(); ++i){
        if(ransac_status[i]!=0){
            matches_ransac.push_back(matches_bf[i]);        
        }    
    }
    t = 1000*((double)getTickCount() - t)/getTickFrequency();

    cout << "ransac筛选使用了"
         << t << " milliseconds."<< endl;
    
    
}

Mat DrawInlier(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type) {
	const int height = max(src1.rows, src2.rows);
	const int width = src1.cols + src2.cols;
	Mat output(height, width, CV_8UC3, Scalar(0, 0, 0));
	src1.copyTo(output(Rect(0, 0, src1.cols, src1.rows)));
	src2.copyTo(output(Rect(src1.cols, 0, src2.cols, src2.rows)));

	if (type == 1)
	{
		for (size_t i = 0; i < inlier.size(); i++)
		{
			Point2f left = kpt1[inlier[i].queryIdx].pt;
			Point2f right = (kpt2[inlier[i].trainIdx].pt + Point2f((float)src1.cols, 0.f));
			line(output, left, right, Scalar(0, 255, 255));
		}
	}
	else if (type == 2)
	{
		for (size_t i = 0; i < inlier.size(); i++)
		{
			Point2f left = kpt1[inlier[i].queryIdx].pt;
			Point2f right = (kpt2[inlier[i].trainIdx].pt + Point2f((float)src1.cols, 0.f));
			line(output, left, right, Scalar(255, 0, 0));
		}

		for (size_t i = 0; i < inlier.size(); i++)
		{
			Point2f left = kpt1[inlier[i].queryIdx].pt;
			Point2f right = (kpt2[inlier[i].trainIdx].pt + Point2f((float)src1.cols, 0.f));
			circle(output, left, 1, Scalar(0, 255, 255), 2);
			circle(output, right, 1, Scalar(0, 255, 0), 2);
		}
	}

	return output;
}

Mat DrawInlier1(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type) {
	const int height = src1.rows + src2.rows;
	const int width = max(src1.cols , src2.cols);
	Mat output(height, width, CV_8UC3, Scalar(0, 0, 0));
	src1.copyTo(output(Rect(0, 0, src1.cols, src1.rows)));
	src2.copyTo(output(Rect(0, src1.rows, src2.cols, src2.rows)));

	if (type == 1)
	{
		for (size_t i = 0; i < inlier.size(); i++)
		{
			Point2f up = kpt1[inlier[i].queryIdx].pt;
			Point2f down = (kpt2[inlier[i].trainIdx].pt + Point2f(0.f, (float)src1.rows));
			line(output, up, down, Scalar(0, 255, 255));
		}
	}
	else if (type == 2)
	{
		for (size_t i = 0; i < inlier.size(); i++)
		{
			Point2f up = kpt1[inlier[i].queryIdx].pt;
			Point2f down = (kpt2[inlier[i].trainIdx].pt + Point2f(0.f, (float)src1.rows));
			line(output, up, down, Scalar(0, 255, 255));
		}

		for (size_t i = 0; i < inlier.size(); i++)
		{
			Point2f up = kpt1[inlier[i].queryIdx].pt;
			Point2f down = (kpt2[inlier[i].trainIdx].pt + Point2f(0.f, (float)src1.rows));
			circle(output, up, 1, Scalar(0, 255, 255), 2);
			circle(output, down, 1, Scalar(0, 255, 0), 2);
		}
	}

	return output;
}

