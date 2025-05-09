#ifndef BLINK_H
#define BLINK_H

#define GPIOC_BSRR (*(volatile unsigned int*)0x40011010)

void delay(volatile unsigned int count);
void blink();

#endif