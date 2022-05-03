/*
 * ToRelay.h
 *
 * Created: 5/2/2022 8:18:58 AM
 *  Author: Nishshanka
 */ 


#include <avr/io.h>
#include <util/delay.h>


void switchOff();
void switchOn();

void switchOn()
{
	PORTC =PORTC|(1<<3);
}
void switchOff()
{
	PORTC = PORTC|(0<<3);
}