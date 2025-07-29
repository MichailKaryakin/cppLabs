cmake_minimum_required(VERSION 3.20)
project(lab_2_sys)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_2_sys main.cpp)

target_link_libraries(lab_2_sys wsock32 ws2_32)
