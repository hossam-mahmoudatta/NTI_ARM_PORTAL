 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD_CONFIG.h
 *
 * Description: Header file for the AVR LCD Driver Macro Definitions
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "STD_FUNCTIONS.h"


/*******************************************************************************
 *                                							Macro Definitions                                  		   		   *
 *******************************************************************************/

#define LCD_4_BIT								4
#define LCD_8_BIT								8
#define LCD_BIT_MODE						LCD_4_BIT

#if((LCD_BIT_MODE != LCD_4_BIT) && (LCD_BIT_MODE != LCD_8_BIT))
	#error "Number of Data bits should be equal to 4 or 8"
#endif

#define RS_PORT		PORT_A
#define RS_PIN			PIN_12

#define EN_PORT		PORT_A
#define EN_PIN			PIN_15

#define D7_PORT		PORT_B
#define D7_PIN		PIN_12

#define D6_PORT		PORT_B
#define D6_PIN		PIN_13

#define D5_PORT		PORT_B
#define D5_PIN		PIN_14

#define D4_PORT		PORT_B
#define D4_PIN		PIN_15


#define LCD_CLEAR_DISPLAY					0x01
#define LCD_2LINES_FOUR_BIT				0x02
#define LCD_2LINES_FOUR_BIT_INIT1   	0x33
#define LCD_2LINES_FOUR_BIT_INIT2		0x32
#define LCD_2LINES_5x7_DOTS				0x28
#define LCD_TWO_LINE_EIGHT_BIT			0x38
#define LCD_ENTRY_MODE						0x06
#define LCD_CURSOR_BLINKING          	0x0F
#define LCD_CURSOR_OFF          			0x0C
#define LCD_CURSOR_ON          				0x0E

#define LINE0_ADDRESS							0x80
#define LINE1_ADDRESS							0xC0
#define LINE2_ADDRESS							0x94
#define LINE3_ADDRESS							0xD4

#define LINE0											0
#define LINE1											1
#define LINE2											2
#define LINE3											3

/*------------ Declaring Private Macro -----------------*/

#define PIN_LOW(PORT, PIN)	GPIO_voidSetPinValue(PIN, PORT, LOGIC_LOW)
#define PIN_HIGH(PORT, PIN)	GPIO_voidSetPinValue(PIN, PORT, LOGIC_HIGH)

#define LCD_MAXROW_SIZE        			2
#define LCD_MAXCOL_SIZE        			16

#endif /* LCD_CONFIG_H_ */
