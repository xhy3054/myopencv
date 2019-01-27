# 特征检测
使用`cv::Feature2D`接口寻找特征点：
1. 使用类`cv::xfeatures2d::SURF`和它的函数`cv::xfeatures2d::SURF::detect`来执行检测过程；
2. 使用函数`cv::drawKeypoints`画出检测到的特征点
3. 最后我输出了关键点坐标，我们会发现，关键点坐标是小数，这说明在提取关键点时，opencv已经做过亚像素优化了

## opencv接口说明
### cv::KeyPoint类（声明在core模块的`types.hpp`）
这个类是用来抽象表达一个关键点，总共有六个公有数据成员，三个构造函数，三个静态成员函数，和一个普通函数。
```
Point2f　pt	    x & y coordinates of the keypoint
float　size	    keypoint diameter
float　angle	    keypoint orientation
float　response	keypoint detector response on the keypoint (that is, strength of the keypoint)
int octave	    pyramid octave in which the keypoint has been detected
int class_id	object id
```
---

### cv::Feature2D类
opencv中提供了一个抽象基类`cv::Feature2D`，像是常用的一些特征类`cv::ORB`等都是继承自这个类，一般每个派生类都会定义自己独特的提取关键点、计算描述子的方法，并且一般每个派生类都会有一个返回智能指针的静态方法。

> 本例程中的类`cv::xfeatures2d::SURF`就是`cv::Feature2D`的一个派生类。并且由于各种原因，这个类不在feature2D模块中，在扩展模块里，且受到版权约束。

### 函数`cv::drawKeypoints`
这个函数在模块feature2d中，作用是画出检测到的关键点
```cpp
void cv::drawKeypoints	(	InputArray 	                        image,
                            const std::vector< KeyPoint > & 	keypoints,
                            InputOutputArray 	                outImage,
                            const Scalar & 	                    color = Scalar::all(-1),
                            DrawMatchesFlags 	                flags = DrawMatchesFlags::DEFAULT 
)	
```
---
其中：
- image	    Source image.
- keypoints	Keypoints from the source image.
- outImage	Output image. Its content depends on the flags value defining what is drawn in the output image. See possible flags bit values below.
- color	    Color of keypoints.
- flags	    Flags setting drawing features. Possible flags bit values are defined by DrawMatchesFlags. See details above in drawMatches .

