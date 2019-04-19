cmake_minimum_required(VERSION 2.8)
project(mat_creat_print)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( mat_creat_print mat_creat_print.cpp)
target_link_libraries( mat_creat_print ${OpenCV_LIBS} )


