/*
 * TIMER2_Private.h
 *
 *  Created on: Sep 24, 2023
 *      Author: moham
 */

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_


/******************************************** TCCR2 Register ******************************************************/
#define TCCR2		*((volatile u8 *) 0x45)
//TCCR2 Register bits
#define FOC2		7
#define WGM20		6
#define COM21		5
#define COM20		4
#define WGM21		3
#define CS22		2
#define CS21		1
#define CS20		0

/******************************************** TCNT0 Register ******************************************************/
#define TCNT2		*((volatile u8 *) 0x44)
/******************************************** OCR0 Register ******************************************************/
#define OCR2		*((volatile u8 *) 0x43)

/******************************************** TIMSK Register ******************************************************/
#define TIMSK		*((volatile u8 *) 0x59)
//TIMSK Register bits
#define OCIE2		7
#define TOIE2			6

/******************************************** TIFR Register ******************************************************/
#define TIFR		*((volatile u8 *) 0x58)
//TIFR Register bits
#define OCF2		7
#define TOV2		6


/***************************************** TIMER2 Configurations ************************************************/
//TIMER2 4 MODES
#define TIMER2_FASTPWM			0
#define TIMER2_OVERFLOW			1
#define TIMER2_CTC				2
#define TIMER2_PHASECORRECT_PWM	3

//TIMER2 Prescaler Modes
#define TIMER2_PRESCALER_DISABLE				0
#define TIMER2_PRESCALER_0						1
#define TIMER2_PRESCALER_8						2
#define TIMER2_PRESCALER_32					3
#define TIMER2_PRESCALER_64					4
#define TIMER2_PRESCALER_128					5
#define TIMER2_PRESCALER_256					6
#define TIMER2_PRESCALER_1024			7
//TIMER2 Interrupts Modes
#define TIMER2_OVINTERRUPT						1
#define TIMER2_CTCINTERRUPT						2
//TIMER2 PWM Modes
#define TIMER2_PWM_NORMAL_OC0					0
#define	TIMER2_PWM_NON_INVERTED					2
#define	TIMER2_PWM_INVERTED						3

//General Enable & Disable
#define ENABLE									1
#define DISABLE									0
/**********************************************************************************************************************/

/***************************************** TIMER2 Private Prototypes ************************************************/

static void (* TIMER2_PVidCallBack)(void) = NULL;		//CallBack pointer
void __vector_5(void) __attribute__((signal));			//TIMER2 Overflow ISR
void __vector_4(void) __attribute__((signal));			//TIMER2 CTC ISR




#endif /* TIMER2_PRIVATE_H_ */
