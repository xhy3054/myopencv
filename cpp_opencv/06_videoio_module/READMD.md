# 视频输入输出模块
视频就是一串的快速切换的图片。衡量视频中图片切换速度的度量是FPS(frames per second)

## 读视频
在opencv中，想要读取视频，首先需要创建一个`VideoCapture`对象，他的参数可以是设备编号，也可以是视频文件名

    VideoCapture cap("chaplin.mp4"); //cpp
    cap = cv2.VideoCapture('chaplin.mp4') #python

