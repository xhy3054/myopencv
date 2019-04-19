cmake_minimum_required(VERSION 2.8)
project(add_trackbar)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( add_trackbar add_trackbar.cpp)
target_link_libraries( add_trackbar ${OpenCV_LIBS} )

