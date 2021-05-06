/*
 * arbunedo/include/kernel/kernel.h - The central of everthing in h!
 * 
 * Copyright (c) 2021 2008matteo
 */

#ifndef KERNEL_H
#define KERNEL_H

#include "init.h"
#include "../kernel/isr.h"
#include "../kernel/tty.h"
#include "../drivers/keyboard/keyboard.h"
#include "../kernel/idt.h"
#include "../kernel/util.h"

void kernel_entry();

#endif