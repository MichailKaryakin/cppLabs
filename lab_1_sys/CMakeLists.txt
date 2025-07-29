cmake_minimum_required(VERSION 3.20)
project(lab_1_sys)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_1_sys main.cpp)

include_directories(hidapi)

add_library(
        hidapi
        hidapi/hid.c
        hidapi/hid.h
        hidapi/hidapi.h
        hidapi/hidapi_cfgmgr32.h
        hidapi/hidapi_hidclass.h
        hidapi/hidapi_hidpi.h
        hidapi/hidapi_hidsdi.h
)

target_link_libraries(lab_1_sys PRIVATE hidapi wsock32 ws2_32)
