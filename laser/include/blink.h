#ifndef BLINK_H
#define BLINK_H

#define GPIOC_BSRR (*(volatile unsigned int*)0x40011010)

void blink();

#endif