cmake_minimum_required(VERSION 3.5)
project(stereo)

set(CMAKE_CXX_STANDARD 11)

include_directories("/usr/include/eigen3")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Pangolin REQUIRED)

set(SOURCE_FILES stereo.cpp)
add_executable(stereo ${SOURCE_FILES})
target_link_libraries(stereo ${OpenCV_LIBS} ${Pangolin_LIBRARIES} )
