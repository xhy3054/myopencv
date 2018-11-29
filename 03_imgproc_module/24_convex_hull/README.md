# 根据轮廓凸包的对象
1. 使用canny边沿检测检测出边缘
2. 对边缘应用函数`cv::findContours`找出轮廓，是一个个点集
3. 使用函数`cv::convexHull`找出每个轮廓的凸包对象，也是生成点集
3. 使用函数`cv::drawContours`画出轮廓与凸包对象
