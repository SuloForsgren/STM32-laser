#include "../../include/laser/blink.h"
#include "../../include/laser/core.h"

void blink() 
{
    GPIOC_BSRR |= (1 << 13);
    delay(250000);
    GPIOC_BSRR |= (1 << 29);
}