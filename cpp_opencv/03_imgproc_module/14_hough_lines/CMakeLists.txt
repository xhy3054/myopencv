cmake_minimum_required(VERSION 2.8)
project(hough_lines)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( hough_lines hough_lines.cpp)
target_link_libraries( hough_lines ${OpenCV_LIBS} )

add_executable( houghlines_demo houghlines_demo.cpp)
target_link_libraries( houghlines_demo ${OpenCV_LIBS} )
