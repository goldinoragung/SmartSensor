#ifndef ADC_H_
#define ADC_H_

#include "stdio.h"

void ADC_INISIALISASI(void);
void READ_ADC(uint8_t channel);
uint8_t HasilADCH(uint8_t channel);
uint8_t HasilADCL(uint8_t channel);
uint16_t TenADC(uint16_t channel);
int ADCSingleRead(uint8_t adcpin);


#endif /* ADC_H_ */
