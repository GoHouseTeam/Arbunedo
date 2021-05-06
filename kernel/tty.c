/*
 * arbunedo/kernel/tty.c - Terminal.   
 * 
 * Copyright (c) 2021 https://github.com/iknowbrain/NIDOS
 */

#include "tty.h"

void tty(int n)
{
	string ch = (string) malloc(200); // util.h
	int counter = 0;
	do
	{
		printk("Arbunedo@hostname ");
		printk(int_to_string(n));
		printk("> ");
		ch = readStr(); //memory_copy(readStr(), ch,100);
		if(strEql(ch,"terminal"))
		{
			printk("\n");
			tty(n+1);
		}
		else if(strEql(ch,"clear"))
		{
			clearScreen();
		}
		else if(strEql(ch,"exit"))
		{
			printk("\nGood Bye!\n");
		}
		else if(strEql(ch,"echo"))
		{
			echo();
		}
		else if(strEql(ch,"help"))
		{
			help();
		}
		else if(strEql(ch,"color"))
		{
			set_background_color();
		}
		else
		{
			printk("\nCommand not found\n");
		} 
	} while (!strEql(ch,"exit"));
}

void echo()
{
	printk("\n");
	string str = readStr();
	printk("\n");
	printk(str);
	printk("\n");
}

void fill_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		printk("ARR[");
		printk(int_to_string(i));
		printk("]: ");
		arr[i] = str_to_int(readStr());
		printk("\n");
	}
}
void printk_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		/*printk("ARR[");
		printk(int_to_string(i));
		printk("]: ");*/
		printk(int_to_string(arr[i]));
		printk("   ");
	}
	printk("\n");
}

void set_background_color()
{
	printk("\nColor codes : ");
	printk("\n0 : black");
	printkcol("\n1 : blue",1,0);
	printkcol("\n2 : green",2,0);
	printkcol("\n3 : cyan",3,0);
	printkcol("\n4 : red",4,0);
	printkcol("\n5 : purple",5,0);
	printkcol("\n6 : orange",6,0);
	printkcol("\n7 : grey",7,0);
	printkcol("\n8 : dark grey",8,0);
	printkcol("\n9 : blue light",9,0);
	printkcol("\n10 : green light",10,0);
	printkcol("\n11 : blue lighter",11,0);
	printkcol("\n12 : red light",12,0);
	printkcol("\n13 : rose",13,0);
	printkcol("\n14 : yellow",14,0);
	printkcol("\n15 : white",15,0);
	
	printk("\n\nText color? : ");
	int text_color = str_to_int(readStr());
	printk("\n\nBackground color? : ");
	int bg_color = str_to_int(readStr());
	set_screen_color(text_color,bg_color);
	clearScreen();
}

void help()
{
	printk("\nterminal: Launch a new terminal");
	printk("\nclear: Clears the screen");
	printk("\necho: Reprint a given text");
	printk("\nexit: Quits the current shell");
	printk("\ncolor: Changes the colors of the terminal");
	printk("\n\n");
}

