/*
 * LCD_Program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: moham
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"LCD_Config.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"
#include<avr/delay.h>

/********************************************* LCD_VidInit ***************************************************/
void LCD_VidInit(void)
{
	_delay_ms(35);

	//Setting RS pin to low to write "Command"
	DIO_SetPinMode(LCD_Pin_RS,OutPut_Low);
	Private_VidWriteHalfPort(0b0010);
	/* Enable Pulse *//* H => L */
	DIO_SetPinMode(LCD_Pin_EN,OutPut_High);
	_delay_ms(1);
	DIO_SetPinMode(LCD_Pin_EN,OutPut_Low);


	LCD_VidSendCommand(0b00101000);
	_delay_us(45);

	// Display on off Control (DisplayOn, Cursor on, Blink on)
	LCD_VidSendCommand(0b00001111);
	_delay_us(45);

	// Clear Display
	LCD_VidSendCommand(0b00000001);
	_delay_ms(2);

	// Set Entry Mode
	LCD_VidSendCommand(0b00000110);

}


/********************************************* LCD_VidSendChar ***************************************************/
void LCD_VidSendChar(u8 Cpy_u8Data)
{
	//Setting RS pin to low to write "Command"
	DIO_SetPinMode(LCD_Pin_RS,OutPut_High);
	//Sending The 4 MSB
	Private_VidWriteHalfPort(Cpy_u8Data>>4);
	//Enable for sending command confirmation
	DIO_SetPinMode(LCD_Pin_EN,OutPut_High);
	_delay_ms(1);
	DIO_SetPinMode(LCD_Pin_EN,OutPut_Low);
	//Sending The 4 LSB
	Private_VidWriteHalfPort(Cpy_u8Data);
	//Enable for sending command confirmation
	DIO_SetPinMode(LCD_Pin_EN,OutPut_High);
	_delay_ms(1);
	DIO_SetPinMode(LCD_Pin_EN,OutPut_Low);
}


/********************************************* LCD_VidSendCommand ***************************************************/
void LCD_VidSendCommand(u8 Cpy_u8Command)
{
	//Setting RS pin to low to write "Command"
	DIO_SetPinMode(LCD_Pin_RS,OutPut_Low);
	//Sending The 4 MSB
	Private_VidWriteHalfPort(Cpy_u8Command>>4);
	//Enable for sending command confirmation
	DIO_SetPinMode(LCD_Pin_EN,OutPut_High);
	_delay_ms(1);
	DIO_SetPinMode(LCD_Pin_EN,OutPut_Low);
	//Sending The 4 LSB
	Private_VidWriteHalfPort(Cpy_u8Command);
	//Enable for sending command confirmation
	DIO_SetPinMode(LCD_Pin_EN,OutPut_High);
	_delay_ms(1);
	DIO_SetPinMode(LCD_Pin_EN,OutPut_Low);
}



/********************************************* LCD_VidClear ***************************************************/
void LCD_VidClear(void)
{
	//Send LCD Clear command
	LCD_VidSendCommand(0b00000001);
	_delay_ms(2);
}

/********************************************* LCD_VidSendString ***************************************************/
void LCD_VidSendString(u8 * PString)
{

	while(*PString != NULL)
	{
		//Sending String character by character
		LCD_VidSendChar(*PString);
		//Incrementing string pointer to the next character address
		PString++;
	}
}


/********************************************* LCD_VidSendNumber ***************************************************/
void LCD_VidSendNumber(u32 Cpy_u32Num)
{
	u32 Loc_u32Reverted = 0;

	//Sending '0' if the number is 0
	if(Cpy_u32Num == 0)
	{
		LCD_VidSendChar('0');
	}

	else
	{
		//Reverse The number and store the new reversed number in Loc_u32Reverted
		while (Cpy_u32Num > 0)
		{
			Loc_u32Reverted =(Loc_u32Reverted * 10) + (Cpy_u32Num % 10);
			Cpy_u32Num = Cpy_u32Num / 10;
		}

		//Printing the reversed number on LCD by sending number by number and printing their ASCII
		while (Loc_u32Reverted > 0)
			{
				 LCD_VidSendChar(Loc_u32Reverted%10	 + '0');
				 Loc_u32Reverted = Loc_u32Reverted / 10;
			}
	}

}


