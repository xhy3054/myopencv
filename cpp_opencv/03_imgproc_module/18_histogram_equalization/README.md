# 直方图均衡
本节主要有两个任务：
1. 讲清楚图像直方图的含义与用途
2. 演示如何使用opencv提供的函数`cv::equalizeHist()`对一幅图像进行直方图均衡

## 理论
### 图像的直方图是什么
1. 它是图像像素分布的一种图形化表示
2. 它量化了每个强度值的像素数量

### 什么是直方图均衡化
1. 这是一种通过对图像的直方图进行重映射以**增强图像对比度**的方法。
2. 所谓的对图像的直方图进行重映射指的是，将原本的局部比较拥挤的亮度分布重新映射到另一种整体上更加均匀的亮度分布上。
![row](picture/row.jpg)
![after_operation](picture/after_operation.jpg)

> 上述图像是应用说明图解，更加详细的说明，可以查看图像处理的书籍。

### 直方图均衡化的实现
1. 所谓的对图像的直方图进行重映射指的是，将原本的局部比较拥挤的亮度分布重新映射到另一种整体上更加均匀的亮度分布上。
2. 为了完成均衡化期望的效果，我们使用分布密度的累计分布函数形式的重映射，使得各个直方图柱之间间隔一致，并且最亮的是１，最暗的是０

## 程序分析
1. 加载图片
2. 将原图转成灰度格式
3. 通过opencv函数`cv::equalizeHist()`对图像进行直方图均衡化处理
4. 显示原图与处理后的图


