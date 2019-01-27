#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>
//每层上的特征点在其第二幅图上的匹配在各层之间分布很均匀，额所以分层筛选不可取。
using namespace std;
using namespace cv;
vector<KeyPoint> kp1, kp2;
Mat ds1, ds2;

Mat DrawInlier(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type);
Mat DrawInlier1(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type);
void maxpoint(vector<pair<int, int>> & m, vector<int> &p);
int main(){
    Mat img1 = imread("../data/03.jpg");
    Mat img2 = imread("../data/04.jpg");
    // 设置提取器


    double t;
    t = (double)getTickCount();
    Ptr<ORB> orb = ORB::create(10000, 1.2f, 8);
    orb->setFastThreshold(0);
    // 提取特征点并计算描述子

    orb->detectAndCompute(img1, Mat(), kp1, ds1);
    orb->detectAndCompute(img2, Mat(), kp2, ds2);
    t = 1000*((double)getTickCount() - t)/getTickFrequency();

    cout << "提取关键点、计算描述子一共使用了"
         << t << " milliseconds."<< endl;

    cout<<"the numbers os kp1 is: "<<kp1.size()<<endl;
    vector<int> num(8,0);
    for(auto k:kp1){
        switch(k.octave){
            case 0:
                ++num[0];
                break;
            case 1:
                ++num[1];
                break;
            case 2:
                ++num[2];
                break;
            case 3:
                ++num[3];
                break;
            case 4:
                ++num[4];
                break;
            case 5:
                ++num[5];
                break;
            case 6:
                ++num[6];
                break;
            case 7:
                ++num[7];
                break;
            default:
                break;
        }
    }
    for(int i=0; i<8; ++i)
        cout<<"第　"<<i<<" 层的特征点数量是： "<<num[i]<<endl;
    
    vector<DMatch> matches;

    //Mat img_matches_bf, img_matches_flann;

    // 暴力匹配，汉明距离，
    //double t;
    t = (double)getTickCount();

	BFMatcher bfmatcher(NORM_HAMMING);
	bfmatcher.match(ds1, ds2, matches);

    t = 1000*((double)getTickCount() - t)/getTickFrequency();

    cout << "暴力匹配方法使用了"
         << t << " milliseconds."<< endl;
    cout << "the size of matches is : "<<matches.size()<<endl;

    vector<vector<pair<int, int>>> lmatches;
    lmatches.resize(8);
    // 整理一下，每层的匹配对放在一起
    for(size_t i=0; i<matches.size(); ++i) {
        switch(kp1[matches[i].queryIdx].octave){
            case 0:
                lmatches[0].push_back(pair<int, int>(matches[i].queryIdx, matches[i].trainIdx));
                break;
            case 1:
                lmatches[1].push_back(pair<int, int>(matches[i].queryIdx, matches[i].trainIdx));
                break;
            case 2:
                lmatches[2].push_back(pair<int, int>(matches[i].queryIdx, matches[i].trainIdx));
                break;
            case 3:
                lmatches[3].push_back(pair<int, int>(matches[i].queryIdx, matches[i].trainIdx));
                break;
            case 4:
                lmatches[4].push_back(pair<int, int>(matches[i].queryIdx, matches[i].trainIdx));
                break;
            case 5:
                lmatches[5].push_back(pair<int, int>(matches[i].queryIdx, matches[i].trainIdx));
                break;
            case 6:
                lmatches[6].push_back(pair<int, int>(matches[i].queryIdx, matches[i].trainIdx));
                break;
            case 7:
                lmatches[7].push_back(pair<int, int>(matches[i].queryIdx, matches[i].trainIdx));
                break;
            default:
                break;    
        }        
    }   
    for(int i=0; i<8; ++i)
        cout<<"第　"<<i<<"　层有 "<<lmatches[i].size()<<"　对匹配"<<endl;
    //统计每层匹配对的指向问题；
    vector<vector<int>> p;
    p.resize(8);
    for(size_t i=0; i<8; ++i)
        p[i].assign(8,0);
    for(int i=0; i<lmatches.size(); ++i)
        maxpoint(lmatches[i], p[i]);
    
    for(int i=0; i<p.size(); ++i){
        cout<<"第　"<<i<<"　层的指向信息如下："<<endl;
        for(int j=0; j<p[i].size(); ++j){
            cout<<p[i][j]<<endl;        
        }    
    }


    // 画出匹配对
    //Mat img_matches = DrawInlier1(img1, img2, kp1, kp2, matches, 1);
    //imshow("Matches", img_matches);    

    waitKey();

    return 0;
}

void maxpoint(vector<pair<int, int>> &m, vector<int> &p){
    //p.resize(8);
    //p.assign(8,0);
    
    for(int i=0; i<m.size(); ++i){
        p[kp2[m[i].second].octave]++;    
    }
            
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


