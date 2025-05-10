#ifndef INIT_H
#define INIT_H

#define RCC_APB2ENR (*(volatile unsigned int*)0x40021018)

#define GPIOA_CRH (*(volatile unsigned int*)0x40010804)
#define GPIOB_CRH (*(volatile unsigned int*)0x40010C04)
#define GPIOC_CRH (*(volatile unsigned int*)0x40011004)

#define TIM1_PSC (*(volatile unsigned int*)0x40012C28)
#define TIM1_ARR (*(volatile unsigned int*)0x40012C2C)
#define TIM1_CCR1 (*(volatile unsigned int*)0x40012C34)
#define TIM1_CCMR1 (*(volatile unsigned int*)0x40012C18)
#define TIM1_CCER (*(volatile unsigned int*)0x40012C20)
#define TIM1_CR1 (*(volatile unsigned int*)0x40012C00)
#define TIM1_BDTR (*(volatile unsigned int*)0x40012C44)


void blink_init();
void motor_init();

#endif