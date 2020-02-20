TARGET = rpi3

# CC = aarch64-elf-gcc
# LD = aarch64-elf-ld
# OC = aarch64-elf-objcopy
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
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

CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles


# kernel8 = build/kernel8.elf
# kernel8_bin = build/kernel8.img
kernel7 = build/kernel7.elf
kernel7_bin = build/kernel7.img


# all: clean $(kernel8)
all: clean $(kernel7)


build/%.os: boot.S
	mkdir -p $(shell dirname $@)
#	$(CC) $(CFLAGS) $(INC_DIRS) include -c ./boot/boot.S -o ./build/boot.o 
	$(CC) $(CFLAGS) $(INC_DIRS) -mcpu=cortex-a53 -fpic -ffreestanding -c ./boot/boot.S -o ./build/boot.o 

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -mcpu=cortex-a53 $(CFLAGS) $(INC_DIRS) -c $< -o $@


#$(kernel8): $(ASM_OBJS) $(C_OBJS) $(LINKER_SCRIPT)
#	$(LD) -nostdlib -nostartfiles ./build/boot.o $(C_OBJS) -T $(LINKER_SCRIPT) -o ./build/kernel8.elf
#	$(OC) -O binary ./build/kernel8.elf ./build/kernel8.img

$(kernel7): $(ASM_OBJS) $(C_OBJS) $(LINKER_SCRIPT)
	$(CC) -T $(LINKER_SCRIPT) -o ./build/kernel7.elf -ffreestanding -O2 -nostdlib ./build/*.o -lgcc
	$(OC) -O binary ./build/kernel7.elf ./build/kernel7.img

clean:
	rm -fr build

pull:
	git pull https://github.com/ImSangKyun/SmartUniverse
