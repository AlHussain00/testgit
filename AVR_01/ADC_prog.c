/*
 * ADC_prog.c
 *
 *  Created on: Apr 30, 2019
 *      Author: Al-Hussein
 */
#include "Std_Types.h"
#include "BitMath.h"
#include "ADC_reg.h"
#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_int.h"




void ADC_voidInit(void)
{
	//Choose Vref
#if VOLTAGE_REF == INTERNAL_VREF_OFF
	CLEAR_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
#elif VOLTAGE_REF == AVCC_EXT
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
#elif VOLTAGE_REF == INTERNAL_VREF
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
#else
	SET_BIT(ADMUX,REFS1);
	CLEAR_BIT(ADMUX,REFS0);
#endif

	//Choose the resolution
#if RESOLUTION == TEN_BIT
	CLEAR_BIT(ADMUX,ADLAR);
#else
	SET_BIT(ADMUX,ADLAR);
#endif

	//Choose the prescaler
#if PRESCALER == FACTOR_2
	SET_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
#elif PRESCALER == FACTOR_4
	CLEAR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
#elif PRESCALER == FACTOR_8
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLEAR_BIT(ADCSRA,ADPS2);
#elif PRESCALER == FACTOR_16
	CLEAR_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
#elif PRESCALER == FACTOR_32
	SET_BIT(ADCSRA,ADPS0);
	CLEAR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
#elif PRESCALER == FACTOR_64
	CLEAR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
#else
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
#endif

	//Checking if the trigger mode is on or off and if it is on check the options
#if ENABLE_TRIG == ON
	SET_BIT(ADCSRA,ADATE);
#if TRIGGER_SOURCE == FREE_RUNNING
	CLEAR_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
#elif TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
#elif TRIGGER_SOURCE == INT0_REQUEST
	CLEAR_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
#elif TRIGGER_SOURCE == TMR0_COMPARE_MATCH
	SET_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	CLEAR_BIT(SFIOR,ADTS2);
#elif TRIGGER_SOURCE == TMR0_OVERFLOW
	CLEAR_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS2);
#elif TRIGGER_SOURCE == TMR1_COMPARE_MATCH
	SET_BIT(SFIOR,ADTS0);
	CLEAR_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS2);
#elif TRIGGER_SOURCE == TMR1_OVERFLOW
	CLEAR_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS2);
#else
	SET_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	SET_BIT(SFIOR,ADTS2);
#endif
	//if the trigger is off, that means it will run on single conversion mode
#else
	CLEAR_BIT(ADCSRA,ADATE);
#endif
}

void ADC_voidEnable()
{
	SET_BIT(ADCSRA,ADEN);
}

void ADC_voidDisable()
{
	CLEAR_BIT(ADCSRA,ADEN);
}

void ADC_voidStartConv()
{
	SET_BIT(ADCSRA,ADSC);
}

void ADC_voidSelectChannel(uint8 ChannelNum)
{
	if(ChannelNum == ADC_0)
	{
		CLEAR_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(ChannelNum == ADC_1)
	{
		SET_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(ChannelNum == ADC_2)
	{
		CLEAR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(ChannelNum == ADC_3)
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(ChannelNum == ADC_4)
	{
		CLEAR_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(ChannelNum == ADC_5)
	{
		SET_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(ChannelNum == ADC_6)
	{
		CLEAR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else
	{
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
}

uint8 ADC_uint8GetResult()
{
	uint8 result = 0;
	while(!GET_BIT(ADCSRA,ADIF)); //wait until finishing reading
	SET_BIT(ADCSRA,ADIF); //reset flag
	result = ADCH;
	return result;
}

uint16 ADC_uint16GetResult()
{
	uint16 result = 0;
	while(!GET_BIT(ADCSRA,ADIF)); //wait until finishing reading
	SET_BIT(ADCSRA,ADIF); //reset flag
	result = result| ADCL | (ADCH<<8);
	return result;
}
