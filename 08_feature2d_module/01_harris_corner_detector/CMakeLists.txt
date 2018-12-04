cmake_minimum_required(VERSION 2.8)
project(harris_corner_detector)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( harris_corner_detector harris_corner_detector.cpp)
target_link_libraries( harris_corner_detector ${OpenCV_LIBS} )

add_executable( harris_corner_detector1 harris_corner_detector1.cpp)
target_link_libraries( harris_corner_detector1 ${OpenCV_LIBS} )

