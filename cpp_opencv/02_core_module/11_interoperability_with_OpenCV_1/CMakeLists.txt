cmake_minimum_required(VERSION 2.8)
project(interoperability_with_OpenCV_1)
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( interoperability_with_OpenCV_1 interoperability_with_OpenCV_1.cpp)
target_link_libraries( interoperability_with_OpenCV_1 ${OpenCV_LIBS} )

