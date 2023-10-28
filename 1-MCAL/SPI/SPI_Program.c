/*
 * SPI_Program.c
 *
 *  Created on: Sep 23, 2023
 *      Author: moham
 */
#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"

void SPI_VidMasterInit(void)
{
	SPCR = (0<< SPIE) | (1 << SPE) | (0 << DORD) |  (1<<MSTR) |(0<< CPOL) | (0 << CPHA) | (0<< SPR1) | (0<< SPR0);
}
void SPI_MasterTransmit(u8  cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */

	while(0 == GET_BIT(SPSR ,SPIF));
}

void SPI_VidSlaveInit(void)
{
	/* Set MISO output, all others input */
	//DDR_SPI = (1<<DD_MISO);
	/* Enable SPI */
	SPCR = (1<< SPIE) | (1 << SPE) | (0 << DORD) |  (0<<MSTR) |(0<< CPOL) | (0 << CPHA) | (0<< SPR1) | (0<< SPR0);
}
u8 SPI_u8SlaveReceive(void)
{
	/* Wait for reception complete */
	while(0 == GET_BIT(SPSR , SPIF));
	/* Return data register */
	return Glb_u8Data;
}


void __vector_12(void)
{

	Glb_u8Data = SPDR;
}
