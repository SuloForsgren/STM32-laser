#include "../include/blink.h"
#include "../include/core.h"

void blink() 
{
    GPIOC_BSRR |= (1 << 13);
    delay(250000);
    GPIOC_BSRR |= (1 << 29);
}