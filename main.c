/*
 * GccApplication3.c
 *
 * Created: 4/30/2022 7:54:26 PM
 * Author : Ishanka
 */ 
#define F_CPU 8000000UL
#define BAUD 9600
#define MYUBBR F_CPU/16/BAUD-1


#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include "flowsensor.h"

int main(void){
	DDRB = DDRB & (~(1<<2));    /*Make PB2 as input pin*/
	DDRD = DDRD & (~(1<<2));
	DDRD = DDRD & (~(1<<3));
	
	DDRB = DDRB | (1<<5);		/* Make PB5 as output pin */
	DDRB = DDRB | (1<<6);
	DDRB = DDRB | (1<<7);
	pump_w();
	_delay_ms(5000);
	pump_l();
	_delay_ms(5000);
	pump_a();
	_delay_ms(5000);
}

