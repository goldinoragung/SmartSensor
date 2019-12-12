#ifndef MYUSART_H_
#define MYUSART_H_

#include <avr/io.h>

#define BAUD_RATE 9600
#define VBAUDRATE (((F_CPU/(BAUD_RATE*16UL)))-1)
#define BAUDH VBAUDRATE /256
#define BAUDL VBAUDRATE % 256

void USART_Init(void);
volatile unsigned char USART_GetChar(void);
void USART_SendChar(unsigned char);
void USART_SendStr(char *);
void USART_SendNum(int16_t);

#endif /* MYUSART_H_ */
