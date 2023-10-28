/*
 * TIMER1_Interface.h
 *
 *  Created on: Sep 17, 2023
 *      Author: moham
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_VidInit(void);
void TIMER1_VidStop(void);
void TIMER1_VidFastPWMSetFrequancy (u16 Cpy_u16Frquancy);
void TIMER1_VidFastPWMSetDuty(u8 Cpy_u16DutyCycle);
void TIMER1_VoidSetCallBack(void (*Ptr1)(void));
void TIMER1_VoidICRSet(u16 Cpy_u8ICUValue);
void TIMER1_VidOCR1ASet(u16 Cpy_u16OCR1AValue);
void TIMER1_ICUSetEdge(u8 Cpy_u8Edge);

u8 Glb_u8ICUFlag;
u16 Glb_u16Ton;
u16 Glb_u16Ttotal;
u16 glb_u16OvCounter;

#endif /* TIMER1_INTERFACE_H_ */
