cmake_minimum_required(VERSION 2.8)
project(operation_image)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( operations operation_image.cpp)
target_link_libraries( operations ${OpenCV_LIBS} )

