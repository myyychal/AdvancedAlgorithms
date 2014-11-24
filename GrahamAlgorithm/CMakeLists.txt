cmake_minimum_required(VERSION 2.8.4)
project(GrahamAlgorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Graham.cpp Point.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\myyychal\\ClionProjects\\AdvancedAlgorithms\\GrahamAlgorithm\\")

add_executable(GrahamAlgorithm ${SOURCE_FILES})
