/*
 * GccApplication10.c
 *
 * Created: 5/2/2022 8:15:36 AM
 * Author : Nishshanka
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "ToRelay.h"

int main()
{
	/*configure the port C3 as output */
	DDRC=DDRC|(1<<3);
	
	while(1)
	{
		
		switchOn();
		_delay_ms(5000);
		switchOff();
		_delay_ms(5000);
	}

	return 0;
}






