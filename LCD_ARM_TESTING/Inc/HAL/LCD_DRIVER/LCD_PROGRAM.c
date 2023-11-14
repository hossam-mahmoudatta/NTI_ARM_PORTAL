 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD_PROGRAM.c
 *
 * Description: Source file for the AVR LCD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "LCD_INTERFACE.h"

/*******************************************************************************
 *                              						Functions Declarations                     	      				  *
 *******************************************************************************/

// Initializes and enables the LCD Module to start functionality
void LCD_voidInitialization(void) {
	// Initialize RS Pin
	GPIO_voidSetPinDirection(LCD_RS, LCD_INIT_PORT, PIN_OUTPUT_MODE);

	// Initialize Enable Pin
	GPIO_voidSetPinDirection(LCD_ENABLE, LCD_INIT_PORT, PIN_OUTPUT_MODE);

	// LCD Power On Internal Delay is 15 mS
	delay(30);

	// Setup the port and pins for the data pins inside the LCD
#if (LCD_BIT_MODE == LCD_8_BIT)
		for(u8 PINx = 3 ; PINx < 10 ; PINx++)
		{
			GPIO_voidSetPinDirection(PINx, LCD_DATA_PORT, PIN_OUTPUT_MODE);
		}
		LCD_voidSendCommand(LCD_TWO_LINE_EIGHT_BIT);
#else
		GPIO_voidSetPinDirection(LCD_DATAPIN_D4, LCD_DATA_PORT, PIN_OUTPUT_MODE);
		GPIO_voidSetPinDirection(LCD_DATAPIN_D5, LCD_DATA_PORT, PIN_OUTPUT_MODE);
		GPIO_voidSetPinDirection(LCD_DATAPIN_D6, LCD_DATA_PORT, PIN_OUTPUT_MODE);
		GPIO_voidSetPinDirection(LCD_DATAPIN_D7, LCD_DATA_PORT, PIN_OUTPUT_MODE);

		LCD_voidSendCommand(LCD_2LINES_FOUR_BIT_INIT1);
		LCD_voidSendCommand(LCD_2LINES_FOUR_BIT_INIT2);
		LCD_voidSendCommand(LCD_2LINES_5x7_DOTS);
		delay(5);
#endif

	LCD_voidSendCommand(LCD_CURSOR_OFF);
	delay(5);
	LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
	delay(5);
}


// Sends a command to the LCD
void LCD_voidSendCommand(u8 copy_u8Command) {
	// Set RS Pin to '0'
	GPIO_voidSetPinValue(LCD_RS, LCD_INIT_PORT, GPIO_ODR_LOW);
	delay(1);

	// Set Enable Pin to '1'
	GPIO_voidSetPinValue(LCD_ENABLE, LCD_INIT_PORT, GPIO_ODR_HIGH);
	delay(1);

#if (LCD_BIT_MODE == LCD_8_BIT)
	for(u8 BITx = 0 ; BITx < LCD_8_BIT ; BITx++)
	{
		// Write the command bit by bit on the LCD Data Port
		GPIO_voidSetPinValue((BITx + 3), LCD_DATA_PORT, GET_BIT(copy_u8Command, BITx));
	}
	delay(2);

	// Set Enable Pin to '0'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, GPIO_ODR_LOW);
	delay(2);
#else
	// Inserts the command in the assigned PORT to be sent to the LCD
	GPIO_voidSetPinValue(LCD_DATAPIN_D4, LCD_DATA_PORT, GET_BIT(copy_u8Command, 4));
	GPIO_voidSetPinValue(LCD_DATAPIN_D5, LCD_DATA_PORT, GET_BIT(copy_u8Command, 5));
	GPIO_voidSetPinValue(LCD_DATAPIN_D6, LCD_DATA_PORT, GET_BIT(copy_u8Command, 6));
	GPIO_voidSetPinValue(LCD_DATAPIN_D7, LCD_DATA_PORT, GET_BIT(copy_u8Command, 7));
	delay(1);

	// Set Enable Pin to '0'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, GPIO_ODR_LOW);
	delay(1);
	// Set Enable Pin to '1'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, GPIO_ODR_HIGH);
	delay(1);

	GPIO_voidSetPinValue(LCD_DATAPIN_D4, LCD_DATA_PORT, GET_BIT(copy_u8Command, 0));
	GPIO_voidSetPinValue(LCD_DATAPIN_D5, LCD_DATA_PORT, GET_BIT(copy_u8Command, 1));
	GPIO_voidSetPinValue(LCD_DATAPIN_D6, LCD_DATA_PORT, GET_BIT(copy_u8Command, 2));
	GPIO_voidSetPinValue(LCD_DATAPIN_D7, LCD_DATA_PORT, GET_BIT(copy_u8Command, 3));
	delay(1);

	// Set Enable Pin to '0'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, GPIO_ODR_LOW);
	delay(1);

#endif

}


