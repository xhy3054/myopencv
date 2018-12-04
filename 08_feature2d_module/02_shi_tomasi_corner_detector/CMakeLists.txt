cmake_minimum_required(VERSION 2.8)
project(shi_tomasi)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( shi_tomasi shi_tomasi.cpp)
target_link_libraries( shi_tomasi ${OpenCV_LIBS} )

