cmake_minimum_required(VERSION 3.1)
project(algo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${SOURCE_DIR}/bin)
add_executable(algo ${SOURCE_FILES})