#include <avr/io.h>
#include "stdio.h"
#include "uart.h"
#include <util/delay.h>

void USART_Init(void)
{
	UBRR0H = BAUDH;
	UBRR0L = BAUDL;

	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (0<<USBS0)|(3<<UCSZ00);

}
volatile unsigned char USART_GetChar(void)
{
	while(!(UCSR0A&(1<<RXC0)));
	return UDR0;
}
void USART_SendChar(unsigned char pData)
{
	while(!(UCSR0A&(1<<UDRE0)));
	UDR0=pData;
}
void USART_SendStr(char *pData)
{
	while(*pData){
		USART_SendChar(*pData++);
	}
}
void USART_SendNum(int16_t  numVal)
{
	char buff[20];
	sprintf(buff,"%d",numVal);
	USART_SendStr(buff);
}
