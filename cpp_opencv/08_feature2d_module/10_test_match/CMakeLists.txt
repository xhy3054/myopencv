cmake_minimum_required(VERSION 2.8)
project(test_match)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(OpenCV_DIR /usr/local/opencv-4.0.0/lib/cmake/opencv4)

find_package(OpenCV 4.0.0 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(SRCS
    ./src/utils.cpp
)

add_executable( test_match test_match.cpp ${SRCS})
target_link_libraries( test_match ${OpenCV_LIBS} )

