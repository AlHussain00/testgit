/*
 * UART_prog.c
 *
 *  Created on: May 22, 2019
 *      Author: Al-Hussein
 */

#include "Std_Types.h"
#include "BitMath.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_reg.h"
#include "UART_int.h"


void UART_voidInit(void)
{
	uint8 UCSRC_var = 0x80;

	//Receiving or transmitting
#if TX_ENABLE == ENABLE
	SET_BIT(UCSRB,TXEN);
#endif
#if RX_ENABLE == ENABLE
	SET_BIT(UCSRB,RXEN);
#endif
	//Data size
#if CHAR_SIZE == _5_BIT
	CLEAR_BIT(UCSRB,UCSZ2);
	CLEAR_BIT(UCSRC_var,UCSZ1);
	CLEAR_BIT(UCSRC_var,UCSZ0);
#elif CHAR_SIZE == _6_BIT
	CLEAR_BIT(UCSRB,UCSZ2);
	CLEAR_BIT(UCSRC_var,UCSZ1);
	SET_BIT(UCSRC_var,UCSZ0);
#elif CHAR_SIZE == _7_BIT
	CLEAR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC_var,UCSZ1);
	CLEAR_BIT(UCSRC_var,UCSZ0);
#elif CHAR_SIZE == _8_BIT
	CLEAR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC_var,UCSZ1);
	SET_BIT(UCSRC_var,UCSZ0);
#elif CHAR_SIZE == _9_BIT
	SET_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC_var,UCSZ1);
	SET_BIT(UCSRC_var,UCSZ0);
#endif
	//Choose UART mode
#if MODE == ASYNCH
	CLEAR_BIT(UCSRC_var,UMSEL);
#else
	SET_BIT(UCSRC_var,UMSEL);
#endif
	//Check Parity mode
#if PARRITY_MODE == DISABLE
	CLEAR_BIT(UCSRC_var,UPM0);
	CLEAR_BIT(UCSRC_var,UPM1);
#elif PARRITY_MODE == ENABLE_EVEN_PARITY
	CLEAR_BIT(UCSRC_var,UPM0);
	SET_BIT(UCSRC_var,UPM1);
#else
	SET_BIT(UCSRC_var,UPM0);
	SET_BIT(UCSRC_var,UPM1);
#endif
	//Select number of stop bits
#if STOP_BITS == _1_BIT
	CLEAR_BIT(UCSRC_var,USBS);
#else
	SET_BIT(UCSRC_var,USBS);
#endif
	UCSRC = UCSRC_var;

	//Select the baud rate
#if BAUD_RATE == BR_2400 //2400 is equavilant to 0x1A0
	UCSRC_var = 0x01;
	UCSRC = UCSRC_var;
	UBRRL = 0xA0;
#elif BAUD_RATE == BR_4800
	UBRRL = 207;
#else
	UBRRL = 103;
#endif

	//Transmission speed
#if TRANS_MODE == SING_MODE
	// Do Nothing
#else
	SET_BIT(UCSRA,U2X);
#endif
}

void UART_voidSend(uint8 data)
{
	UDR = data;
	while(!GET_BIT(UCSRA,TXC));
	SET_BIT(UCSRA,TXC);
}

uint8 UART_uint8Receive(void)
{
	while(!GET_BIT(UCSRA,RXC));
	return UDR;
}
