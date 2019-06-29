/*
 * SPIINT_prog.c
 *
 *  Created on: Jun 7, 2019
 *      Author: Al-Hussein
 */

#include "Std_Types.h"
#include "BitMath.h"
#include "SPI_reg.h"
#include "SPIINT_priv.h"
#include "SPIINT_config.h"
#include "SPIINT_int.h"

#define DATASIZE 7

static uint8 dataArr[DATASIZE];
static uint8 dataIndex = 0;
static void(*SPIINT_CallBack)(void);

void SPIINT_voidInit(void)
{
	//Select data order
#if DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR,DORD);
#elif DATA_ORDER == MSB_FIRST
	CLEAR_BIT(SPCR,DORD);
#endif
	//Master of Slave
#if MODE == MASTER
	SET_BIT(SPCR,MSTR);
#elif MODE == SLAVE
	CLEAR_BIT(SPCR,MSTR);
#endif
	//Select Clock Polarity
#if CLK_POLARITY == NON_INVERTED
	CLEAR_BIT(SPCR,CPOL);
#elif CLK_POLARITY == INVERTED
	SET_BIT(SPCR,CPOL);
#endif
	//Select Clock Phase
#if CLK_PHASE == LEADING_EDGE
	CLEAR_BIT(SPCR,CPOL);
#elif CLK_PHASE == TRAILING_EDGE
	SET_BIT(SPCR,CPOL);
#endif

	//Select Transimission Mode
#if TRANS_MODE == SING_MODE //Single Mode
	CLEAR_BIT(SPSR,SPI2X);
	//Clock Frequency
#if CLK_FRQ == _2_FRQ
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR0);
#elif CLK_FRQ == _8_FRQ
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR0);
#elif CLK_FRQ == _32_FRQ
	CLEAR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR0);
#else
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR0);
#endif
#elif TRANS_MODE == DOUB_MODE //Double Mode
	SET_BIT(SPSR,SPI2X);
#if CLK_FRQ == _4_FRQ
	CLEAR_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR0);
#elif CLK_FRQ == _16_FRQ
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR0);
#elif CLK_FRQ == _64_FRQ
	CLEAR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR0);
#else
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR0);
#endif
#endif

	SET_BIT(SPCR,SPE);
}
void SPIINT_voidSend(uint8 data)
{
	SPDR = data;
	while(!GET_BIT(SPSR,SPIF));
}
void SPIINT_voidEnableInterrupt(void)
{
	SET_BIT(SPCR,SPIE);
}
void SPIINT_voidDisableInterrupt(void)
{
	CLEAR_BIT(SPCR,SPIE);
}
uint8* SPIINT_uint8Receive(void)
{
	return dataArr;
}


void SPIINT_voidSetCallBack(void (*copy_ptr)(void))
{
	SPIINT_CallBack = copy_ptr;
}
void __vector_12(void) __attribute__((signal,used));
void __vector_12(void)
{
	if(dataIndex >= DATASIZE)
	{
		dataIndex = 0;
		SPIINT_CallBack();
	}
	else
	{
		dataArr[dataIndex] = SPDR;
		++dataIndex;
	}
}

