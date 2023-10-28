/*
 * DCMotor_Program.c
 *
 *  Created on: Sep 21, 2023
 *      Author: moham
 */


/*
 * DCMotor_Program.h
 *
 *  Created on: Sep 21, 2023
 *      Author: moham
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "TIMER0_Interface.h"
#include "DCMotor_Interface.h"
#include "DCMotor_Config.h"

/* Turn DC motor on using H-Bridge
 *	 By Setting PWM, Dir and Enable pins with high
 *	 or Dir Low depend on Copy_u8Direction   */
void DCM_voidOn(u8 Copy_u8Direction)
{
	DIO_SetPinMode(DCMotor_Enable_Pin,OutPut_High);
	TIMER0_VidInit();
	switch(Copy_u8Direction)
	{
	case DCM_CLOCK_WISE: DIO_SetPinMode(DCMotor_Direction_Pin,OutPut_High); break;
	case DCM_COUNTER_CLOCK_WISE : DIO_SetPinMode(DCMotor_Direction_Pin,OutPut_Low); break;
	}
}

/* Controlling DC motor speed using PWM
mode from TMR0 by setting Duty Cycle*/
void DCM_voidControlSpeed(u8 Copy_u8Speed)
{
	TIMER0_VoidOCRSet(Copy_u8Speed);

}

/* Turn DC motor off using H-Bridge
   By Setting Enable pin with low */
void DCM_voidOff(void)
{
	DIO_SetPinMode(DCMotor_Enable_Pin,OutPut_Low);
}
