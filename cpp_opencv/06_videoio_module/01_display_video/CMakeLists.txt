cmake_minimum_required(VERSION 2.8)
project(display_video)

#set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV  REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( display display.cpp)
target_link_libraries( display ${OpenCV_LIBS} )

add_executable( set_show_fps set_show_fps.cpp)
target_link_libraries( set_show_fps ${OpenCV_LIBS} )
