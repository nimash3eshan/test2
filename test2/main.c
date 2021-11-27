#include <avr/io.h>
#include <stdio.h>
#include <string.h>

#define F_CPU 1600000UL
#include "cust_lcd4.h"
#include "keypad.h"

int num_trays = 0;
float vol = 0;

int main(void)
{
	unsigned char data0[]="Number of trays?";
	unsigned char data1[]="Vol. of tray (L)?";
	
	int i=0,x;
	DDRB=0xFF;
	lcd_init();
	
	while(data0[i]!='\0')
	{
		dis_data(data0[i]);
		_delay_ms(10);
		i++;
	}
	
	dis_cmd(0xC0);
	
	char key;
	do 
	{
		key = keyfind();
		if (key == ' ')
		{
			break;
		}else if (key == '=')
		{
			dis_cmd(0x04);
			dis_data(' ');
			dis_cmd(0x06);
		}else{
			dis_data(key);
		}
		
				
	} while (1);
	
	dis_cmd(0x01);
	dis_cmd(0x06);
	
	i=0;
	while(data1[i]!='\0')
	{
		dis_data(data1[i]);
		_delay_ms(10);
		i++;
	}
	
	
	
	//i=0;
	//while(data1[i]!='\0')
	//{
		//dis_data(data1[i]);
		//_delay_ms(100);
		//i++;
	//}
	
	//while(1)
	//{
		//for(x=0;x<16;x++)
		//{
			//dis_cmd(0x1c); 
			//_delay_ms(100);
		//}
	//}
	
}



