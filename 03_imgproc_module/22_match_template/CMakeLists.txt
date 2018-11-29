cmake_minimum_required(VERSION 2.8)
project(match_template)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( match_template match_template.cpp)
target_link_libraries( match_template ${OpenCV_LIBS} )

