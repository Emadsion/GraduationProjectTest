/*
 * UART_Interface.h
 *
 *  Created on: Sep 22, 2023
 *      Author: moham
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void UART_init(void);
void UART_TxChar(u8 data);
u8 UART_RxChar(void);


u8 Data;
#endif /* USART_INTERFACE_H_ */
