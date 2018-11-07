# [opencv1到opencv2的转变](https://docs.opencv.org/3.4.1/df/de5/tutorial_interoperability_with_OpenCV_1.html)

- 使用了新的数据结构`cv::Mat`代替以前的`CvMat`和`IplImage`来表示图像。
- 不在是所有功能都放到一个大库里，现在分成了一个个模块，每个模块里有某个功能相关的数据结构与方法函数的定义。
- 所有opencv相关的定义都放到了一个叫`cv`的命名空间里，防止与其他库产生命名冲突。

## 代码说明
本代码主要是来展示一下如何**混合使用**opencv的c接口与c++接口。

主要是ｃ风格代码数据结构与c++的转换等。

