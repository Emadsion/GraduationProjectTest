/*
 * SevSeg_Config.h
 *
 *  Created on: Sep 15, 2023
 *      Author: moham
 */

#ifndef SEVSEG_CONFIG_H_
#define SEVSEG_CONFIG_H_

//7-Segment BCD Decoder pins(Not used in NTI KIT implementation as this NTI KIT depends on writing directly to the 7-Segment PORT)
// It's Recommended to Write to each single pin individually to ensure driver Portability
#define SevSeg_PinA	 Pin_B0
#define SevSeg_PinB	 Pin_B1
#define SevSeg_PinC	 Pin_B2
#define SevSeg_PinD	 Pin_B4

//7-Segment COM(Enable) Pins
#define SevSeg_COMPIN1	Pin_A3
#define SevSeg_COMPIN2	Pin_A2
#define SevSeg_COMPIN3	Pin_B5
#define SevSeg_COMPIN4	Pin_B6

//Setting 7-Segment configuration to portable makes it suitable for all 7-segment driver implementation regardless of pin configuration
#define NTI_KIT		0
//Setting 7-Segment configuration to NTI_KIT make it suitable for only NTI_KIT driver implementation with instructor notes taken into consideration
#define PORTABLE 	1
#define SevSeg_Implementation  NTI_KIT



#endif /* SEVSEG_CONFIG_H_ */
