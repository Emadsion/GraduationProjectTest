/*
 * TIMER0_Interface.h
 *
 *  Created on: Sep 16, 2023
 *      Author: moham
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_VidInit(void);
void TIMER0_VidStop(void);
void TIMER0_VoidSetCallBack(void (*Ptr0)(void));
//void TIMER0_VidDelayTimems(u32 Desired_Time);
void TIMER0_VoidOCRSet(u8 Cpy_u8OCRValue);
void TIMER0_VidFastPWMSetDuty(u8 Cpy_u8DutyCycle);
void TIMER0_VidPhasePWMSetDuty(u8 Cpy_u8DutyCycle);
#endif /* TIMER0_INTERFACE_H_ */
