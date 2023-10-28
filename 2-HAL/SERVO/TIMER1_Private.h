/*
 * TIMER1_Private.h
 *
 *  Created on: Sep 17, 2023
 *      Author: moham
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A		(*(volatile u8 *) 0x4F)
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
#define FOC1A		3
#define FOC1B		2
#define WGM11		1
#define WGM10		0






#define TCCR1B		(*(volatile u8 *) 0x4E)
#define ICNC1		7
#define ICES1		6
#define T1Res		5
#define WGM13		4
#define WGM12		3
#define CS12		2
#define CS11		1
#define CS10		0



#define TCNT1L		(*(volatile u16 *) 0x4C)



#define OCR1AL		(*(volatile u16 *) 0x4A)



#define OCR1BL		(*(volatile u16 *) 0x48)



#define ICR1L		(*(volatile u16 *) 0x46)



#define TIMSK		(*(volatile u8 *) 0x59)
#define TICIE1		5
#define OCIE1A		4
#define OCIE1B		3
#define TOIE1		2



#define TIFR		(*(volatile u8 *) 0x58)
#define ICF1		5
#define OCF1A		4
#define OCF1B		3
#define TOV1		2


//TIMER1_MODES
#define TIMER1_OVERFLOW_MODE	0
#define TIMER1_CTC_MODE			12
#define TIMER1_FASTPWM_ICR1		14


//TIMER PWM MODES & CHANNELS
#define TIMER1_PWM_CHANNEL_A_NON_INVERTED				8
#define TIMER1_PWM_CHANNEL_A_INVERTED					12
#define TIMER1_PWM_CHANNEL_B_NON_INVERTED				2
#define TIMER1_PWM_CHANNEL_B_INVERTED					3
#define TIMER1_BOTHCHANNELS_NON_INVERTED				10
#define TIMER1_BOTHCHANNELS_INVERTED					15
#define	TIMER1_BOTHCHANNELS_A_NONINVERTED_B_INVERTED	11
#define	TIMER1_BOTHCHANNELS_A_INVERTED_B_NONINVERTED	14


#define TIMER1_FASTPWM_ICR1_TCCR1A_WGM			2
#define TIMER1_FASTPWM_ICR1_TCCR1B_WGM			3

//TIMER1 OVERFLOW MODE
#define TIMER1_OVERFLOW_ENABLE					0
#define TIMER1_OVERFLOW_INTERRUPT_ENABLE		1

//TIMER1 ENABLE CTC MODE
#define TIMER1_CTC_ENABLE						1
#define TIMER1_CTC_CH_A							4
#define TIMER1_CTC_CH_B							2
#define TIMER1_CTC_CH_BOTH						6

#define TIMER1_PRESCALER_DISABLE				0
#define TIMER1_PRESCALER_1						1
#define TIMER1_PRESCALER_8						2
#define TIMER1_PRESCALER_64						3
#define TIMER1_PRESCALER_256					4
#define TIMER1_PRESCALER_1024					5

#define DISABLE							0
#define ENABLE							1


/*******************************************************************************************************************/
static void (* TIMER1_PVidCallBack)(void) = NULL;		//CallBack pointer
void __vector_9(void) __attribute__((signal));			//Timer1 Overflow ISR
void __vector_7(void) __attribute__((signal));			//Timer1 CTC ISR


#endif /* TIMER1_PRIVATE_H_ */
