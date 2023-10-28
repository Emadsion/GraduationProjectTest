/*
 * DIO_Prog.c
 *
  * Created: 5/27/2022 4:44:18 PM
  *  Author: En Eslam Eid
  */

#include "STD_Types.h"
#include "DIO_Private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

u8 * const DIO_RegPORT[4]={&PORTA,&PORTB,&PORTC,&PORTD};
u8 * const DIO_RegDDR[4]= {&DDRA,&DDRB,&DDRC,&DDRD};
u8 * const DIO_RegPIN[4]= {&PINA,&PINB,&PINC,&PIND};
	
//static u8 PortA,PortB,PortC,PortD;
/*****************************DIO_VoidInit***********************************/
 
 u8 Dio_PinInitArray[]={     
 Dio_PinA0_init, Dio_PinA1_init, Dio_PinA2_init, Dio_PinA3_init,
 Dio_PinA4_init, Dio_PinA5_init, Dio_PinA6_init, Dio_PinA7_init,
 Dio_PinB0_init, Dio_PinB1_init, Dio_PinB2_init, Dio_PinB3_init,
 Dio_PinB4_init, Dio_PinB5_init, Dio_PinB6_init, Dio_PinB7_init,
 Dio_PinC0_init, Dio_PinC1_init, Dio_PinC2_init, Dio_PinC3_init,
 Dio_PinC4_init, Dio_PinC5_init, Dio_PinC6_init, Dio_PinC7_init,
 Dio_PinD0_init, Dio_PinD1_init, Dio_PinD2_init, Dio_PinD3_init,
 Dio_PinD4_init, Dio_PinD5_init, Dio_PinD6_init, Dio_PinD7_init 
 };				
 
 void Dio_SetPinMode(Pin_Type Pin_ID , PinMode_type Mode){
	
	   Pin_Type Port_Index = Pin_ID/8;
	   Pin_Type Pin_Index  = Pin_ID%8;
	
	switch(Mode){
		
		case OutPut_High :
			   SET_BIT(*DIO_RegDDR[Port_Index] ,Pin_Index);
			   SET_BIT(*DIO_RegPORT[Port_Index],Pin_Index);
		
		break;
		
		case OutPut_Low  :
			   SET_BIT(*DIO_RegDDR[Port_Index] ,Pin_Index);
			   CLEAR_BIT(*DIO_RegPORT[Port_Index],Pin_Index);
		break;
		
		case InPut_Float :
		   CLEAR_BIT(*DIO_RegDDR[Port_Index] ,Pin_Index);
		  
		break;
		
		case InPut_PullUp :
			   CLEAR_BIT(*DIO_RegDDR[Port_Index] ,Pin_Index);
			   CLEAR_BIT(*DIO_RegPORT[Port_Index],Pin_Index);
		break;
	}
	 
	 
 }	 
 
 void DIO_Init(void)
{
	for(u8 PinCount=Pin_A0;PinCount<=Pin_D7;PinCount){
	
		  Dio_SetPinMode(PinCount,Dio_PinInitArray[PinCount]);
	
	}
	
	
	
	
}
/*****************************DIO_u8ReadPinVal***********************************/

 void DIO_ReadPinVal(Pin_Type Pin_ID ,u8 * ReadBufferPTR )
{
	 
	 Pin_Type Port_Index = Pin_ID / 8;
	 Pin_Type Pin_Index  = Pin_ID % 8;
	 
   *ReadBufferPTR = GET_BIT(*DIO_RegPIN[Port_Index],Pin_Index);
	
	
}

 void DIO_WritePinVal(Pin_Type Pin_ID ,u8 * ReadBufferPTR )
 {
	 
	 Pin_Type Port_Index = Pin_ID / 8;
	 Pin_Type Pin_Index  = Pin_ID % 8;
	 
	 *ReadBufferPTR = GET_BIT(*DIO_RegPIN[Port_Index],Pin_Index);
	 
	 
 }
