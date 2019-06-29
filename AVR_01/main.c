/*
 * main.c
 *
 *  Created on: Apr 19, 2019
 *      Author: Al-Hussein
 */

#include "Std_Types.h"
#include "BitMath.h"
#include  "DIO_int.h"
#include "I2C_int.h"
#include "util/delay.h"



int main(void)
{
	DIO_voidInit();
	I2C_voidInitialize();

	while(1)
	{
		if(DIO_uint8GetPin(DIO_PIN_31))
		{
			_delay_ms(1000);
			I2C_uint8MasterTransmit('A', 0x01,ENABLE_REPEATED_START);
			_delay_ms(1000);
			while(!I2C_uint8MasterTransmit_RepeatedStart('b', 0x01, DISABLE_REPEATED_START));
		}

	}
	return 0;
}


