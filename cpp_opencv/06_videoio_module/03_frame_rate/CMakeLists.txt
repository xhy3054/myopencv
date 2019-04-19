cmake_minimum_required(VERSION 2.8)
project(fps)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(OpenCV_DIR /usr/local/opencv-4.0.0/lib/cmake/opencv4)

find_package(OpenCV 4.0.0 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( fps frame_rate.cpp)
target_link_libraries( fps ${OpenCV_LIBS} )

