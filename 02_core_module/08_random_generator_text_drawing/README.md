# 程序说明
这个程序主要是用`imgproc`库在一个固定大小的窗口上，
1. 随机画１００条线段;
2. 随机画１００个长方形；
3. 随机画１００个椭圆；
4. 随机画１００个多边形（空心）；
5. 随机画１００个填充多边形；
6. 随机画１００个圆；
7. 随机打印字符串"Testing text rendering"的１００种形式；
8. 在原图基础上新建一张相同的图并显示，在中间打印字符串"OpenCV forever!"，并渐变颜色。

# 新知识
## 随机数生成器 RNG　类型
定义在`core`模块中，它的对象有两种构造方式：
```cpp
//1. cv::RNG::RNG	(		)	
RNG rng1;

//2. cv::RNG::RNG	(	uint64 	state	)
RNG rng2( 0xFFFFFFFF );
```
***
上述是`RNG`对象的两种构造方式，区别是第一种使用了默认的`2^32-1`来初始化。此处需要说明的是，如果第二种方式传入参数０，为了避免产生全０的随机序列，程序会使用默认值进行构造。

随机数生成如下：
```cpp
//使用rng随机在默认范围随机生成一个值，此处先转成unsigned型然后对一个int变量进行赋值
int icolor = (unsigned) rng;

//在１～１００间随机生成一个数赋值给ｉ
int i  = rng.uniform( 1, 100 );
```

## 在一张图上打印字符串
使用函数`putText`(定义在improc模块)。
```cpp
//The function cv::putText renders the specified text string in the image. Symbols that cannot be rendered using the specified font are replaced by question marks.
void cv::putText	(	InputOutputArray 	img,
const String & 	text,
Point 	org,
int 	fontFace,
double 	fontScale,
Scalar 	color,
int 	thickness = 1,
int 	lineType = LINE_8,
bool 	bottomLeftOrigin = false 
)	
/*
Parameters
img	Image.
text	Text string to be drawn.
org	Bottom-left corner of the text string in the image.
fontFace	Font type, see HersheyFonts.
fontScale	Font scale factor that is multiplied by the font-specific base size.
color	Text color.
thickness	Thickness of the lines used to draw a text.
lineType	Line type. See LineTypes
bottomLeftOrigin	When true, the image data origin is at the bottom-left corner. Otherwise, it is at the top-left corner.
*/
```


