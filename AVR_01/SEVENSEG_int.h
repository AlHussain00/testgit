/*
 * SEVENSEG_int.h
 *
 *  Created on: Apr 21, 2019
 *      Author: Al-Hussein
 */

#ifndef SEVENSEG_INT_H_
#define SEVENSEG_INT_H_

#define SEVENSEG_1 1
#define SEVENSEG_2 2

void SEVENSEG_voidInit();
void SEVENSEG_voidEnableSevenSeg(uint8 SegNum);
void SEVENSEG_voidDisableSevenSeg(uint8 SegNum);
void SEVENSEG_voidReset();
void SEVENSEG_voidIncrement();
void SEVENSEG_voidDecrement();
uint8 SEVENSEG_uint8GetValue();
void SEVENSEG_voidSetValue(uint8 Num);

#endif /* SEVENSEG_INT_H_ */
