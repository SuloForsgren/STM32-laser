#include "../include/blink.h"
#include "../include/init.h"
#include "../include/core.h"
#include "../include/motor.h"


int main(void) {
    blink_init();
    motor_init();
    
    move_motor_x(1000);
    delay(1000000);

    move_motor_x(2000);
    delay(1000000);

    move_motor_x(1500);
    delay(1000000);

    while (1) {blink(); delay(500000);}

    return 0;
}