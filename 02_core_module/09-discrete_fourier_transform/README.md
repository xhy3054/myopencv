# 程序说明
本程序完成的主要任务是对一副灰度图像进行离散傅里叶变换（DFT），查看空间域与频率域的转换效果。

## 步骤说明
1. [expand]: 因为当图像维度是2、3、5的倍数时，会使得DFT的运算速度达到最快，所以第一步将图像维度进行扩充（如果需要，填充0）;

2. [complex_and_real]:因为输入是灰度图像，只有一维，而DFT的结果是两维的数据（实部与虚部），并且通常DFT的数据比较复杂，所以每个维度需要用32位来表示。所以这一步将上一步中生成的图像转成一个符合要求的MAT类型图像；

3. [dft]:进行离散傅里叶变换；

4. [magnitude]: 将DFT的**实数结果转换成模长**；

5. [log]: 上一步得到的模长表示的**范围太大**，不好显式，将上一步结果加１然后对数做一个非线性转换；

6. [crop_rearrange]: 此时的结果是原点在四个角上的，为了**可视化**，将原点移到中心。图像分四块，０与３交换，１与２交换(如果图像维度不是２的倍数，适当裁剪一下)；

7. [normalize]: 最后一次为可视化将每个像素值调整到０～１之间（使用`cv::normalize()` function）。

## 运行说明
提供了两张图片，一张没旋转，一张旋转了，可以看一下结果对比。