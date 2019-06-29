/*
 * UART_config.h
 *
 *  Created on: May 22, 2019
 *      Author: Al-Hussein
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

//To receive and transmit data, you can enable both options
#define TX_ENABLE 	 DISABLE
#define RX_ENABLE    ENABLE

/*Select the size of data
 * options: _5_BIT
 * 			_6_BIT
 * 			_7_BIT
 * 			_8_BIT
 * 			_9_BIT
 */
#define CHAR_SIZE _8_BIT


/*Operating mode: SYNCH
 * 				  ASYNCH
 */

#define MODE ASYNCH

/*Parity check: DISABLE
 * 				ENABLE_EVEN_PARITY
 * 				ENABLE_ODD_PARITY
 */
#define PARRITY_MODE DISABLE

/*Stop bits: _1_BIT
 * 			 _2_BIT
 */

#define STOP_BITS _1_BIT

/*Transimission mode: SING_MODE
 * 					  DOUB_MODE
 */

#define TRANS_MODE SING_MODE

/*Baud rate: BR_2400
 * 			 BR_4800
 * 			 BR_9600
 */

#define BAUD_RATE BR_9600

#endif /* UART_CONFIG_H_ */
