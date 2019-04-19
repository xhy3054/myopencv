# 图像重映射
本节主要的目的是演示如何使用opencv中的函数`cv::remap()`来实现图像重映射。

## 理论
1. 图像重映射就是将像素从源图像的一个位置重新映射到目的图像的另一个位置。
2. 为了完成这个映射过程，可能会在非整数的像素位置进行差值操作，这是因为原图像与目标图像的像素总是一对一的关系。
3. 这个映射过程可用一个方程表示`g(x,y)=f(h(x,y))`，其中g是重映射后的图像，h是源图像，f是重映射的方法。
4. 在opencv库中，`cv::remap()`提供了一个简单的重映射实现。

## 代码分析
1. 加载图片
2. 总共四种重映射处理，每秒切换一个，一直循环显示
3. 等待用户终止程序

## `cv::remap()`函数
```cpp
void cv::remap  (   InputArray  src,
                    OutputArray     dst,
                    InputArray  map1,
                    InputArray  map2,
                    int     interpolation,
                    int     borderMode = BORDER_CONSTANT,
                    const Scalar &  borderValue = Scalar() 
)   
```
---
功能：
        
    dst(x,y) = src(map1(x,y), map2(x,y))   
 
参数含义：
- src:              输入源图像
- dst:              输出图像
- map1:             与输出图像二维尺寸相同，对应位置的元素是重映射前的x值，float型
- map2:             与输出图像二维尺寸相同，对应位置的元素是重映射前的y值，float型
- interpolation:    插入方式 
