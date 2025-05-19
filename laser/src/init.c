#include "../include/init.h"

// Blink init
void blink_init() 
{
    RCC_APB2ENR |= (1 << 4);

    GPIOC_CRH &= ~(0xF << 20);
    GPIOC_CRH |= (0x2 << 20);
}

void timer_init() 
{
    // Timer clock = 1mhz, 20ms period as 50hz and 1.5ms / pulse
    TIM1_PSC = 72 -1;
    TIM1_ARR = 20000 - 1;
    TIM1_CCR1 = 1500;

    TIM1_CCMR1 |= (0x6E << 4); // Enable PWM mode 1
    TIM1_CCMR1 |= (1 << 3);    // Preload register on TIMx_CCR1 enabled
    TIM1_CCER |= (1 << 0);     // CC1E enable
    TIM1_CR1 |= (1 << 7);      // Enable auto preload
    TIM1_CR1 |= (1 << 0);      // Enable counter
    TIM1_BDTR |= (1 << 15);    // Enable Main output
}

// Init motor pins for X,Y,Z axis
void motor_init() 
{
    RCC_APB2ENR |= (0xB << 2); // Enable gpio channels A and B
    RCC_APB2ENR |= (1 << 11);  // Enable Timer 1 clock

    // Init timer bits and calculate clock speed
    timer_init();
    
    GPIOA_CRH |= (0x3F3 << 0) | (0x3F3 << 4) | (0x3F3 << 8);
    GPIOA_CRL |= (0x3F2 << 0) | (0x3F2 << 4) | (0x3F2 << 8);
    
    GPIOB_CRL |= (10 << 12) | (10 << 16) | (10 << 20);
    GPIOB_CRH |= (10 << 20) | (10 << 24) | (10 << 28);
}