#　在ubuntu上编译安装opencv(包含扩展模块)
查看系统opencv版本：`pkg-config --modversion opencv`

首先安装依赖库，这个因系统机器会有差异，按照自己的查一下。

下载opencv源码，自己下

## 安装在默认路径（不含拓展模块）
```bash
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_TIFF=ON .. 
make
sudo make install
```
---

### cmake使用默认路径上的opencv
```
cmake_minimum_required(VERSION 2.8)
project(harris_corner_detector)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( harris_corner_detector harris_corner_detector.cpp)
target_link_libraries( harris_corner_detector ${OpenCV_LIBS} )
```
---
 
## 选定路径安装（含拓展模块）
将拓展模块也下载好，并放到命令中指示的位置，注意连同拓展模块一起编译时需要很大的硬盘空间。
```bash
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local/opencv-4.0.0 -D BUILD_TIFF=ON  -D OPENCV_ENABLE_NONFREE=1  -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.0.0/modules ..
make
sudo make install
```
---
### cmake使用指定路径上的opencv
```cmake
cmake_minimum_required(VERSION 3.5)
project(harris_corner_detector)

set(CMAKE_CXX_FLAGS "-std=c++11")
SET(OpenCV_DIR /usr/local/opencv-4.0.0/lib/cmake/opencv4    #此处主要是找到这个版本的opencv的.cmake文件

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( harris_corner_detector harris_corner_detector.cpp)
target_link_libraries( harris_corner_detector ${OpenCV_LIBS} )
```
---

# 卸载opencv
```bash
sudo make uninstall
cd ..
rm -r build
sudo rm -r /usr/local/include/opencv2 /usr/local/include/opencv /usr/inc
lude/opencv /usr/include/opencv2 /usr/local/share/opencv /usr/local/shar
e/OpenCV /usr/share/opencv /usr/share/OpenCV /usr/local/bin/opencv* /usr
/local/lib/libopencv*
```
---

> 指定路径上的不同版本的opencv互相不干扰

# 常见问题

1. 在cmake时会从raw.githubusercontent.com下载很多数据，但是这个网站会存在不能访问的情况；
解决方法：查询其ip，并将其写入`/etc/hosts`中，直接ip访问是可以的。

