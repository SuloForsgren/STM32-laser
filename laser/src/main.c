#include "../include/blink.h"
#include "../include/init.h"
#include "../include/core.h"
#include "../include/motor.h"

#include <stdbool.h>

#define CLOCKWISE true
#define COUNTER_CLOCKWISE false

int main(void) {
    blink_init();
    motor_init();
    
    move_motor_x(CLOCKWISE, 100);
    delay(1000000);

    while (1) { blink(); delay(500000); }

    return 0;
}