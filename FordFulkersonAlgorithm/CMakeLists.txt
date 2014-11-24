cmake_minimum_required(VERSION 2.8.4)
project(FordFulkersonAlgorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES FordFulkerson.cpp BreadthFirstSearch.cpp DepthFirstSearch.cpp)
add_executable(FordFulkersonAlgorithm ${SOURCE_FILES})