/*
 * TIMER2_Program.c
 *
 *  Created on: Sep 24, 2023
 *      Author: moham
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER2_Private.h"
#include "TIMER2_Config.h"
#include "TIMER2_Interface.h"

u32 x;

/*
Equation of timer:
					T(OV)=256*Prescaler/frequency
					Counter = Required time / T(ov)
					Preload = 256 - (256 * counter float)
					OCR_Duty_cycle = ((Cpy_u8DutyCycle*256)/100) - 1;

 */

/**************************************************************** TIMER2_VidInit *****************************************************************************/
void TIMER2_VidInit(void)
{

#if (TIMER2_MODE == TIMER2_OVERFLOW)

	TCCR2 = (DISABLE << WGM20) | (DISABLE << WGM21) | (DISABLE << COM20);
	//Preload Value
	TCNT2 = TIMER2_PRELOAD_VALUE;
	//Enabling Overflow interrupt
	SET_BIT(TIMSK,TOIE2);
	//PRESCALER
	TCCR2 = (TCCR2 &0xF8) | TIMER2_PRESCALER;


#elif (TIMER2_MODE == TIMER2_CTC)

	TCCR2 = (DISABLE << WGM20)  | (DISABLE << COM20) | (ENABLE << WGM21);
	//CTC Value
	OCR2 = TIMER2_CTC_VALUE;
	//Enable CTC Interrupt
	SET_BIT(TIMSK,OCIE2);
	//PRESCALER and Enabling TIMER2
	TCCR2 = (TCCR2 &0xF8) | TIMER2_PRESCALER;

#elif (TIMER2_MODE == TIMER2_FASTPWM)
		//Setting FASTPWM MODE (Inverted or Non Inverted)
		TCCR2 = (ENABLE << WGM20) | (TIMER2_FASTPWM_MODE << COM20) | (ENABLE << WGM21);
		//Disabling Overflow and CTC interrupt
		CLEAR_BIT(TIMSK,OCIE2);
		CLEAR_BIT(TIMSK,TOIE2);
		//PRESCALER and Enabling TIMER2
		TCCR2 = (TCCR2 &0xF8) | TIMER2_PRESCALER;
#elif (TIMER2_MODE == TIMER2_PHASECORRECT_PWM)
		//Setting Phase correct PWM MODE (Inverted or Non Inverted)
		TCCR2 = (ENABLE << WGM20) | (TIMER2_PWM_NON_INVERTED << COM20) | (DISABLE << WGM21);
		//Disabling Overflow and CTC interrupt
		CLEAR_BIT(TIMSK,OCIE2);
		CLEAR_BIT(TIMSK,TOIE2);
		//PRESCALER and Enabling TIMER2
		TCCR2 = (TCCR2 &0xF8) | TIMER2_PRESCALER;

#endif
}

/**************************************************************** TIMER2_VidStop *****************************************************************************/
void TIMER2_VidStop(void)
{
	//Disable PRESCALER and Disable TIMER2
	TCCR2 = (TCCR2 &0xF8) | DISABLE;
}

/**************************************************************** TIMER2_VoidDutyCycle **************************************************************************/
void TIMER2_VoidOCRSet(u8 Cpy_u8OCRValue)
{
	OCR2 = Cpy_u8OCRValue;
}
/**************************************************************** TIMER2_VidFastPWMSetDuty **************************************************************************/
void TIMER2_VidFastPWMSetDuty(u8 Cpy_u8DutyCycle)
{
	//Inverting T_off with T_on if it's inverted
	#if (TIMER2_FASTPWM_MODE == TIMER2_PWM_INVERTED)
	Cpy_u8DutyCycle = 100 - Cpy_u8DutyCycle;
	#endif
	//Calculating the OCR0 value from the Given duty cycle
	if(Cpy_u8DutyCycle <=100)
	{
		OCR2 = (((u16)Cpy_u8DutyCycle*256)/100) - 1;
	}
}
/**************************************************************** TIMER2_VidPhasePWMSetDuty **************************************************************************/
void TIMER2_VidPhasePWMSetDuty(u8 Cpy_u8DutyCycle)
{
	//Inverting T_off with T_on if it's inverted
	#if (TIMER2_PHASECORRECT_MODE == TIMER2_PWM_INVERTED )
	Cpy_u8DutyCycle = 100 - Cpy_u8DutyCycle;
	#endif
	//Calculating the OCR0 value from the Given duty cycle
	if(Cpy_u8DutyCycle <=100)
	{
		OCR2 = (((u16)Cpy_u8DutyCycle*256)/100) - 1;
	}

}

/**************************************************************** TIMER2_VoidSetCallBack *************************************************************************/
void TIMER2_VoidSetCallBack(void (*Ptr2)(void))
{
	TIMER2_PVidCallBack = Ptr2;
}
/**************************************************************** TIMSER0_VidDelayTimems *************************************************************************/
/* Only for 64 Prescaler AND ONLY FOR CTC MODE
void TIMSER0_VidDelayTimems(u32 Desired_Time)
{

	OCR0 = 249;
	x = Desired_Time;
}
*/

/**************************************************************** TIMER2_OVERFLOW ISR *************************************************************************/
void __vector_5(void)
{
	if(TIMER2_PVidCallBack != NULL)
	{
		static u16 Loc_u8Counter = 0;
		Loc_u8Counter ++;
		if(Loc_u8Counter == TIMER2_COUNTER_VALUE) //counter for X Seconds
		{
			TIMER2_PVidCallBack();
			Loc_u8Counter = 0;
			TCNT2 = TIMER2_PRELOAD_VALUE;
		}
	}
}


/**************************************************************** TIMER2_CTC ISR *************************************************************************/
void __vector_4(void)
{
	if(TIMER2_PVidCallBack != NULL)
	{

		static u16 Loc_u16Counter = 0;
		Loc_u16Counter ++;
		if(Loc_u16Counter == TIMER2_COUNTER_VALUE) //counter for X Seconds
		{
			TIMER2_PVidCallBack();
			Loc_u16Counter = 0;
		}
	}
}
