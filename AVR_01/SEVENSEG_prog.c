/*
 * SEVENSEG_prog.c
 *
 *  Created on: Apr 21, 2019
 *      Author: Al-Hussein
 */
#include "Std_Types.h"
#include "BitMath.h"
#include "DIO_int.h"
#include "SEVENSEG_priv.h"
#include "SEVENSEG_config.h"
#include "SEVENSEG_int.h"

static uint8 counter;


void SEVENSEG_voidInit()
{
	counter = 0;

	DIO_voidSetPin(SEVENSEG_DP_PIN, LOW);
	DIO_voidSetPin(SEVENSEG1_ENABLE_PIN, LOW);
	DIO_voidSetPin(SEVENSEG2_ENABLE_PIN, LOW);
}
void SEVENSEG_voidEnableSevenSeg(uint8 SegNum)
{
	if(SegNum == SEVENSEG_1)
	{
		DIO_voidSetPin(SEVENSEG1_ENABLE_PIN, HIGH);
	}else if(SegNum == SEVENSEG_2)
	{
		DIO_voidSetPin(SEVENSEG2_ENABLE_PIN, HIGH);
	}
}
void SEVENSEG_voidDisableSevenSeg(uint8 SegNum)
{
	if(SegNum == SEVENSEG_1)
	{
		DIO_voidSetPin(SEVENSEG1_ENABLE_PIN, LOW);
	}else if(SegNum == SEVENSEG_2)
	{
		DIO_voidSetPin(SEVENSEG2_ENABLE_PIN, LOW);
	}
}
void SEVENSEG_voidReset()
{
#if(SEVENSEG1_MODE == COMMON_CATHOD || SEVENSEG2_MODE == COMMON_CATHOD)
	DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
	DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
	DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
	DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
#elif(SEVENSEG1_MODE == COMMON_ANODE || SEVENSEG2_MODE == COMMON_ANODE)
	DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
	DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
	DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
	DIO_voidSetPin(SEVENSEG_D_PIN, HIGH);
#endif
}

void SEVENSEG_voidIncrement()
{
	++counter;
	if(counter > 9)
	{
		counter = 0;
	}
	switch(counter)
	{
	case 0:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 1:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 2:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 3:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 4:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 5:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 6:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 7:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 8:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, HIGH);
		break;
	case 9:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, HIGH);
		break;
	}
}
void SEVENSEG_voidDecrement()
{
	--counter;
	if(counter < 0)
	{
		counter = 9;
	}
	switch(counter)
	{
	case 0:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 1:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 2:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 3:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 4:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 5:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 6:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 7:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 8:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, HIGH);
		break;
	case 9:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, HIGH);
		break;
	}
}

uint8 SEVENSEG_uint8GetValue()
{
	return counter;
}
void SEVENSEG_voidSetValue(uint8 Num)
{

	counter = Num;
	switch(counter)
	{
	case 0:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 1:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 2:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 3:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 4:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 5:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 6:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 7:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_C_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_D_PIN, LOW);
		break;
	case 8:
		DIO_voidSetPin(SEVENSEG_A_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, HIGH);
		break;
	case 9:
		DIO_voidSetPin(SEVENSEG_A_PIN, HIGH);
		DIO_voidSetPin(SEVENSEG_B_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_C_PIN, LOW);
		DIO_voidSetPin(SEVENSEG_D_PIN, HIGH);
		break;
	}
}
