cmake_minimum_required(VERSION 2.8)
project(scan_image)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( scan_image_measure_time scan_image_measure_time.cpp)
target_link_libraries( scan_image_measure_time ${OpenCV_LIBS} )

