/*
 * LCD_config.h
 *
 *  Created on: 10/09/2023
 *      Author: Kareem Hussein
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

                      /* MACROS FOR LCD CONTROL PORTS & PINS CONFIGURATION */
								
/* Macros For Rs configuration */	
#define LCD_RS_PORT           DIO_PORTA
#define LCD_RS_PIN            DIO_PIN3

/* Macros For En configuration */
#define LCD_E_PORT            DIO_PORTA
#define LCD_E_PIN             DIO_PIN2 


                      /* MACROS FOR LCD DATA PORT & PINS CONFIGURATION */

/* 4 Bit Mode Pins Configurtion */

#define LCD_D4_PIN            DIO_PIN0
#define LCD_D4_PORT           DIO_PORTB
							  
#define LCD_D5_PIN            DIO_PIN1
#define LCD_D5_PORT           DIO_PORTB
							  
#define LCD_D6_PIN            DIO_PIN2
#define LCD_D6_PORT           DIO_PORTB
							  
#define LCD_D7_PIN            DIO_PIN4
#define LCD_D7_PORT           DIO_PORTB

#endif /* LCD_CONFIG_H_ */
