 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD_INTERFACE.h
 *
 * Description: Header file for the ARM LCD Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef		LCD_INTERFACE_H_
#define		LCD_INTERFACE_H_

#include 		"LCD_CONFIG.h"

/*******************************************************************************
 *                                						Function Prototypes												 *
 *******************************************************************************/

void LCD_voidInitialization(void);

void LCD_voidSendData(u8 copy_u8Data);

void LCD_voidSendCommand(u8 copy_u8Command);

void LCD_voidSetCursor(u8 copy_u8Col, u8 copy_u8Row);

void LCD_voidSendString(cu8 *copy_cu8String);

void LCD_voidWriteNumber(u32 copy_u32Number);

void LCD_voidClear(void);

#endif /* LCD_INTERFACE_H_ */

