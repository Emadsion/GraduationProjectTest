/*
 * SevSeg_Private.h
 *
 *  Created on: Sep 15, 2023
 *      Author: moham
 */

#ifndef SEVSEG_PRIVATE_H_
#define SEVSEG_PRIVATE_H_



//For Comparison Usage
typedef enum {SevSeg_COM1,SevSeg_COM2,SevSeg_COM3,SevSeg_COM4}SevSeg_COM;
//For Writing data to BCD encoder chip
void Private_VidWriteData(u8 Cpy_u8Data,SevSeg_COM  Cpy_SevSegCom);



#endif /* SEVSEG_PRIVATE_H_ */
