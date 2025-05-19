cmake_minimum_required(VERSION 3.13)  # SDK recommends >= 3.13

# Set the target board before initializing SDK
set(PICO_BOARD pico_w)

# Set SDK path if not already defined
if(NOT DEFINED ENV{PICO_SDK_PATH})
    message(FATAL_ERROR "PICO_SDK_PATH not set in environment")
endif()

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(pico_wifi_bridge C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK (after project() and PICO_BOARD)
pico_sdk_init()

# Add your subdirectory with the actual code
add_subdirectory(src/wifi)
