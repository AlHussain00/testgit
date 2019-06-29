/*
 * EXTINT0_config.h
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */

#ifndef EXTINT0_CONFIG_H_
#define EXTINT0_CONFIG_H_

/***********************************************
 * User can choose the required interrupt mode *
 * Interrupt modes: LOW_LVL					   *
 * 					LOGICAL_CHANGE             *
 * 					FALLING_EDGE               *
 * 					RISING_EDGE                *
 **********************************************/

#define INTERRUPT_MODE 	 	LOGICAL_CHANGE

#define INTERRUPT_ENABLE 	DISABLE

#endif /* EXTINT0_CONFIG_H_ */
