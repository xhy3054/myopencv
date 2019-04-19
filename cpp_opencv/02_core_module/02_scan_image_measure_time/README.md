## 遍历方法
1. 使用ｃ的`[]`符号来自动依据每行首地址位置偏移访问，优点是效率高；
2. 使用迭代器来遍历访问，优点是安全稳定；
3. 直接使用`_I(i,j)`动态获取对应像素地址来遍历，没什么优点，官网教程不推荐使用；
4. 使用opencv的`core`模块中提供一个函数`cv::LUT()`来通过查找表法修改图像每个元素，速度当然奇快无比；

测试用时结果：`2>3>1>4`(官方测试结果是`3>2>1>4`)
## 细节说明
### Mat中指针指向的矩阵中像素的组织形式
像素的组织形式主要依赖于颜色空间类型的选择，下图是灰度空间下像素的组织形式：
![tutorial_how_matrix_stored_1](opencv-mat/tutorial_how_matrix_stored_1.png)

下面这张图是BGR颜色空间的组织形式，每个大列下会有三个小列依次代表着三种颜色通道（分别是B、G、R），其实就是每个像素由三个`uchar`组成（假设`data_type`是`uchar`）：
![tutorial_how_matrix_stored_2](opencv-mat/tutorial_how_matrix_stored_2.png)

> 无论Mat是几通道的颜色空间，其矩阵都是两维的。只是两维矩阵的每一个元素的大小是`通道数*数据类型的大小`，即在一个元素中，各通道依次存储。同时有一点需要说明，如果内存足够大，在载入图像时，便会将下一行紧随着上一行存储，所以最后有可能**整幅图像存成了一行**。这种情况是可以帮我们提升扫描速度的（按照一维方式扫描），我们可以使用opencv提供的`cv::Mat::isContinuous()`函数来确定是否是连续存储的。
### 查表法优化简化图像操作
简化图像那个操作其实就是，对每个像素都应用如下公式(假设输入第三个参数为10)：

    I(new) = I(old)/10*10

但是这么做对每个元素都要做一次乘法与除法，这个实在太耗费资源了。所以使用**查表法**进行简化。即先将查表准备好，然后在遍历时直接进行赋值操作即可，大大优化了程序，建立查表的操作如下：
```cpp
    int divideWith = 0; // convert our input string to number - C++ style
    stringstream s;
    s << argv[2];
    s >> divideWith;    //这种方法可以很自然地将第三个输入参数从字符串转换成整数
    if (!s || !divideWith)  //如果上面两步转换有哪一步格式不匹配或者输入提前结束
    {
        cout << "Invalid number entered for dividing. " << endl;
        return -1;
    }
    uchar table[256];   //查表法建立表
    for (int i = 0; i < 256; ++i)
       table[i] = (uchar)(divideWith * (i/divideWith));
```

### 计量耗时
这一步使用了opencv提供的两个简单的函数` cv::getTickCount()`与` cv::getTickFrequency()`。其中第一个函数的作用是返回cpu从某一个固定时刻（比如说系统启动）到现在为止经历了多少个小周期，第二个函数返回cpu在一秒里会经历多少个小周期。所以一般可以通过如下程序测量前后时间差：
```cpp
double t = (double)getTickCount();
// do something ...
t = ((double)getTickCount() - t)/getTickFrequency();
cout << "Times passed in seconds: " << t << endl;
``` 



### cv::LUT使用方法

    LUT(I, lookUpTable, J);

其中，I为原图，lookUpTable是查找表，J是修改后的图像；


## 程序说明
这个程序主要想描述遍历图像（Mat）的方法(代码中使用了四种方法)。然后顺便执行中做了两个额外的操作：
1. 将每个像素的描述（原先是0~255级）级别除以一个参数（程序执行时第三个输入参数），即简化了图像。

2. 对每种遍历方法的运行时间进行测量，比较哪种效率最高。

## 运行结果
```bash
myopencv/005_scan_image_measure_time$ build/scan_image_measure_time ../../data/wechat.jpg 10

--------------------------------------------------------------------------
This program shows how to scan image objects in OpenCV (cv::Mat). As use case we take an input image and divide the native color palette (255) with the 
input. Shows C operator[] method, iterators and at function for on-the-fly item address calculation.
Usage:
./how_to_scan_images <imageNameToUse> <divideWith> [G]
if you add a G parameter the image is processed in gray scale
--------------------------------------------------------------------------

Time of reducing with the C operator [] (averaged for 100 runs): 5.95751 milliseconds.
Time of reducing with the iterator (averaged for 100 runs): 49.2993 milliseconds.
Time of reducing with the on-the-fly address generation - at function (averaged for 100 runs): 37.609 milliseconds.
Time of reducing with the LUT function (averaged for 100 runs): 2.53712 milliseconds.

```
