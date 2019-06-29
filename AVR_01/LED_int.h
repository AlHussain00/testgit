/*
 * LED_int.h
 *
 *  Created on: Apr 20, 2019
 *      Author: Al-Hussein
 */

#ifndef LED_INT_H_
#define LED_INT_H_

//Giving names to each LED instead of numbers
#define LED_0 0
#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4
#define LED_5 5
#define LED_6 6
#define LED_7 7
#define LED_8 8
#define LED_9 9
#define LED_10 10
#define LED_11 11
#define LED_12 12
#define LED_13 13
#define LED_14 14
#define LED_15 15
#define LED_16 16
#define LED_17 17
#define LED_18 18
#define LED_19 19
#define LED_20 20
#define LED_21 21
#define LED_22 22
#define LED_23 23
#define LED_24 24
#define LED_25 25
#define LED_26 26
#define LED_27 27
#define LED_28 28
#define LED_29 29
#define LED_30 30
#define LED_31 31

void LED_voidInit(void); //initialize the LED
void LED_voidLedON(uint8 LEDNum); //Turns the LED on
void LED_voidLedOFF(uint8 LEDNum); //Turns the LED off


#endif /* LED_INT_H_ */
