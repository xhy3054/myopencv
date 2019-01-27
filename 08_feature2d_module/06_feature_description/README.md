# 特征检测
使用`cv::Feature2D`接口提取关键点并计算关键点的描述子：
1. 使用类`cv::xfeatures2d::SURF`和它的函数`cv::xfeatures2d::SURF::compute`来执行描述子过程；
2. 使用类`cv::DescriptorMatcher`来进行特征匹配
3. 使用函数`cv::drawMatches`画出匹配结果

## opencv接口说明

### 抽象的特征类`cv::Feature2D`
opencv中提供了一个抽象基类`cv::Feature2D`，像是常用的一些特征类`cv::ORB`等都是继承自这个类，一般每个派生类都会定义自己独特的提取关键点、计算描述子的方法，并且一般每个派生类都会有一个返回智能指针的静态方法。

> 本例程中的类`cv::xfeatures2d::SURF`就是`cv::Feature2D`的一个派生类。并且由于各种原因，这个类不在feature2D模块中，在扩展模块里，且受到版权约束。

### 特征匹配类`cv::DescriptorMatcher`
这个类提供了根据描述子进行特征匹配的功能。这个类提供了返回一个智能指针的静态函数，并且提供了三个（不同匹配方式）
1. `match()`－－寻找最好的那一个匹配;
2. `knnmatch()`－－寻找最好的k个匹配;
3. `radiusMatch()`－－寻找特定距离内的所有匹配;

> 上述三个函数每个重载有两种不同的参数列表形式，分别用于识别与跟踪。此例程使用的是跟踪版本函数。

并且这个类在初始化时可以选择匹配器类型，如今一共支持６中类型(详细见学习opencv3第461页)：
```cpp
enum  	MatcherType { 
  FLANNBASED = 1, 
  BRUTEFORCE = 2, 
  BRUTEFORCE_L1 = 3, 
  BRUTEFORCE_HAMMING = 4, 
  BRUTEFORCE_HAMMINGLUT = 5, 
  BRUTEFORCE_SL2 = 6 
}
```
---

### cv::DMatch类（声明在core模块的`types.hpp`）
这个类用来抽象表达一组匹配。总共四个数据成员，三个构造函数，一个重载运算符`<`（用于比较distance成员），都是公有的。
```cpp
float 	distance 
int 	imgIdx      // train image index
int 	queryIdx    // query descriptor index
int 	trainIdx    // train descriptor index
```
---

### 函数`cv::drawMatches`
```cpp
void cv::drawMatches	(	InputArray 	                        img1,
                            const std::vector< KeyPoint > & 	keypoints1,
                            InputArray 	                        img2,
                            const std::vector< KeyPoint > & 	keypoints2,
                            const std::vector< DMatch > & 	    matches1to2,
                            InputOutputArray 	                outImg,
                            const Scalar & 	                    matchColor = Scalar::all(-1),
                            const Scalar & 	                    singlePointColor = Scalar::all(-1),
                            const std::vector< char > & 	    matchesMask = std::vector< char >(), 
                            DrawMatchesFlags 	                flags = DrawMatchesFlags::DEFAULT 
)	
```
---


