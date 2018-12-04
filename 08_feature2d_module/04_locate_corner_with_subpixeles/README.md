# 优化检测到的角点位置
1. 使用函数`goodFeaturesToTrack`检测shi-tomasi角点
2. 使用函数`cv::cornerSubPix`对检测到的角点进行位置优化
