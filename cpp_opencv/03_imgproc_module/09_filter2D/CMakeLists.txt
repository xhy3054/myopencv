cmake_minimum_required(VERSION 2.8)
project(filter2D)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( filter2D filter2D.cpp)
target_link_libraries( filter2D ${OpenCV_LIBS} )

