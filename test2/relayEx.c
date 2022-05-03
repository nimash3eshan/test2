/*
 * GccApplication4.c
 *
 * Created: 12/2/2021 8:17:33 PM
 * Author : Nishshanka
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define Relay PA0
#define F_CPU 8000000UL

void switchOn();
void switchOff();


/*int main(void)
{*/
    /* Replace with your application code */
	/*configure port A0 as a output port */
	/*DDRA =(1<<Relay);
	
    while (1) 
    {
		switchOn();
		_delay_ms(5000);
		switchOff();
		_delay_ms(5000);
    }
	return 0;
}*/
void switchOn()
{
	PORTA =(1<<Relay);
};
void switchOff()
{
	PORTA=(1<<Relay);
}

