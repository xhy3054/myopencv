# 单应性验证
关于空间单应性与单应矩阵原理的讲解可以看[这里](https://xhy3054.github.io/Homography-matrix/)

## 使用的api

- `Mat h = findHomography(pts_src, pts_dst);`计算出单应矩阵
    - 此处输入的点集合至少需要四对点，多了更好会求出最优解；

- `warpPerspective(im_src, im_dst, h, size);`根据单应矩阵将`im_src`投影到`imsrc`

## 程序思路
1. 通过事先标定好的四对点，计算出单应矩阵h

2. 通过h将图src映射出图out

3. 输出三种图，查看结果
