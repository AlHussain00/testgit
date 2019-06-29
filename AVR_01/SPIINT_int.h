/*
 * SPIINT_int.h
 *
 *  Created on: Jun 7, 2019
 *      Author: Al-Hussein
 */

#ifndef SPIINT_INT_H_
#define SPIINT_INT_H_

void SPIINT_voidInit(void);
void SPIINT_voidSend(uint8 data);
void SPIINT_voidEnableInterrupt(void);
void SPIINT_voidDisableInterrupt(void);
uint8* SPIINT_uint8Receive(void);
void SPIINT_voidSetCallBack(void (*copy_ptr)(void));

#endif /* SPIINT_INT_H_ */
