/*
 * arbunedo/kernel/kernel.c - The central of everthing!
 * 
 * Copyright (c) 2021 2008matteo
 */

#include "include/drivers/video/vga.h"
#include "include/drivers/keyboard/utils.h"
#include "include/drivers/keyboard/char.h"
#include "include/kernel/kernel.h"

void usr_input()
{
  char ch = 0;
  char keycode = 0;

  do{
    keycode = get_input_keycode();
    if(keycode == KEY_ENTER){
      printl();
    }else{
      ch = get_ascii_char(keycode);
      print_char(ch);
    }

    if(keycode == KEY_H)
    {
      printk("K S");
    }

    if(keycode == KEY_C)
    {
      vga_buffer = (uint16*)VGA_ADDRESS;
      clear_vga_buffer(&vga_buffer);
    }

    if(keycode == KEY_R)
    {
      init_vga(RED, BLACK);
    }

    if(keycode == KEY_G)
    {
      init_vga(GREY, BLACK);
    }

    if(keycode == KEY_K)
    {
      printk("Version of the Arbunedo: 0.1.4 Beta");
      printk("For more information go to:");
      printk("ghteam.ddns.net");
    }

    sleep(0x02FFFFFF);
  }while(ch > 0);
}

void kernel_entry()
{
  init_vga(WHITE, BLACK);
  printk("Welcome to the Arbunedo (Version 0.1.4 Beta)");
  printk("Arbunedo is made by the GHTeam");
  printk("Type here, one key per second, ENTER to go to next line");
  printk("Digit 'H' for all commands");
  usr_input();
}

void init_kernel()
{
  kernel_entry();
}