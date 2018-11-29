# 检测圆的霍夫变换
本节主要演示如何使用opencv提供的函数`HoughCircles()`来用霍夫变换检测圆

## 理论
和上一节讲述的检测线的霍夫变换相似，检测圆的霍夫变换也是进行空间变换，不过因为一个圆是由圆心与半径唯一确定，所以参数数量是三个。

## 程序分析
1. 加载图片并且祛除噪声
2. 应用检测圆的霍夫变换
3. 显示

## opencv提供的函数`HoughCircles()`
在opencv中，为了效率，实现的检测方法相比较于标准霍夫变换稍有不同，主要分两步：
1. 第一步进行边缘检测并且找到可能的圆心位置
2. 第二步确定最好的半径大小对与每个候选圆

> 更具体细节可以查看《learning opencv》等书籍

```cpp
void cv::HoughCircles   (   InputArray  image,
                            OutputArray     circles,
                            int     method,
                            double  dp,
                            double  minDist,
                            double  param1 = 100,
                            double  param2 = 100,
                            int     minRadius = 0,
                            int     maxRadius = 0 
)   
```
---
参数含义：
- image:    输入原图像；
- circles:  结果向量，三维，前两维是圆心坐标，第三维是半径
- method:   检测方法，目前opencv中唯一可用的是`HOUGH_GRADIENT`，基于梯度的
- dp:       累加器分辨率与图像分辨率的反比
- minDist:  检测中心的最小距离

> 其他参数自行翻看官方文档。
