cmake_minimum_required(VERSION 2.8)
project(image_segmentation)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( image_segmentation image_segmentation.cpp)
target_link_libraries( image_segmentation ${OpenCV_LIBS} )

