cmake_minimum_required(VERSION 2.8)
project(affine_transformations)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( affine_transformations affine_transformations.cpp)
target_link_libraries( affine_transformations ${OpenCV_LIBS} )

