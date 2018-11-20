cmake_minimum_required(VERSION 2.8)
project(image_pyramids)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( image_pyramids image_pyramids.cpp)
target_link_libraries( image_pyramids ${OpenCV_LIBS} )

