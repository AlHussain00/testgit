/*
 * LCD_prog.c
 *
 *  Created on: Apr 22, 2019
 *      Author: Al-Hussein
 */

#include "util/delay.h"
#include "BitMath.h"
#include "Std_Types.h"
#include "DIO_int.h"
#include "LCD_priv.h"
#include "LCD_config.h"
#include "LCD_int.h"


void LCD_voidInit(void)
{
	//Initializing the LCD
	LCD_voidSendCommand(0x03);
	_delay_ms(5);
	LCD_voidSendCommand(0x03);
	_delay_ms(11);
	LCD_voidSendCommand(0x03);
	LCD_voidSendCommand(0x02);
	LCD_voidSendCommand(0x08);
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(0x0C); //cursor blinking put it D and C
	LCD_voidSendCommand(0x01);
	_delay_ms(100);
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(0x06);
}


void LCD_voidSendCommand(uint8 command)
{
	//Send the 1st 4 bits on the left
	DIO_voidSetPin(LCD_PIN_7, GET_BIT(command,7));
	DIO_voidSetPin(LCD_PIN_6, GET_BIT(command,6));
	DIO_voidSetPin(LCD_PIN_5, GET_BIT(command,5));
	DIO_voidSetPin(LCD_PIN_4, GET_BIT(command,4));
	DIO_voidSetPin(LCD_PIN_WR, LOW); //Writing mode
	DIO_voidSetPin(LCD_PIN_RS, LOW); //LOW to write commands
	//Give a pulse
	DIO_voidSetPin(LCD_PIN_ENABLE, HIGH);
	_delay_ms(1);
	DIO_voidSetPin(LCD_PIN_ENABLE, LOW);
	_delay_ms(100);
	//Send the 2nd 4 bits on the right
	DIO_voidSetPin(LCD_PIN_7, GET_BIT(command,3));
	DIO_voidSetPin(LCD_PIN_6, GET_BIT(command,2));
	DIO_voidSetPin(LCD_PIN_5, GET_BIT(command,1));
	DIO_voidSetPin(LCD_PIN_4, GET_BIT(command,0));
	DIO_voidSetPin(LCD_PIN_ENABLE, HIGH);
	_delay_us(1);
	DIO_voidSetPin(LCD_PIN_ENABLE, LOW);
	_delay_us(100);
}


void LCD_voidDisplayCharacter(uint8 data)
{
	//Send the 1st 4 bits on the left
	DIO_voidSetPin(LCD_PIN_RS, HIGH);
	DIO_voidSetPin(LCD_PIN_7, GET_BIT(data,7));
	DIO_voidSetPin(LCD_PIN_6, GET_BIT(data,6));
	DIO_voidSetPin(LCD_PIN_5, GET_BIT(data,5));
	DIO_voidSetPin(LCD_PIN_4, GET_BIT(data,4));
	DIO_voidSetPin(LCD_PIN_WR, LOW); // Write mode
	DIO_voidSetPin(LCD_PIN_RS, HIGH);// To write data
	//Give a pulse
	DIO_voidSetPin(LCD_PIN_ENABLE, HIGH);
	_delay_ms(1);
	DIO_voidSetPin(LCD_PIN_ENABLE, LOW);
	_delay_ms(100);
	//Send the 2nd 4 bits on the right
	DIO_voidSetPin(LCD_PIN_7, GET_BIT(data,3));
	DIO_voidSetPin(LCD_PIN_6, GET_BIT(data,2));
	DIO_voidSetPin(LCD_PIN_5, GET_BIT(data,1));
	DIO_voidSetPin(LCD_PIN_4, GET_BIT(data,0));
	//Give a pulse
	DIO_voidSetPin(LCD_PIN_ENABLE, HIGH);
	_delay_ms(1);
	DIO_voidSetPin(LCD_PIN_ENABLE, LOW);
	_delay_ms(100);
}

/*Function Descrition: it takes a string and loops on each character inside it
 ******************************and displays it*******************************/
void LCD_voidDisplayString(uint8 *data)
{
	uint8 i = 0;
	while(data[i] != '\0')
	{
		LCD_voidDisplayCharacter(data[i]);
		++i;
	}
}


void LCD_voidClearScreen()
{
	LCD_voidSendCommand(0x01);
}

void LCD_voidSetCursor(uint8 a, uint8 b)
{
	uint8 position;
	if(a == 1)
	{
		position = 0x80 | b; //0x80 to choose the first row and "OR" with b to choose the column
	}else if(a == 2)
	{
		position = 0xC0 | b; //0xC0 to choose the first row and "OR" with b to choose the column
	}
	LCD_voidSendCommand(position);
}

/*Function Descrition: it extracts each numbers from the data*
*************and sending the equivalent ASCI code*************/

void LCD_voidDisplayInteger(uint16 data)
{
	for(uint16 i = 1000; i >= 1; i/=10)
	{
		LCD_voidDisplayCharacter(48+(data/i));
		data = data % i;
	}
}

void LCD_voidShiftRight(void)
{
	LCD_voidSendCommand(0x1C);
}
