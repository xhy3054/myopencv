#include <opencv2/opencv.hpp>
#include <iostream>
//#include <array>
#include <vector>
using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    const int seed = argc > 1 ? std::stoi(argv[1]) : 0;
    srand(seed);

    // generate space 生成二维空间，一张图
    const int width = 500;
    const int height = 500;
    cv::Mat img = cv::Mat::zeros(cv::Size(width, height), CV_8UC3);

    // generate points  随机生成二维点集，并在二维空间上画出
    const int npoints = 5000;
    std::vector<cv::Point2f> points(npoints);
    for (int i = 0; i < npoints; i++)
    {
        points[i].x = rand() % width;
        points[i].y = rand() % height;
    }

    for (const auto& pt : points){
        cout<<pt<<endl;
        cv::circle(img, pt, 1, cv::Scalar(0, 255, 255), -1);
    }
    cv::Mat points_mat(npoints,2,CV_32FC1);
    for(int i=0; i<npoints; ++i){
        points_mat.at<float>(i,0)=points[i].x;
        points_mat.at<float>(i,1)=points[i].y;
    }
    // build k-d tree kmeans索引
//    kdt::KDTree<MyPoint> kdtree(points);
    flann::Index kdtree(points_mat, cv::flann::KMeansIndexParams());

    // generate query (center of the space)  生成图中心点，并在二维空间上画出
    //const MyPoint query(0.5 * width, 0.5 * height);
    cv::Point2f query(0.5*width, 0.5*height);
    cv::circle(img, query, 1, cv::Scalar(0, 0, 255), -1);
    cv::Mat query1(1,2,CV_32FC1);
    query1.at<float>(0,0) = 0.5*width;
    query1.at<float>(0,1) = 0.5*height;
    cout<<"query1 cols = "<<query1.cols<<endl;
    
    
/**************** k-nearest neigbors search k近邻搜索**************/
    int k = 20;
    cv::Mat nearest_index;
    cv::Mat nearest_dist;
    kdtree.knnSearch(query1, nearest_index, nearest_dist, k);
    cout<<"nearest_index = "<<endl<<nearest_index<<endl;
    cout<<"nearest_index "<<endl<<"rows = "<<nearest_index.rows<<endl<<"cols = "<<nearest_index.cols<<endl;
    cout<<"nearest_dist = "<<endl<<nearest_dist<<endl;

    cv::Mat I1 = img.clone();
    for (int i=0; i<k; ++i)
    {
        cout<<"第 "<<i<<" 个最近邻点是 "<<"第 "<<nearest_index.at<int>(0,i)<<" 个点，为"<<points[nearest_index.at<int>(0,i)]<<endl;
        cv::circle(I1, points[nearest_index.at<int>(0,i)], 1, cv::Scalar(255, 255, 0), -1);
        cv::line(I1, query, points[nearest_index.at<int>(0,i)], cv::Scalar(0, 0, 255));
    }
    cv::imshow("K-nearest neigbors search (k = 10)", I1);
/**************** radius neigbors search ****************************/
/*
    double radius = 100;
    cv::Mat nearest_index1;
    cv::Mat nearest_dist1;
    kdtree.radiusSearch(query1, nearest_index1, nearest_dist1, radius, 10); 
    cv::Mat I2 = img.clone();
    int cols = nearest_index1.cols;
    cout<<"cols is "<<cols<<endl;
    cout<<"nearest_index1 is "<<endl<<nearest_index1<<endl;
    cout<<"nearest_dist1 is "<<endl<<nearest_dist1<<endl;
    for(int i=0; i<cols; ++i){
        cv::circle(I2, points[nearest_index1.at<int>(0,i)], 1, cv::Scalar(255, 255, 0), -1);
        cv::line(I2, query, points[nearest_index1.at<int>(0,i)], cv::Scalar(0, 0, 255));
    }    
    cv::imshow("Radius neighbors search", I2);
*/
    cv::waitKey(0);

    return 0;
}
