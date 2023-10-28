/*
 * ADC_Private.h
 *
 *  Created on: Sep 15, 2023
 *      Author: moham
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_



#define ADCL		(*( volatile u16 *)(0x24))
//#define ADCH		(*( volatile u8 *)(0x25))

/************************************************************* ADMUX **********************************************************************/
#define ADMUX		(*( volatile u8 *)(0x27))
//ADMUX Register Bits
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

//ADMUX Configuration

#define RIGHT_ADJUST	0
#define LEFT_ADJUST		1
#define AREF			0
#define AVCC			1
#define INTERNAL		3

/************************************************************* ADCSRA **********************************************************************/
#define ADCSRA		(*( volatile u8 *)(0x26))
// ADCSRA Reg bits
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0
//ADSCRA Configurations
#define ADC_PRESCALER_2		1
#define ADC_PRESCALER_4		2
#define ADC_PRESCALER_8		3
#define ADC_PRESCALER_16	4
#define ADC_PRESCALER_32	5
#define ADC_PRESCALER_64	6
#define ADC_PRESCALER_128	7

#define ADC_INTERRUPT_ENABLE	1
#define ADC_INTERRUPT_DISABLE	0
#define ADC_STARTCONV			1
#define ADC_Single_Mode			0
#define ADC_AUTOTRIG_SOURCE		1



/************************************************************* SFIOR **********************************************************************/
#define SFIOR		(*( volatile u8 *)(0x50))
// SFIOR Reg bits
#define ADTS2	7
#define ADTS1 	6
#define ADTS0	5

//SFIOR Configuration
#define AUTO_Free Run		0
#define AUTO_Anlg_Comp		1
#define AUTO_Exit_Trig 		2
#define AUTO_Timer0_CTC 	3
#define AUTO_Timer0_OV 		4
#define AUTO_Timer1_CTC		5
#define AUTO_Timer1_OV 		6
#define AUTO_Timer1_ICU		7


#define ENABLE				1
#define DISABLE				0




#endif /* ADC_PRIVATE_H_ */
