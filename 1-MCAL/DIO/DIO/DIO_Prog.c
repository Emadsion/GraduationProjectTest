/*
 * DIO_Prog.c
 *
  * Created: 5/27/2022 4:44:18 PM
  *  Author: En Eslam Eid
  */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"


u8 * const DIO_RegDDR[4]= {&DDRA_Reg,&DDRB_Reg,&DDRC_Reg,&DDRD_Reg};
u8 * const DIO_RegPORT[4]={&PORTA_Reg,&PORTB_Reg,&PORTC_Reg,&PORTD_Reg};
u8 * const DIO_RegPIN[4]= {&PINA_Reg,&PINB_Reg,&PINC_Reg,&PIND_Reg};

/*Pointer to Three Registers (DDR,PORT,PIN) arrays */
u8 ** DIO_RegPtr[3] = {DIO_RegDDR,DIO_RegPORT,DIO_RegPIN};

	
/*****************************DIO_VoidInit**************************************/
/********************************************************************************
 * Function to Initiate All the Pins of DIO to InputFloat as the default state
 * Inputs : void
 * Return : void
 **********************************************************************************/
void DIO_Init(void)
{
	 for(u8 PinCount = Pin_A0 ; PinCount <= Pin_D7; PinCount++)
	 {
	 	DIO_SetPinMode(PinCount,Dio_Pin_init);
	 }
}

/***********************************DIO_SetPinMode********************************************/
/**********************************************************************************************
 * Function to Set Pin Mode to the state entered by user
 * Inputs : Pin_Num, PinMode[Output High, Output Low, Input Float, Input Pullup, Toggle]
 * Return : void
 **********************************************************************************************/
void DIO_SetPinMode(Pin_Type Cpy_Pin_ID , PinMode_type Cpy_Mode)
 {

	 Pin_Type Port_Index = Cpy_Pin_ID / 8;
	 Pin_Type Pin_Index  = Cpy_Pin_ID % 8;

	switch(Cpy_Mode)
	{
		case OutPut_High:
			//Setting DDR -> Output || Clearing PORT -> High
			SET_BIT(*(DIO_RegPtr[DDR][Port_Index]),Pin_Index);
			SET_BIT(*(DIO_RegPtr[PORT][Port_Index]),Pin_Index);
			break;
		case OutPut_Low:
				//Setting DDR -> Output || Clearing PORT -> Low
				SET_BIT(*(DIO_RegPtr[DDR][Port_Index]),Pin_Index);
				CLEAR_BIT(*(DIO_RegPtr[PORT][Port_Index]),Pin_Index);
				break;
		case InPut_Float:
				//Clearing DDR -> Input || Clearing PORT -> Float
				CLEAR_BIT(*(DIO_RegPtr[DDR][Port_Index]),Pin_Index);
				CLEAR_BIT(*(DIO_RegPtr[PORT][Port_Index]),Pin_Index);
				break;
		case InPut_PullUp:
				//Clearing DDR -> Input || Setting PORT -> PullUp
				CLEAR_BIT(*(DIO_RegPtr[DDR][Port_Index]),Pin_Index);
				SET_BIT(*(DIO_RegPtr[PORT][Port_Index]),Pin_Index);
				break;

		case Toggle:
				//Toggle bit from High to Low or vice versa
				TOG_BIT(*(DIO_RegPtr[PORT][Port_Index]),Pin_Index);
				break;
		default:

			//Error
				break;
	}
 }



/**************************************************DIO_SetDirectionMode************************************************************/
/**********************************************************************************************************************************
 * Function to Set DDR Pins according to value entered by user
 * Ex: DIO_SetPortMode(DDR_A,0xFF) -> Set all DDRA (PinA0 ~ PinA7) to Output
 * Inputs : DDRNum(DDR_A, DDR_B, DDR_C, DDR_D), Value Entered by user to activate certain number of Pins inside the Port
 * Return : void
 *********************************************************************************************************************************/
void DIO_SetDirectionMode(DDR_Type Cpy_DDR , u8 Cpy_Value)
{
	*(DIO_RegPtr[DDR][Cpy_DDR]) = Cpy_Value;
}



/****************************************************DIO_SetPortMode**************************************************************/
/**********************************************************************************************************************************
 * Function to Set Port Pins according to value entered by user
 * Ex: DIO_SetPortMode(PORT_A,0xFF) -> Set all PortA (PinA0 ~ PinA7) to High
 * Inputs : PortNum(Port_A, Port_B, Port_C, Port_D), Value Entered by user to activate certain number of Pins inside the Port
 * Return : void
 *********************************************************************************************************************************/
void DIO_SetPortMode(PORT_Type Cpy_PORT , u8 Cpy_Value)
{
	*(DIO_RegPtr[PORT][Cpy_PORT]) = Cpy_Value;
}



/*****************************DIO_u8ReadPinVal***********************************/
/*********************************************************************************
 * Function to Read Content from a specified PIN Register
 * Inputs : Pin_Num
 * Return : Content of the specified Pin Register
 *********************************************************************************/
u8 DIO_u8ReadPinVal(Pin_Type Pin_ID)
{
	 
	 Pin_Type Port_Index = Pin_ID / 8;
	 Pin_Type Pin_Index  = Pin_ID % 8;
	 return GET_BIT(*(DIO_RegPtr[PIN][Port_Index]),Pin_Index);
}


