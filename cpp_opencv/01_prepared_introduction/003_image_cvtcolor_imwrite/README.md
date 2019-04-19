# 程序说明
## 运行

    build/image_cvtcolor_imwrite ../data/village.jpg

1. 首先读入`imread`输入的第二个参数（一张图片），并存放在一个`Mat(image)`；

2. 新建一个`Mat(gray_image)`用于存放灰度图，用`cvtColor`将`image`转换成灰度空间表示并存放到`gray_image`中；

3. 将`gray_image`用`imwrite`写入到硬盘，存放在一张叫`Gray_Image.jpg`的图片；

4. 使用`namedWindow`建立两个窗口用于显示`image`和`gray_image`；

5. 使用４中建立的两个窗口用`imshow`显示。
