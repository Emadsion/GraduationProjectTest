/*
 * EXITEEPROM_Interface.h
 *
 *  Created on: Sep 25, 2023
 *      Author: moham
 */

#ifndef EXITEEPROM_INTERFACE_H_
#define EXITEEPROM_INTERFACE_H_

void ExEEPROM_Init(void);
void ExEEPROM_VidWriteByte(u16 Cpy_u16WordAddress ,u8 Cpy_u8Data);
void ExEEPROM_VidReadByte(u16 Cpy_u16WordAddress ,u8* Cpy_Pu8RxData);
void ExEEPROM_VidWritePage(u16 Cpy_u16WordAddress , u8 *Cpy_Pu8Data, u8 Cpy_u8Size);
void ExEEPROM_VidReadPage(u16 Cpy_u16WordAddress ,u8* Cpy_Pu8RxData, u8 Cpy_u8Size);

#endif /* EXITEEPROM_INTERFACE_H_ */
