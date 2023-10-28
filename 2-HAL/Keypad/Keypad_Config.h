/*
 * Keypad_Config.h
 *
 *  Created on: Sep 9, 2023
 *      Author: moham
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


const unsigned char number[4][4] =
{
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
};


/***************** Columns and Rows PINS are changed upon suitable configuration ************************/
#define COL1 Pin_A0
#define COL2 Pin_A1
#define COL3 Pin_A2
#define COL4 Pin_A3

#define ROW1 Pin_A4
#define ROW2 Pin_A5
#define ROW3 Pin_A6
#define ROW4 Pin_A7


#endif /* KEYPAD_CONFIG_H_ */
