cmake_minimum_required(VERSION 2.8)
project(file_input_output)
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( file_input_output file_input_output.cpp)
target_link_libraries( file_input_output ${OpenCV_LIBS} )

