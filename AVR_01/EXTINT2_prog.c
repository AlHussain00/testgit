/*
 * EXTINT2_prog.c
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */


#include "Std_Types.h"
#include "BitMath.h"
#include "EXTINT_reg.h"
#include "EXTINT2_priv.h"
#include "EXTINT2_config.h"
#include "EXTINT2_int.h"

static void(*EXTINT2_uint8Callback) (void);

void EXTINT2_voidInit(void)
{
	//Check the interrupt mode
#if INTERRUPT_MODE == FALLING_EDGE
	CLEAR_BIT(MCUCSR,ISC2);
#else
	SET_BIT(MCUCSR,ISC2);
#endif
	//Check if the user wants to enable the interrupt
#if INTERRUPT_ENABLE == ENABLE
	SET_BIT(GICR,INT2);
#else
	CLEAR_BIT(GICR,INT2);
#endif
}


void EXTINT2_voidEnableINT2(void)
{
	SET_BIT(GICR,INT2);
}
void EXTINT2_voidDisableINT2(void)
{
	CLEAR_BIT(GICR,INT2);
}
void EXTINT2_voidSetINT2Callback(void (*copy_callback) (void))
{
	EXTINT2_uint8Callback = copy_callback;
}

void __vector_3(void) __attribute((signal,used));
void __vector_3(void)
{
	EXTINT2_uint8Callback();
}
