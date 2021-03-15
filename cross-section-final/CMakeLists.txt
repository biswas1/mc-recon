cmake_minimum_required(VERSION 2.8.11)

project(cross_section)

#-- bring the header , such as Student.h into the project --#

include_directories(include)


#-- can manually add the sources --#
#-- we are setting a variable "SOURCES" which contains the name values of all the source files --#
#-- add executable function uses the variable "SOURCES" rather than induvisual source files --#
#set(SOURCES src/recon_mc.cpp )


#-- instead of adding the source files one by one we can use the file(GLOB ..)--#

file(GLOB SOURCES "src/*.cpp")


##### FOR THE ROOT COMPILER #########################
EXECUTE_PROCESS(COMMAND root-config --cflags OUTPUT_VARIABLE ROOT_CXX_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
### Need to set CMAKE_FLAGS for root otherwise program will not compile
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")


##### FOR THE ROOT LINKER #########################
EXECUTE_PROCESS(COMMAND root-config --glibs OUTPUT_VARIABLE ROOT_LD_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)

set(CMAKE_EXE_LINKER_FLAGS ${ROOT_LD_FLAGS})
set(ROOT_LIBRARIES ${ROOT_LIBRARIES})
#####################################################



add_executable(cross_section ${SOURCES})
