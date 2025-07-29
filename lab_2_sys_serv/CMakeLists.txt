cmake_minimum_required(VERSION 3.20)
project(lab_2_sys_serv)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_2_sys_serv main.cpp)

target_link_libraries(lab_2_sys_serv wsock32 ws2_32)
