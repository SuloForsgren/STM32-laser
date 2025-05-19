#ifndef MOTOR_H
#define MOTOR_H

#include "core.h"
#include <stdbool.h>

#define TIM1_CCR1 (*(volatile unsigned int*)0x40012C34)
#define GPIOB_BSRR (*(volatile unsigned int*)0x40010C10)


void move_motor_x(bool direction, int steps);

#endif