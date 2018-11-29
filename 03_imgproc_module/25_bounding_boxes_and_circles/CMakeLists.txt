cmake_minimum_required(VERSION 2.8)
project(bounding_boxes_and_circles)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( bounding_boxes_and_circles bounding_boxes_and_circles.cpp)
target_link_libraries( bounding_boxes_and_circles ${OpenCV_LIBS} )
add_executable( bounding_boxes_and_circles1 bounding_boxes_and_circles1.cpp)
target_link_libraries( bounding_boxes_and_circles1 ${OpenCV_LIBS} )

