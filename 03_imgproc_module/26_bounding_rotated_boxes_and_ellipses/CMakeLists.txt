cmake_minimum_required(VERSION 2.8)
project(bounding_rotated_boxes_and_ellipses)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( bounding_rotated_boxes_and_ellipses bounding_rotated_boxes_and_ellipses.cpp)
target_link_libraries( bounding_rotated_boxes_and_ellipses ${OpenCV_LIBS} )

