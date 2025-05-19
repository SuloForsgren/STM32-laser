#include <stdint.h>

// From linker script
extern uint32_t _stack;
extern uint32_t _data, _edata, _data_loadaddr;
extern uint32_t __bss_start__, __bss_end__;

// Forward declarations
void reset_handler(void);
void default_handler(void);

// Vector table
__attribute__((section(".vectors")))
void (* const vector_table[])(void) = {
    (void (*)(void))(&_stack), // Initial stack pointer
    reset_handler,             // Reset handler
    default_handler,           // NMI
    default_handler,           // Hard fault
    // add more if needed
};

// Reset handler
void reset_handler(void) {
    // Copy .data section from Flash to RAM
    uint32_t *src = &_data_loadaddr;
    uint32_t *dst = &_data;
    while (dst < &_edata) {
        *(dst++) = *(src++);
    }

    // Zero initialize the .bss section
    for (uint32_t *bss = &__bss_start__; bss < &__bss_end__; bss++) {
        *bss = 0;
    }

    extern int main(void);
    main();

    while (1); // Loop if main returns
}

// Fallback handler
void default_handler(void) {
    while (1);
}
