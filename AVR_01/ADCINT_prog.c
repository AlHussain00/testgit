/*
 * ADCINT_prog.c
 *
 *  Created on: May 19, 2019
 *      Author: Al-Hussein
 */
#include "Std_Types.h"
#include "BitMath.h"
#include "ADCINT_priv.h"
#include "ADCINT_config.h"
#include "ADCINT_int.h"
#include "ADC_reg.h"


static void(*ADCINT_CallBack)(void);
static uint8 arr8[8]; //arry to store ADC values for 8 bit mode
static uint16 arr16[8]; //array to store ADC values for 10 bit mode
static uint8 index;



void ADCINT_voidInit(void)
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


void ADCINT_voidEnable(void)
{
	SET_BIT(ADCSRA,ADEN); //Enable the ADC
	SET_BIT(ADCSRA,ADIE); //Enable the interrupt
}



void ADCINT_voidDisable(void)
{
	CLEAR_BIT(ADCSRA,ADEN); //Disable the ADC
	CLEAR_BIT(ADCSRA,ADIE); //Disable the interrupt
}


void ADCINT_voidStartConv (uint8 channelNum)
{
	//Select ADC Channel first
	if(channelNum == ADCINT_0)
		{
			CLEAR_BIT(ADMUX,MUX0);
			CLEAR_BIT(ADMUX,MUX1);
			CLEAR_BIT(ADMUX,MUX2);
			CLEAR_BIT(ADMUX,MUX3);
			CLEAR_BIT(ADMUX,MUX4);
		}
		else if(channelNum == ADCINT_1)
		{
			SET_BIT(ADMUX,MUX0);
			CLEAR_BIT(ADMUX,MUX1);
			CLEAR_BIT(ADMUX,MUX2);
			CLEAR_BIT(ADMUX,MUX3);
			CLEAR_BIT(ADMUX,MUX4);
		}
		else if(channelNum == ADCINT_2)
		{
			CLEAR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLEAR_BIT(ADMUX,MUX2);
			CLEAR_BIT(ADMUX,MUX3);
			CLEAR_BIT(ADMUX,MUX4);
		}
		else if(channelNum == ADCINT_3)
		{
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLEAR_BIT(ADMUX,MUX2);
			CLEAR_BIT(ADMUX,MUX3);
			CLEAR_BIT(ADMUX,MUX4);
		}
		else if(channelNum == ADCINT_4)
		{
			CLEAR_BIT(ADMUX,MUX0);
			CLEAR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLEAR_BIT(ADMUX,MUX3);
			CLEAR_BIT(ADMUX,MUX4);
		}
		else if(channelNum == ADCINT_5)
		{
			SET_BIT(ADMUX,MUX0);
			CLEAR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLEAR_BIT(ADMUX,MUX3);
			CLEAR_BIT(ADMUX,MUX4);
		}
		else if(channelNum == ADCINT_6)
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
	SET_BIT(ADCSRA,ADSC); //Start conversion
	index = channelNum;
}


uint8 ADCINT_uint8GetResult(uint8 channelNum)
{
	return arr8[channelNum];
}


uint16 ADCINT_uint16GetResult(uint8 channelNum)
{
	return arr16[channelNum];
}


void ADCINT_voidSetCallBack(void (*copy_ptr)(void))
{
	ADCINT_CallBack = copy_ptr;
}


void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
#if RESOLUTION == EIGHT_BIT
	arr8[index] = ADCH;
#else
	arr16[index] = ADCL | (ADCH << 8);
#endif
	ADCINT_CallBack();
}
