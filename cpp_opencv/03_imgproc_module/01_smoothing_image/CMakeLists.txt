cmake_minimum_required(VERSION 2.8)
project(smoothing_image)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( smoothing_image smoothing_image.cpp)
target_link_libraries( smoothing_image ${OpenCV_LIBS} )

