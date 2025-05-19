cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)

if(NOT DEFINED ENV{PICO_SDK_PATH})
    message(FATAL_ERROR "PICO_SDK_PATH not set in environment")
endif()

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(pico_wifi_bridge C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# Just add your source folder — executable defined there
add_subdirectory(wifi/src)
