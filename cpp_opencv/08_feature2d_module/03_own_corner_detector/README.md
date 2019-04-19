# 自己实现角点检测器
主要是分别使用函数`cv::cornerEigenValsAndVecs`与`cv::cornerMinEigenVal`来自己实现角点检测器。本文自己分别实现了harris与shi-tomasi角点检测器。

> 目前角点的检测原理都是我博客中讲解的那样。所以系数矩阵的特征值就是衡量一个点的角点属性的重要依据。通过实现两种角点检测，我发现harris角点的计算量似乎还是大了一些，相比较shi-tomasi计算量就会小很多，不过准确性也会小一些。

## 函数`cv::cornerEigenValsAndVecs`
```cpp
void cv::cornerEigenValsAndVecs	(	InputArray 	src,
                                    OutputArray 	dst,
                                    int 	blockSize,
                                    int 	ksize,
                                    int 	borderType = BORDER_DEFAULT 
)
```
---
其中：
- src:          输入的单通道８位或浮点型图像
- dst:          存储结果的图像，与src大小相同，但是元素类型为`CV_32FC(6)`
- blockSize:    邻域大小
- ksize:        使用的sobel算子的卷积核尺寸

功能：对于每一个像素，首先生成一个`blockSize * blocksize`大小的协方差矩阵M(我博客里harris角点原理的那个系数矩阵)。然后计算这个矩阵的特征值与特征向量，并存储在一个`CV_32FC(6)`(λ1,λ2,x1,y1,x2,y2)中，最终dst是一个与src大小相同，但是元素类型为`CV_32FC(6)`的mat

- λ1,λ2 是矩阵M的特征值
- x1,y1 are the eigenvectors corresponding to λ1
- x2,y2 are the eigenvectors corresponding to λ2

## 函数`cv::cornerMinEigenVal`
```cpp
void cv::cornerMinEigenVal	(	InputArray 	src,
                                OutputArray 	dst,
                                int 	blockSize,
                                int 	ksize = 3,
                                int 	borderType = BORDER_DEFAULT 
)	
```
---
其中：
- src:          输入的单通道８位或浮点型图像
- dst:          存储结果的图像，与src大小相同，但是元素类型为`CV_32FC1`
- blockSize:    邻域大小
- ksize:        使用的sobel算子的卷积核尺寸

功能: 与上个函数类似，对于每个像素处的协方差矩阵只计算最小的那个特征值`min(λ1,λ2)`。

## harris角点检测
harris角点依据harris响应值来判断。

通过函数`cv::cornerEigenValsAndVecs`能计算出每个点处的系数矩阵的两个特征值，通过这两个特征值计算harris响应值。并依据滑动棒确定的阈值判断是否是角点。
## shi-tomasi角点检测
shi-tomasi角点依据系数矩阵较小的那个特征值来判断。

通过函数`cv::cornerMinEigenVal`来计算出每个点处的系数矩阵的较小的那个特征值，并依据滑动棒确定的阈值判断是否是角点。

