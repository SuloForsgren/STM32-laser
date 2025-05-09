// Define peripheral addresses
#define RCC_APB2ENR   (*(volatile unsigned int*)0x40021018)
#define GPIOC_CRH     (*(volatile unsigned int*)0x40011004)
#define GPIOC_BSRR    (*(volatile unsigned int*)0x40011010)

void delay(volatile unsigned int count) {
    while (count--) {
        __asm__("nop");
    }
}

void gpio_init(void) {
    // Enable GPIOC clock (bit 4 in APB2ENR)
    RCC_APB2ENR |= (1 << 4);

    // Set PC13 as General-purpose output push-pull (2 MHz)
    // PC13 config is in bits [23:20] of GPIOC_CRH
    GPIOC_CRH &= ~(0xF << 20);  // Clear bits
    GPIOC_CRH |=  (0x2 << 20);  // 0b0010: Output mode, max speed 2 MHz, push-pull
}

void gpio_set(void) {
    GPIOC_BSRR = (1 << 13);  // Set PC13 high
}

void gpio_clear(void) {
    GPIOC_BSRR = (1 << (13 + 16));  // Reset PC13
}

int main(void) {
    gpio_init();

    while (1) {
        gpio_clear();    // Turn LED ON (active-low)
        delay(500000);

        gpio_set();      // Turn LED OFF
        delay(500000);
    }

    return 0;
}
