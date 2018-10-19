# Mat类

很久以前（大概两千年左右），opencv还只是提供ｃ接口的一个库。那时它使用一种ｃ语言的结构体叫做`IplImage`来存储图像。后来实在是受不了了，因为使用ｃ语言接口的用户需要自己来管理内存，实在特别麻烦并且容易出错。opencv维护者们就使用c++又翻新了一遍opencv库。新版本中（2.0往后）支持使用Mat来存储图像。

## Mat的组成
Mat主要由两部分组成：
1. 矩阵头信息：主要是矩阵大小、矩阵存储方法、矩阵地址等，矩阵头大小是固定的；

2. 图像像素矩阵的指针对象，使用类似智能指针`shared_ptr`的方法来管理内存；

## Mat对象的拷贝问题
Mat对象的拷贝构造函数、拷贝赋值运算符（重载的`=`）都是使用的浅拷贝，即只拷贝了指针的值，但是它们指向共同的一片区域。

```cpp
Mat A, C;                          // creates just the header parts
A = imread(argv[1], IMREAD_COLOR); // here we'll know the method used (allocate matrix)
Mat B(A);                                 // Use the copy constructor
C = A;                                    // Assignment operator
Mat D (A, Rect(10, 10, 100, 100) ); // using a rectangle　Ｄ中的指针指向Ａ指针指向矩阵的一片长方形区域
Mat E = A(Range::all(), Range(1,3)); // using row and column boundaries　也是指向一部分区域，第一个参数代表行（全部行），第二个参数代表列（１～３列）
```

如上，A、B、C三个对象最终指向的都是同一片内存区域。即对它们三个任何一个的图像进行修改，另外两个也修改了。如果想要进行深拷贝，可以使用Mat类自带的两个函数：`cv::Mat::clone()`与`cv::Mat::copyTo()`，使用方法如下：

```cpp
Mat F = A.clone();
Mat G;
A.copyTo(G);
```

现在，Ａ、Ｆ、Ｇ三个Mat对象分别管理属于自己的图像矩阵内存，不会互相干扰。

## Mat对象的存储方法
存储方法主要受两个参数影响：
1. 颜色空间：决定了使用何种方法编码一个像素的颜色，比如灰度空间单通道描述、RGB三通道红绿蓝描述、RGBD四通道红绿蓝透明度四通道描述等等；

2. 数据类型：使用何种数据类型来描述一个通道，如unsigned char(8位0~255)、signed char(8位-128~127)、float(32位)、double(64位)等，越大则图像占用内存越大，可描述的色彩越细微；

颜色空间主要有RGB、HSV、HLS、YCrCb等，想了解自己再查书吧。值得一提的是**opencv标准显式中使用的RGB其实是BGR**，即翻转了一下顺序。同时，RGB转灰度空间使用了如下公式：

    Gray = R*0.299 + G*0.587 + B*0.114

> 无论Mat是几通道的颜色空间，其矩阵都是两维的。只是两维矩阵的每一个元素的大小是`通道数*数据类型的大小`，即在一个元素中，各通道依次存储。

## Mat对象的创建与显示
Mat的创建有好多方式，同时它重载了`<<`，使得可以直接用`cout`进行输出显示，`mat_creat_print.cpp`中实现了各种创建与显示的方法，可以查看代码或者直接运行查看结果。



