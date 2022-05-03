/*
 * sensor.h
 *
 * Created: 5/1/2022 4:24:24 PM
 *  Author: Nishshanka
 */ 


#include <avr/io.h>
	
#include <util/delay.h>
#include <stdlib.h>

static volatile int pulse = 0;
static volatile int i = 0;

void ultrasonic1();
void ultrasonic2();
void ultrasonic3();
int depth();

void ultrasonic1()
{
	PORTB=PORTB|(0<<3);
	PORTB=PORTB|(0<<4);
}

void ultrasonic2()
{
	PORTB=PORTB|(1<<3);
	PORTB=PORTB|(0<<4);
}


void ultrasonic3()
{
	PORTB=PORTB|(0<<3);
	PORTB=PORTB|(1<<3);
}

int depth()
{
	int16_t count_a = 0;
	int Sdepth;
	Sdepth=50; //assume that the height of the tank is 50cm
	_delay_ms(50);
	
	PORTB |= 1<<PINB1;
	_delay_us(15);

	PORTB &= ~(1<<PINB1);
	count_a = pulse/58;
	if(count_a>=Sdepth)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

