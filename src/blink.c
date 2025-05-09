#include "../include/blink/blink.h"

void blink(int set_bit) 
{
    if (set_bit == 0) 
    {
        GPIOC_BSRR |= (1 << 13);
    }
    else if (set_bit == 1) 
    {
        GPIOC_BSRR |= (1 << 29);
    }
}