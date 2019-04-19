# 调整图片大小
- 这一个例子主要就是调整图片大小，使用`cv::resize()`

##  函数说明
```cpp
void cv::resize (   InputArray  src,
                    OutputArray     dst,
                    Size    dsize,
                    double  fx = 0,
                    double  fy = 0,
                    int     interpolation = INTER_LINEAR 
)   
```
---

作用：调整图片大小，在`imgproc`模块中。
- src:          源图像
- dst:          输出图像
- dsize:        输出图像尺寸
- fx,fy:        输出图像相对于源图像的比例
- interpolation:插值方式，一般默认双线性插值

这个函数可以通过两种方式指定输出图像大小，第一种通过`dsize`确定。第二种通过`fx,fy`确定，使用第二种方式时需要将dsize设置成`cv::Size(0,0)`
