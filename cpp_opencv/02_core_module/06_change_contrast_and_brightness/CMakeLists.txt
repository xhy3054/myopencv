cmake_minimum_required(VERSION 2.8)
project(change_contrast_brightness)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( change_contrast_brightness change_contrast_brightness.cpp)
target_link_libraries( change_contrast_brightness ${OpenCV_LIBS} )

