/*
 * DIO_prog.c
 *
 *  Created on: Apr 19, 2019
 *      Author: Al-Hussein
 */

#include "Std_Types.h"
#include "BitMath.h"
#include "DIO_reg.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO_int.h"
/******************************************
/*Description: Defining the pins direction*
 *****************************************/
void DIO_voidInit(void)
{
	DDRA = CONC(DIO_PIN7_DIR,DIO_PIN6_DIR,DIO_PIN5_DIR,DIO_PIN4_DIR,DIO_PIN3_DIR,DIO_PIN2_DIR,DIO_PIN1_DIR,DIO_PIN0_DIR);
	DDRB = CONC(DIO_PIN15_DIR,DIO_PIN14_DIR,DIO_PIN13_DIR,DIO_PIN12_DIR,DIO_PIN11_DIR,DIO_PIN10_DIR,DIO_PIN9_DIR,DIO_PIN8_DIR);
	DDRC = CONC(DIO_PIN23_DIR,DIO_PIN22_DIR,DIO_PIN21_DIR,DIO_PIN20_DIR,DIO_PIN19_DIR,DIO_PIN18_DIR,DIO_PIN17_DIR,DIO_PIN16_DIR);
	DDRD = CONC(DIO_PIN31_DIR,DIO_PIN30_DIR,DIO_PIN29_DIR,DIO_PIN28_DIR,DIO_PIN27_DIR,DIO_PIN26_DIR,DIO_PIN25_DIR,DIO_PIN24_DIR);
}
/*******************************************
/*Description: Setting the pins HIGH or LOW*
 ******************************************/
void DIO_voidSetPin(uint8 pinNum, uint8 value)
{
	if(value == HIGH) //use SET_BIT() because the user wants the pin HIGH
	{
		if(pinNum >= 0 && pinNum <= 7)
		{
			SET_BIT(PORTA,pinNum);
		}
		if(pinNum >= 8 && pinNum <= 15)
		{
			SET_BIT(PORTB,pinNum-8);
		}
		if(pinNum >= 16 && pinNum <= 23)
		{
			SET_BIT(PORTC,pinNum-16);
		}
		if(pinNum >= 24 && pinNum <= 31)
		{
			SET_BIT(PORTD,pinNum-24);
		}
	}else if(value == LOW)
	{
		if(pinNum >= 0 && pinNum <= 7)
		{
			CLEAR_BIT(PORTA,pinNum);
		}
		if(pinNum >= 8 && pinNum <= 15)
		{
			CLEAR_BIT(PORTB,pinNum-8);
		}
		if(pinNum >= 16 && pinNum <= 23)
		{
			CLEAR_BIT(PORTC,pinNum-16);
		}
		if(pinNum >= 24 && pinNum <= 31)
		{
			CLEAR_BIT(PORTD,pinNum-24);
		}
	}
}
/***********************************************************
********Description: Returns if the PIN HIGH or LOW*********
***if HIGH the function returns 1 and if LOW it returns 0***
***********************************************************/
uint8 DIO_uint8GetPin(uint8 pinNum)
{
	uint8 result = 0;
	if(pinNum >= 0 && pinNum <= 7)
	{
		result = GET_BIT(PINA,pinNum);
	}
	else if(pinNum >= 8 && pinNum <= 15)
	{
		result = GET_BIT(PINB,pinNum-8);
	}
	else if(pinNum >= 16 && pinNum <= 23)
	{
		result = GET_BIT(PINC,pinNum-16);
	}
	else if(pinNum >= 24 && pinNum <= 31)
	{
		result = GET_BIT(PIND,pinNum-24);
	}
	return result;
}
