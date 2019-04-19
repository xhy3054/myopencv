# harris角点检测
在这篇教程中，我们主要关注两点：
1. harris角点的原理
2. 如何使用opencv函数`cv::cornerHarris`检测角点

## 原理
太多了，写在了[博客里](https://xhy3054.github.io/corner-detect-harris/)

## opencv接口代码使用分析
1. 读入图像
2. 创建窗口，添加一个滑动棒，调整阈值
3. harris检测角点，并画圆

### cv::cornerHarris函数
```cpp
void cv::cornerHarris	(	InputArray 	src,
                            OutputArray 	dst,
                            int 	blockSize,
                            int 	ksize,
                            double 	k,
                            int 	borderType = BORDER_DEFAULT 
)	
```
---
- src – 输入的单通道8-bit或浮点图像。
- dst – 存储着Harris角点响应的图像矩阵，大小与输入图像大小相同，是一个浮点型矩阵。
- blockSize – 邻域大小。
- ksize – sobel算子的卷积核尺寸。
- k – 响应公式中的，参数α(见博客里)。
- boderType – 边界处理的类型。



