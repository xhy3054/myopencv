cmake_minimum_required(VERSION 2.8)
project(add_noise)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( add_noise add_noise.cpp)
target_link_libraries( add_noise ${OpenCV_LIBS} )

