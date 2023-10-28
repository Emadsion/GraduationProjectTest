/*
 * DIO_interface.h
 *
 * Created: 5/27/2022 4:44:18 PM
 *  Author: En Eslam Eid
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_


/*Used to Control DIO Pins*/
typedef enum {
Pin_A0  ,Pin_A1	,Pin_A2	,Pin_A3	,Pin_A4	,Pin_A5	, Pin_A6 ,Pin_A7 ,
Pin_B0	,Pin_B1 ,Pin_B2 ,Pin_B3	,Pin_B4 ,Pin_B5	, Pin_B6 ,Pin_B7 ,
Pin_C0	,Pin_C1	,Pin_C2	,Pin_C3	,Pin_C4	,Pin_C5	, Pin_C6 ,Pin_C7 ,
Pin_D0	,Pin_D1	,Pin_D2	,Pin_D3	,Pin_D4	,Pin_D5	, Pin_D6 ,Pin_D7 ,
}Pin_Type;

/*Used to Control DIO DDR Registers*/
typedef enum
{
DDR_A,DDR_B,DDR_C,DDR_D
}DDR_Type;


/*Used to Control DIO Port Registers*/
typedef enum
{
PORT_A,PORT_B,PORT_C,PORT_D
}PORT_Type;


/*Used to determine the state of Pins*/
typedef enum {
	OutPut_High , OutPut_Low,
	InPut_Float,InPut_PullUp,
	Toggle
}PinMode_type;

/*Used to control The pointer to the array of registers */
typedef enum {
	DDR,PORT,PIN
}DIO_Reg;

/***************************************** DIO Prototypes *************************************************/
void DIO_Init(void);
void DIO_SetPinMode(Pin_Type Cpy_Pin_ID , PinMode_type Cpy_Mode);
void DIO_SetPortMode(PORT_Type Cpy_PORT , unsigned char Cpy_Value);
void DIO_SetDirectionMode(DDR_Type Cpy_DDR , unsigned char Cpy_Value);
unsigned char DIO_u8ReadPinVal(Pin_Type Pin_ID);

/*********************************************************************************************************/



#endif /* DIO_INTERFACE_H_ */













