# 图像金字塔
图像金字塔主要分为两种：
- 高斯金字塔：对金字塔中低一层图像进行下采样操作得到上一层图像的金字塔；
- 拉普拉斯金字塔：通过金字塔中上一层图像图像通过上采样重建得到下一层图像的金字塔并计算预测残差得到的金字塔；

## 高斯金字塔
高斯金字塔的上采样与下采样操作如下：
- 下采样：
    - 首先使用一个高斯卷积核对整幅图像进行一个卷积操作得到一个平滑后的图像；
    - 对上一步得到的图像进行下采样（抛弃所有的偶数行与偶数列）；
- 上采样：
    - 将图像行与列都变成之前的两倍，并将新插入的行列元素初始化为０;
    - 使用一个高斯卷积核对上一步得到的图像进行卷积操作（近似缺失像素的值）；

> 上述两个操作在opencv中已经提供了，分别是 `pyrUp()` 和 `pyrDown()`
 
## 程序分析
读入图片，可以选择对图片进行高斯上采样与下采样才做。

> 图像的下采样是会损失信息。


