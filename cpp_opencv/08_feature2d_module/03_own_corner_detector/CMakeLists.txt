cmake_minimum_required(VERSION 2.8)
project(own_corner_detector)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( own_corner_detector own_corner_detector.cpp)
target_link_libraries( own_corner_detector ${OpenCV_LIBS} )

