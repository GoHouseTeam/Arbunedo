/*
 * arbunedo/kernel/kernel.c - The central of everthing!
 * 
 * Copyright (c) 2021 2008matteo
 */

#include "kernel.h"

void kernel_entry()
{
  printk("Welcome to the Arbunedo (Version 0.1.5 Beta)\nArbunedo is made by the GHTeam\n\n");
  tty(1);
}

void preinit_kernel()
{
  init_kernel();
}
