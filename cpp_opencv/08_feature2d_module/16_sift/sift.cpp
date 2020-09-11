#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#include <string>
#include <iostream>
using namespace std;
using namespace cv;

Mat DrawInlier(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type);
Mat DrawInlier1(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type);

int main(){
        cv::Mat img1 = cv::imread("../bikes3/img1.ppm");
        cv::Mat img2 = cv::imread("../bikes3/img2.ppm");
    // 设置提取器
    vector<cv::KeyPoint> kp1, kp2;
    cv::Mat ds1, ds2;
    Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create(5);
    // 提取特征点并计算描述子
    sift->detectAndCompute(img1, Mat(), kp1, ds1);
    sift->detectAndCompute(img2, Mat(), kp2, ds2);

    vector<cv::DMatch> matches_knn0, matches_knn1;
    vector<vector<cv::DMatch>> matches_knn;
    //Mat img_matches_bf, img_matches_flann;

    // 暴力匹配，汉明距离，knn近邻
    double t;
    t = (double)getTickCount();

    Ptr<cv::DescriptorMatcher> bfmatcher = cv::BFMatcher::create();
    
	bfmatcher->knnMatch(ds1, ds2, matches_knn, 2);

    t = 1000*((double)getTickCount() - t)/getTickFrequency();

    cout << "暴力匹配2nn方法使用了"
         << t << " milliseconds."<< endl;
    cout << "the size of matches_knn is : "<<matches_knn.size()<<endl;
    for(int i=0; i<matches_knn.size(); ++i){
        matches_knn0.push_back(matches_knn[i][0]);
        matches_knn1.push_back(matches_knn[i][1]);        
    }
    // 画出匹配对
    Mat img_matches_knn0 = DrawInlier(img1, img2, kp1, kp2, matches_knn0, 1);
    imshow("Matches_knn0", img_matches_knn0);
    Mat img_matches_knn1 = DrawInlier(img1, img2, kp1, kp2, matches_knn1, 1);
    imshow("Matches_knn1", img_matches_knn1);    

    waitKey();

    return 0;
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
