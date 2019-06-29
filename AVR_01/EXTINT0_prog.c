/*
 * EXTINT0_prog.c
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */

#include "Std_Types.h"
#include "BitMath.h"
#include "EXTINT_reg.h"
#include "EXTINT0_priv.h"
#include "EXTINT0_config.h"
#include "EXTINT0_int.h"

static void(*EXTINT0_uint8Callback) (void);

void EXTINT0_voidInit(void)
{
	//Check the interrupt mode
#if INTERRUPT_MODE == LOW_LVL
	CLEAR_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);
#elif INTERRUPT_MODE == LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);
#elif INTERRUPT_MODE == FALLING_EDGE
	SET_BIT(MCUCR,ISC01);
	CLEAR_BIT(MCUCR,ISC00);
#else
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#endif
	//Check if the user wants to enable the interrupt
#if INTERRUPT_ENABLE == ENABLE
	SET_BIT(GICR,INT0);
#else
	CLEAR_BIT(GICR,INT0);
#endif
}


void EXTINT0_voidEnableINT0(void)
{
	SET_BIT(GICR,INT0);
}
void EXTINT0_voidDisableINT0(void)
{
	CLEAR_BIT(GICR,INT0);
}
void EXTINT0_voidSetINT0Callback(void (*copy_callback) (void))
{
	EXTINT0_uint8Callback = copy_callback;
}

void __vector_1(void) __attribute((signal,used));
void __vector_1(void)
{
	EXTINT0_uint8Callback();
}
