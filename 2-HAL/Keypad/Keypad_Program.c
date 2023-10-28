/*
 * Keypad_Program.c
 *
 *  Created on: Sep 9, 2023
 *      Author: moham
 */


#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Keypad_Config.h"
#include <avr/delay.h>



/***************************** Keypad_Init *******************************/
void Keypad_Init()
{
	//Setting Columns to Output High
	DIO_SetPinMode(COL1,OutPut_High);
	DIO_SetPinMode(COL2,OutPut_High);
	DIO_SetPinMode(COL3,OutPut_High);
	DIO_SetPinMode(COL4,OutPut_High);

	//Setting Rows to Input Pullup
	DIO_SetPinMode(ROW1,InPut_PullUp);
	DIO_SetPinMode(ROW2,InPut_PullUp);
	DIO_SetPinMode(ROW3,InPut_PullUp);
	DIO_SetPinMode(ROW4,InPut_PullUp);
}


/***************************** Keypad_u8GetPressedKey *******************************/

u8 Keypad_u8GetPressedKey(void)
{
	u8 LOC_u8Col, LOC_u8Row;
	u8 LOC_u8Button = 0;
	for (LOC_u8Col = 0 ; LOC_u8Col < 4 ; LOC_u8Col++)
	{
		DIO_SetPinMode((COL1 + LOC_u8Col), OutPut_Low);
		for(LOC_u8Row = 0; LOC_u8Row < 4; LOC_u8Row++)
		{
			if (!DIO_u8ReadPinVal((ROW1+LOC_u8Row)))
				{
				LOC_u8Button = number[LOC_u8Row][LOC_u8Col];
				_delay_ms(20); //Consider Debounce
				}
		}
		DIO_SetPinMode((COL1 + LOC_u8Col), OutPut_High);
	}
	return LOC_u8Button;
}
