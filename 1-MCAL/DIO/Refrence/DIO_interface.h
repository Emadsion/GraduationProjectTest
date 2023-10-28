/*
 * DIO_interface.h
 *
 * Created: 5/27/2022 4:44:18 PM
 *  Author: En Eslam Eid
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

typedef enum {
Pin_A0  ,Pin_A1	,Pin_A2	,Pin_A3	,Pin_A4	,Pin_A5	, Pin_A6 ,Pin_A7 ,
Pin_B0	,Pin_B1 ,Pin_B2 ,Pin_B3	,Pin_B4 ,Pin_B5	, Pin_B6 ,Pin_B7 ,
Pin_C0	,Pin_C1	,Pin_C2	,Pin_C3	,Pin_C4	,Pin_C5	, Pin_C6 ,Pin_C7 ,
Pin_D0	,Pin_D1	,Pin_D2	,Pin_D3	,Pin_D4	,Pin_D5	, Pin_D6 ,Pin_D7 ,
}Pin_Type;

typedef enum {
	OutPut_High , OutPut_Low,
	InPut_Float,InPut_PullUp
}PinMode_type;








#endif /* DIO_INTERFACE_H_ */













