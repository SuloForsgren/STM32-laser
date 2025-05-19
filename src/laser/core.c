#include "../../include/laser/core.h"

void delay(volatile unsigned int count) 
{
    while (count--) {
        __asm__("nop");
    }
}

void micro_delay(volatile unsigned int count) 
{
    count *= 2;
    while (count--) 
    {
        __asm__("nop");
    }
}