// Displays a character on the LCD
void LCD_voidSendData(u8 copy_u8Data) {
	// Set RS Pin to '1'
	GPIO_voidSetPinValue(LCD_RS, LCD_INIT_PORT, GPIO_ODR_HIGH);
	delay(1);

	// Set Enable Pin to '1'
	GPIO_voidSetPinValue(LCD_ENABLE, LCD_INIT_PORT, GPIO_ODR_HIGH);
	delay(1);

#if (LCD_BIT_MODE == LCD_8_BIT)
	for(u8 BITx = 0 ; BITx < LCD_8_BIT ; BITx++)
	{
		// Write the command bit by bit on the LCD Data Port
		GPIO_voidSetPinValue((BITx + 3), LCD_DATA_PORT, GET_BIT(copy_u8Data, BITx));
	}
	delay(2);

	// Set Enable Pin to '0'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, GPIO_ODR_LOW);
	delay(2);
#else
	// Inserts the command in the assigned PORT to be sent to the LCD
	GPIO_voidSetPinValue(LCD_DATAPIN_D4, LCD_DATA_PORT, GET_BIT(copy_u8Data, 4));
	GPIO_voidSetPinValue(LCD_DATAPIN_D5, LCD_DATA_PORT, GET_BIT(copy_u8Data, 5));
	GPIO_voidSetPinValue(LCD_DATAPIN_D6, LCD_DATA_PORT, GET_BIT(copy_u8Data, 6));
	GPIO_voidSetPinValue(LCD_DATAPIN_D7, LCD_DATA_PORT, GET_BIT(copy_u8Data, 7));
	delay(1);

	// Set Enable Pin to '0'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, GPIO_ODR_LOW);
	delay(1);
	// Set Enable Pin to '1'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, GPIO_ODR_HIGH);
	delay(1);

	// Write the command bit by bit on the LCD Data Port FROM the 0th Bit -> 3th Bit
	GPIO_voidSetPinValue(LCD_DATAPIN_D4, LCD_DATA_PORT, GET_BIT(copy_u8Data, 0));
	GPIO_voidSetPinValue(LCD_DATAPIN_D5, LCD_DATA_PORT, GET_BIT(copy_u8Data, 1));
	GPIO_voidSetPinValue(LCD_DATAPIN_D6, LCD_DATA_PORT, GET_BIT(copy_u8Data, 2));
	GPIO_voidSetPinValue(LCD_DATAPIN_D7, LCD_DATA_PORT, GET_BIT(copy_u8Data, 3));
	delay(1);

	// Set Enable Pin to '0'
	GPIO_voidSetPinValue(LCD_INIT_PORT, LCD_ENABLE, GPIO_ODR_LOW);
	delay(1);

#endif
}


// Displays a string on the LCD
void LCD_voidDisplayString(cu8 *copy_cu8Str) {
	u8 i = 0;
	while(copy_cu8Str[i] != '\0') {
		LCD_voidSendData(copy_cu8Str[i]);
		i++;
	}
}


// Chooses where the cursor would stand on the LCD to type from it
void LCD_voidSetCursor(u8 copy_u8row, u8 copy_u8_col) {
	// Calculate the required address in the LCD DDRAM checking
	// The location of the cursor originally on which line
	u8 LCD_MEMORY_ADDRESS;
	switch(copy_u8row) {
		case LINE0:
			LCD_MEMORY_ADDRESS = copy_u8_col;
			break;
		case LINE1:
			LCD_MEMORY_ADDRESS = copy_u8_col + 0x40;
			break;
		case LINE2:
			LCD_MEMORY_ADDRESS = copy_u8_col + 0x10;
			break;
		case LINE3:
			LCD_MEMORY_ADDRESS = copy_u8_col + 0x50;
			break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_voidSendCommand(LCD_MEMORY_ADDRESS | LINE0_ADDRESS);
}


// LCD only understands ASCII, so this converts Int to a string
void LCD_voidIntgerToString(u32 copy_u32Data) {
	// A string to hold the ASCII values
	cu8 buffer[16];

	// Converts data to its ASCII
	itoa(copy_u32Data, buffer, 10);

	// Display string with the results in the buffer
	LCD_voidDisplayString(buffer);
}

// Clears the LCD from any garbage
void LCD_voidClearScreen(void) {
	// Clears the LCD Display
	LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
}









//// Displays a string on the LCD at a chosen cursor and row
//void LCD_voidDisplayStringRowColumn(u8 copy_u8row,
//		u8 copy_u8_col,
//		cu8 *copy_cu8Str) {
//	// Go to to the required LCD position
//	LCD_voidMoveCursor(copy_u8row, copy_u8_col);
//
//	// Display the string from the cursor
//	LCD_voidDisplayString(*copy_cu8Str, copy_u8row, copy_u8_col);
//}
