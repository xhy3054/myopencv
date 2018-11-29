cmake_minimum_required(VERSION 2.8)
project(launch_viz)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( launch_viz launch_viz.cpp)
target_link_libraries( launch_viz ${OpenCV_LIBS} )

