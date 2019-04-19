#include "./src/utils.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
  if (argc != 4) {
    cerr << "Error introducing input arguments!" << endl;
    cerr << "The format needs to be: ./test_match img1 imgN H1toN" << endl;
    return -1;
  }

  cv::Mat img1, imgN;
  string img1File = argv[1];
  string imgNFile = argv[2];
  string HFile = argv[3];

  // Open the input image
  img1 = imread(img1File, 1);
  imgN = imread(imgNFile, 1);
  cv::Mat H1toN = read_homography(HFile);

  Ptr<ORB> orb = ORB::create(10000);
  
  // Timing information
  double t1 = 0.0, t2 = 0.0;
  double torb = 0.0, tmatch = 0.0;

  // Detect KAZE features in the images
  vector<cv::KeyPoint> kpts1, kptsN;
  cv::Mat desc1, descN;

  t1 = cv::getTickCount();
  orb->detectAndCompute(img1, cv::noArray(), kpts1, desc1);
  orb->detectAndCompute(imgN, cv::noArray(), kptsN, descN);
  t2 = cv::getTickCount();
  torb = 1000.0*(t2-t1) / cv::getTickFrequency();

  int nr_kpts1 = kpts1.size();
  int nr_kptsN = kptsN.size();

  // Match the descriptors using NNDR matching strategy
  vector<cv::DMatch> dmatches;
  vector<cv::Point2f> matches, inliers;
  BFMatcher matcher(NORM_HAMMING);
  
  t1 = cv::getTickCount();
  matcher.match(desc1, descN, dmatches); //最近邻
  matches2points_nndr(kpts1, kptsN, dmatches, matches);
  t2 = cv::getTickCount();
  tmatch = 1000.0*(t2-t1) / cv::getTickFrequency();

  // Compute the inliers using the ground truth homography
  float max_h_error = 2.5;
  compute_inliers_homography(matches, inliers, H1toN, max_h_error);

  // Compute the inliers statistics
  int nr_matches = matches.size()/2;
  int nr_inliers = inliers.size()/2;
  int nr_outliers = nr_matches - nr_inliers;
  float ratio = 100.0*((float) nr_inliers / (float) nr_matches);

  cout << "ORB Matching Results" << endl;
  cout << "*******************************" << endl;
  cout << "# Keypoints 1:                        \t" << nr_kpts1 << endl;
  cout << "# Keypoints N:                        \t" << nr_kptsN << endl;
  cout << "# Matches:                            \t" << nr_matches << endl;
  cout << "# Inliers:                            \t" << nr_inliers << endl;
  cout << "# Outliers:                           \t" << nr_outliers << endl;
  cout << "Inliers Ratio (%):                    \t" << ratio << endl;
  cout << "Time Detection+Description (ms):      \t" << torb << endl;
  cout << "Time Matching (ms):                   \t" << tmatch << endl;
  cout << endl;


  // Visualization
  cv::Mat img_com = cv::Mat(cv::Size(2*img1.cols, img1.rows), CV_8UC3);
  draw_keypoints(img1, kpts1);
  draw_keypoints(imgN, kptsN);
  draw_inliers(img1, imgN, img_com, inliers);

  cv::namedWindow("ORB Matching", cv::WINDOW_KEEPRATIO);
  cv::imshow("ORB Matching", img_com);
  cv::waitKey(0);

  return 1;
}

