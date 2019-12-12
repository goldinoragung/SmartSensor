#include <avr/io.h>
#include <util/delay.h>
#include "MyUSART.h"

unsigned int num_variable;

int main(void)
{
	USART_Init();
	num_variable=100;
	while(1){
		USART_SendNum(num_variable);
		USART_SendStr("\n\r");
		if(++num_variable>250){
			num_variable=0;
		}

		_delay_ms(50);
	}
}


