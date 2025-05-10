#include "../include/core.h"

void delay(volatile unsigned int count) {
    while (count--) {
        __asm__("nop");
    }
}