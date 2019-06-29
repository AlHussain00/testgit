/*
 * ADCINT_int.h
 *
 *  Created on: May 19, 2019
 *      Author: Al-Hussein
 */

#ifndef ADCINT_INT_H_
#define ADCINT_INT_H_

#define ADCINT_0		0
#define ADCINT_1		1
#define ADCINT_2		2
#define ADCINT_3		3
#define ADCINT_4		4
#define ADCINT_5		5
#define ADCINT_6		6
#define ADCINT_7		7

void ADCINT_voidInit(void);
void ADCINT_voidEnable(void);
void ADCINT_voidDisable(void);
void ADCINT_voidStartConv (uint8 ChannelNum);
void ADCINT_voidSetCallBack(void (*copy_ptr)(void));
uint8 ADCINT_uint8GetResult(uint8 ChannelNum);
uint16 ADCINT_uint16GetResult(uint8 ChannelNum);

#endif /* ADCINT_INT_H_ */
