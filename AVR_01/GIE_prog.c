/*
 * GIE_prog.c
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */
#include "BitMath.h"
#include "Std_Types.h"
#include "GIE_reg.h"
#include "GIE_priv.h"
#include "GIE_config.h"
#include "GIE_int.h"

void GIE_voidInit(void)
{

}

void GIE_voidEnableGlobalInt(void)
{
	SET_BIT(SREG,I);
}

void GIE_voidDisableGlobalInt(void)
{
	CLEAR_BIT(SREG,I);
}
