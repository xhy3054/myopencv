#include <opencv2/opencv.hpp>
using namespace cv;
int main( int argc, char** argv )
{
 char* imageName = argv[1];
 Mat image;
 image = imread( imageName, IMREAD_COLOR );
 if( argc != 2 || !image.data )
 {
   printf( " No image data \n " );
   return -1;
 }
 Mat gray_image;
/*
Converts an image from one color space to another.
void cv::cvtColor   (   InputArray  src,
                        OutputArray     dst,
                        int     code,
                        int     dstCn = 0 
)   
Parameters
    src: input image: 8-bit unsigned, 16-bit unsigned ( CV_16UC... ), or single-precision floating-point.
    dst: output image of the same size and depth as src.
    code:    color space conversion code (see ColorConversionCodes).
    dstCn:   number of channels in the destination image; if the parameter is 0, the number of the channels is derived automatically from src and code.

*/
 cvtColor( image, gray_image, COLOR_BGR2GRAY );//默认opencv读入的是BGR顺序

/*
函数imwrite将图像保存到指定的文件。 基于文件扩展名选择图像格式。 使用此功能时，只能保存(指mat)8位（或PNG，JPEG 2000和TIFF情况下的16位无符号（CV_16U））单通道或3通道（带'BGR'通道顺序）图像。 如果格式，深度或通道顺序不同，请使用Mat :: convertTo和cv :: cvtColor在保存之前进行转换。 或者，使用通用FileStorage I / O函数将图像保存为XML或YAML格式。
使用此功能可以使用Alpha通道存储PNG图像。 为此，创建8位（或16位）4通道图像BGRA，其中alpha通道最后。 完全透明的像素应将alpha设置为0，完全不透明的像素应将alpha设置为255/65535。
bool cv::imwrite    (   const String &  filename,
                        InputArray  img,
                        const std::vector< int > &  params = std::vector< int >() 
)       
*/
 imwrite( "Gray_Image.jpg", gray_image );//第三个参数是一个参数列表，可以pushback一些特定指定要求
 namedWindow( imageName, WINDOW_AUTOSIZE );
 namedWindow( "Gray image", WINDOW_AUTOSIZE );
 imshow( imageName, image );
 imshow( "Gray image", gray_image );
 waitKey(0);
 return 0;
}
