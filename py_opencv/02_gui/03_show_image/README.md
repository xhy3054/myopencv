# 显示图像
- opencv显示图像的函数是`cv.imshow()`

- Python在64位机器上使用`cv.waitKey(0)`会出错，应该写成`cv.waitKey(0) & 0xFF`

- 由于opencv使用的numpy的array来表示矩阵，所以opencv读入的图像可以直接使用matplotlib显示
    - 由于opencv读入图片是bgr，所以直接使用matplotlib显示会出现颜色通道混乱
