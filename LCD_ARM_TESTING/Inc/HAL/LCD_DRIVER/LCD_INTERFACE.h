 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD_INTERFACE.h
 *
 * Description: Header file for the AVR LCD Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_CONFIG.h"
#include <stdlib.h>

/*******************************************************************************
 *                              						Functions Prototypes                  								  *
 *******************************************************************************/

// Initializes and enables the LCD Module to start functionality
void LCD_voidInitialization(void);


 // Sends a command to the LCD
void LCD_voidSendCommand(u8 copy_u8Command);


 // Displays a character on the LCD
void LCD_voidSendData(u8 copy_u8Data);


// Chooses where the cursor would stand on the LCD to type from it
void LCD_voidSetCursor(u8 copy_u8Row, u8 copy_u8Col);


// Displays a string on the LCD
void LCD_voidDisplayString(cu8 *copy_cu8Str);


// LCD only understands ASCII, so this converts Int to a string
void LCD_voidIntgerToString(u32 copy_u32Data);


// Clears the LCD from any garbage
void LCD_voidClearScreen(void);


#endif /* LCD_INTERFACE_H_ */
