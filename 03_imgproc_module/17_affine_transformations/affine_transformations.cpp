/**
 * @function Geometric_Transforms_Demo.cpp
 * @brief Demo code for Geometric Transforms
 * @author OpenCV team
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/**
 * @function main
 */
int main( int argc, char** argv )
{
    //! [Load the image]
    CommandLineParser parser( argc, argv, "{@input | ../../data/lena.jpg | input image}" );
    Mat src = imread( parser.get<String>( "@input" ) );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    //! [Load the image]

    // 设置仿射变换前后的三对点
    Point2f srcTri[3];
    srcTri[0] = Point2f( 0.f, 0.f );
    srcTri[1] = Point2f( src.cols - 1.f, 0.f );
    srcTri[2] = Point2f( 0.f, src.rows - 1.f );

    Point2f dstTri[3];
    dstTri[0] = Point2f( 0.f, src.rows*0.33f );
    dstTri[1] = Point2f( src.cols*0.85f, src.rows*0.25f );
    dstTri[2] = Point2f( src.cols*0.15f, src.rows*0.7f );
    //! [Set your 3 points to calculate the  Affine Transform]

    // 使用前面的三对点推出放射变换矩阵
    Mat warp_mat = getAffineTransform( srcTri, dstTri );
	cout<<"the affine_matrix is:\n"<<warp_mat<<endl;
    //! [Get the Affine Transform]

    // 应用仿射变换
    /// Set the dst image the same type and size as src
    Mat warp_dst = Mat::zeros( src.rows, src.cols, src.type() );

    warpAffine( src, warp_dst, warp_mat, warp_dst.size() );
    // 应用仿射变换

    /** Rotating the image after Warp */

    // 计算一个以中心为原点，旋转-50度，尺度缩小到0.6的旋转矩阵
    Point center = Point( warp_dst.cols/2, warp_dst.rows/2 );
    double angle = -50.0;	//注意：opencv中正角度是逆时针的，所以此处是顺时针旋转５０°
    double scale = 0.6;
    //! [Compute a rotation matrix with respect to the center of the image]

    //! [Get the rotation matrix with the specifications above]
    Mat rot_mat = getRotationMatrix2D( center, angle, scale );
	cout<<"the rot_mat= \n"<<rot_mat<<endl;
    //! [Get the rotation matrix with the specifications above]

    // 旋转
    Mat warp_rotate_dst;
    warpAffine( warp_dst, warp_rotate_dst, rot_mat, warp_dst.size() );
    //! [Rotate the warped image]

    //! [Show what you got]
    imshow( "Source image", src );
    imshow( "Warp", warp_dst );
    imshow( "Warp + Rotate", warp_rotate_dst );
    //! [Show what you got]

    //! [Wait until user exits the program]
    waitKey();
    //! [Wait until user exits the program]

    return 0;
}
