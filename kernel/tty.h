/*
 * arbunedo/include/kernel/tty.h - Terminal.   
 * 
 * Copyright (c) 2021 https://github.com/iknowbrain/NIDOS
 */

#ifndef TTY_H
#define TTY_H
#include "../init/system.h"
#include "string.h"
#include "../drivers/keyboard/keyboard.h"
#include "../drivers/video/screen.h"
#include "types.h"
#include "util.h"

void tty(int n);

#endif
