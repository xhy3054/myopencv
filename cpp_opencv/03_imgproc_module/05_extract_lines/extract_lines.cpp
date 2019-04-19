/**
 * @file Morphology_3(Extract_Lines).cpp
 * @brief Use morphology transformations for extracting horizontal and vertical lines sample code
 * @author OpenCV team
 */

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

void show_wait_destroy(const char* winname, cv::Mat img);

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    //! [load_image]
    CommandLineParser parser(argc, argv, "{@input | ../../data/src.png | input image}");
    Mat src = imread(parser.get<String>("@input"), IMREAD_COLOR);
    if (src.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    // Show source image
    imshow("src", src);
    //! [load_image]

    //! [gray]转成灰度图
    // Transform source image to gray if it is not already
    Mat gray;

    if (src.channels() == 3)
    {
        cvtColor(src, gray, COLOR_BGR2GRAY);
    }
    else
    {
        gray = src;
    }

    // Show gray image
    show_wait_destroy("gray", gray);
    //! [gray]

    //! [bin]抓成二值图
    // Apply adaptiveThreshold at the bitwise_not of gray, notice the ~ symbol
    Mat bw;
    adaptiveThreshold(~gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);

    // Show binary image
    show_wait_destroy("binary", bw);
    //! [bin]

    //! [init]
    // Create the images that will use to extract the horizontal and vertical lines
    Mat horizontal = bw.clone();
    Mat vertical = bw.clone();
    //! [init]

    //! [horiz]创建提取水平线的卷积核（结构元素）
    // Specify size on horizontal axis
    int horizontal_size = horizontal.cols / 30;

    // Create structure element for extracting horizontal lines through morphology operations
    Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontal_size, 1));

    // Apply morphology operations先腐蚀再膨胀
    erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
    dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));

    // Show extracted horizontal lines
    show_wait_destroy("horizontal", horizontal);
    //! [horiz]

    //! [vert]创建提取垂直线的卷积核（结构元素）
    // Specify size on vertical axis
    int vertical_size = vertical.rows / 30;

    // Create structure element for extracting vertical lines through morphology operations
    Mat verticalStructure = getStructuringElement(MORPH_RECT, Size(1, vertical_size));

    // Apply morphology operations先腐蚀再膨胀
    erode(vertical, vertical, verticalStructure, Point(-1, -1));
    dilate(vertical, vertical, verticalStructure, Point(-1, -1));

    // Show extracted vertical lines
    show_wait_destroy("vertical", vertical);
    //! [vert]

    //! [smooth]
    // Inverse vertical image
    bitwise_not(vertical, vertical);
    show_wait_destroy("vertical_bit", vertical);

	//１，２提取图像的轮廓，３，４，５与平滑图像
    // Extract edges and smooth image according to the logic
    // 1. extract edges
    // 2. dilate(edges)
    // 3. src.copyTo(smooth)
    // 4. blur smooth img
    // 5. smooth.copyTo(src, edges)

    // Step 1提取边沿轮廓
    Mat edges;
    adaptiveThreshold(vertical, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, -2);
    show_wait_destroy("edges", edges);

    // Step 2膨胀一下
    Mat kernel = Mat::ones(2, 2, CV_8UC1);
    dilate(edges, edges, kernel);
    show_wait_destroy("dilate", edges);

    // Step 3
    Mat smooth;
    vertical.copyTo(smooth);

    // Step 4使用均值滤波器平滑一下
    blur(smooth, smooth, Size(2, 2));

    // Step 5
    smooth.copyTo(vertical, edges);

    // Show final result
    show_wait_destroy("smooth - final", vertical);
    //! [smooth]

    return 0;
}

void show_wait_destroy(const char* winname, cv::Mat img) {
    imshow(winname, img);
    moveWindow(winname, 500, 0);
    waitKey(0);
    destroyWindow(winname);
}
