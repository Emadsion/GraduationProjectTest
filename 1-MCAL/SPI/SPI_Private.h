/*
 * SPI_Private.h
 *
 *  Created on: Sep 23, 2023
 *      Author: moham
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR			(*(volatile u8 *)(0x2D))
#define SPIE			7
#define SPE				6
#define DORD		5
#define MSTR			4
#define CPOL			3
#define CPHA			2
#define SPR1			1
#define SPR0			0

#define SPSR			(*(volatile u8 *)(0x2E))
#define SPIF			7
#define WCOL 		6
#define SPI2X			0
#define SPDR			(*(volatile u8 *)(0x2F))


void __vector_12(void) __attribute__((signal));

#endif /* SPI_PRIVATE_H_ */
