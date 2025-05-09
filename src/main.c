#include "../include/blink/blink.h"
#include "../include/definitions/definitions.h"
#include "../include/init/init.h"

void delay(volatile unsigned int count) {
    while (count--) {
        __asm__("nop");
    }
}


int main(void) {
    gpio_init();
    int set_bit = 0;

    while (1) 
    {
        blink(set_bit);
        set_bit = 1;
        delay(500000);
        
        blink(set_bit);
        set_bit = 0;
        delay(500000);
    }
    return 0;
}
