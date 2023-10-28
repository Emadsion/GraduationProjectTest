/*
 * ADC_Interface.h
 *
 *  Created on: Sep 15, 2023
 *      Author: moham
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC0			0
#define ADC1			1
#define ADC2			2
#define ADC3			3
#define ADC4			4
#define ADC5			5
#define ADC6			6
#define ADC7			7



u16 ADC_u16ReadSingleChannel( u8 ADC_CHANNEL );
void ADC_VidInit(void);
#endif /* ADC_INTERFACE_H_ */
