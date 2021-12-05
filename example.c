/*
 * GccApplication5.c
 *
 * Created: 12/4/2021 1:15:30 PM
 * Author : Nishshanka
 */ 

// Measuring distance using ultrasonic distance sensor

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#define F_CPU 8000000UL

static volatile int pulse = 0;
static volatile int i = 0;
void ultrasonic1();
void ultrasonic2();
void ultrasonic3();
void depth();
int main(void)
{
	DDRB=DDRB|(1<<3);
	DDRB=DDRB|(1<<4);
	DDRD = DDRD&~(1<<2);
	/*follow  output port use as a example to give output to display */
	DDRD =DDRD|(1<<3);
	while(1)
	{
		ultrasonic1();
	    depth();
		ultrasonic2();
	    depth();
		ultrasonic3();
	    depth();
	
	}
	return 0;
}


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

void depth()
{
	int16_t count_a = 0;
	int Sdepth;
	Sdepth=50; 
	_delay_ms(50);

	GICR |= 1<<INT0;
	MCUCR |= 1<<ISC00;

	sei();
		

	
	PORTD |= 1<<PIND0;
	_delay_us(15);

	PORTD &= ~(1<<PIND0);
	count_a = pulse/58;
	if(count_a>=Sdepth)
	{
		PORTD=PORTD|(1<<3);
	}
	else
	{
		PORTD=PORTD|(0<<3);
	}
			

	
}

ISR(INT0_vect)
{
	if(i == 0)
	{
		TCCR1B |= 1<<CS10;
		i = 1;
	}
	else
	{
		TCCR1B = 0;
		pulse = TCNT1;
		TCNT1 = 0;
		i = 0;
	}
}


