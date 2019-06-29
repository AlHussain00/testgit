/*
 * SPI_reg.h
 *
 *  Created on: Jun 2, 2019
 *      Author: Al-Hussein
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPCR	*((volatile uint8*) 0x2D)
#define SPIE				7
#define SPE					6
#define DORD				5
#define MSTR				4
#define CPOL				3
#define CPHA				2
#define SPR1				1
#define SPR0				0

#define SPSR	*((volatile uint8*) 0x2E)
#define SPIF				7
#define WCOL				6
#define SPI2X				0

#define SPDR	*((volatile uint8*) 0x2F)

#endif /* SPI_REG_H_ */
