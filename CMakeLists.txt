cmake_minimum_required(VERSION 3.23)
project(uno_cpp)

set(CMAKE_CXX_FLAGS "-Wall -Wconversion -Wextra")
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(third_party)
add_executable(main src/main.cpp src/add.cpp)