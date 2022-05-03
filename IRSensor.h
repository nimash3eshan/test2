/*
 * IRSensor.h
 * Created: 12/4/2021 3:54:04 PM
 *  Author: Githmi Paranahewa
 */ 

#include <avr/io.h> /* Include AVR std. library file */
#include <util/delay.h> /* Include delay header file */

#define IR_PRT PORTC
#define IR_DDR DDRC
#define IR_PIN PINC
#define IR_ConnectPIN PC2

void ir_init();
void act_IR();

void ir_init(){
	IR_DDR =0xF0;
	IR_PRT =0x0F;
}

void act_IR(){
	ir_init();
	while(1)	{
		if (0!=(IR_PIN &(1<<IR_ConnectPIN)))	// IR Sensor detects the tray or not
		{
			return 1;
		}
	}
}
