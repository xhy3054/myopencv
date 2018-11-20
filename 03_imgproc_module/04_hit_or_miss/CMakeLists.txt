cmake_minimum_required(VERSION 2.8)
project(hit_or_miss)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( hit_or_miss hit_or_miss.cpp)
target_link_libraries( hit_or_miss ${OpenCV_LIBS} )

