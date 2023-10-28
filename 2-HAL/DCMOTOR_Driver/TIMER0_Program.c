/*
 * TIMER0_Program.c
 *
 *  Created on: Sep 16, 2023
 *      Author: moham
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_Private.h"
#include "TIMER0_Config.h"
#include "TIMER0_Interface.h"

u32 x;

/*
Equation of timer:
					T(OV)=256*Prescaler/frequency
					Counter = Required time / T(ov)
					Preload = 256 - (256 * counter float)
					OCR_Duty_cycle = ((Cpy_u8DutyCycle*256)/100) - 1;

 */

/**************************************************************** TIMER0_VidInit *****************************************************************************/
void TIMER0_VidInit(void)
{

#if (TIMER0_MODE == TIMER0_OVERFLOW)

	TCCR0 = (DISABLE << WGM00) | (DISABLE << WGM01) | (DISABLE << COM00);
	//Preload Value
	TCNT0 = TIMER0_PRELOAD_VALUE;
	//Enabling Overflow interrupt
	TIMSK = (TIMSK &0xFC) |TIMER0_MODE;
	//PRESCALER
	TCCR0 = (TCCR0 &0xF8) | TIMER0_PRESCALER;


#elif (TIMER0_MODE == TIMER0_CTC)

	TCCR0 = (DISABLE << WGM00) | (ENABLE << WGM01) | (DISABLE << COM00);
	//CTC Value
	OCR0 = TIMER0_CTC_VALUE;
	//Enable CTC Interrupt
	TIMSK = (TIMSK &0xFC) |TIMER0_MODE;
	//PRESCALER and Enabling Timer0
	TCCR0 = (TCCR0 &0xF8) | TIMER0_PRESCALER;

#elif (TIMER0_MODE == TIMER0_FASTPWM)
		//Setting FASTPWM MODE (Inverted or Non Inverted)
		TCCR0 = (ENABLE << WGM00) | (TIMER0_FASTPWM_MODE << COM00) | (ENABLE << WGM01);
		//Disabling Overflow and CTC interrupt
		TIMSK = (TIMSK &0xFC) |TIMER0_MODE;
		//PRESCALER and Enabling Timer0
		TCCR0 = (TCCR0 &0xF8) | TIMER0_PRESCALER;
#elif (TIMER0_MODE == TIMER0_PHASECORRECT_PWM)
		//Setting Phase correct PWM MODE (Inverted or Non Inverted)
		TCCR0 = (ENABLE << WGM00) | (TIMER0_PWM_NON_INVERTED << COM00) | (DISABLE << WGM01);
		//Disabling Overflow and CTC interrupt
		TIMSK = (TIMSK &0xFC) |TIMER0_MODE;
		//PRESCALER and Enabling Timer0
		TCCR0 = (TCCR0 &0xF8) | TIMER0_PRESCALER;

#endif
}

/**************************************************************** TIMER0_VidStop *****************************************************************************/
void TIMER0_VidStop(void)
{
	//Disable PRESCALER and Disable Timer0
	TCCR0 = (TCCR0 &0xF8) | DISABLE;
}

/**************************************************************** TIMER0_VoidDutyCycle **************************************************************************/
void TIMER0_VoidOCRSet(u8 Cpy_u8OCRValue)
{
	OCR0 = Cpy_u8OCRValue;
}
/**************************************************************** TIMER0_VidFastPWMSetDuty **************************************************************************/
void TIMER0_VidFastPWMSetDuty(u8 Cpy_u8DutyCycle)
{
	//Inverting T_off with T_on if it's inverted
	#if (TIMER0_FASTPWM_MODE == TIMER0_PWM_INVERTED)
	Cpy_u8DutyCycle = 100 - Cpy_u8DutyCycle;
	#endif
	//Calculating the OCR0 value from the Given duty cycle
	if(Cpy_u8DutyCycle <=100)
	{
		OCR0 = (((u16)Cpy_u8DutyCycle*256)/100) - 1;
	}
}
/**************************************************************** TIMER0_VidPhasePWMSetDuty **************************************************************************/
void TIMER0_VidPhasePWMSetDuty(u8 Cpy_u8DutyCycle)
{
	//Inverting T_off with T_on if it's inverted
	#if (TIMER0_PHASECORRECT_MODE == TIMER0_PWM_INVERTED )
	Cpy_u8DutyCycle = 100 - Cpy_u8DutyCycle;
	#endif
	//Calculating the OCR0 value from the Given duty cycle
	if(Cpy_u8DutyCycle <=100)
	{
		OCR0 = (((u16)Cpy_u8DutyCycle*256)/100) - 1;
	}

}

/**************************************************************** TIMER0_VoidSetCallBack *************************************************************************/
void TIMER0_VoidSetCallBack(void (*Ptr0)(void))
{
	TIMER0_PVidCallBack = Ptr0;
}
/**************************************************************** TIMSER0_VidDelayTimems *************************************************************************/
/* Only for 64 Prescaler AND ONLY FOR CTC MODE
void TIMSER0_VidDelayTimems(u32 Desired_Time)
{

	OCR0 = 249;
	x = Desired_Time;
}
*/

/**************************************************************** TIMER0_OVERFLOW ISR *************************************************************************/
void __vector_11(void)
{
	if(TIMER0_PVidCallBack != NULL)
	{
		static u16 Loc_u8Counter = 0;
		Loc_u8Counter ++;
		if(Loc_u8Counter == TIMER0_COUNTER_VALUE) //counter for X Seconds
		{
			TIMER0_PVidCallBack();
			Loc_u8Counter = 0;
			TCNT0 = TIMER0_PRELOAD_VALUE;
		}
	}
}


/**************************************************************** TIMER0_CTC ISR *************************************************************************/
void __vector_10(void)
{
	if(TIMER0_PVidCallBack != NULL)
	{

		static u16 Loc_u16Counter = 0;
		Loc_u16Counter ++;
		if(Loc_u16Counter == TIMER0_CTC_VALUE) //counter for X Seconds
		{
			TIMER0_PVidCallBack();
			Loc_u16Counter = 0;
		}
	}
}
