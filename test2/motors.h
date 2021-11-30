#include <avr/io.h> /* Include AVR std. library file */
#include <util/delay.h> /* Include delay header file */

void mixpartStepper();
void pushingpartStepper();
void mixpartDCmotor();

//int main(void)
//{
	//
	////int period;
	//DDRA=0x00;
	//DDRC = 0xFF; /* Make PORTA lower pins as output */
	//DDRD = 0xFF; //PORTD as Output
	//PORTC=0X00;
	//PORTD = 0x00;
	//PORTA=0XFF;
	//
	//
	//
	//pushingpartStepper();
	//while(1)	{					// Push a tray on to the convey belt
		//if (0!=(PINA &(1<<PA0)))					// IR Sensor detects the tray or not
		//{
			//mixpartStepper();						// stepper motor at mixing position rotates
			//
		//}
	//}
	//
	//
//}

void pushingpartStepper()
{
	int period= 6;
	for(int i=0;i<1;i++)
	{
		
		PORTC = 0x09;
		_delay_ms(period);
		PORTC = 0x08;
		_delay_ms(period);
		PORTC = 0x0C;
		_delay_ms(period);
		PORTC = 0x04;
		_delay_ms(period);
		PORTC = 0x06;
		_delay_ms(period);
		PORTC = 0x02;
		_delay_ms(period);
		PORTC = 0x03;
		_delay_ms(period);
		PORTC = 0x01;
		_delay_ms(period);
	}
	PORTC = 0x09; /* Last step to initial position */
	_delay_ms(period);
	
	
	
	for(int i=0;i<1;i++)
	{
		PORTC = 0x01;
		_delay_ms(period);
		PORTC = 0x03;
		_delay_ms(period);
		PORTC = 0x02;
		_delay_ms(period);
		PORTC = 0x06;
		_delay_ms(period);
		PORTC = 0x04;
		_delay_ms(period);
		PORTC = 0x0C;
		_delay_ms(period);
		PORTC = 0x08;
		_delay_ms(period);
		PORTC = 0x09;
		_delay_ms(period);
		
	}
	PORTC = 0x09;
	_delay_ms(period);
	_delay_ms(10);
}

void mixpartStepper()
{
	int period=6;
	for(int i=0;i<2;i++)
	{
		
		PORTC = 0x90;
		_delay_ms(period);
		PORTC = 0x80;
		_delay_ms(period);
		PORTC = 0xC0;
		_delay_ms(period);
		PORTC = 0x40;
		_delay_ms(period);
		PORTC = 0x60;
		_delay_ms(period);
		PORTC = 0x20;
		_delay_ms(period);
		PORTC = 0x30;
		_delay_ms(period);
		PORTC = 0x10;
		_delay_ms(period);
	}
	PORTC = 0x90; /* Last step to initial position */
	_delay_ms(period);
	
	//mixpartDCmotor();
	
	/* Rotate Stepper Motor Anticlockwise with Full step sequence */
	for(int i=0;i<2;i++)
	{
		PORTC = 0x10;
		_delay_ms(period);
		PORTC = 0x30;
		_delay_ms(period);
		PORTC = 0x20;
		_delay_ms(period);
		PORTC = 0x60;
		_delay_ms(period);
		PORTC = 0x40;
		_delay_ms(period);
		PORTC = 0xC0;
		_delay_ms(period);
		PORTC = 0x80;
		_delay_ms(period);
		PORTC = 0x90;
		_delay_ms(period);
		
	}
	PORTC = 0x90;
	_delay_ms(period);
	_delay_ms(10);
}

void mixpartDCmotor()
{
	//    for(int i=0; i<1;i++)
	// 	{
	PORTD = 0x02;
	_delay_ms(2000);
	PORTD = 0x03;
	// 		_delay_ms(2000);
	// 		PORTD = 0x01;
	// 		_delay_ms(2000);
	// 		PORTD = 0x00;
	// 		_delay_ms(2000);
	
	//}
	
}