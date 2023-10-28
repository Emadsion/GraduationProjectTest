/*
 * WD_Private.h
 *
 *  Created on: Sep 29, 2023
 *      Author: moham
 */

#ifndef WD_PRIVATE_H_
#define WD_PRIVATE_H_

#define WDTCR				(*(volatile u8 *)(0x41))

#define WDTOE				4
#define WDE					3
#define WDP2				2
#define WDP1				1
#define WDP0				0

#define WD_PRESCALER_16K				0
#define WD_PRESCALER_32K				1
#define WD_PRESCALER_64K				2
#define WD_PRESCALER_128K				3
#define WD_PRESCALER_256K				4
#define WD_PRESCALER_512K				5
#define WD_PRESCALER_1024K			6
#define WD_PRESCALER_2048K			7


#define ENABLE										1
#define DISABLE									0

#endif /* WD_PRIVATE_H_ */
