
MCPU =cortex-a53

TARGET = rpi3

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy


LINKER_SCRIPT = ./linker.ld

ASM_SRCS = $(wildcard boot/*.S)
ASM_OBJS = $(patsubst boot/%.S, build/%.os, $(ASM_SRCS))

VPATH = boot \
		hal/$(TARGET)	\
		lib

C_SRCS = $(notdir $(wildcard boot/*.c))
C_SRCS += $(notdir $(wildcard hal/$(TARGET)/*.c))
C_SRCS += $(notdir $(wildcard lib/*.c))

C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

INC_DIRS =  -I include \
			-I hal \
			-I hal/$(TARGET)  \
			-I lib

CFLAGS = -fpic -ffreestanding -std=gnu99 -Wall -O2 


kernel8 = build/kernel8.elf
kernel8_bin = build/kernel8.img


all: clean $(kernel8)


build/%.os: boot.S
	mkdir -p $(shell dirname $@)
	$(CC) -mcpu=$(MCPU) $(CFLAGS) $(INC_DIRS) -c ./boot/boot.S -o ./build/boot.o

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -mcpu=$(MCPU) $(CFLAGS) $(INC_DIRS) -c $< -o $@


$(kernel8): $(ASM_OBJS) $(C_OBJS) $(LINKER_SCRIPT)
	$(LD) -nostdlib -nostartfiles ./build/boot.o $(C_OBJS) -T $(LINKER_SCRIPT) -o ./build/kernel7.elf
	$(OC) -O binary ./build/kernel7.elf ./build/kernel7.img

clean:
	rm -fr build
