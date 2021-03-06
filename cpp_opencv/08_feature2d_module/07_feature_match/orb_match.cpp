#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace cv;
float match_ratio_ = 2.0;
void filter(vector<DMatch>& matches1, vector<DMatch>& matches2);
Mat DrawInlier(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type);
Mat DrawInlier1(Mat &src1, Mat &src2, vector<KeyPoint> &kpt1, vector<KeyPoint> &kpt2, vector<DMatch> &inlier, int type);
int main(){
    Mat img1 = imread("../data/05.jpg");
    Mat img2 = imread("../data/06.jpg");
    // 设置提取器
    vector<KeyPoint> kp1, kp2;
    Mat ds1, ds2;
    Ptr<ORB> orb = ORB::create(5000);
    orb->setFastThreshold(0);
    // 提取特征点并计算描述子
    orb->detectAndCompute(img1, Mat(), kp1, ds1);
    orb->detectAndCompute(img2, Mat(), kp2, ds2);

    
/*
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::BRUTEFORCE);
    matcher->match(ds1,ds2,matches);
*/
    vector<DMatch> matches_bf, matches_flann,matches_bf1, matches_flann1;
    vector<vector<DMatch>> matches_knn;
    //Mat img_matches_bf, img_matches_flann;

    // 特征匹配方法一，暴力匹配，汉明距离
    double t;
    t = (double)getTickCount();

	BFMatcher bfmatcher(NORM_HAMMING);
	bfmatcher.match(ds1, ds2, matches_bf);

    t = 1000*((double)getTickCount() - t)/getTickFrequency();

    cout << "暴力匹配方法使用了"
         << t << " milliseconds."<< endl;
    
    // 筛选并画出匹配对
    filter(matches_bf, matches_bf1);
    //drawMatches(img1, kp1, img2, kp2, matches_bf1, img_matches_bf);
    Mat img_matches_bf = DrawInlier1(img1, img2, kp1, kp2, matches_bf1, 1);
    imshow("Matches_bf", img_matches_bf);

    // 特征匹配方法二，快速最近邻
    // 在使用这种匹配方法之前需要将描述子转成32位浮点型
    t = (double)getTickCount();

    if(ds1.type()!=CV_32F) { 
        ds1.convertTo(ds1, CV_32F); 
    } 
    if(ds2.type()!=CV_32F) { 
        ds2.convertTo(ds2, CV_32F); 
    }     
    FlannBasedMatcher flann_matcher;
    flann_matcher.match(ds1, ds2, matches_flann);

    t = 1000*((double)getTickCount() - t)/getTickFrequency();

    cout << "快速近似最近邻方法使用了"
         << t << " milliseconds."<< endl;
     
    // 筛选并画出匹配对
    filter(matches_flann, matches_flann1);

    //drawMatches(img1, kp1, img2, kp2, matches_flann1, img_matches_flann);
    Mat img_matches_flann = DrawInlier1(img1, img2, kp1, kp2, matches_flann1, 1);
    imshow("Matches_flann", img_matches_flann);
    waitKey();


    return 0;
}

/*
 * 此处的筛选方法是将每个匹配的距离与所有匹配的最小距离进行比对，
 * 如果比最小距离的match_ratio倍小或者小于30，就保留这个匹配。
 */
void filter(vector<DMatch>& matches1, vector<DMatch>& matches2){
    // select the best matches 找到最小的一个距离（使用了lambda表达式）
    float min_dis1 = std::min_element (
                        matches1.begin(), matches1.end(),
                        [] ( const cv::DMatch& m1, const cv::DMatch& m2 )
    {
        return m1.distance < m2.distance;
    } )->distance;
    // 根据所有匹配中的最佳匹配与match_ratio_来选择是否将这个匹配放入feature_matches_
    matches2.clear();
    for ( cv::DMatch& m : matches1 )
    {
        if ( m.distance < max<float> ( min_dis1*match_ratio_, 30.0 ) )
        {
            matches2.push_back(m);
        }
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
