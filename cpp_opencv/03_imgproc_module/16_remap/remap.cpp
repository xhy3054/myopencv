/**
 * @function Remap_Demo.cpp
 * @brief Demo code for Remap
 * @author Ana Huaman
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;

/// Function Headers
void update_map( int &ind, Mat &map_x, Mat &map_y );

/**
 * @function main
 */
int main(int argc, const char** argv)
{
    CommandLineParser parser(argc, argv, "{@image |../../data/wechat.jpg|input image name}");
    std::string filename = parser.get<std::string>(0);
    // 加载图像
    /// Load the image
    Mat src = imread( filename, IMREAD_COLOR );
    if (src.empty())
    {
        std::cout << "Cannot read image: " << filename << std::endl;
        return -1;
    }
    //! [Load]

    // 创建目标图像（与源图像尺寸完全相同），map_x,map_y二维尺寸与源图像相同，元素为浮点数类型
    /// Create dst, map_x and map_y with the same size as src:
    Mat dst(src.size(), src.type());
    Mat map_x(src.size(), CV_32FC1);
    Mat map_y(src.size(), CV_32FC1);
    //! [Create]

    //! [Window]
    /// Create window
    const char* remap_window = "Remap demo";
    namedWindow( remap_window, WINDOW_AUTOSIZE );
    //! [Window]

    // 循环
    /// Index to switch between the remap modes
    int ind = 0;
    for(;;)
    {
		// 根据不同模式生成不同的map_x与map_y
        /// Update map_x & map_y. Then apply remap
        update_map(ind, map_x, map_y);
        remap( src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0) );

        /// Display results
        imshow( remap_window, dst );

        /// Each 1 sec. Press ESC to exit the program
        char c = (char)waitKey( 1000 );
        if( c == 27 )
        {
            break;
        }
    }
    //! [Loop]
    return 0;
}

/**
 * @function update_map
 * @brief Fill the map_x and map_y matrices with 4 types of mappings
 */
//! [Update]
void update_map( int &ind, Mat &map_x, Mat &map_y )
{
    for( int i = 0; i < map_x.rows; i++ )
    {
        for( int j = 0; j < map_x.cols; j++ )
        {
            switch( ind )
            {
            case 0:　//缩小一倍，多余区域像素取原图（０,０）处像素值
                if( j > map_x.cols*0.25 && j < map_x.cols*0.75 && i > map_x.rows*0.25 && i < map_x.rows*0.75 )
                {
                    map_x.at<float>(i, j) = 2*( j - map_x.cols*0.25f ) + 0.5f;//加0.5确保值大于０一直
                    map_y.at<float>(i, j) = 2*( i - map_x.rows*0.25f ) + 0.5f;
                }
                else
                {
                    map_x.at<float>(i, j) = 0;
                    map_y.at<float>(i, j) = 0;
                }
                break;
            case 1:　//上下翻转
                map_x.at<float>(i, j) = (float)j;
                map_y.at<float>(i, j) = (float)(map_x.rows - i);
                break;
            case 2:	//左右对称
                map_x.at<float>(i, j) = (float)(map_x.cols - j);
                map_y.at<float>(i, j) = (float)i;
                break;
            case 3:	//上下翻转并且左右对称
                map_x.at<float>(i, j) = (float)(map_x.cols - j);
                map_y.at<float>(i, j) = (float)(map_x.rows - i);
                break;
            default:
                break;
            } // end of switch
        }
    }
    ind = (ind+1) % 4;
}
//! [Update]
