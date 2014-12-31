cmake_minimum_required(VERSION 2.8.4)
project(BoyerMooreAlgorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES BoyerMoore.cpp)
add_executable(BoyerMooreAlgorithm ${SOURCE_FILES})