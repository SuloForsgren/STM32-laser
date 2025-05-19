# Define the target eg. main.elf
TARGET = main

INCLUDE_DIR = include
BLINK_DIR = blink

LINKER = laser/board_config/STM32F103C8.ld

# Src to c and assembly files
SRCS := $(wildcard laser/src/*.c)
OBJS = $(SRCS:.c=.o)

# Define Cross Compiling
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# Set flags
CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -g -O0 -I$(INCLUDE_DIR)/$(BLINK_DIR)
LDFLAGS = -T$(LINKER) -nostartfiles

UNAME_S := $(shell uname -s)

# Make the target, flash to stm32 and clean
all: $(TARGET).elf flash clean

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(OBJCOPY) -O ihex $@ $(TARGET).hex
	$(OBJCOPY) -O binary $@ $(TARGET).bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the directory if needed
clean:
	rm -f *.o *.hex *.bin *.elf
	rm -f laser/src/*.o

# Flashing rules for picoprobe --> openocd
flash: $(TARGET).elf
	openocd -f ./laser/board_config/cmsis-dap.cfg -f ./laser/board_config/stm32f1x.cfg \
		-c "program $(TARGET).elf verify reset exit"