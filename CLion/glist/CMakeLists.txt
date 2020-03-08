cmake_minimum_required(VERSION 3.15)
project(glist)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static -lpthread")

add_executable(glist main.cpp)