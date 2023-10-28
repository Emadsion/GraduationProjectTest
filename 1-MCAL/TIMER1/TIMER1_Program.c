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
	ICR1L = ICR_Value_Init;
	OCR1AL = OCR1AL_Value_Init;
	OCR1BL = OCR1BL_Value_Init;
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


#elif (TIMER1_MODE == TIMER1_ICU_MODE)
	// Timer1 Normal mode
	TCCR1A = 0x00;
	TCCR1B = ( TIMER1_OVERFLOW_ENABLE <<  WGM12);
	// Trigger on Rising Edge & Enabling Prescaler
	TCCR1B = (ENABLE << ICES1) | (TIMER1_PRESCALER<<CS10);
	// Initialize ICU Flag to 0 (PreSetting)
	Glb_u8ICUFlag = PreSetting;
	//Enabling Timer1 Normal Mode + ICU Mode
	SET_BIT(TIMSK, TOIE1);
	SET_BIT(TIMSK,TICIE1);
#endif
}

void TIMER1_VidOCR1ASet(u16 Cpy_u16OCR1AValue)
{

	OCR1AL = Cpy_u16OCR1AValue ;

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

void TIMER1_ICUSetEdge(u8 Cpy_u8Edge)
{
	switch (Cpy_u8Edge)
	{
	case RisingEdge: SET_BIT(TCCR1B,ICES1); break;
	case FallingEdge: CLEAR_BIT(TCCR1B,ICES1); break;
	}
}

//TIMER1 Normal mode ISR
void __vector_9(void)
{
	glb_u16OvCounter ++;
	if(TIMER1_PVidCallBack != NULL)
	{

		//static u16 Loc_u16Counter = 0;
		//glb_u16OvCounter ++;

		if(glb_u16OvCounter == TIMER1_OVERFLOW_COUNTER_VALUE) //counter for X Seconds
		{
			TIMER1_PVidCallBack();
			glb_u16OvCounter = 0;
			TCNT1L = TIMER1_PRELOAD_VALUE;
		}
	}
}
//TIMER1 CTC mode ISR
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

//TIMER1 Input Capture Unit ISR
void __vector_6(void)
{
	switch(Glb_u8ICUFlag)
	{
	case PreSetting:
		//Initializing Timer1 Reg to 0 for every reading to avoid overflow and for getting exact timing for T_on and T_total
		TCNT1L = 0;
		glb_u16OvCounter = 0;
		//Change to Falling Edge
		CLEAR_BIT(TCCR1B,ICES1);
		//Next Phase
		Glb_u8ICUFlag = FallingEdge;
		break;
	case FallingEdge:
		//Capturing T_on Value
		Glb_u16Ton = ICR1L + (65536 * glb_u16OvCounter);
		//Change to Rising Edge
		SET_BIT(TCCR1B,ICES1);
		//Next Phase
		Glb_u8ICUFlag = RisingEdge;
		break;

	case RisingEdge:
		//Capturing T_total Value
		Glb_u16Ttotal = ICR1L + (65536 * glb_u16OvCounter);
		//Return to Phase 0 (PreSetting)
		Glb_u8ICUFlag = PreSetting;
		break;

	}

}
