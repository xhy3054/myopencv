cmake_minimum_required(VERSION 2.8)
project(image_moments)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( image_moments image_moments.cpp)
target_link_libraries( image_moments ${OpenCV_LIBS} )

