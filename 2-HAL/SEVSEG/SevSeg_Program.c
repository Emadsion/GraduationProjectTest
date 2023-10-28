/*
 * SevSeg_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: moham
 */


#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "SevSeg_Interface.h"
#include "SevSeg_Config.h"
#include "SevSeg_Private.h"
#include <avr/delay.h>



/******************************************************* SevSeg_VidInit *************************************************************/
/*********************************** Initializing all Pins used for Controlling 7-Seg to OutPut_High ********************************/
void SevSeg_VidInit(void)
{

	DIO_SetPinMode(SevSeg_PinA,OutPut_High);
	DIO_SetPinMode(SevSeg_PinB,OutPut_High);
	DIO_SetPinMode(SevSeg_PinC,OutPut_High);
	DIO_SetPinMode(SevSeg_PinD,OutPut_High);

	DIO_SetPinMode(SevSeg_COMPIN1,OutPut_High);
	DIO_SetPinMode(SevSeg_COMPIN2,OutPut_High);
	DIO_SetPinMode(SevSeg_COMPIN3,OutPut_High);
	DIO_SetPinMode(SevSeg_COMPIN4,OutPut_High);
}

/******************************************************* SevSeg_VidWriteNum *************************************************************/
void SevSeg_VidWriteNum(u16 Cpy_u16Num)
{
	//Number cannot exceed 4-Digits
	if((Cpy_u16Num / 10000) > 0)
	{
		//Error
	}

	else
	{
		SevSeg_COM CurrentSevSeg_COM = SevSeg_COM1;
		while (Cpy_u16Num > 0)
		{
			//Sending each digit to Private_VidWriteData() function to be written on 7-Seg
			Private_VidWriteData(Cpy_u16Num % 10, CurrentSevSeg_COM);
			Cpy_u16Num /= 10;
			//Incrementing COM (Enable) Pins to iterate through each 7-Seg
			CurrentSevSeg_COM++;
		}

	}
}





void Private_VidWriteData(u8 Cpy_u8Data,SevSeg_COM  Cpy_SevSegCom)
{
//For NTI_KIT configuration
#if SevSeg_Implementation == NTI_KIT
	Cpy_u8Data = ((Cpy_u8Data<<1)&0X10) | (Cpy_u8Data&0X07);
	Cpy_u8Data = (0xFF &0xE8) | Cpy_u8Data;
	DIO_SetPortMode(PORT_B,Cpy_u8Data);

//For any other configuration (Portable Configuration)
#elif SevSeg_Implementation == PORTABLE
	DIO_SetPinMode(SevSeg_PinA,GET_BIT(Cpy_u8Data,0));
	DIO_SetPinMode(SevSeg_PinB,GET_BIT(Cpy_u8Data,1));
	DIO_SetPinMode(SevSeg_PinC,GET_BIT(Cpy_u8Data,2));
	DIO_SetPinMode(SevSeg_PinD,GET_BIT(Cpy_u8Data,3));
#endif

//Enabling Each 7_Seg COM foe 2ms to display each digit on an individual 7_Seg COM
	switch(Cpy_SevSegCom)
	{
		case SevSeg_COM1:
			DIO_SetPinMode(SevSeg_COMPIN1, OutPut_Low);
			_delay_ms(2);
			DIO_SetPinMode(SevSeg_COMPIN1, OutPut_High);
			break;
		case SevSeg_COM2:
			DIO_SetPinMode(SevSeg_COMPIN2, OutPut_Low);
			_delay_ms(2);
			DIO_SetPinMode(SevSeg_COMPIN2, OutPut_High);
			break;
		case SevSeg_COM3:
			DIO_SetPinMode(SevSeg_COMPIN3, OutPut_Low);
			_delay_ms(2);
			DIO_SetPinMode(SevSeg_COMPIN3, OutPut_High);
			break;
		case SevSeg_COM4:
			DIO_SetPinMode(SevSeg_COMPIN4, OutPut_Low);
			_delay_ms(2);
			DIO_SetPinMode(SevSeg_COMPIN4, OutPut_High);
			break;
	}


}
