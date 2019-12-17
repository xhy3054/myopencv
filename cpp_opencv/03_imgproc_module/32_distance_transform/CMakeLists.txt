cmake_minimum_required(VERSION 2.8)
project(distance_transform)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( demo demo.cpp)
target_link_libraries( demo ${OpenCV_LIBS} )

