# ICP(Iterative Closest Point,迭代最近点)
> 迭代最近点算法，讲的是给定两个匹配好的点云，两个点云中的点一一对应，是传感器从不同的位置上采集的。现在根据这两个点云计算传感器的位姿变化。ICP的求解可以看看十四讲

## 代码示例

- `campare.txt`中是相机的位姿
	- 奇数行是使用VO估计的相机轨迹，因此第一帧为原点
	- 偶数行是其他传感器采集的相机真值轨迹，相对于其他的某个坐标系A

- 目标：通过ICP计算出第一帧时相机相对于坐标系A的位姿;

> 此处将轨迹看作点云，通过两个点云的ICP算法来轨迹所处的两个坐标系的位姿变换


