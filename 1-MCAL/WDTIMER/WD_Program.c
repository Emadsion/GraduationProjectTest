/*
 * WD_Program.c
 *
 *  Created on: Sep 29, 2023
 *      Author: moham
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WD_Private.h"
#include "WD_Config.h"
#include "WD_Interface.h"


void WD_VidOn(void)
{
	/*Enabling Watch dog timer with configurable prescaler*/
	WDTCR =   (ENABLE << WDE) | (WD_PRESCALER << WDP0);
}


void WD_VidOff(void)
{
	/*to disable an enabled WDT we must follow certain procedure
	1- Write logic one to both WDTOE and WDE at the same time
	2- Write 4 clock cycle disable WDE (4 clock cycle is a MUST)
	*/
	WDTCR = (ENABLE << WDTOE) | (ENABLE << WDE);
	//Do not use the CLR_BIT operation as it may take more than 4 clock cycle
	WDTCR = 0x00;
}
