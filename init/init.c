/*
 * arbunedo/init.c - This file starts the kernel.
 * 
 * Copyright (c) 2021 2008matteo
 */

#include "init.h"

void init_kernel()
{
    isr_install();
	clearScreen();
    kernel_entry();
}