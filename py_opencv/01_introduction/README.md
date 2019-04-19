# python的opencv接口配置
> opencv-python的官方[教程](https://docs.opencv.org/3.4.1/d6/d00/tutorial_py_root.html)

## 使用apt安装

    sudo apt-get install python-opencv

## 使用pip安装（建议使用这种方法）

    pip install opencv-python==3.4.2.17
    pip install opencv-contrib-python==3.4.2.17

## 使用anaconda安装

    conda install opencv

## 源码安装
- 首先cmake进行源码工程构建与安装， gcc用来编译， python-devel和numpy用来编译python接口

    sudo apt-get install cmake
    sudo apt-get install python-devel numpy
    sudo apt-get install gcc gcc-c++

- 然后GTK用来支持GUI，libv4l相机支持，ffmpeg与gstreamer用来进行媒体支持

    sudo apt-get install gtk2-devel
    sudo apt-get install libv4l-devel
    sudo apt-get install ffmpeg-devel
    sudo apt-get install gstreamer-plugins-base-devel

- 下面是一些可选依赖，一般都安装就行了

    sudo apt-get install libpng-devel
    sudo apt-get install libjpeg-turbo-devel
    sudo apt-get install jasper-devel
    sudo apt-get install openexr-devel
    sudo apt-get install libtiff-devel
    sudo apt-get install libwebp-devel

- 下载对应[opencv版本](https://github.com/opencv/opencv)，编译安装过程与cpp版本是一样的。

    mkdir build && cd build
    cmake ../
    make
    sudo make install

- cmake完后，记得查看是否有如下信息输出，如果有则说明编译时会一遍Python接口

    --   Python 2:
    --     Interpreter:                 /usr/bin/python2.7 (ver 2.7.6)
    --     Libraries:                   /usr/lib/x86_64-linux-gnu/libpython2.7.so (ver 2.7.6)
    --     numpy:                       /usr/lib/python2.7/dist-packages/numpy/core/include (ver 1.8.2)
    --     packages path:               lib/python2.7/dist-packages
    --
    --   Python 3:
    --     Interpreter:                 /usr/bin/python3.4 (ver 3.4.3)
    --     Libraries:                   /usr/lib/x86_64-linux-gnu/libpython3.4m.so (ver 3.4.3)
    --     numpy:                       /usr/lib/python3/dist-packages/numpy/core/include (ver 1.8.2)
    --     packages path:               lib/python3.4/dist-packages

## 验证安装是否成功

    import cv2 as cv
    print(cv.__version__)
