cmake_minimum_required(VERSION 2.8)
project(Basic_drawing)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( basic_drawing basic_drawing.cpp)
target_link_libraries( basic_drawing ${OpenCV_LIBS} )

