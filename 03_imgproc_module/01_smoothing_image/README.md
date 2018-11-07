# 图像平滑操作
- 平滑操作也叫模糊操作，是十分常见的图像处理操作
- 使用平滑操作会有很多缘由，本文的目的是用其减少噪声。
- 平滑操作通常就是使用**滤波操作**，即使用线性卷积核对图像进行掩膜操作。在`02-03`（core部分）已经讲过掩膜操作哦。
- 有很**多种滤波器**，本文会提最常见的几种｀

## 归一化滤波器
窗口内每个元素加权值一样做平均操作。

## 高斯滤波器
- 最有用的滤波器（不是最快的）。
- 使用高斯核对图像进行卷积操作。
- (想像一下高斯函数图像)高斯核中心的元素权重占比最大，越靠外衰减越大。

## 中值滤波器
使用邻近窗函数系数中的中值作为本点的值。

## 双边滤波器
- 上述讲的滤波器除了减少噪声外也会将边缘进行一定程度的平滑，这是我们不想要的，双边滤波器可以在消除噪声的同时**保留边缘**。
- 双边滤波器基于高斯滤波器，其邻近像素的权值由两部分组成。
    - 第一部分是高斯滤波器加权值
    - 第二部分考虑了相邻像素与评估像素之间的强度差异。
- 更多[双边滤波器](http://homepages.inf.ed.ac.uk/rbf/CVonline/LOCAL_COPIES/MANDUCHI1/Bilateral_Filtering.html)内容。

## 程序说明
1. 载入图像
2. 依次应用上述四种滤波器并展示效果

> 在图像处理模块（imgproc）中，四种滤波器都实现好了，直接调用即可。