/*
* IncFile1.h
*
* Created: 11/26/2021 11:23:38 PM
*  Author: Admin
*/


#include <avr/io.h>
#include <util/delay.h>

#define KEY_PRT 	PORTD
#define KEY_DDR		DDRD
#define KEY_PIN		PIND

unsigned char colloc, rowloc;

char* keyfind()
{
	while(1)
	{
		KEY_DDR = 0xF0;           /*  port direction  */
		KEY_PRT = 0xFF;			  /*  activate pull up resistors of pins  */

		do
		{
			KEY_PRT = 0x0F; 	/*  activate pull up registers of last 4 pins  */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F); /* read status of column */
		}while(colloc != 0x0F);
		
		do
		{
			
			do
			{
				_delay_ms(20);             /* 20ms key debounce time */
				colloc = (KEY_PIN & 0x0F); /* read status of column */
				
				}while(colloc == 0x0F);        /* check for any key press */
				
				
				_delay_ms (40);	            /* 20 ms key debounce time */
				colloc = (KEY_PIN & 0x0F);
				
			}while(colloc == 0x0F);

			/* now check for rows */
			KEY_PRT = 0xEF;        /* check for pressed key in 1st row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 0;
				break;
			}

			KEY_PRT = 0xDF;		/* check for pressed key in 2nd row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 1;
				break;
			}
			
			KEY_PRT = 0xBF;		/* check for pressed key in 3rd row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 2;
				break;
			}

			KEY_PRT = 0x7F;		/* check for pressed key in 4th row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 3;
				break;
			}
		}

		if(colloc == 0x0E){
			switch (rowloc){
				case  0:
				return "7";
				case  1:
				return "4";
				case  2:
				return "1";
				case  3:
				return " ";
				
			}
		}
		if(colloc == 0x0D){
			switch (rowloc){
				case  0:
				return "8";
				case  1:
				return "5";
				case  2:
				return "2";
				case  3:
				return "0";
				
			}
		}
		else if(colloc == 0x0B){
			switch (rowloc){
				case  0:
				return "9";
				case  1:
				return "6";
				case  2:
				return "3";
				case  3:
				return "=";
				
			}
		}
		else{
			switch (rowloc){
				case  0:
				return "/";
				case  1:
				return "x";
				case  2:
				return "-";
				case  3:
				return "+";
				default:
				return "";
				
			}
		}
}