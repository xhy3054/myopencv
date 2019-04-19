# 程序说明
本程序作用是对一幅图像进行特定窗函数的卷积操作（掩码操作，加权求和）。并将手写的卷积操作与opencv提供的内置的`filter2D`函数进行运行速度的对比。


## 运行结果

本程序最多三个参数，最少一个参数，当只有一个参数时，默认使用彩色空间读取`../../data/wechat.jpg`图像进行操作。第三个参数是`G`则使用灰度空间。

```bash
myopencv/006_mat_mask_operation$ build/mat_mask 

This program shows how to filter images with mask: the write it yourself and thefilter2d way. 
Usage:
build/mat_mask [image_path -- default ../../data/wechat.jpg] [G -- grayscale] 

Hand written function time passed in seconds: 0.0407254
Built-in filter2D time passed in seconds:     0.103882
```
我也不知道为什么，我自己跑出来的结果竟然是手写的更快，官网上说`filter2D`函数有一些优化操作所以应该比手写的快的。。。

又跑了一次，这次结果又变了。。
```bash
myopencv/006_mat_mask_operation$ build/mat_mask 

This program shows how to filter images with mask: the write it yourself and thefilter2d way. 
Usage:
build/mat_mask [image_path -- default ../../data/wechat.jpg] [G -- grayscale] 

Hand written function time passed in seconds: 0.0228755
Built-in filter2D time passed in seconds:     0.00331746

```
