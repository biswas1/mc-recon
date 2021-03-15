# minimum verison of cmake to produce the makefile 
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(main)


add_executable(
main
main.cpp
class1.cpp
class2.cpp

)

