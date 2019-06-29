/*
 * ADCINT_config.h
 *
 *  Created on: May 19, 2019
 *      Author: Al-Hussein
 */

#ifndef ADCINT_CONFIG_H_
#define ADCINT_CONFIG_H_

/*Volatge reference: INTERNAL_VREF_OFF
 * 					 AVCC_EXT
 * 					 RESERVED
 * 					 INTERNAL_VREF
 */

#define VOLTAGE_REF AVCC_EXT

/*Adjustment of the result: EIGHT_BIT
 * 							TEN_BIT
 */

#define RESOLUTION TEN_BIT

/*Prescaler: FACTOR_2
 * 			 FACTOR_4
 * 			 FACTOR_8
 * 			 FACTOR_16
 * 			 FACTOR_32
 * 			 FACTOR_64
 * 			 FACTOR_128
 */

#define PRESCALER FACTOR_128


/*Enable Auto Trigger Mode*/

#define ENABLE_TRIG OFF

/*ENABLE_TRIG should be ON to use the following features otherwise
 * it will be a single conversion mode
 *Trigger Source: FREE_RUNNING
 * 				  ANALOG_COMPARATOR
 * 				  INT0_REQUEST
 * 				  TMR0_COMPARE_MATCH
 * 				  TMR0_OVERFLOW
 * 				  TMR1_COMPARE_MATCH
 * 				  TMR1_OVERFLOW
 * 				  TMR1_CAPTURE_EVENT
 */

#define TRIGGER_SOURCE FREE_RUNNING

#endif /* ADCINT_CONFIG_H_ */
