/*
 * LCD_interface.h
 *
 *  Created on: 10/09/2023
 *      Author: Kareem Hussein
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Macros For LCD Shifting Direction */
#define LCD_SHIFT_LEFT          0
#define LCD_SHIFT_RIGHT         1

/* Macros For LCD Line Id */
#define LCD_LINE_ONE            1
#define LCD_LINE_TWO            2
#define LCD_LINE_THREE          3
#define LCD_LINE_FOUR           4


                                /* APIS PROTOTYPES */
									   
void LCD_voidInit(void);
void LCD_voidSendCmnd(u8 copy_u8Cmnd);
void LCD_voidSendChar(u8 copy_u8Data);
void LCD_voidWriteString(u8* copy_pu8String);
void LCD_voidWriteNumber(u32 copy_u32Number);
void LCD_voidClear(void);
void LCD_voidShift(u8 copy_u8ShifttingDirection);
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position);
// 	Create Special Pattern

#endif /* LCD_INTERFACE_H_ */
