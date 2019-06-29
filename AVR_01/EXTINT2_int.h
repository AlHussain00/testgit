/*
 * EXTINT2_int.h
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */

#ifndef EXTINT2_INT_H_
#define EXTINT2_INT_H_

void EXTINT2_voidInit(void); //Initialize INTO intterupt
void EXTINT2_voidEnableINT0(void); //Enable interrupt on pin INT2
void EXTINT2_voidDisableINT0(void); // Disable interrupt on pin INT2
void EXTINT2_voidSetINT2Callback(void (*copy_callback) (void)); //This function lets the user to use any name for ISR

#endif /* EXTINT2_INT_H_ */
