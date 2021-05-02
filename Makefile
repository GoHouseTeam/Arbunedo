#
# arbunedo/Makefile - For execute the 'make' command
# Copyright (c) 2020 2008matteo
#

ifeq (,$(.VARIABLES)) # The variable .VARIABLES, new with 3.80, is never empty.
$(error GNU make version 3.80 or newer is required.)
endif

ASSEMBLER	=as
LINKER		=ld
COMPILER	=gcc

CFLAGS = -m32 -c -ffreestanding

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
	mkdir -p ${BUILD_DIR}/
	mkdir -p ${BUILD_DIR}/boot/
	mkdir -p ${BUILD_DIR}/boot/grub/

	@#Asseble the boot.asm file
	${ASSEMBLER} --32 ./${BOOT_DIR}/boot.asm -o ./${BUILD_DIR}/boot.o

	@#Build the .c files
	${COMPILER} -m32 -c kernel.c -o ./${BUILD_DIR}/kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
	${COMPILER} -m32 -c ./kernel/utils.c -o ./${BUILD_DIR}/utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
	${COMPILER} -m32 -c ./kernel/char.c -o ./${BUILD_DIR}/char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
	${COMPILER} -m32 -c ./drivers/video/vga.c -o ./${BUILD_DIR}/vga.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra

	@#Link files to Arbunedo.bin with linker.ld
	${LINKER} -m elf_i386 -T ${BOOT_DIR}/linker.ld ${BUILD_DIR}/kernel.o ${BUILD_DIR}/utils.o ${BUILD_DIR}/char.o ${BUILD_DIR}/vga.o ${BUILD_DIR}/boot.o -o ${BUILD_DIR}/boot/Arbunedo-${KERNEL_VERSION}.bin -nostdlib

	@#Verify if the Arbunedo.bin is x86 multiboot
	grub-file --is-x86-multiboot ./${BUILD_DIR}/boot/Arbunedo-${KERNEL_VERSION}.bin

	@#Copy the boot directory files in the build directory
	cp -r ./${BOOT_DIR}/ ${BUILD_DIR}/
	
	@#Create the Arbunedo.iso file
	grub-mkrescue -o Arbunedo-${KERNEL_VERSION}.iso ${BUILD_DIR}/

clean:
	@echo "Deleting the making files of Arbunedo..."
	rm -R ${BUILD_DIR}/
	rm Arbunedo-${KERNEL_VERSION}.iso

run:
	@echo "Run Arbunedo..."
	@#Start QEMU
	qemu-system-x86_64 -cdrom Arbunedo-${KERNEL_VERSION}.iso
