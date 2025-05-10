#include "../include/blink.h"
#include "../include/init.h"
#include "../include/core.h"


int main(void) {
    gpio_init(RCC_APB2ENR, GPIOC_CRH);

    while (1)
    {
        blink();
        delay(100000);
    }

    return 0;
}