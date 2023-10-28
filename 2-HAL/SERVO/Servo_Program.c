/*
 * Servo.c
 *
 *  Created on: Sep 21, 2023
 *      Author: moham
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_Interface.h"
#include "TIMER1_Interface.h"
#include "Servo_Config.h"
#include "Servo_Interface.h"

void SERVO_VidInit(void)
{
	TIMER1_VidInit();
	DIO_SetPinMode(SERVO_PIN,OutPut_Low);
	TIMER1_VidFastPWMSetFrequancy(50);
}

void SERVO_VidOn(u8 Cpy_u8Angle)
{
	switch (Cpy_u8Angle)
	{
	case 180:TIMER1_VidFastPWMSetDuty(5); break;
	case 135:TIMER1_VidFastPWMSetDuty(6); break;
	case 90:TIMER1_VidFastPWMSetDuty(7); break;
	case 45:TIMER1_VidFastPWMSetDuty(8); break;
	case 0:TIMER1_VidFastPWMSetDuty(10); break;
	}
}

void SERVO_VidOff(void)
{
	TIMER1_VidStop();
}
