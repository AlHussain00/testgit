/*
 * LED_prog.c
 *
 *  Created on: Apr 20, 2019
 *      Author: Al-Hussein
 */
#include "Std_Types.h"
#include "BitMath.h"
#include "DIO_int.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "LED_int.h"

void LED_voidInit(void)
{

}

void LED_voidLedON(uint8 LEDNum)
{
	if(LEDNum == LED_2){
#if(LED2_MODE == FORWARD)
		DIO_voidSetPin(LED_2_PIN, HIGH);
#elif(LED2_MODE == REVERSE)
		DIO_voidSetPin(LED_2_PIN, LOW);
#endif
	}
	else if(LEDNum == LED_1){
#if(LED1_MODE == FORWARD)
		DIO_voidSetPin(LED_1_PIN, HIGH);
#elif(LED1_MODE == REVERSE)
		DIO_voidSetPin(LED_1_PIN, LOW);
#endif
	}
	else{
#if(LED0_MODE == FORWARD)
		DIO_voidSetPin(LED_0_PIN, HIGH);
#elif(LED0_MODE == REVERSE)
		DIO_voidSetPin(LED_0_PIN, LOW);
#endif
	}
}

void LED_voidLedOFF(uint8 LEDNum)
{
	if(LEDNum == LED_0){
#if(LED0_MODE == FORWARD)
		DIO_voidSetPin(LED_0_PIN, LOW);
#elif(LED0_MODE == REVERSE)
		DIO_voidSetPin(LED_0_PIN, HIGH);
#endif
	}
	else if(LEDNum == LED_1){
#if(LED1_MODE == FORWARD)
		DIO_voidSetPin(LED_1_PIN, LOW);
#elif(LED1_MODE == REVERSE)
		DIO_voidSetPin(LED_1_PIN, HIGH);
#endif
	}
	else{
#if(LED2_MODE == FORWARD)
		DIO_voidSetPin(LED_2_PIN, LOW);
#elif(LED2_MODE == REVERSE)
		DIO_voidSetPin(LED_2_PIN, HIGH);
#endif
	}
}
