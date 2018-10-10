cmake_minimum_required(VERSION 2.8)
project(Colormap)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( colormap colormap.cpp)
target_link_libraries( colormap ${OpenCV_LIBS} )

add_executable( custom_colormap custom_colormap.cpp)
target_link_libraries( custom_colormap ${OpenCV_LIBS} )

