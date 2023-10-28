/*
 * TIMER0_Private.h
 *
 *  Created on: Sep 16, 2023
 *      Author: moham
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
/******************************************** TCCR0 Register ******************************************************/
#define TCCR0		*((volatile u8 *) 0x53)
//TCCR0 Register bits
#define FOC0		7
#define WGM00		6
#define COM01		5
#define COM00		4
#define WGM01		3
#define CS02		2
#define CS01		1
#define CS00		0

/******************************************** TCNT0 Register ******************************************************/
#define TCNT0		*((volatile u8 *) 0x52)
/******************************************** OCR0 Register ******************************************************/
#define OCR0		*((volatile u8 *) 0x5C)

/******************************************** TIMSK Register ******************************************************/
#define TIMSK		*((volatile u8 *) 0x59)
//TIMSK Register bits
#define OCIE0		1
#define TOIE0		0

/******************************************** TIFR Register ******************************************************/
#define TIFR		*((volatile u8 *) 0x58)
//TIFR Register bits
#define OCF0		1
#define TOV0		0


/***************************************** Timer0 Configurations ************************************************/
//TIMER0 4 MODES
#define TIMER0_FASTPWM			0
#define TIMER0_OVERFLOW			1
#define TIMER0_CTC				2
#define TIMER0_PHASECORRECT_PWM	3

//TIMER0 Prescaler Modes
#define TIMER0_PRESCALER_DISABLE				0
#define TIMER0_PRESCALER_0						1
#define TIMER0_PRESCALER_8						2
#define TIMER0_PRESCALER_64						3
#define TIMER0_PRESCALER_256					4
#define TIMER0_PRESCALER_1024					5
#define TIMER0_PRESCALER_EXITCLK_FALLING		6
#define TIMER0_PRESCALER_EXITCLK_RISING			7
//TIMER0 Interrupts Modes
#define TIMER0_OVINTERRUPT						1
#define TIMER0_CTCINTERRUPT						2
//TIMER0 PWM Modes
#define TIMER0_PWM_NORMAL_OC0					0
#define	TIMER0_PWM_NON_INVERTED					2
#define	TIMER0_PWM_INVERTED						3

//General Enable & Disable
#define ENABLE									1
#define DISABLE									0
/**********************************************************************************************************************/

/***************************************** Timer0 Private Prototypes ************************************************/

static void (* TIMER0_PVidCallBack)(void) = NULL;		//CallBack pointer
void __vector_11(void) __attribute__((signal));			//Timer0 Overflow ISR
void __vector_10(void) __attribute__((signal));			//Timer0 CTC ISR



#endif /* TIMER0_PRIVATE_H_ */
