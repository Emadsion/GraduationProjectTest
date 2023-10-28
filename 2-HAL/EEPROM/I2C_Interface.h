/*
 * I2C_Interface.h
 *
 *  Created on: Sep 24, 2023
 *      Author: moham
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


void I2C_VidMasterInit(u8 Cpy_u8Address);
void I2C_VidSendStartCondition(void);
void I2C_VidSendRepStartCondition(void);
void I2C_VidSendStopCondition(void);
void I2C_VidSendSlaveAddToWrite (u8 Cpy_u8SlaveAddress);
void I2C_VidSendSlaveAddToRead (u8 Cpy_u8SlaveAddress);
void I2C_VidMasterSendDataByte(u8 Cpy_u8TxData);
void I2C_VidRecieveMasterDataByte(u8 * Cpy_Pu8RxData);
//to continue
//Init slave
//slave send data
//slave recive data
// slave listen -> check wheather it's called ot not and can be handeled inside send or recive data



#endif /* I2C_INTERFACE_H_ */
