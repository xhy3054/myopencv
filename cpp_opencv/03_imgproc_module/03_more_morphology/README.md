# 形态学操作
上一个教程了里面描述演示了最基础的两种形态学操作－－腐蚀与膨胀。这一个教程继续来介绍opencv提供的五种新的形态学操作。
- 开操作（opening）
- 闭操作（closing）
- 形态学梯度（morphological gradient）
- top hat
- black hat

## opening
- 操作：先腐蚀再膨胀。（相同卷积核）

- 效果：可以使得白色的小块消失。

## closing
- 操作：先膨胀再腐蚀。（相同卷积核）

- 效果：可以使得黑色的小块消失。

## morphological gradient
- 操作：膨胀后的图片减去腐蚀后的图片。

- 效果：对于一个白色背景上的黑色物体应用此操作可以得到黑色物体的轮廓。

## top hat
- 操作：原图像**减去**开操作后的图像。

- 效果：

## black hat
- 操作：闭操作后的图像**减去**原图像。

- 效果：

## 程序分析
创建窗口，并在窗口上放置Trackbar，动态监控并应用形态学操作并显示。

1. 使用函数` cv::getStructuringElement`获得指定形状大小的卷积核。

2. 使用函数` cv::morphologyEx`函数来应用上述五种形态学操作。

```cpp
void cv::morphologyEx	(	InputArray 	src,
OutputArray 	dst,
int 	op,
InputArray 	kernel,
Point 	anchor = Point(-1,-1),
int 	iterations = 1,
int 	borderType = BORDER_CONSTANT,
const Scalar & 	borderValue = morphologyDefaultBorderValue() 
)	
/*
Parameters
src	Source image. The number of channels can be arbitrary. The depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
dst	Destination image of the same size and type as source image.
op	Type of a morphological operation, see MorphTypes
kernel	Structuring element. It can be created using getStructuringElement.
anchor	Anchor position with the kernel. Negative values mean that the anchor is at the kernel center.
iterations	Number of times erosion and dilation are applied.
borderType	Pixel extrapolation method, see BorderTypes
borderValue	Border value in case of a constant border. The default value has a special meaning.
*/
```
