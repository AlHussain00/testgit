/*
 * UART_int.h
 *
 *  Created on: May 22, 2019
 *      Author: Al-Hussein
 */

#ifndef UART_INT_H_
#define UART_INT_H_

void UART_voidInit(void);
void UART_voidSend(uint8 data);
uint8 UART_uint8Receive(void);

#endif /* UART_INT_H_ */
