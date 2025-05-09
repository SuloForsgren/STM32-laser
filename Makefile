# Define the target eg. main.elf
TARGET = main

# Src to c and assembly files
SRCS = src/main.c src/startup.c
OBJS = $(SRCS:.c=.o)

# Define Cross Compiling
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# Set flags
CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -g -O0
LDFLAGS = -TSTM32F103C8.ld -nostartfiles

all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(OBJCOPY) -O ihex $@ $(TARGET).hex
	$(OBJCOPY) -O binary $@ $(TARGET).bin

# Clean the directory if needed
clean:
	rm -f *.o *.hex *.bin *.elf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Flashing rules for picoprobe --> openocd
flash: $(TARGET).elf
	openocd -f /usr/share/openocd/scripts/interface/cmsis-dap.cfg -f /usr/share/openocd/scripts/target/stm32f1x.cfg \
		-c "program $(TARGET).elf verify reset exit"