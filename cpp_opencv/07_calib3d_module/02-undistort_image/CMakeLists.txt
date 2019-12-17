cmake_minimum_required(VERSION 3.5)
project(undistort)

set(CMAKE_CXX_STANDARD 11)

include_directories("/usr/include/eigen3")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

#find_package(Pangolin REQUIRED)

set(SOURCE_FILES undistort_image.cpp)
add_executable(undistort_image ${SOURCE_FILES})
target_link_libraries(undistort_image ${OpenCV_LIBS} )
#${Pangolin_LIBRARIES} )
