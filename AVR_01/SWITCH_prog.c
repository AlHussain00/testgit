/*
 * SWITCH_prog.c
 *
 *  Created on: Apr 21, 2019
 *      Author: Al-Hussein
 */

#include "Std_Types.h"
#include "BitMath.h"
#include "DIO_int.h"
#include "SWITCH_priv.h"
#include "SWITCH_config.h"
#include "SWITCH_int.h"


void SWITCH_voidInit()
{

}

uint8 SWITCH_voidIsPressed(uint8 SwitchNum)
{
	uint8 result = 0;
	if(SwitchNum == SWITCH_0)
	{
#if(SWITCH0_MODE == PULL_DOWN)
		result = DIO_uint8GetPin(SWITCH_0_PIN);
#elif(SWITCH0_MODE == PULL_UP)
		result = DIO_uint8GetPin(SWITCH_0_PIN);
#endif
	}else if(SwitchNum == SWITCH_1)
		{
#if(SWITCH1_MODE == PULL_DOWN)
			result = DIO_uint8GetPin(SWITCH_1_PIN);
#elif(SWITCH1_MODE == PULL_UP)
		result = DIO_uint8GetPin(SWITCH_1_PIN);
#endif
	}else {
#if(SWITCH2_MODE == PULL_DOWN)
		result = DIO_uint8GetPin(SWITCH_2_PIN);
#elif(SWITCH2_MODE == PULL_UP)
		result = DIO_uint8GetPin(SWITCH_2_PIN);
#endif
	}
	return result;
}
