#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>

// Defining the dimensions of checkerboard
int CHECKERBOARD[2]{6,9}; 

int main()
{
  // Creating vector to store vectors of 3D points for each checkerboard image
  // 此向量用来存储多张棋盘格图片的3d点
  std::vector<std::vector<cv::Point3f> > objpoints;

  // Creating vector to store vectors of 2D points for each checkerboard image
  // 此向量用来存储多张棋盘格图片的2d点
  std::vector<std::vector<cv::Point2f> > imgpoints;

  // Defining the world coordinates for 3D points
  // 定义3d点的世界坐标
  std::vector<cv::Point3f> objp;
  for(int i{0}; i<CHECKERBOARD[1]; i++)
  {
    for(int j{0}; j<CHECKERBOARD[0]; j++)
      objp.push_back(cv::Point3f(j,i,0));
  }


  // Extracting path of individual image stored in a given directory
  // 此向量用来存储图片序列中每张图的路径
  std::vector<cv::String> images;
  // Path of the folder containing checkerboard images
  // 包含棋盘格图片的文件夹
  std::string path = "./images/*.jpg";

  cv::glob(path, images);

  cv::Mat frame, gray;
  // vector to store the pixel coordinates of detected checker board corners 
  // 此向量用来存储检测到的棋盘角点的像素坐标
  std::vector<cv::Point2f> corner_pts;
  bool success;

  // Looping over all the images in the directory
  // 循环文件夹下的所有图片
  for(int i{0}; i<images.size(); i++)
  {
    // 读取图像
    frame = cv::imread(images[i]);
    cv::cvtColor(frame,gray,cv::COLOR_BGR2GRAY); //转为灰度图

    // Finding checker board corners
    // If desired number of corners are found in the image then success = true  
    // 检测棋盘格角点
    success = cv::findChessboardCorners(gray,cv::Size(CHECKERBOARD[0],CHECKERBOARD[1]), corner_pts, cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_FAST_CHECK | cv::CALIB_CB_NORMALIZE_IMAGE);

    /*
     * If desired number of corner are detected,
     * we refine the pixel coordinates and display 
     * them on the images of checker board
    */
    if(success)
    {
      cv::TermCriteria criteria(cv::TermCriteria::EPS | cv::TermCriteria::MAX_ITER, 30, 0.001);

      // refining pixel coordinates for given 2d points.
      cv::cornerSubPix(gray,corner_pts,cv::Size(11,11), cv::Size(-1,-1),criteria);

      // Displaying the detected corner points on the checker board
      cv::drawChessboardCorners(frame, cv::Size(CHECKERBOARD[0],CHECKERBOARD[1]), corner_pts,success);

      objpoints.push_back(objp);
      imgpoints.push_back(corner_pts);
    }

    cv::imshow("Image",frame);
    cv::waitKey(0);
  }

  cv::destroyAllWindows();

  cv::Mat cameraMatrix,distCoeffs,R,T;

  /*
   * Performing camera calibration by 
   * passing the value of known 3D points (objpoints)
   * and corresponding pixel coordinates of the 
   * detected corners (imgpoints)
  */
  cv::calibrateCamera(objpoints, imgpoints,cv::Size(gray.rows,gray.cols),cameraMatrix,distCoeffs,R,T);

  std::cout << "cameraMatrix : " << cameraMatrix << std::endl;
  std::cout << "distCoeffs : " << distCoeffs << std::endl;
  std::cout << "Rotation vector : " << R << std::endl;
  std::cout << "Translation vector : " << T << std::endl;

  return 0;
}
