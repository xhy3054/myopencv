cmake_minimum_required(VERSION 2.8)
project(pa5)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

include_directories("/usr/include/eigen3")

find_package(Sophus REQUIRED)
#不知道为啥这个库没被链接到，需要手动
set(Sophus_LIBRARIES libSophus.so)
include_directories(${Sophus_INCLUDE_DIRS})


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(direct_method direct_method.cpp)
target_link_libraries(direct_method ${OpenCV_LIBS} ${Sophus_LIBRARIES} ${Pangolin_LIBRARIES})
