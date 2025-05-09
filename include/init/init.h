#ifndef INIT_H
#define INIT_H

#define RCC_APB2ENR (*(volatile unsigned int*)0x40021018)
#define GPIOC_CRH (*(volatile unsigned int*)0x40011004)

void gpio_init();

#endif