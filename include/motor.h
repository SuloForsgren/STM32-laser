#ifndef MOTOR_H
#define MOTOR_H

#define TIM1_CCR1 (*(volatile unsigned int*)0x40012C34)

void move_motor_x(int angle);

#endif