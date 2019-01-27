cmake_minimum_required(VERSION 2.8)
project(pca)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( pca_basic pca_basic.cpp)
target_link_libraries( pca_basic ${OpenCV_LIBS} )

add_executable( pca_face pca_face.cpp)
target_link_libraries( pca_face ${OpenCV_LIBS} )
