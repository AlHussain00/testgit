/*
 * DIO_int.h
 *
 *  Created on: Apr 19, 2019
 *      Author: Al-Hussein
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

/* Giving each pin a name so the everything is readable */

#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7
#define DIO_PIN_8 8
#define DIO_PIN_9 9
#define DIO_PIN_10 10
#define DIO_PIN_11 11
#define DIO_PIN_12 12
#define DIO_PIN_13 13
#define DIO_PIN_14 14
#define DIO_PIN_15 15
#define DIO_PIN_16 16
#define DIO_PIN_17 17
#define DIO_PIN_18 18
#define DIO_PIN_19 19
#define DIO_PIN_20 20
#define DIO_PIN_21 21
#define DIO_PIN_22 22
#define DIO_PIN_23 23
#define DIO_PIN_24 24
#define DIO_PIN_25 25
#define DIO_PIN_26 26
#define DIO_PIN_27 27
#define DIO_PIN_28 28
#define DIO_PIN_29 29
#define DIO_PIN_30 30
#define DIO_PIN_31 31
/*----------------------------*/
       /*Pins' status*/
#define HIGH 1
#define LOW  0

/*****************************************************************************
**Function Descrition: it initializes DIO driver by sitting pins' directions**
*****************************************************************************/
void DIO_voidInit(void);
/***********************************************************
**Function Descrition: It makes the pin either HIGH or LOW**
**                value: HIGH		pinNum:DIO_PIN_0	  **
**                       LOW               DIO_PIN_x      **
***********************************************************/
void DIO_voidSetPin(uint8 pinNum, uint8 value);
/*********************************************************
**Function Descrition: It checks if the pin  HIGH or LOW**
**                	pinNum:DIO_PIN_0					**
**                         DIO_PIN_x    				**
*********************************************************/
uint8 DIO_uint8GetPin(uint8 pinNum);



#endif /* DIO_INT_H_ */
