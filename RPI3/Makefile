TARGET = rpi3

CC = aarch64-elf-gcc
LD = aarch64-elf-ld
OC = aarch64-elf-objcopy


LINKER_SCRIPT = ./linker.ld

ASM_SRCS = $(wildcard boot/*.S)
ASM_OBJS = $(patsubst boot/%.S, build/%.os, $(ASM_SRCS))

VPATH = boot \
		hal/$(TARGET)

C_SRCS = $(notdir $(wildcard boot/*.c))
C_SRCS += $(notdir $(wildcard hal/$(TARGET)/*.c))
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

INC_DIRS =	-I include \
			-I hal \
			-I hal/$(TARGET)

CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles


kernel8 = build/kernel8.elf
kernel8_bin = build/kernel8.img


all: clean $(kernel8)


build/%.os: boot.S
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c ./boot/boot.S -o ./build/boot.o

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@


$(kernel8): $(ASM_OBJS) $(C_OBJS) $(LINKER_SCRIPT)
	$(LD) -nostdlib -nostartfiles ./build/boot.o $(C_OBJS) -T $(LINKER_SCRIPT) -o ./build/kernel8.elf
	$(OC) -O binary ./build/kernel8.elf ./build/kernel8.img

clean:
	rm -fr build
