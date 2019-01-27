cmake_minimum_required(VERSION 2.8)
project(feature_detection)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(OpenCV_DIR /usr/local/opencv-4.0.0/lib/cmake/opencv4)

find_package(OpenCV 4.0.0 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( feature_detection feature_detection.cpp)
target_link_libraries( feature_detection ${OpenCV_LIBS} )

add_executable( orb_detection orb_detection.cpp)
target_link_libraries( orb_detection ${OpenCV_LIBS} )
