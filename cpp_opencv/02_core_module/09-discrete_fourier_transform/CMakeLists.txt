cmake_minimum_required(VERSION 2.8)
project(discrete_fourier_transform)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(OpenCV 3.4.1 REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( discrete_fourier_transform discrete_fourier_transform.cpp)
target_link_libraries( discrete_fourier_transform ${OpenCV_LIBS} )

