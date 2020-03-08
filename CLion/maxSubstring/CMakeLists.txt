cmake_minimum_required(VERSION 3.15)
project(maxSubstring)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static -lpthread")

add_executable(maxSubstring main.cpp)