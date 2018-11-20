# 使用`cv::inRange`的阈值转换操作
原理上一篇已经讲了。

## 代码分析
使用`cv::inRange`对图像进行阈值转换操作，其中
1. `thresgold_inRange.cpp`是对一副图像在RGB通道上进行阈值转换操作。
2. `thresgold_inRange1.cpp`是对摄像头输出的视频流在HSV通道上进行阈值转换操作。

## 要点分析
```cpp
void cv::inRange    (   InputArray  src,
InputArray  lowerb,
InputArray  upperb,
OutputArray     dst 
) 
/*
功能：如果src一个位置的像素值如果在lowerb与upperb对应位置像素值之间，则dst对应位置像素值为255(全１),否则dst对应位置像素值设为0.
src: 通常是一个图像mat
lowerb与upperb:　这两个序列维度一致，可以和src一样是mat，也可以是一个像素值，总之能够和src中像素比较大小即可。
dst: 输出的一个灰度图像。
*/
```
> `cv::inRange`主要是一个二值化的作用，可根据像素范围分割出想要的物体。
