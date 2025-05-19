add_executable(wifi_bridge
    wifi.c
)

target_link_libraries(wifi_bridge
    pico_stdlib
    hardware_uart
    hardware_gpio
)

pico_enable_stdio_usb(wifi_bridge 1)
pico_enable_stdio_uart(wifi_bridge 0)

pico_add_extra_outputs(wifi_bridge)
