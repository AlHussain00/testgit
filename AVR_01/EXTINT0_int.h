/*
 * EXTINT0_int.h
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */

#ifndef EXTINT0_INT_H_
#define EXTINT0_INT_H_

void EXTINT0_voidInit(void); //Initialize INTO intterupt
void EXTINT0_voidEnableINT0(void); //Enable interrupt on pin INT0
void EXTINT0_voidDisableINT0(void); // Disable interrupt on pin INT0
void EXTINT0_voidSetINT0Callback(void (*copy_callback) (void)); //This function lets the user to use any name for ISR


#endif /* EXTINT0_INT_H_ */
