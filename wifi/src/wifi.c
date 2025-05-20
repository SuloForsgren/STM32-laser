#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define SSID "DNA-Mokkula-Eteinen"
#define PASS "17399557522"

#define UART1_TX 4
#define UART1_RX 5

void init_wifi()
{
    cyw43_arch_init_with_country(CYW43_COUNTRY_FINLAND);
    cyw43_arch_poll();
}

void connect_wifi()
{
    cyw43_arch_enable_sta_mode();
    cyw43_arch_wifi_connect_blocking(SSID, PASS, CYW43_AUTH_WPA2_AES_PSK);
}

void init_uart()
{
    uart_init(uart1, 115200);
    gpio_set_function(UART1_TX, GPIO_FUNC_UART);
    gpio_set_function(UART1_RX, GPIO_FUNC_UART);
}

int main() {
    stdio_init_all();
    printf("Booting..\n");

    init_wifi();
    connect_wifi();

    init_uart();
    uart_puts(uart1, "UART1 says hello\r\n");

    return 0;
}