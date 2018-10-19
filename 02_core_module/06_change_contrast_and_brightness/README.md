# 对比度与亮度变换程序说明

## 线性变换
 通过如下公式改变图像的对比度与亮度;

    g(i,j) = a * f(i,j) + b

其中，ａ为对比度参数，ｂ为亮度参数。缺点，在数值饱和后会丢失一些图像细节（大于255的值全部调整为255，不具备区分性了）。

## 伽马变换
伽马变换来改变对比度

	O = (I/255)^r * 255

其中，ｒ为伽马系数。非线性变换，不会因为数值饱和丢失细节。

![Basic_Linear_Transform_Tutorial_gamma](Basic_Linear_Transform_Tutorial_gamma.png)

## 两种处理方法后的直方图对比

![Basic_Linear_Transform_Tutorial_histogram_compare](Basic_Linear_Transform_Tutorial_histogram_compare.png)



