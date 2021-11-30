/*
* main.c
*
* Created: 11/20/2021 11:23:38 PM
*  Author: W.K. Milan Swanthra
*/


//Libraries used in the project
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

#define F_CPU 16000000UL

/*Custom Header Files*/

//LCD Header Files
#include "i2c.h"
#include "LCD_I2C.h"

//Keypad Header Files
#include "keypad.h"


//Global Variable
int num_trays = 0;
float vol = 0;

int main(void){
	
	/*---Function for initializing the i2c module
	and the LCD Display---*/
	i2c_init();
	i2c_start();
	i2c_write(0x70);
	lcd_init();
	
	//Main Program Loop
	while(1){
		//Displaying the starting information
		lcd_cmd(0x80);
		lcd_msg("Rubber Solution Mixer 1.0");
		lcd_cmd(0xC0);
		lcd_cmd(0x14);
		lcd_cmd(0x14);
		lcd_cmd(0x14);
		lcd_cmd(0x14);
		lcd_msg("Welcome");
		_delay_ms(500);
		for(int i = 0; i<27 ; i++)
		{
			lcd_cmd(0x18);
			_delay_ms(100);
		}
		
		//Getting the user input for the number of trays
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_msg("Number of trays?");
		lcd_cmd(0xC0);
		lcd_cmd(0x0F);
		
		char temp[10];
		char str[10];
		int digs=0;
		do
		{
			strcpy(temp,keyfind());
			
			if (strcmp (temp, "=")==0){
				if (digs>=1)
				{
					lcd_cmd(0x10);
					lcd_msg(" ");
					lcd_cmd(0x10);
					lcd_cmd(0x10);
					lcd_cmd(0x14);
					digs--;
					strcpy(&str[digs]," ");
				}
				continue;
			}
			lcd_msg(temp);
			strcpy(&str[digs],temp);
			digs++;
		} while (strcmp (temp, " ")!=0);

		num_trays = atoi(str);
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		
		//Getting the volume of trays in milliliters
		lcd_msg("Number of trays?");
		lcd_cmd(0xC0);
		lcd_cmd(0x0F);
		char temp[10];
		char str[10];
		int digs=0;
		do
		{
			strcpy(temp,keyfind());
			
			if (strcmp (temp, "=")==0){
				if (digs>=1)
				{
					lcd_cmd(0x10);
					lcd_msg(" ");
					lcd_cmd(0x10);
					lcd_cmd(0x10);
					lcd_cmd(0x14);
					digs--;
					strcpy(&str[digs]," ");
				}
				continue;
			}
			lcd_msg(temp);
			strcpy(&str[digs],temp);
			digs++;
		} while (strcmp (temp, " ")!=0);

		vol = atoi(str);
		lcd_cmd(0x01);
		lcd_cmd(0x80);
			
	}
}




