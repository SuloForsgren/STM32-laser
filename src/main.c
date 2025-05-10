#include "../include/blink.h"
#include "../include/init.h"
#include "../include/core.h"

void blink_led() 
{
    // Turn led on
    blink(GPIOC_BSRR);
    delay(500000);
    
    // Turn led off
    blink(GPIOC_BSRR);
    delay(500000);
}


int main(void) {
    gpio_init(RCC_APB2ENR, GPIOC_CRH);

    while (1) 
    {
        blink();
        delay(1000000);
    }

    return 0;
}
