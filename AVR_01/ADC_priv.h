/*
 * ADC_priv.h
 *
 *  Created on: Apr 30, 2019
 *      Author: Al-Hussein
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_


#define INTERNAL_VREF_OFF 	0
#define AVCC_EXT 			1
#define RESERVED 			2
#define INTERNAL_VREF 		3


#define FACTOR_2			1
#define FACTOR_4			2
#define FACTOR_8			3
#define FACTOR_16			4
#define FACTOR_32			5
#define FACTOR_64			6
#define FACTOR_128			7

#define EIGHT_BIT			0
#define TEN_BIT				1

#define ON					1
#define OFF					0

#define FREE_RUNNING		0
#define ANALOG_COMPARATOR	1
#define INT0_REQUEST		2
#define TMR0_COMPARE_MATCH	3
#define TMR0_OVERFLOW		4
#define TMR1_COMPARE_MATCH	5
#define TMR1_OVERFLOW		6
#define TMR1_CAPTURE_EVENT	7

#endif /* ADC_PRIV_H_ */
