/*
 * arbunedo/boot/boot.asm - In this file there is the BOOT! MAGIC!
 * 
 * Copyright (c) 2021 2008matteo
 */

# Set flags ton 0
.set FLAGS,    0

# Set magic number to 0x1BADB002 to identified by bootloader 
.set MAGIC,    0x1BADB002

# Set the checksum
.set CHECKSUM, -(MAGIC + FLAGS)

# Set multiboot enabled
.section .multiboot

# Define type to long for each data defined as above
.long MAGIC
.long FLAGS
.long CHECKSUM

# Set the stack bottom 
stackBottom:

# Define the maximum size of stack to 512 bytes
.skip 4096

# Set the stack top which grows from higher to lower
stackTop:

.section .text
.global _start
.type _start, @function

_start:

  # assign current stack pointer location to stackTop
	mov $stackTop, %esp

  # Call main void of the Arbunedo
	call init_kernel

	cli

# Put system in infinite loop
hltLoop:

	hlt
	jmp hltLoop

.size _start, . - _start
