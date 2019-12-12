#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdbool.h>
#include "ADC.h"
#include "uart.h"

int i;
uint16_t adc[100];
uint16_t threshold;
unsigned int adc_value;
unsigned int Logic_sens2;
int treshold;
unsigned int adcLow;
bool condition = true;

unsigned int throwFirstADC(bool, uint16_t);

//bsmillah
int main(void){
	USART_Init();
	DDRA = 0xFF;
	while(1){
		adc_value = ADCSingleRead(1);
		throwFirstADC(condition, adc_value);
		if(adc_value>=treshold){
			Logic_sens2=1;
		}else{
			Logic_sens2=0;
		}
		USART_SendStr("RAW = ");
		USART_SendNum(adc_value);
		USART_SendStr("\tDIGITAL = ");
		USART_SendNum(Logic_sens2);
		USART_SendStr("\n\r");
	}
}

unsigned int throwFirstADC(bool state, uint16_t adc)
{
	int low;
	if(state){
		low=adc;
		treshold=(low+1024)/2;
		condition=false;
	}
	return treshold;
}
