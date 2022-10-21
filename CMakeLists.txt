cmake_minimum_required(VERSION 3.23)
project(uno)

set(CMAKE_CXX_STANDARD 23)

add_executable(uno main.cpp)

target_include_directories(uno PRIVATE src/include)


