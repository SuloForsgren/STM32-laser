#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define SSID "DNA-Mokkula-Eteinen"
#define PASS "17399557522"

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

int main() {
    stdio_init_all();
    printf("Booting..\n");

    init_wifi();
    connect_wifi();

    return 0;
}