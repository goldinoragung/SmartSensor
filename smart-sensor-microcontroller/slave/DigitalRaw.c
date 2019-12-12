#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "ADC.c"
#include "ADC.h"
#include "uart.c"
#include "uart.h"
#define adc_total, dig, DigVal;


void Digital()
{
	for(int i=0; i<3; i++){
		if (adc_total[i] > threshold[i])
			dig[i]=1;
		else
			dig[i]=0;
	}
	DigVal = (dig[2]*4)+(dig[1]*2)+dig[0];
}

