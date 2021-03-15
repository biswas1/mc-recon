#-- sets the minimum version of the CMAKE for the project --# 
cmake_minimum_required(VERSION 2.8.11)

#--sets the project name --#
project(hello)

#--first argument "hello" = name of the executable to be built --#
#-- second argument is the source file from which the executable to be built --#
add_executable(hello helloworld.cpp)

