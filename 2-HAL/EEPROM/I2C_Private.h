/*
 * I2C_Private.h
 *
 *  Created on: Sep 24, 2023
 *      Author: moham
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define I2C_STATUS_VALUE 													(TWSR &0xF8)
#define I2C_START_CONDITION_ACK											0x08
#define I2C_RESTART_CONDITION_ACK										0x10
#define I2C_SEND_SLAVE_ADD_WRITE_ACK								0x18
#define I2C_SEND_SLAVE_ADD_READ_ACK									0x40
#define I2C_MASTER_DATA_TRANSMIT										0x28
#define I2C_MASTER_DATA_RECIEVE											0x50


#define TWBR		(*(volatile u8 *)(0x20)) // equal to 12


#define TWCR		(*(volatile u8 *)(0x56))
#define TWINT				7					//stretch the clock and must be cleared to continue sending in either blocking system and interrupt system
#define TWEA				6
#define TWSTA				5
#define TWSTO				4
#define TWWC				3
#define TWEN				2
#define TWIE					0

#define TWSR		(*(volatile u8 *)(0x21))
#define TWS7					7
#define TWS6					6
#define TWS5					5
#define TWS4					4
#define TWS3					3
#define TWPS1				1
#define TWPS0				0

#define TWDR		(*(volatile u8 *)(0x23))
#define TWD7				7
#define TWD6				6
#define TWD5				5
#define TWD4				4
#define TWD3				3
#define TWD2				2
#define TWD1				1
#define TWD0				0

#define TWAR		(*(volatile u8 *)(0x22))
#define TWA6				7
#define TWA5				6
#define TWA4				5
#define TWA3				4
#define TWA2				3
#define TWA1				2
#define TWA0				1
#define TWGCE				0

#endif /* I2C_PRIVATE_H_ */
