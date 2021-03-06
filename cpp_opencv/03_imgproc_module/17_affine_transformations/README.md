# 仿射变换
本节主要有两个要点
1. 使用opencv函数`cv::warpAffine`来实现一个简单的重映射示例
2. 使用opencv函数`cv::getAffineTransform`获得仿射变换矩阵（２＊３）
3. 使用opencv函数`cv::getRotationMatrix2D`来获得一个旋转矩阵（２＊３）

> 由于仿射变换是对二维点的其次坐标进行作用的，所以不论是标准放射变换矩阵还是旋转矩阵都是（2*3）的

注意：opencv中实现的仿射变换是针对二维图像的，所以放射变换矩阵都是`2*3`的

## 理论
1. 一个二维点的仿射变换可以用一个矩阵乘法（线性变换）与一个向量加法（平移）表示
2. 所以我们可以用仿射变换表示（不局限于表示这些）：
    - 旋转（矩阵乘法）
    - 平移（向量加法）
    - 尺度变换（矩阵乘法）
3. 通常使用一个`2*3`的矩阵代表仿射变换，其中前`2*2`代表线性变换（旋转、尺度）,后面`2*1`代表平移，作用于一个二维点的齐次坐标（x,y,1）

## 仿射变换、刚体变换与相似变换（２ｄ）
- **刚体变换**可以保证两个点在**变换前后欧式距离不变**，具有3个自由度（旋转一个，平移两个）；
    - 通常是旋转加上平移；

- **相似变换**通常指相似刚体变换，指增加了缩放的刚体变换，具有4个自由度（刚体的3个再加上缩放尺度），相似变换具有**保角性与保持距离比**的性质；
    - 通常可以描述为先旋转一次，再缩放一次，最后平移一次；

- **仿射变换**具有两个旋转因子与两个缩放因子，外加两个平移因子，因此具有6个自由度（其实就是2*3矩阵每个元素都互不先关，都代表一个自由度），上面讲的仿射变换其实是仿射变换的子集，甚至可以简单的使用相似变换达到。仿射变换不具有保角性与保持距离比的性质，但是原本的平行线，变换后仍然是平行线；
    - 通常可以描述为**先**旋转一个角度j1，**然后**在x方向缩放s1，y方向缩放s2，**然后再**反向旋转角度j，**最后**，再旋转一个角度j2，并平移一次；

- **投影变换（也叫单应变换）**具有8个自由度，仿射变换的不变性对于投影变换不适用，但是原本共线的三个点在变换后仍旧共线。

## 仿射变换的应用
1. 根据已知的仿射变换前的点与仿射变换后的点，反推出仿射变换矩阵，主要是几何方法
2. 根据已知的仿射变换矩阵，对一幅图像进行变换。

## 代码分析
1. 加载图像
2. 对一幅图像应用仿射变换`cv::warpAffine`，仿射变换矩阵为由三对仿射变换前后的点对推出`cv::getAffineTransform`。
3. 变换后对图像进行旋转`cv::warpAffine`（以中心为原点），旋转矩阵由缺点的旋转原点，角度，尺度获得`cv::getRotationMatrix2D`
4. 等待用户终止程序


## 函数分析
注意：opencv中实现的仿射变换是针对二维图像的，所以放射变换矩阵都是`2*3`的

比较简单，就不多写了，有需要再查官方文档
 
