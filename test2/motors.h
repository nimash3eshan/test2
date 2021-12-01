/*
* main.c
*
* Created: 11/29/2021 11:23:38 PM
*  Author: Githmi Paranahewa
*/

#include <avr/io.h> /* Include AVR std. library file */
#include <util/delay.h> /* Include delay header file */

#define STPR_PRT PORTA
#define STPR_DDR DDRA
#define STPR_PIN PINA

#define DC_PRT PORTB
#define DC_DDR DDRB
#define DC_PIN PINB

void dc_init();
void dc_stp();
void dc_clk(int);
void dc_aclk(int);
void stpr_init();
void stpr_clk(int,int);
void stpr_aclk(int,int);
void acvt_mixer();
void acvt_trayPsh();
void acvt_lwr_mixr();


void acvt_mixer(){
	dc_init();
	dc_clk(2000);
}
void acvt_trayPsh(){
	stpr_init();
	stpr_clk(2,0);
	_delay_ms(1000);
	stpr_aclk(2,0) ;
}
void acvt_lwr_mixr(){
	stpr_init();
	stpr_clk(2,4);
	_delay_ms(1000);
	stpr_aclk(2,4);
}

//Stepper Motor functions
void stpr_init(){
	STPR_DDR = 0xFF;
	STPR_PRT = 0X00;
	
}

void stpr_clk(int cycles, int mtr){
	
	const unsigned int period= 60;
	for(int i=0;i<cycles;i++)
	{
		
		STPR_PRT = 0x09<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x08<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x0C<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x04<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x06<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x02<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x03<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x01<<mtr;
		_delay_ms(period);
	}
	STPR_PRT = 0x09<<mtr; /* Last step to initial position */
	_delay_ms(period);
	
}

void stpr_aclk(int cycles,int mtr){
	
	int period= 60;
	for(int i=0;i<cycles;i++)
	{
		STPR_PRT = 0x01<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x03<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x02<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x06<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x04<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x0C<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x08<<mtr;
		_delay_ms(period);
		STPR_PRT = 0x09<<mtr;
		_delay_ms(period);
		
	}
	STPR_PRT = 0x09<<mtr;
	_delay_ms(period);
}


// DC Motor Functions
void dc_init(){
	DC_DDR |= 0x03; //Set pin B0 and B1 to output
	DC_PRT |= (0X00 &~(1<<0)); //Set pin B0 to low to avoid any initial movements
	DC_PRT |= (0X00 &~(1<<0)); //Set pin B1 to low to avoid any initial movements
}

void dc_stp(){
	DC_PRT &= 0xFC; // Set the pins B0 and B1 to low to stop the motor
}

void dc_aclk(int ms){
	DC_PRT |= (1<<0); //Set pin B0 to high for clock wise rotation
	while (ms--)
	{
		_delay_ms(1);
	}
	dc_stp();
}
	
void dc_clk(int ms){
	DC_PRT |= (1<<1); //Set pin B0 to high for clock wise rotation
	while (ms--)
	{
		_delay_ms(1);
	}
	dc_stp();
}
	
