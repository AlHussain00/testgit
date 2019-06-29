/*
 * UARTINT_prog.c
 *
 *  Created on: May 25, 2019
 *      Author: Al-Hussein
 */


#include "Std_Types.h"
#include "BitMath.h"
#include "UARTINT_priv.h"
#include "UARTINT_config.h"
#include "UART_reg.h"
#include "UARTINT_int.h"

#define DATASIZE 7

static uint8 RX_arr[DATASIZE];
volatile static uint8 arrIndex = 0;
static void (*UARTINT_TxCallBack)(void);
static void (*UARTINT_RxCallBack)(void);

void UARTINT_voidInit(void)
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

void UARTINT_voidSend(uint8 data)
{
	UDR = data;
	while(!GET_BIT(UCSRA,TXC));
	SET_BIT(UCSRA,TXC);
}

uint8* UARTINT_uint8Receive()
{
	return &RX_arr[0];
}


void UARTINT_voidEnableRXInterrupt()
{
	SET_BIT(UCSRB,RXCIE);
}

void UARTINT_voidDisableRXInterrupt()
{
	CLEAR_BIT(UCSRB,RXCIE);
}

void UARTINT_voidDisableTXInterrupt()
{
	SET_BIT(UCSRB,TXCIE);
}

void UARTINT_voidEnableTXInterrupt()
{
	CLEAR_BIT(UCSRB,TXCIE);
}

void UARTINT_voidSetRXCallBack(void (*copy_ptr)(void))
{
	UARTINT_RxCallBack = copy_ptr;
}

void UARTINT_voidSetTXCallBack(void (*copy_ptr)(void))
{
	UARTINT_TxCallBack = copy_ptr;
}



void __vector_13(void) __attribute__((signal,used));
void __vector_15(void) __attribute__((signal,used));
void __vector_13(void)
{
	if(arrIndex >= DATASIZE) //the max size of the array is 7
	{
		arrIndex = 0;
		UARTINT_RxCallBack(); //data = UARTINT_uint8Receive(); "what is written in main.c"
	}
	else
	{
		RX_arr[arrIndex] = UDR; //otherwise put the data in the array at that index
		++arrIndex;
	}
}
void __vector_15(void)
{
	UARTINT_TxCallBack();
}
