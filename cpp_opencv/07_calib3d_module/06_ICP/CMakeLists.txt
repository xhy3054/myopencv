cmake_minimum_required(VERSION 2.8)
project(IcpTest)
 
# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    add_definitions(-DCOMPILEDWITHC11)
    message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    add_definitions(-DCOMPILEDWITHC0X)
    message(STATUS "Using flag -std=c++0x.")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
 
include_directories( "/usr/include/eigen3" )
 

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
 
find_package(OpenCV 3  REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})
 

LIST( APPEND CMAKE_MODULE_PATH /home/moonx/g2o/cmake_modules )
SET( G2O_ROOT /home/moonx/g2o )
find_package(G2O REQUIRED)
include_directories(${G2O_INCLUDE_DIRS})

add_executable(icp_test icp_test.cpp)
target_link_libraries( icp_test  ${OpenCV_LIBRARIES} ${Sophus_LIBRARIES} ${Pangolin_LIBRARIES} ${G2O_LIBRARIES})