cmake_minimum_required(VERSION 2.8)
project(more_morphology)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( more_morphology more_morphology.cpp)
target_link_libraries( more_morphology ${OpenCV_LIBS} )

