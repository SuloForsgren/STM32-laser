#include "../include/motor.h"


void move_motor_x(bool direction, int steps) 
{
    if (direction) 
    {
        GPIOB_BSRR |= (1 << 3);
    }
    else 
    {
        GPIOB_BSRR |= (1 << 19);
    }

    GPIOB_BSRR |= (1 << 13);

    for (int i = 0; i < steps; i++) 
    {
        TIM1_CCR1 = 1500;
        micro_delay(1000);
    }

    GPIOB_BSRR |= (1 << 29);
}