cmake_minimum_required(VERSION 3.23)
project(uno)

set(CMAKE_CXX_STANDARD 23)

add_executable(uno main.cpp src/data.cpp src/state_machine.cpp src/thread_local_state_machine.cpp src/threaded_state_machine.cpp)

target_include_directories(uno PRIVATE include)


