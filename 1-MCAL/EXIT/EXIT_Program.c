/*
 * EXIT_Program.c
 *
 *  Created on: Sep 11, 2023
 *      Author: moham
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXIT_Private.h"
#include"EXIT_Config.h"
#include"EXIT_Interface.h"


/************************************** EXIT_VidInit **************************************/
void EXIT_VidInit(EXIT_Pin CPY_EXIT_Pin, EXIT_Mode CPY_EXIT_Mode)
{
	if(CPY_EXIT_Pin == EXIT0)
	{
		switch (CPY_EXIT_Mode)
		{
		case Rising_Edge:
			SET_BIT(MCUCR,ISC00_BIT);
			SET_BIT(MCUCR,ISC01_BIT);
			break;
		case Falling_Edge:
			CLEAR_BIT(MCUCR,ISC00_BIT);
			SET_BIT(MCUCR,ISC01_BIT);
			break;
		case Low_Level:
			CLEAR_BIT(MCUCR,ISC00_BIT);
			CLEAR_BIT(MCUCR,ISC01_BIT);
			break;
		case OCH:
			SET_BIT(MCUCR,ISC00_BIT);
			CLEAR_BIT(MCUCR,ISC01_BIT);
			break;
		default:
			//error
			break;
		}
		//Enabling EXIT
		SET_BIT(GICR, INT0_BIT);
	}


	else if(CPY_EXIT_Pin == EXIT1)
	{
		switch (CPY_EXIT_Mode)
		{
		case Rising_Edge:
			SET_BIT(MCUCR,ISC10_BIT);
			SET_BIT(MCUCR,ISC11_BIT);
			break;
		case Falling_Edge:
			CLEAR_BIT(MCUCR,ISC10_BIT);
			SET_BIT(MCUCR,ISC11_BIT);
			break;
		case Low_Level:
			CLEAR_BIT(MCUCR,ISC10_BIT);
			CLEAR_BIT(MCUCR,ISC11_BIT);
			break;
		case OCH:
			SET_BIT(MCUCR,ISC10_BIT);
			CLEAR_BIT(MCUCR,ISC11_BIT);
			break;
		default:
			//error
			break;
		}
		SET_BIT(GICR, INT1_BIT);
	}


	else if(CPY_EXIT_Pin == EXIT2)
	{
		switch (CPY_EXIT_Mode)
		{
		case Rising_Edge:
			SET_BIT(MCUCSR,ISC2_BIT);
			break;
		case Falling_Edge:
			CLEAR_BIT(MCUCSR,ISC2_BIT);
			break;
		default:
			//error
			break;
		}

		SET_BIT(GICR, INT2_BIT);
	}
}

void EXIT_VidDisable(EXIT_Pin CPY_EXIT_Pin)
{
	switch (CPY_EXIT_Pin)
	{
	case EXIT0: CLEAR_BIT(GICR, INT0_BIT);
				break;
	case EXIT1:CLEAR_BIT(GICR, INT1_BIT);
				break;
	case EXIT2:CLEAR_BIT(GICR, INT2_BIT);
				break;
	default : // error
				break;
	}
}

/********************************* Setting call back function for the interrupts **************************************/

void EXIT0_VoidSetCallBack(void (*Ptr0)(void))
{
	EXIT0_PVidCallBack = Ptr0;
}

void EXIT1_VoidSetCallBack(void (*Ptr1)(void))
{
	EXIT1_PVidCallBack = Ptr1;
}
void EXIT2_VoidSetCallBack(void (*Ptr2)(void))
{
	EXIT2_PVidCallBack = Ptr2;
}


/************************************* Interrupt Service Routine *******************************************/
//INT0 VECTOR
void __vector_1(void)
{
	if(EXIT0_PVidCallBack != NULL)
		EXIT0_PVidCallBack();
}
//INT1 VECTOR
void __vector_2(void)
{
	if(EXIT1_PVidCallBack != NULL)
		EXIT1_PVidCallBack();

}
//INT2 VECTOR
void __vector_3(void)
{
	if(EXIT2_PVidCallBack != NULL)
		EXIT2_PVidCallBack();
}

