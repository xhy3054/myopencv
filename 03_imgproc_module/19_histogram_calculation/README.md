# 计算直方图
本节的任务主要有三个：
1. 演示使用函数`cv::split()`对一幅图像进行各个通道的分离。 
2. 演示使用函数`cv::calcHist()`对一幅图像进行直方图序列的计算。
3. 演示使用函数`cv::normalize()`对数组进行标准化，让统计结果符合指定的范围。

## 理论
### 直方图是什么
1. 直方图是预定义一系列不同的容器，然后把分别满足不同容器的个体的数量进行统计。
2. 由上面描述我们知道，图像的直方图不一定是对图像的像素强度的统计结果，也可以是其他特征的统计结果。
3. 一般来说，直方图会有如下部分:
    - dims:     想要进行统计的参数的数量，一般灰度图的直方图都是`dims=1`，因为只有一个统计参数（像素强度值）
    - bins:     分类容器的数量，比如说`[0~255]`的区域每15作为一个容器统计每个区域的像素数，共16个容器，则`bins=16`
    - range:    参数的取值范围，比如像素强度取值范围一般是[0~255]
4. 此处说明一下，多个参数的直方图统计是联合统计。比如说两个参数的直方图统计就会是一个三维直方图，两个参数分别代表x轴、y轴。而z轴代表（x,y）这个箱子里元素的数量。

## 程序分析
1. 加载图片
2. 使用函数`cv::split()`将图片分离成R、G、B三个灰度图
3. 通过函数`cv::calcHist`分别计算上述三个一通道的灰度图的直方图
4. 在一个窗口中画出三个直方图结果。


## opencv中的函数
```cpp
void cv::calcHist	(	const Mat * 	images,
						int 	nimages,
						const int * 	channels,
						InputArray 	mask,
						OutputArray 	hist,
						int 	dims,
						const int * 	histSize,
						const float ** 	ranges,
						bool 	uniform = true,
						bool 	accumulate = false 
)	
```
---
这个函数作用是计算一个序列的直方图，各参数含义如下：
1. `images`:		Source arrays. They all should have the same depth, CV_8U, CV_16U or CV_32F , and the same size. Each of them can have an arbitrary number of channels.注意：参数类型是指针类型。
2. `nimages`:		Number of source images.
3. `channels`:		List of the dims channels used to compute the histogram. The first array channels are numerated from 0 to images[0].channels()-1 , the second array channels are counted from images[0].channels() to images[0].channels() + images[1].channels()-1, and so on.
4. `mask`:			Optional mask.　直方图统计前用于图像图像的卷积核，如果没有定义(null)就不进行卷积操作。
5. `hist`:			Output histogram, 这是一个dims维度的数组。
6. `dims`:			直方图的用于统计的参数数量。只能为正，并且当前opencv规定不能大于`CV_MAX_DIMS=32`
7. `histSize`:		Array of histogram sizes in each dimension.注意：这是一个指针
8. `ranges`:		参数的范围，（注意：参数类型是指针的指针，因为范围是dims个数组）
9. `uniform`:		在给定范围上划分bins的大小是否均匀（uniform）的
10. `accumulate`:	在计算直方图时是否是累积（accumulate）模式
