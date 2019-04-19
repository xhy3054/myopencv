# 获取并修改像素1
- 读取图像
```
>>> import cv2
>>> import numpy as np
>>> img = cv2.imread('earth-16-bit-per-channel.png')
```
---
- 获取像素
```
>>> px = img[100,100]
>>> print(px)
[127  85  78]
>>> blue = img[100,100,0]
>>> print(blue)
127
```
---
- 修改像素
```
>>> img[100, 100] = [255,255,255]
>>> print(img[100,100])
[255 255 255]
```
---

> numpy库一个经过优化的进行矩阵计算的库，使用上述方法访问并修改单一矩阵元素，速度很慢，不推荐，可以使用下面numpy提供的方法会好很多

# numpy提供的方法
- 获取并修改像素
```
>>> img.item(100,100,2)
255
>>> img.itemset((100,100,2), 100)
>>> img.item(100,100,2)
100
```
---

- 获得图像属性
```
>>> print(img.shape)
(512, 512, 3)
>>> print(img.size)
786432
>>> print(img.dtype)
uint8
```
---

- 图像区域选择与赋值
```
>>> regin = img[280:340, 330:390]
>>> img[0:60, 0:60]=regin
```
---

- 分离处各个通道b,g,r，然后重新组合成rgb，或者使用numpy矩阵操作直接操作某一通道的数据(后一种速度更快)。
```
>>> b,g,r = cv.split(img)
>>> img = cv.merge((r,g,b))
#单独取出b通道
>>> b = img[:,:,0]
#将r通道全赋值0
>>> img[:,:,2] = 0
```
---


