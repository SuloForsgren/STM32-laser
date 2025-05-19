cmake_minimum_required(VERSION 3.9)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
project(pico_wifi_bridge C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(src/wifi)