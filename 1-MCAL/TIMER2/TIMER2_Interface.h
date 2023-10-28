/*
 * TIMER2_Interface.h
 *
 *  Created on: Sep 24, 2023
 *      Author: moham
 */

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

void TIMER2_VidInit(void);
void TIMER2_VidStop(void);
void TIMER2_VoidSetCallBack(void (*Ptr2)(void));
//void TIMER2_VidDelayTimems(u32 Desired_Time);
void TIMER2_VoidOCRSet(u8 Cpy_u8OCRValue);
void TIMER2_VidFastPWMSetDuty(u8 Cpy_u8DutyCycle);
void TIMER2_VidPhasePWMSetDuty(u8 Cpy_u8DutyCycle);


#endif /* TIMER2_INTERFACE_H_ */
