/*
 * DCMotor_Interface.h
 *
 *  Created on: Sep 21, 2023
 *      Author: moham
 */

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_


#define DCM_CLOCK_WISE                   1
#define DCM_COUNTER_CLOCK_WISE           2


void DCM_voidOn          (u8 Copy_u8Direction);
void DCM_voidControlSpeed(u8 Copy_u8Speed);
void DCM_voidOff         (void);


#endif /* DCMOTOR_INTERFACE_H_ */
