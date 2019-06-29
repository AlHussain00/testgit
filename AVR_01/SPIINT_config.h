/*
 * SPIINT_config.h
 *
 *  Created on: Jun 7, 2019
 *      Author: Al-Hussein
 */

#ifndef SPIINT_CONFIG_H_
#define SPIINT_CONFIG_H_

/*Data Order Select: LSB_FIRST
 * 					 MSB_FIRST
 */

#define DATA_ORDER MSB_FIRST

/*Master or Slave: MASTER
 * 				   SLAVE
 */
#define MODE MASTER

/*Selec Clock Polarity: NON_INVERTED
 * 						INVERTED
 */

#define CLK_POLARITY NON_INVERTED

/*Select Clock Phase: LEADING_EDGE
 * 					  TRAILING_EDGE
 */

#define CLK_PHASE LEADING_EDGE


/*Transimission mode: SING_MODE
 * 					  DOUB_MODE
 */

#define TRANS_MODE SING_MODE

/*Clock Frequency:-double mode: _4_FRQ
 * 				   				_16_FRQ
 * 				   				_64_FRQ
 * 				   				_128_FRQ
 * 				  -single mode: _2_FRQ
 * 				   				_8_FRQ
 * 				   				_32_FRQ
 * 				   				_64_FRQ
 */

#define CLK_FRQ	_64_FRQ

#endif /* SPIINT_CONFIG_H_ */
