/*
 * LCD_config.h
 *
 *  Created on: Apr 22, 2019
 *      Author: Al-Hussein
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*Asigning each pin in the LCD to a pin in the uC*/

#define LCD_PIN_4 		DIO_PIN_4
#define LCD_PIN_5 		DIO_PIN_5
#define LCD_PIN_6		DIO_PIN_6
#define LCD_PIN_7 		DIO_PIN_7
#define LCD_PIN_ENABLE  DIO_PIN_11
#define LCD_PIN_RS 		DIO_PIN_9
#define LCD_PIN_WR		DIO_PIN_10

/*If the LCD is connected through 4 pins only then choose MODE_4_BITS
 ***and if it is connected through 8 pins then choose MODE_8_BITS***/
#define LCD_MODE 		MODE_4_BITS

#endif /* LCD_CONFIG_H_ */
