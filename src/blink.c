#include "../include/blink/blink.h"

void delay(volatile unsigned int count) {
    while (count--) {
        __asm__("nop");
    }
}

void blink() 
{
    GPIOC_BSRR |= (1 << 13);
    delay(250000);
    GPIOC_BSRR |= (1 << 29);
}