/*
 * arbunedo/include/drivers/video/vga.h - The include file for VGA video port
 * 
 * Copyright (c) 2021 2008matteo
 */

#ifndef VGA_H
#define VGA_H

#include "../keyboard/types.h"

#define NULL 0

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200

uint16* vga_buffer;

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

#include "../keyboard/ps2.h"

#endif

extern uint32 vga_index;
//static uint32 next_line_index;
extern uint8 g_fore_color, g_back_color;
extern int digit_ascii_codes[10];

extern uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color);
extern void clear_vga_buffer(uint16 **buffer);
extern void init_vga(uint8 fore_color, uint8 back_color);
extern void printl();
extern void print_char(char ch);
extern void printk(char *str);
extern void print_int(int num);
extern uint8 inb(uint16 port);
extern void outb(uint16 port, uint8 data);
extern char get_input_keycode();
extern void wait_for_io(uint32 timer_count);
extern void sleep(uint32 timer_count);
extern void test_input();