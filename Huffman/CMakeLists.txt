cmake_minimum_required(VERSION 2.8.4)
project(Huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Huffman.cpp TreeNode.cpp Node.cpp)
add_executable(Huffman ${SOURCE_FILES})