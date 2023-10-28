/*
 * LCD_program.c
 *
 *  Created on: 10/09/2023
 *      Author: Kareem Hussein
 */

#define F_CPU 16000000UL
#include <util/delay.h> 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void LCD_voidInit(void)
{
	_delay_ms(35);

	// set Rs pin = 0 (write command)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	private_voidWriteHalfPort(0b0010);
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	LCD_voidSendCmnd(0b00101000);	
	_delay_us(45);
	
	// Display on off Control (DisplayOn, Cursor on, Blink on)
	LCD_voidSendCmnd(0b00001111);
	_delay_us(45);
	
	// Clear Display
	LCD_voidSendCmnd(0b00000001);
	_delay_ms(2);
	
	// Set Entry Mode
	LCD_voidSendCmnd(0b00000110);
}


void LCD_voidSendCmnd(u8 copy_u8Cmnd)
{
	// set Rs pin = 0 (write command)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);

	// Write The Most 4 bits Of command on Data Pins
	private_voidWriteHalfPort(copy_u8Cmnd>>4);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	// Write The Least 4 bits Of command on Data Pins
	private_voidWriteHalfPort(copy_u8Cmnd);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
}


void LCD_voidSendChar(u8 copy_u8Data)
{
	// set Rs pin = 1 (write data)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	
	// Write The Most 4 bits Of data on Data Pins
	private_voidWriteHalfPort(copy_u8Data>>4);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	// Write The Least 4 bits Of data on Data Pins
	private_voidWriteHalfPort(copy_u8Data);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
}


static void private_voidWriteHalfPort(u8 copy_u8Value)
{
	DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Value,0));
	DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Value,1));
	DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Value,2));
	DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Value,3));
}
