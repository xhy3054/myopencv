cmake_minimum_required(VERSION 2.8)
project(find_draw_contours)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( find_draw_contours find_draw_contours.cpp)
target_link_libraries( find_draw_contours ${OpenCV_LIBS} )

