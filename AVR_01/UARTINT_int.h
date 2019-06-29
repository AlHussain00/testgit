/*
 * UARTINT_int.h
 *
 *  Created on: May 25, 2019
 *      Author: Al-Hussein
 */

#ifndef UARTINT_INT_H_
#define UARTINT_INT_H_

#define DATA_NUM_1			0
#define DATA_NUM_2			1
#define DATA_NUM_3			2
#define DATA_NUM_4			3
#define DATA_NUM_5			4
#define DATA_NUM_6			5

void UARTINT_voidInit(void);
void UARTINT_voidSend(uint8 data);
void UARTINT_voidEnableRXInterrupt(void);
void UARTINT_voidDisableRXInterrupt(void);
void UARTINT_voidEnableTXInterrupt(void);
void UARTINT_voidDisableTXInterrupt(void);
uint8* UARTINT_uint8Receive(void);
void UARTINT_voidSetRXCallBack(void (*copy_ptr)(void));
void UARTINT_voidSetTXCallBack(void (*copy_ptr)(void));

#endif /* UARTINT_INT_H_ */
