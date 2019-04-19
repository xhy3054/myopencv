cmake_minimum_required(VERSION 2.8)
project(Drawing_2)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( Drawing_2 Drawing_2.cpp)
target_link_libraries( Drawing_2 ${OpenCV_LIBS} )

