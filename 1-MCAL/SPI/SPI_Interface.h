/*
 * SPI_Interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: moham
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_VidMasterInit(void);
void SPI_MasterTransmit(u8 cData);
void SPI_VidSlaveInit(void);
u8 SPI_u8SlaveReceive(void);

u8 Glb_u8Data;
#endif /* SPI_INTERFACE_H_ */