/***************************************************** LCD_VidGoTo ***********************************************************/
/**************** Sending the cursor to desired [ROW , COLOUMN] position by going to DDRam Address location ******************/

/*************************************************** Display Position ********************************************************

Position:		1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20
DD RAM Address [00] [01] [02] [03] [04] [05] [06] [07] [08] [09] [0A] [0B] [0C] [0D] [0E] [0F] [10] [11] [12] [13]
DD RAM Address [40] [41] [42] [43] [44] [45] [46] [47] [48] [49] [4A] [4B] [4C] [4D] [4E] [4F] [50] [51] [52] [53]
DD RAM Address [14] [15] [16] [17] [18] [19] [1A] [1B] [1C] [1D] [1E] [1F] [20] [21] [22] [23] [24] [25] [26] [27]
DD RAM Address [54] [55] [56] [57] [58] [59] [5A] [5B] [5C] [5D] [5E] [5F] [60] [61] [62] [63] [64] [65] [66] [67]

 ******************************************************************************************************************************/
void LCD_VidGoTo(u8 Cpy_u8Row, u8 Cpy_u8Col)
{
	if(Cpy_u8Col > 20)
	{
		//Error
	}

	switch (Cpy_u8Row)
	{
		//Sending Move Cursor command + DDRAM Row Position + DDRAM Row Position
		case 0: LCD_VidSendCommand(0b10000000 + 0x00 + Cpy_u8Col);
				break;
		case 1: LCD_VidSendCommand(0b10000000 + 0x40 + Cpy_u8Col);
				break;
		case 2: LCD_VidSendCommand(0b10000000 + 0x14 + Cpy_u8Col);
				break;
		case 3:LCD_VidSendCommand(0b10000000 + 0x54 + Cpy_u8Col);
				break;
		default: //Error
				break;
	}

}



/***************************************************** LCD_VidGoTo ***********************************************************/
void LCD_VidShiftDisplay(u8 Cpy_u8ShiftDir,u8 Cpy_u8ShiftNum)
{
	switch (Cpy_u8ShiftDir)
	{

		case LCD_Shift_Right:
			//Shifting the display Right with Num of of shifts
			for( ; Cpy_u8ShiftNum > 0 ; Cpy_u8ShiftNum--)
				{
					LCD_VidSendCommand(0b00011100);
				}
			break;

		case LCD_Shift_Left:
			//Shifting the display Left with Num of of shifts
			for( ; Cpy_u8ShiftNum > 0 ; Cpy_u8ShiftNum--)
				{
					LCD_VidSendCommand(0b00011000);
				}
		break;
	}
}

/****************************************** LCD_VidSetCGRAMAdres **************************************************/
void LCD_VidSetCGRAMAdres(void)
{
	//Setting to CGRAM Address
	LCD_VidSendCommand(64);
	//Writing Patterns to CGRAM Address

	//Address	0
		LCD_VidSendChar(0b11111111);
		LCD_VidSendChar(0b11111111);
		LCD_VidSendChar(0b11111111);
		LCD_VidSendChar(0b11000011);
		LCD_VidSendChar(0b11000011);
		LCD_VidSendChar(0b11000011);
		LCD_VidSendChar(0b11111111);
		LCD_VidSendChar(0b11111111);

	//Address	1
		LCD_VidSendChar(0b00111100);
		LCD_VidSendChar(0b00111100);
		LCD_VidSendChar(0b11111111);
		LCD_VidSendChar(0b11011011);
		LCD_VidSendChar(0b11011011);
		LCD_VidSendChar(0b00011000);
		LCD_VidSendChar(0b00011000);
		LCD_VidSendChar(0b00011000);
	LCD_VidGoTo(0,0);

}

/***************************************************** Private_VidWriteHalfPort ***********************************************************/
/********************************************* Function to Send each bit to the right DIO pin *********************************************/
void Private_VidWriteHalfPort(u8 Cpy_u8HalfData)
{
	DIO_SetPinMode(LCD_Pin_D4,GET_BIT(Cpy_u8HalfData,0));
	DIO_SetPinMode(LCD_Pin_D5,GET_BIT(Cpy_u8HalfData,1));
	DIO_SetPinMode(LCD_Pin_D6,GET_BIT(Cpy_u8HalfData,2));
	DIO_SetPinMode(LCD_Pin_D7,GET_BIT(Cpy_u8HalfData,3));
}
