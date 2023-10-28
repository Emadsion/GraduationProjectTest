/*
 * UART_program.c
 *
 * Created: 5/5/2023 5:10:26 PM
 *  Author: AMIT
 */


#define F_CPU 16000000UL
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "USART_Private.h"
#include "USART_Config.h"
#include "USART_Interface.h"


void UART_init(void)
{
	// writing the UCSRC , // selct UART MODE = Asynchronous , 	// configure no parity , // configure data bits = 8 , // configure stop bits = 1
	UCSRC = (UCSRC_REG_SELECT << URSEL) | (USART_ASYNC<< UMSEL) | (USART_PARITY << UPM0) | (USART_STOP_BITS << USBS) | (USART_DATA_8_BITS << UCSZ0) | (USART_CLK_POLARITY << UCPOL);
    //UCSRC = 0x86; //0b10000110
	CLEAR_BIT(UCSRB,2);

	// set buad rate = 9600
	UBRRL = 103;

	//Enable Tx
	SET_BIT(UCSRB,3);

	//Enable Rx
	SET_BIT(UCSRB,4);
	
	//Enable Rx Interrupt
	SET_BIT(UCSRB,7);
}


void UART_TxChar(u8 data)
{
	UDR = data;
	while(0 == GET_BIT(UCSRA,5));
}


u8 UART_RxChar(void)
{
	while(0 == GET_BIT(UCSRA,7));

	return UDR;
}


void __vector_13(void)
{

	Data = UDR;
}