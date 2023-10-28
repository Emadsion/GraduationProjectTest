/*
 * EXITEEPROM_Program.c
 *
 *  Created on: Sep 25, 2023
 *      Author: moham
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_Interface.h"
#include "EXITEEPROM_Private.h"
#include "EXITEEPROM_Interface.h"
#include "util/delay.h"


void ExEEPROM_Init(void)
{
	// Give the master MC any address
	I2C_VidMasterInit(255);
}

void ExEEPROM_VidWriteByte(u16 Cpy_u16WordAddress ,u8 Cpy_u8Data)
{
	//Sending First Address frame which contain EEPROM Fixed Address +  Part of Word Address     ->    0 1010 A1 A2 A3
	u8 Local_u8Address = EEPROM_FIXED_ADDRESS |  (Cpy_u16WordAddress >> 8); // or (0x50) |  (Cpy_u16WordAddress >> 8); or (0x01010000) |  (Cpy_u16WordAddress >> 8);
	//Send Start Condition
	I2C_VidSendStartCondition();
	//Send slave address with write operation
	I2C_VidSendSlaveAddToWrite(Local_u8Address);
	//Send word address
	I2C_VidMasterSendDataByte((u8)Cpy_u16WordAddress);
	//Send data
	I2C_VidMasterSendDataByte(Cpy_u8Data);
	//Send Stop Condition
	I2C_VidSendStopCondition();
	//Must delay for 5ms to give EEPROM Space to write or read data
	_delay_ms(5);
}
void ExEEPROM_VidReadByte(u16 Cpy_u16WordAddress ,u8* Cpy_Pu8RxData)
{
	//Sending First Address frame which contain EEPROM Fixed Address +  Part of Word Address     ->    0 1010 A1 A2 A3
	u8 Local_u8Address = EEPROM_FIXED_ADDRESS |  (Cpy_u16WordAddress >> 8); // or (0x50) |  (Cpy_u16WordAddress >> 8); or (0x01010000) |  (Cpy_u16WordAddress >> 8);
		//Send Start Condition
		I2C_VidSendStartCondition();
		//Send slave address with write operation
		I2C_VidSendSlaveAddToWrite(Local_u8Address);
		//Send word address
		I2C_VidMasterSendDataByte((u8)Cpy_u16WordAddress);
		//Send repeated start condition
		I2C_VidSendRepStartCondition();
		//Send slave address with read operation
		I2C_VidSendSlaveAddToRead(Local_u8Address);
		//Receive the data from EEPROM
		I2C_VidRecieveMasterDataByte(Cpy_Pu8RxData);
		//Send Stop Condition
		I2C_VidSendStopCondition();
		//Must delay for 5ms to give EEPROM Space to write or read data
		_delay_ms(5);
}

void ExEEPROM_VidWritePage(u16 Cpy_u16WordAddress , u8 *Cpy_Pu8Data, u8 Cpy_u8Size)
{
	//Sending First Address frame which contain EEPROM Fixed Address +  Part of Word Address     ->    0 1010 A1 A2 A3
	u8 Local_u8Address = EEPROM_FIXED_ADDRESS |  (Cpy_u16WordAddress >> 8); // or (0x50) |  (Cpy_u16WordAddress >> 8); or (0x01010000) |  (Cpy_u16WordAddress >> 8);
	//Send Start Condition
	I2C_VidSendStartCondition();
	//Send slave address with write operation
	I2C_VidSendSlaveAddToWrite(Local_u8Address);
	//Send word address
	I2C_VidMasterSendDataByte((u8)Cpy_u16WordAddress);
	//Send data per word size
	for (u8 Loc_u8Inc = 0 ; Loc_u8Inc  < Cpy_u8Size  ; Loc_u8Inc++)
	{
		I2C_VidMasterSendDataByte(Cpy_Pu8Data[Loc_u8Inc]);
	}
	//Send Stop Condition
	I2C_VidSendStopCondition();
	//Must delay for 5ms to give EEPROM Space to write or read data
	_delay_ms(5);
}

void ExEEPROM_VidReadPage(u16 Cpy_u16WordAddress ,u8* Cpy_Pu8RxData, u8 Cpy_u8Size)
{
		//Sending First Address frame which contain EEPROM Fixed Address +  Part of Word Address     ->    0 1010 A1 A2 A3
		u8 Local_u8Address = EEPROM_FIXED_ADDRESS |  (Cpy_u16WordAddress >> 8); // or (0x50) |  (Cpy_u16WordAddress >> 8); or (0x01010000) |  (Cpy_u16WordAddress >> 8);
		//Send Start Condition
		I2C_VidSendStartCondition();
		//Send slave address with write operation
		I2C_VidSendSlaveAddToWrite(Local_u8Address);
		//Send word address
		I2C_VidMasterSendDataByte((u8)Cpy_u16WordAddress);
		//Send repeated start condition
		I2C_VidSendRepStartCondition();
		//Send slave address with read operation
		I2C_VidSendSlaveAddToRead(Local_u8Address);
		//Recieve data per word size and put data in array
		for (u8 Loc_u8Inc =0 ; Loc_u8Inc <Cpy_u8Size ;Loc_u8Inc++ )
		{
			//Receive the data from EEPROM
			I2C_VidRecieveMasterDataByte((Cpy_Pu8RxData+Loc_u8Inc));
		}
		//Send Stop Condition
		I2C_VidSendStopCondition();
		//Must delay for 5ms to give EEPROM Space to write or read data
		_delay_ms(5);

}
