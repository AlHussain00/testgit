/*
 * EXTINT1_prog.c
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */

#include "Std_Types.h"
#include "BitMath.h"
#include "EXTINT_reg.h"
#include "EXTINT1_priv.h"
#include "EXTINT1_config.h"
#include "EXTINT1_int.h"

static void(*EXTINT1_uint8Callback) (void);

void EXTINT1_voidInit(void)
{
	//Check the interrupt mode
#if INTERRUPT_MODE == LOW_LVL
	CLEAR_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);
#elif INTERRUPT_MODE == LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);
#elif INTERRUPT_MODE == FALLING_EDGE
	SET_BIT(MCUCR,ISC11);
	CLEAR_BIT(MCUCR,ISC10);
#else
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#endif
	//Check if the user wants to enable the interrupt
#if INTERRUPT_ENABLE == ENABLE
	SET_BIT(GICR,INT1);
#else
	CLEAR_BIT(GICR,INT1);
#endif
}


void EXTINT1_voidEnableINT0(void)
{
	SET_BIT(GICR,INT1);
}
void EXTINT1_voidDisableINT0(void)
{
	CLEAR_BIT(GICR,INT1);
}
void EXTINT1_voidSetINT1Callback(void (*copy_callback) (void))
{
	EXTINT1_uint8Callback = copy_callback;
}

void __vector_2(void) __attribute((signal,used));
void __vector_2(void)
{
	EXTINT1_uint8Callback();
}

