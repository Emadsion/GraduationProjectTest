/*
 * GIE_Program.c
 *
 *  Created on: Sep 11, 2023
 *      Author: moham
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"


void GIE_VidEnable(void)
{
	SET_BIT(SREG,Global_Interrupt_Bit);
}

void GIE_VidDisable(void)
{
	CLEAR_BIT(SREG,Global_Interrupt_Bit);
}
