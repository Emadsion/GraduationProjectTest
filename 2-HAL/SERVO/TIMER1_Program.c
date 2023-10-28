/*
 * TIMER1_Program.c
 *
 *  Created on: Sep 17, 2023
 *      Author: moham
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_Private.h"
#include "TIMER1_Config.h"
#include "TIMER1_Interface.h"
#include "DIO_Interface.h"


void TIMER1_VidInit(void)
{


#if (TIMER1_MODE == TIMER1_FASTPWM_ICR1)
	TCCR1A = (TIMER1_PWM_MODE << COM1B0 ) | (DISABLE  << FOC1B) | (TIMER1_FASTPWM_ICR1_TCCR1A_WGM  << WGM10);
	TCCR1B = ( DISABLE <<  T1Res) | (TIMER1_FASTPWM_ICR1_TCCR1B_WGM   << WGM12);
	TIMSK = (TIMSK &0xC0) |(DISABLE << TOIE1) | (TIMSK &0x0C) ;
	TCCR1B = (TCCR1B &0xF8) | TIMER1_PRESCALER;
#elif (TIMER1_MODE == TIMER1_OVERFLOW_MODE)
	TCCR1A = DISABLE;
	TCCR1B = ( TIMER1_OVERFLOW_ENABLE <<  WGM12);
	TCNT1L = TIMER1_PRELOAD_VALUE;
	TIMSK = (TIMSK &0xC0) |(TIMER1_OVERFLOW_INTERRUPT_ENABLE << TOIE1) | (TIMSK &0x0C) ;
	TCCR1B = (TCCR1B &0xF8) | TIMER1_PRESCALER;
#elif (TIMER1_MODE == TIMER1_CTC_MODE)

	TCCR1A = 0x00;
	TCCR1B = ( DISABLE <<  T1Res) | (TIMER1_CTC_ENABLE   << WGM12);
	TIMSK = (TIMSK &0xC0) |(TIMER1_CTC_CHANNEL << TOIE1) | (TIMSK &0x0C) ;
	OCR1AL =TIMER1_OCR1AL_VALUE;
	OCR1BL =DISABLE;
	TCCR1B = (TCCR1B &0xF8) | TIMER1_PRESCALER;
#endif
}

void TIMER1_VidStop(void)
{
	TCCR1B = (TCCR1B &0xF8) | TIMER1_PRESCALER_DISABLE;
}

void TIMER1_VidFastPWMSetDuty(u8 Cpy_u8DutyCycle)
{
#if (TIMER1_MODE == TIMER1_FASTPWM_ICR1)
	//Inverting T_off with T_on if it's inverted
#if (TIMER1_PWM_MODE == TIMER1_PWM_CHANNEL_A_INVERTED)
	Cpy_u8DutyCycle = 100 - Cpy_u8DutyCycle;
	#endif
	//Calculating the OCR1AL value from the Given duty cycle and Given frequency in ICR1
	if(Cpy_u8DutyCycle <=100)
	{
	OCR1AL = (u16)(((u32)Cpy_u8DutyCycle*(u32)(ICR1L+1))/100)-1;
	}
#endif
}

void TIMER1_VidOCR1ASet(u16 Cpy_u16OCR1AValue)
{

	OCR1AL = Cpy_u16OCR1AValue ;

}

void TIMER1_VoidICRSet(u16 Cpy_u16ICUValue)
{
	ICR1L = Cpy_u16ICUValue;
}

void TIMER1_VidFastPWMSetFrequancy (u16 Cpy_u16Frquancy)
{
	//IN 64 PRESCALER ONLY
	ICR1L = (((u32)1000000 / (u32)Cpy_u16Frquancy)/4) - 1;
}

void TIMER1_VoidSetCallBack(void (*Ptr1)(void))
{
	TIMER1_PVidCallBack = Ptr1;
}

void __vector_9(void)
{
	if(TIMER1_PVidCallBack != NULL)
	{

		static u16 Loc_u16Counter = 0;
		Loc_u16Counter ++;
		if(Loc_u16Counter == TIMER1_OVERFLOW_COUNTER_VALUE) //counter for X Seconds
		{
			TIMER1_PVidCallBack();
			Loc_u16Counter = 0;
			TCNT1L = TIMER1_PRELOAD_VALUE;
		}
	}
}

void __vector_7(void)
{

	if(TIMER1_PVidCallBack != NULL)
	{

		static u8 Loc_u8Counter = 0;
		Loc_u8Counter ++;
		if(Loc_u8Counter == TIMER1_CTC_COUNTER_VALUE) //counter for X Seconds
		{
			TIMER1_PVidCallBack();
			Loc_u8Counter = 0;
		}
	}
}
