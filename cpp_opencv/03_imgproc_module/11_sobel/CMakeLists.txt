cmake_minimum_required(VERSION 2.8)
project(sobel)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( sobel sobel.cpp)
target_link_libraries( sobel ${OpenCV_LIBS} )

