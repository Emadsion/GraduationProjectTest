/*
 * ADC_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: moham
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"


//u8 AdcScanGroup1[4]={ ,SG1Channel1,SG1channel2,SG1channel3 };
//u8 AdcScanGroup0[4]={ SG0Channel0,SG0Channel1,SG0channel2,SG0channel3 };
//typedef enum { ScanGroup0,ScanGroup1 }ScanGroup_t 	 ;

//u8 * ptr[2]={AdcScanGroup0 , AdcScanGroup1}	;


void ADC_VidInit(void)
{

	ADMUX = (ADC_VRef << REFS0) | (ADC_AdjustResult << ADLAR) | (ADC_CHANNEL_INIT << MUX0);

#if (ADC_AUTOTRIG_MODE == DISABLED)
 ADCSRA =  (ENABLE <<ADEN) |  (DISABLE<<ADATE) | (ADC_INTERRUPT<<ADIE) | ADC_Prescaler ;
#else

ADCSRA    =  (ENABLE <<ADEN) | (ADC_INTERRUPT<<ADIE) | (ENABLE<<ADATE) | ADC_Prescaler;
SFIOR = (ADC_AUTOTRIG_SOURCE << ADTS0)| (SFIOR & 0x0F);
#endif
}

u16 ADC_u16ReadSingleChannel( u8 ADC_CHANNEL )
{


	//ADMUX =  (ADMUX & 0xE0) | ADC_CHANNEL;
	ADMUX =  (ADC_VRef<<REFS0) | (ADC_AdjustResult<<ADLAR) |ADC_CHANNEL;
	SET_BIT(ADCSRA,ADSC); //  Start Conversion

	while(GET_BIT(ADCSRA,ADIF) == 0);

	SET_BIT(ADCSRA,ADIF);// CLear flag by setting it to 1

	return ADCL ;
}





/*
void ADC_ReadScanGroup(ScanGroup_t ScanGroupID, u16 * bufferPtr ){
	  u8 ChannelIndex;
	  for (ChannelIndex=0;ChannelIndex<4;ChannelIndex++)
	  {
		  bufferPtr[ChannelIndex] = ADC_ReadSingleChannel(  ptr[ScanGroupID][ChannelIndex]	)  ;

	  }

}
*/

