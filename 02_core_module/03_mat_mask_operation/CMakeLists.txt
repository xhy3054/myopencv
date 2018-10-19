cmake_minimum_required(VERSION 2.8)
project(mat_mask)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( mat_mask mat_mask_operations.cpp)
target_link_libraries( mat_mask ${OpenCV_LIBS} )

