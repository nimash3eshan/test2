/*
 * CFile1.c
 *
 * Created: 11/26/2021 10:43:44 PM
 *  Author: Admin
 */ 
#include "cust_lcd4.h"
#define rs PB2
#define en PB3


void lcd_init()	// function for initialize
{
	dis_cmd(0x02);		// to initialize LCD in 4-bit mode.
	dis_cmd(0x28);
	//dis_cmd(0x01);	                  	//to initialize LCD in 2 lines, 5X7 dots and 4bit mode.
	dis_cmd(0x0E);
	dis_cmd(0x06);
	//dis_cmd(0x83);
}

void dis_cmd(char cmd_value)
{
	char cmd_value1;
	
	cmd_value1 = cmd_value & 0xF0;		//mask lower nibble because PA4-PA7 pins are used.
	lcdcmd(cmd_value1);			// send to LCD
	
	cmd_value1 = ((cmd_value<<4) & 0xF0);	//shift 4-bit and mask
	lcdcmd(cmd_value1);			// send to LCD
}


void dis_data(char data_value)
{
	char data_value1;
	
	data_value1=data_value&0xF0;
	lcddata(data_value1);
	
	data_value1=((data_value<<4)&0xF0);
	lcddata(data_value1);
}

void lcdcmd(char cmdout)
{
	PORTB=cmdout;
	PORTB&=~(1<<rs);
	//PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(1);
	PORTB&=~(1<<en);
}

void lcddata(char dataout)
{
	PORTB=dataout;
	PORTB|=(1<<rs);
	//PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(1);
	PORTB&=~(1<<en);
}