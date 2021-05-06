#
# arbunedo/Makefile - For execute the 'make' command
# Copyright (c) 2021 2008matteo
#

ifeq (,$(.VARIABLES)) # The variable .VARIABLES, new with 3.80, is never empty.
$(error GNU make version 3.80 or newer is required.)
endif

ASSEMBLER	=as
LINKER		=ld
COMPILER	=gcc
EMULATOR	=qemu-system-x86_64

ASFLAGS 		= --32
LDFLAGS 		= -m elf_i386 -T
CFLAGS 			= -m32 -c -ffreestanding
EMULATORFLAGS	= -cdrom

BUILD_DIR =./build
BOOT_DIR  =./boot

KERNEL_VERSION =0.1.5

all:
	@echo "Usage: make mrpanda for building Arbunedo;"
	@echo "make clean for deleting the kernel making files;"
	@echo "make run for running the Arbunedo in QEMU."
	@echo " "
	@echo "Make sure xorriso, gcc, QEMU and GRUB are installed."
	@echo " "
	@echo "Arbunedo made by GHTeam"

mrpanda:
	@echo "Compiling Arbunedo V.${KERNEL_VERSION}..."

	@#Create the directory
	mkdir -p ${BUILD_DIR}/boot/grub/

	@#Asseble the boot.asm file
	${ASSEMBLER} ${ASFLAGS} ${BOOT_DIR}/boot.asm -o ./${BUILD_DIR}/boot.o

	@#Build the .c files
	${COMPILER} ${CFLAGS} ./init/init.c -o ${BUILD_DIR}/init.o
	${COMPILER} ${CFLAGS} ./init/kernel.c -o ${BUILD_DIR}/kernel.o
	${COMPILER} ${CFLAGS} ./init/system.c -o ${BUILD_DIR}/system.o
	${COMPILER} ${CFLAGS} ./drivers/video/screen.c -o ${BUILD_DIR}/screen.o
	${COMPILER} ${CFLAGS} ./drivers/keyboard/keyboard.c -o ${BUILD_DIR}/keyboard.o
	${COMPILER} ${CFLAGS} ./kernel/idt.c -o ${BUILD_DIR}/idt.o
	${COMPILER} ${CFLAGS} ./kernel/isr.c -o ${BUILD_DIR}/isr.o
	${COMPILER} ${CFLAGS} ./kernel/string.c -o ${BUILD_DIR}/string.o
	${COMPILER} ${CFLAGS} ./kernel/tty.c -o ${BUILD_DIR}/tty.o
	${COMPILER} ${CFLAGS} ./kernel/util.c -o ${BUILD_DIR}/util.o

	@#Link files to Arbunedo.bin with linker.ld
	${LINKER} ${LDFLAGS} ${BOOT_DIR}/linker.ld ${BUILD_DIR}/*.o -o ${BUILD_DIR}/boot/Arbunedo-${KERNEL_VERSION}.bin -nostdlib

	@#Verify if the Arbunedo.bin is x86 multiboot
	grub-file --is-x86-multiboot ./${BUILD_DIR}/boot/Arbunedo-${KERNEL_VERSION}.bin

	@#Copy the boot directory files in the build directory
	cp -r ${BOOT_DIR}/ ${BUILD_DIR}/
	
	@#Create the Arbunedo.iso file
	grub-mkrescue -o ${BUILD_DIR}/Arbunedo-${KERNEL_VERSION}.iso ${BUILD_DIR}/

clean:
	@echo "Deleting the making files of Arbunedo..."
	rm -R ${BUILD_DIR}/

run:
	@echo "Run Arbunedo..."
	@#Start QEMU
	${EMULATOR} ${EMULATORFLAGS} ${BUILD_DIR}/Arbunedo-${KERNEL_VERSION}.iso
