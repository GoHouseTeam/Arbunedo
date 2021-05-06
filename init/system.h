/*
 * arbunedo/include/system.h - System.   
 * 
 * Copyright (c) 2021 https://github.com/iknowbrain/NIDOS
 */

#ifndef SYSTEM_H
#define SYSTEM_H
#include "../kernel/types.h"
uint8 inportb (uint16 _port);

void outportb (uint16 _port, uint8 _data);

#endif
