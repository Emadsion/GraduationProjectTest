/*
 * LCD_Interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: moham
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

//For User Selection: Shifting Right or Left
#define LCD_Shift_Right	0
#define LCD_Shift_Left	1

void LCD_VidInit(void);
void LCD_VidSendChar(u8 Cpy_Data);
void LCD_VidSendCommand(u8 Cpy_u8Command);
void LCD_VidClear(void);
void LCD_VidSendString(u8 * PString);
void LCD_VidSendNumber(u32 Cpy_u32Num);
void LCD_VidGoTo(u8 Cpy_u8Row, u8 Cpy_u8Col);
void LCD_VidShiftDisplay(u8 Cpy_u8ShiftDir,u8 Cpy_u8ShiftNum);
void LCD_VidSetCGRAMAdres(void);

#endif /* LCD_INTERFACE_H_ */
