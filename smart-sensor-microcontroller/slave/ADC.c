#include "ADC.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void ADC_INISIALISASI(void){
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1);
	ADMUX |= (1<<ADLAR) | (1<<REFS0);
	ADCSRA |= (1<<ADEN);
}

void READ_ADC(uint8_t channel){
	ADMUX &= ~(0x1F);
	ADMUX |= channel;
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA |= (1<<ADIF);
}

uint8_t HasilADCH(uint8_t channel){
	return ADCH;
}

uint8_t HasilADCL(uint8_t channel){
	return ADCL;
}
uint16_t TenADC(uint16_t channel)
{
	uint16_t ADC10Val=0;
	ADC10Val = ADCL;
	ADC10Val = (ADCH<<8)+ADC10Val;

	return ADC10Val;
}
int ADCSingleRead(uint8_t adcpin)
{
	int adcVal;
	ADMUX = adcpin;        // use #1 ADC
	ADMUX |= (1 << REFS0);   // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);  // clear for 10 bit resolution

	// 128 prescale for 8Mhz
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	ADCSRA |= (1 << ADEN);    // Enable the ADC
	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	while(ADCSRA & (1 << ADSC)); // waits for the ADC to finish

	adcVal = ADCL;
	adcVal = (ADCH <<8)+adcVal;
	return adcVal;
}
