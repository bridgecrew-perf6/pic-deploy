cmake_minimum_required(VERSION 3.21)
project(pic_22)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(dishlib)

add_executable(pic_22 main.cpp)
target_link_libraries(pic_22 dishlib)