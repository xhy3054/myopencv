cmake_minimum_required(VERSION 2.8)
project(feature_detection)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( feature_detection feature_detection.cpp)
target_link_libraries( feature_detection ${OpenCV_LIBS} )

