/*
 * EXIT_Private.h
 *
 *  Created on: Sep 11, 2023
 *      Author: moham
 */

#ifndef EXIT_PRIVATE_H_
#define EXIT_PRIVATE_H_


//Register to Enable Interrupt Pins
#define GICR		(*(volatile u8 *)(0x5B))
#define INT2_BIT	5
#define INT0_BIT	6
#define INT1_BIT	7

//Register to Set Interrupt Modes (INT0 - INT1) -> {Rising - Falling - Low level - OCH}
#define MCUCR		(*(volatile u8 *)(0x55))
#define ISC00_BIT	0
#define ISC01_BIT	1
#define ISC10_BIT	2
#define ISC11_BIT	3

//Register for Interrupt Modes (INT2) -> {Rising - Falling - Low level - OCH}
#define MCUCSR		(*(volatile u8 *)(0x54))
#define ISC2_BIT	2

//Register for interrupt flags (Automatic clearance)
#define GIFR		(*(volatile u8 *)(0x5A))
#define INTF2	5
#define INTF0	6
#define INTF1	7


//Pointers to interrupt routine
static void (* EXIT0_PVidCallBack)(void) = NULL;
static void (* EXIT1_PVidCallBack)(void) = NULL;
static void (* EXIT2_PVidCallBack)(void) = NULL;

//ISR of (INT0 , INT1 , INT2)
void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

// __attribute__(signal) -> This is a compiler dependent assembly code which indicates the ISR not optimized and make the linke move the address of the function to IVT




#endif /* EXIT_PRIVATE_H_ */
