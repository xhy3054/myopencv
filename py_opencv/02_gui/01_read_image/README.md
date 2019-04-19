# imread读图像
本文实验中使用不同方法读入同一种图。原图是16位4通道png图
> 默认imread是使用cv2.IMREAD_COLOR的方式读入一个8位的三通道bgr的mat

1. 读入一个八位一通道灰度图

2. 读入一个八位三通道彩色图

3. 读入一个16位三通道彩色图

4. 读入一个无损图，此处是16位四通道png图

```bash
xhy@xhy-SVF14316SCB:~/cv/myopencv/02_core_module/13_read_image$ python2 imread_examples.py 
flags :  cv2.IMREAD_GRAYSCALE
Size (512, 512), type uint8

flags : cv2.IMREAD_COLOR
Size (512, 512, 3), type uint8

flags :  cv2.IMREAD_ANYCOLOR | cv2.IMREAD_ANYDEPTH
Size (512, 512, 3), type uint16

flags : cv2.IMREAD_UNCHANGED
Size (512, 512, 4), type uint16
```



