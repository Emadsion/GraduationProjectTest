/*
 * DIO_Private.h
 *
 * Created: 5/27/2022 4:44:18 PM
 *  Author: En Eslam Eid
 */

#ifndef _DIO_PRV_H_
#define _DIO_PRV_H_

#define PORTA_Address	(0x3B)
#define DDRA_Address	(0x3A)
#define PINA_Address	(0x39)

#define PORTB_Address	(0x38)
#define DDRB_Address	(0x37)
#define PINB_Address	(0x36)

#define PORTC_Address	(0x35)
#define DDRC_Address	(0x34)
#define PINC_Address	(0x33)

#define PORTD_Address	(0x32)
#define DDRD_Address	(0x31)
#define PIND_Address	(0x30)


#define PORTA 	*((volatile u8*)PORTA_Address)
#define DDRA 	*((volatile u8*)DDRA_Address)
#define PINA 	*((volatile u8*)PINA_Address)


#define PORTB 	*((volatile u8*)PORTB_Address)
#define DDRB 	*((volatile u8*)DDRB_Address)
#define PINB 	*((volatile u8*)PINB_Address)


#define PORTC 	*((volatile u8*)PORTC_Address)
#define DDRC 	*((volatile u8*)DDRC_Address)
#define PINC 	*((volatile u8*)PINC_Address)


#define PORTD 	*((volatile u8*)PORTD_Address)
#define DDRD 	*((volatile u8*)DDRD_Address)
#define PIND 	*((volatile u8*)PIND_Address)

#endif /* DIO_PRV_H_ */
