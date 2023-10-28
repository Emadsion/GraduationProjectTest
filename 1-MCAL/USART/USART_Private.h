/*
 * UART_Private.h
 *
 *  Created on: Sep 22, 2023
 *      Author: moham
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define UCSRA			(*(volatile u8*)(0x2B))

#define RXC		7
#define TXC		6
#define UDRE	5
#define FE		4
#define DOR		3
#define PE		2
#define U2X		1
#define MPCM	0

#define UCSRB			(*(volatile u8*)(0x2A))

#define RXCIE 	7
#define TXCIE	6
#define UDRIE	5
#define RXEN	4
#define TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0

#define UCSRC			(*(volatile u8*)(0x40))

#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0

#define UBRRH			(*(volatile u8*)(0x40))

#define URSEL	7
#define URES	4

#define UBRRL			(*(volatile u8*)(0x29))

#define UDR				(*(volatile u8*)(0x2C))
/******************************************************************************************************************************************************************************/
#define USART_ASYNC								0
#define USART_SYNC									1

#define USART_PARITY_EVEN					2
#define USART_PARITY_ODD					3

#define USART_STOP_1_BIT						0
#define USART_STOP_2_BIT						1


#define USART_DATA_5_BITS					0
#define USART_DATA_6_BITS					1
#define USART_DATA_7_BITS					2
#define USART_DATA_8_BITS					3

#define USART_DATA_9_BITS					7

#define UBRRH_REG_SELECT					0
#define UCSRC_REG_SELECT						1

#define USART_RISING_CLK_EDGE			0
#define USART_FALLING_CLK_EDGE			1
/************************************************************************************************************************************************************************************/
#define USART_BAUDRATE_9600			103

#define DISABLE					0
#define ENABLE 					1

void __vector_13(void) __attribute__((signal));
#endif /* USART_PRIVATE_H_ */
