/*
 * arbunedo/include/util.h - Util.   
 * 
 * Copyright (c) 2021 https://github.com/iknowbrain/NIDOS
 */

#ifndef UTIL_H
#define UTIL_H

#include "types.h"

void memory_copy(char *source, char *dest, int nbytes);
void memory_set(uint8 *dest, uint8 val, uint32 len);
void int_to_ascii(int n, char str[]);  
int str_to_int(string ch)  ;
void * malloc(int nbytes);      

#endif
