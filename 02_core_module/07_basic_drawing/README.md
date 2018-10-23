# 画图
这个程序主要是演示一下如何使用opencv库来进行一些基本的绘图（通过基本的直线、椭圆、多边形）。

## 拓展知识
opencv库中定义的两种数据结构
### cv::Point
代表一个2D点，我们可以用它表示一个平面上的坐标，如下：
```cpp
Point pt;
pt.x = 10;
pt.y = 8;
//或者这样
Point pt =  Point(10, 8);
```

### cv::Scalar 
1. 这是一个四元素向量，在opencv中常用来表示图像中的一个像素（经常只用到前三）；

2. 在这个程序中，我们用它来表示一个`BGR`的颜色值，没有用到它的最后一维；

如果我们如下定义一个`Scalar`:
```cpp
Scalar( a, b, c );
``` 
则其代表一个`BGR`的色彩，其中：`blue = a; green = b; red = c;`

## 图像处理模块（imgproc）中常见的画图函数的使用
更多更详细看[官网](https://docs.opencv.org/3.4.1/d6/d6e/group__imgproc__draw.html#ga7078a9fae8c7e7d13d24dac2520ae4a2)
### 画线段
```cpp
//The function line draws the line segment between pt1 and pt2 points in the image. 
void cv::line	(	InputOutputArray 	img,
Point 	pt1,
Point 	pt2,
const Scalar & 	color,
int 	thickness = 1,
int 	lineType = LINE_8,
int 	shift = 0 
)	
/*
Parameters
img	Image.
pt1	First point of the line segment.
pt2	Second point of the line segment.
color	Line color.
thickness	Line thickness.
lineType	Type of the line. See LineTypes.
shift	Number of fractional bits in the point coordinates.

*/
```
### 画长方形
```cpp
//The function cv::rectangle draws a rectangle outline or a filled rectangle whose two opposite corners are pt1 and pt2.
void cv::rectangle	(	InputOutputArray 	img,
Point 	pt1,
Point 	pt2,
const Scalar & 	color,
int 	thickness = 1,
int 	lineType = LINE_8,
int 	shift = 0 
)	
/*
Parameters
img	Image.
pt1	Vertex of the rectangle.
pt2	Vertex of the rectangle opposite to pt1 .
color	Rectangle color or brightness (grayscale image).
thickness	Thickness of lines that make up the rectangle. Negative values, like FILLED, mean that the function has to draw a filled rectangle.
lineType	Type of the line. See LineTypes
shift	Number of fractional bits in the point coordinates.
*/
```

### 画椭圆
有点复杂，具体看[官网](https://docs.opencv.org/3.4.1/d6/d6e/group__imgproc__draw.html#ga28b2267d35786f5f890ca167236cbc69)
```cpp
//Draws a simple or thick elliptic arc or fills an ellipse sector
void cv::ellipse	(	InputOutputArray 	img,
Point 	center,
Size 	axes,
double 	angle,
double 	startAngle,
double 	endAngle,
const Scalar & 	color,
int 	thickness = 1,
int 	lineType = LINE_8,
int 	shift = 0 
)	
/*
Parameters
img	Image.
center	Center of the ellipse.
axes	Half of the size of the ellipse main axes.
angle	Ellipse rotation angle in degrees.
startAngle	Starting angle of the elliptic arc in degrees.
endAngle	Ending angle of the elliptic arc in degrees.
color	Ellipse color.
thickness	Thickness of the ellipse arc outline, if positive. Otherwise, this indicates that a filled ellipse sector is to be drawn.
lineType	Type of the ellipse boundary. See LineTypes
shift	Number of fractional bits in the coordinates of the center and values of axes.
*/
```

### 画多边形


### 画填充的多边形

### 画圆
```cpp
//The function cv::circle draws a simple or filled circle with a given center and radius.
void cv::circle	(	InputOutputArray 	img,
Point 	center,
int 	radius,
const Scalar & 	color,
int 	thickness = 1,
int 	lineType = LINE_8,
int 	shift = 0 
)	
/*
Parameters
img	Image where the circle is drawn.
center	Center of the circle.
radius	Radius of the circle.
color	Circle color.
thickness	Thickness of the circle outline, if positive. Negative values, like FILLED, mean that a filled circle is to be drawn.
lineType	Type of the circle boundary. See LineTypes
shift	Number of fractional bits in the coordinates of the center and in the radius value.
*/
```

