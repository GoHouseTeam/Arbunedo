/*
 * arbunedo/include/drivers/video/screen.c - The screen, a beautiful thing.
 * 
 * Copyright (c) 2021 https://github.com/iknowbrain/NIDOS
 */

#ifndef SCREEN_H
#define SCREEN_H
#include "../../init/system.h"
#include "../../kernel/string.h"
int cursorX , cursorY;
const uint8 sw ,sh ,sd ; 

void clearLine(uint8 from,uint8 to);

void updateCursor();

void clearScreen();

void scrollUp(uint8 lineNumber);

void newLineCheck();

void printch(char c);

void printk(string ch);
void set_screen_color_from_color_code(int color_code);
void set_screen_color(int text_color, int bg_color);
void printkcol(string ch, int text_color, int bg_color);


#endif
