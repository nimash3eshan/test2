/*
 * cust_lcd4.h
 *
 * Created: 11/26/2021 10:44:45 PM
 *  Author: Admin
 */ 
#include <avr/io.h>
#include <util/delay.h>

void lcd_init();
void dis_cmd(char cmd_value);
void dis_data(char data_value);
void lcdcmd(char cmdout);
void lcddata(char dataout);
