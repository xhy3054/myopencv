# sobel锐化
这一节主要是展示
1. 使用opencv函数`Sobel()`生成一副图像的sobel锐化结果。
2. 使用opencv函数`Scharr()`生成更准确的sobel锐化结果。

## 基础知识
1. 其实sobel算子是一种空间滤波器，作用是**提取图像的边缘**。相同作用的还有拉普拉斯算子等。

2. sobel算子的原理是近似计算图像像素强度的**梯度**，而拉普拉斯算子的原理是近似计算图像像素强度的**二阶微分**。

## 程序说明
1. 首先设置一下函数的输入参数说明，功能说明
2. 读入图像，使用高斯滤波器滤掉噪声，并转成灰度图
3. 计算图像水平方向与垂直方向的梯度
4. 通过水平方向梯度的绝对值与垂直方向梯度的绝对值相加近似得到图像的梯度
5. 显示梯度代表的边沿效果

## opencv中提供的sobel锐化功能
1. 函数`cv::Sobel()`
```cpp
void cv::Sobel  (   InputArray  src,
                    OutputArray     dst,
                    int     ddepth,
                    int     dx,
                    int     dy,
                    int     ksize = 3,
                    double  scale = 1,
                    double  delta = 0,
                    int     borderType = BORDER_DEFAULT 
)   
```
---
上述函数参数中：
- src:      原图像
- dst:      输出图像
- ddepth:   输出图像深度类型，程序中设置成`CV_16S`来避免溢出
- dx:       x方向导数的阶数
- dy:       y方向导数的阶数
- ksize:    扩展的sobel卷积核的大小，能设置成1,3,5,7，并且有一个特殊的值-1,结果会生成一个3*3的Scharr卷积核，结果比3*3的Sobel卷积核更精确
- scale:    计算导数值的尺度因子
- delta:    在将结果存储到dst之前加到结果上的偏移值。

2. 函数`cv::Scharr`
```cpp

void cv::Scharr (   InputArray  src,
                    OutputArray     dst,
                    int     ddepth,
                    int     dx,
                    int     dy,
                    double  scale = 1,
                    double  delta = 0,
                    int     borderType = BORDER_DEFAULT 
)   
```
---
上述函数参数中：
- src:      原图像
- dst:      输出图像
- ddepth:   输出图像深度类型，程序中设置成`CV_16S`来避免溢出
- dx:       x方向导数的阶数
- dy:       y方向导数的阶数
- scale:    计算导数值的尺度因子
- delta:    在将结果存储到dst之前加到结果上的偏移值。

> 由上可知`Scharr(src_gray, grad_x, ddepth, 0, 1, scale, delta, BORDER_DEFAULT);`结果与`Sobel(src_gray, grad_y, ddepth, 0, 1, -1, scale, delta, BORDER_DEFAULT);`是一样的。

