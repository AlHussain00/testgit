/*
 * EXTINT1_int.h
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */

#ifndef EXTINT1_INT_H_
#define EXTINT1_INT_H_

void EXTINT1_voidInit(void); //Initialize INTO intterupt
void EXTINT1_voidEnableINT0(void); //Enable interrupt on pin INT0
void EXTINT1_voidDisableINT0(void); // Disable interrupt on pin INT0
void EXTINT1_voidSetINT1Callback(void (*copy_callback) (void)); //This function lets the user to use any name for ISR

#endif /* EXTINT1_INT_H_ */
