# 拉普拉斯变换
本节主要需要完成的是使用`cv::Laplacian()`函数完成对拉普拉斯变换的离散模拟。

## 原理
上节sobel算子那里已经说过了，拉普拉斯变换的主要思想是通过近似求解图像像素强度的**二阶微分**来突出图像的边缘。

## 程序分析
1. 加载图像
2. 通过高斯滤波器来滤除噪声，并且将原彩色图转换成灰度图
3. 对这个灰度图应用拉普拉斯操作，并且存储输出图
4. 展示结果

## opencv中的`cv::Laplacian()`函数
```cpp
void cv::Laplacian  (   InputArray  src,
                        OutputArray     dst,
                        int     ddepth,
                        int     ksize = 1,
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
- ksize:    扩展的sobel卷积核的大小，能设置成1,3,5,7，并且有一个特殊的值-1,结果会生成一个3*3的Scharr卷积核，结果比3*3的Sobel卷积核更精确
- scale:    计算导数值的尺度因子
- delta:    在将结果存储到dst之前加到结果上的偏移值。

> opencv中使用`cv::Laplacian()`函数来实现拉普拉斯变换，因为是计算是图像的导数，所以在这个函数内部其实是调用了上一节的sobel操作来执行二阶导的计算的。
