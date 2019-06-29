/*
 * EXTINT0_reg.h
 *
 *  Created on: May 5, 2019
 *      Author: Al-Hussein
 */

#ifndef EXTINT_REG_H_
#define EXTINT_REG_H_

/* Refere to the datasheet to know how to use each register */

#define MCUCR 	*((volatile uint8*) 0x55)
#define ISC11 	3
#define ISC10 	2
#define ISC01 	1
#define ISC00 	0

#define MCUCSR *((volatile uint8*) 0x54)
#define ISC2 6

#define GICR 	*((volatile uint8*) 0x5B)
#define INT1 	7
#define INT0 	6
#define INT2 	5

#define GIFR 	*((volatile uint8*) 0x5A)
#define INTF1 	7
#define INTF0 	6
#define INTF2 	5

#endif /* EXTINT_REG_H_ */
