/*
 * EXIT_Interface.h
 *
 *  Created on: Sep 11, 2023
 *      Author: moham
 */

#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

typedef enum
{EXIT0, EXIT1, EXIT2}
EXIT_Pin;

typedef enum
{Rising_Edge, Falling_Edge, Low_Level, OCH}
EXIT_Mode;

//Initialization function
void EXIT_VidInit(EXIT_Pin CPY_EXIT_Pin, EXIT_Mode CPY_EXIT_Mode);
void EXIT_VidDisable(EXIT_Pin CPY_EXIT_Pin);

//Call Back Functions
void EXIT0_VoidSetCallBack(void (*Ptr0)(void));
void EXIT1_VoidSetCallBack(void (*Ptr1)(void));
void EXIT2_VoidSetCallBack(void (*Ptr2)(void));


#endif /* EXIT_INTERFACE_H_ */
