cmake_minimum_required(VERSION 2.8)
project(kd-tree)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( kd_test kd_test.cpp)
target_link_libraries( kd_test ${OpenCV_LIBS} )

