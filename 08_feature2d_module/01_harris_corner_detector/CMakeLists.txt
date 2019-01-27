cmake_minimum_required(VERSION 2.8)
project(harris_corner_detector)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(OpenCV_DIR /usr/local/opencv-4.0.0/lib/cmake/opencv4)

find_package(OpenCV 4.0.0 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( harris_corner_detector harris_corner_detector.cpp)
target_link_libraries( harris_corner_detector ${OpenCV_LIBS} )

