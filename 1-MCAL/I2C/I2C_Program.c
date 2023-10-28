/*
 * I2C_Program.c
 *
 *  Created on: Sep 24, 2023
 *      Author: moham
 */
#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_Private.h"
#include "I2C_Config.h"
#include "I2C_Interface.h"


//better to pass address as argument
void I2C_VidMasterInit(u8 Cpy_u8Address)
{
	if(Cpy_u8Address <128)
	{
		TWAR = (Cpy_u8Address <<1) ;//Shifting address by one bit to be stored from 7th bit to 1st bit
	}
	//Setting prescaler = 1 >> Set Freq. = 400KHz
	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	TWBR = 12; //FAST CALCULATION

	//Enable ACK bit
	SET_BIT(TWCR,TWEA);
	//Enabling I2C
	SET_BIT(TWCR,TWEN);

	//In slave mode it's the same code but without init the clk

}
void I2C_VidSendStartCondition(void)
{
	SET_BIT(TWCR,TWSTA); //Set to send start condition
	SET_BIT(TWCR,TWINT);  //Clearing the flag (must be cleared)
	while(0 == GET_BIT(TWCR,TWINT)); //Wait till start condition ends and the flag is set
	while ( I2C_STATUS_VALUE  != I2C_START_CONDITION_ACK ); //Checking the status to continue in +ve condtion
}
void I2C_VidSendRepStartCondition(void)
{
	SET_BIT(TWCR,TWSTA); //Set to send start condition
	SET_BIT(TWCR,TWINT);  //Clearing the flag (must be cleared)
	while(0 == GET_BIT(TWCR,TWINT)); //Wait till start condition ends and the flag is set
	while ( I2C_STATUS_VALUE  != I2C_RESTART_CONDITION_ACK ); //Checking the status to continue in +ve condtion
}

void I2C_VidSendStopCondition(void)
{
	SET_BIT(TWCR,TWSTO); //Set to send Stop condition
	SET_BIT(TWCR,TWINT);  //Clearing the flag (must be cleared)
}
void I2C_VidSendSlaveAddToWrite (u8 Cpy_u8SlaveAddress)
{
	if(Cpy_u8SlaveAddress < 128)
	{
		//Sending address as data to slave
			TWDR = (Cpy_u8SlaveAddress <<1);
		//Write on address
			CLEAR_BIT(TWDR ,TWD0);

			CLEAR_BIT(TWCR,TWSTA); //Clear  start condition (must to send data)
			SET_BIT(TWCR,TWINT);  //Clearing the flag (must be cleared)
			while(0 == GET_BIT(TWCR,TWINT)); //Wait till start condition ends and the flag is set
			while ( I2C_STATUS_VALUE  != I2C_SEND_SLAVE_ADD_WRITE_ACK ); //Checking the status to continue in +ve condtion
	}
	else
	{
		//error
	}
}
void I2C_VidSendSlaveAddToRead (u8 Cpy_u8SlaveAddress)
{
	if(Cpy_u8SlaveAddress < 128)
		{
			//Sending address as data to slave
				TWDR = (Cpy_u8SlaveAddress <<1);
			//Read from address
				SET_BIT(TWDR ,TWD0);

				CLEAR_BIT(TWCR,TWSTA); //Clear  start condition (must to send data)

				SET_BIT(TWCR,TWINT);  //Clearing the flag (must be cleared)
				while(0 == GET_BIT(TWCR,TWINT)); //Wait till start condition ends and the flag is set
				while ( I2C_STATUS_VALUE  != I2C_SEND_SLAVE_ADD_READ_ACK ); //Checking the status to continue in +ve condtion
		}
	else
	{
		//error
	}

}
void I2C_VidMasterSendDataByte(u8 Cpy_u8TxData)
{
	//Write data in register
	TWDR = Cpy_u8TxData;
	SET_BIT(TWCR,TWINT);  //Clearing the flag (must be cleared)
	while(0 == GET_BIT(TWCR,TWINT)); //Wait till start condition ends and the flag is set
	while ( I2C_STATUS_VALUE  != I2C_MASTER_DATA_TRANSMIT ); //Checking the status to continue in +ve condtion
}
void I2C_VidRecieveMasterDataByte(u8 * Cpy_Pu8RxData)
{
	if(Cpy_Pu8RxData != NULL)
	{
	SET_BIT(TWCR,TWINT);  //Clearing the flag (must be cleared)
	while(0 == GET_BIT(TWCR,TWINT)); //Wait till start condition ends and the flag is set
	while ( I2C_STATUS_VALUE  != I2C_MASTER_DATA_RECIEVE ); //Checking the status to continue in +ve condtion
	*Cpy_Pu8RxData = TWDR;
	}

}

