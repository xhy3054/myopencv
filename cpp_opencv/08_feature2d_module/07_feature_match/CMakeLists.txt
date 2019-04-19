cmake_minimum_required(VERSION 2.8)
project(feature_match)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(OpenCV_DIR /usr/local/opencv-4.0.0/lib/cmake/opencv4)

find_package(OpenCV 4.0.0 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( orb_match orb_match.cpp)
target_link_libraries( orb_match ${OpenCV_LIBS} )

add_executable( knn_match knn_match.cpp)
target_link_libraries( knn_match ${OpenCV_LIBS} )

add_executable( fs feature_statistic.cpp)
target_link_libraries( fs ${OpenCV_LIBS} )

