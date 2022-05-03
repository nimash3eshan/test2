/*
 * adc.h
 *
 * Created: 10/11/2021 1:14:23 AM
 *  Author: Nimash
 */


#ifndef ADC_H_
#define ADC_H_

void ADC_Init()
{
	DDRA=0x0;			/* Make ADC port as input */
	ADCSRA = 0x87;			/* Enable ADC, fr/128  */
	ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */

}

int ADC_Read(char channel)
{
	int Ain,AinLow;

	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */

	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and
					Multiply with weight */
	Ain = Ain + AinLow;
	return(Ain);			/* Return digital value*/
}



#endif /* ADC_H_ */