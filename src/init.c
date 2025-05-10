#include "../include/init.h"

void gpio_init() 
{
    RCC_APB2ENR |= (1 << 4);

    GPIOC_CRH &= ~(0xF << 20);
    GPIOC_CRH |= (0x2 << 20);
}