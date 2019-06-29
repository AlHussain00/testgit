/*
 * ADC_int.h
 *
 *  Created on: Apr 30, 2019
 *      Author: Al-Hussein
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#define ADC_0		0
#define ADC_1		1
#define ADC_2		2
#define ADC_3		3
#define ADC_4		4
#define ADC_5		5
#define ADC_6		6
#define ADC_7		7

void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
void ADC_voidStartConv (void);
void ADC_voidSelectChannel(uint8 ChannelNum);
uint8 ADC_uint8GetResult(void);
uint16 ADC_uint16GetResult(void);

#endif /* ADC_INT_H_ */
