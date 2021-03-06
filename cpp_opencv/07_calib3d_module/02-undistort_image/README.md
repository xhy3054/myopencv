# 矫正畸变
- 使用opencv提供的`cv::undistortPoints`来进行离散点集的畸变矫正；
- 使用opencv提供的`cv::undistort`可以直接将图片进行畸变矫正；
- 使用opencv提供的`initUndistortRectifyMap`可以直接求得畸变的矫正变换(有两个，一个是横坐标的，一个是纵坐标的)；

## 畸变
为了获得更好的成像效果，相机里加了透镜。而透镜的加入对成像过程中光线的传播会产生新的影响：
- **径向畸变**：首先透镜自身的形状对光线传播会有影响；
    - 桶形畸变：图像放大率随着与光轴之间的距离增加而减小
    - 枕形畸变：图像放大率随着与光轴之间的距离增大而增大
- **切向畸变**：其次在机械组装过程中，透镜和成像平面不可能完全平行，这也会使得光线穿过透镜投影到成像面时的位置出现变化；

> 关于距离畸变具体的数学形式可以查看《视觉slam十四讲》p88


