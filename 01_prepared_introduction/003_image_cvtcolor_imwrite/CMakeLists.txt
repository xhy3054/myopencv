cmake_minimum_required(VERSION 2.8)
project(cvtcolor_imread)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( cvtcolor_imread image_cvtcolor_imwrite.cpp)
target_link_libraries( cvtcolor_imread ${OpenCV_LIBS} )


