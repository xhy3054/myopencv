cmake_minimum_required(VERSION 2.8)
project(E2Rt)

set(CMAKE_CXX_FLAGS "-std=c++11")
include_directories("/usr/include/eigen3")

find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

add_executable(E2Rt E2Rt.cpp)
target_link_libraries(E2Rt ${Sophus_LIBRARIES})
