/******************************************************************************
 *
 * Module: LCD PROGRAM
 *
 * File Name: LCD_PROGRAM.c
 *
 * Description: Source file for the LCD Driver Function Implementations
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       	*
 *******************************************************************************/

#include "LCD_INTERFACE.h"

/*******************************************************************************
 *                              			APP Function Implementations									 *
 *******************************************************************************/

/*--------------- Initialize LCD ------------------*/
void LCD_voidInitialization(void)
{
	GPIO_voidSetPinDirection(LCD_CTRL_PORT, RS_PIN, OUTPUT_SPEED_10MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LCD_CTRL_PORT, EN_PIN, OUTPUT_SPEED_10MHZ_PUSHPULL);

	GPIO_voidSetPinDirection(LCD_DATA_PORT, D7_PIN, OUTPUT_SPEED_10MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LCD_DATA_PORT, D6_PIN, OUTPUT_SPEED_10MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LCD_DATA_PORT, D5_PIN, OUTPUT_SPEED_10MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LCD_DATA_PORT, D4_PIN, OUTPUT_SPEED_10MHZ_PUSHPULL);

	_delay_ms(30);

	LCD_voidSendCommand(LCD_2LINES_FOUR_BIT);
	_delay_ms(2);

	LCD_voidSendCommand(LCD_2LINES_5x7_DOTS);
	_delay_ms(2);

	LCD_voidSendCommand(LCD_CURSOR_OFF);
	_delay_ms(2);

	LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
	_delay_ms(2);
	
	LCD_voidSendCommand(LCD_ENTRY_MODE);
	_delay_ms(2);
	
	LCD_voidSendCommand(LINE0_ADDRESS);
	_delay_ms(2);
}


/*--------------- Write To LCD ---------------*/
void LCD_voidSendCommand(u8 copy_u8Command)
{
	GPIO_voidSetPinValue(LCD_CTRL_PORT, RS_PIN, LOGIC_LOW);

	// Sends the COmmand
	GPIO_voidSetPinValue(LCD_DATA_PORT, D4_PIN, GET_BIT(copy_u8Command, 4));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D5_PIN, GET_BIT(copy_u8Command, 5));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D6_PIN, GET_BIT(copy_u8Command, 6));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D7_PIN, GET_BIT(copy_u8Command, 7));

	GPIO_voidSetPinValue(LCD_CTRL_PORT, EN_PIN, LOGIC_HIGH);
	_delay_ms(2);
	GPIO_voidSetPinValue(LCD_CTRL_PORT, EN_PIN, LOGIC_LOW);

	// Sends the COmmand
	GPIO_voidSetPinValue(LCD_DATA_PORT, D4_PIN, GET_BIT(copy_u8Command, 0));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D5_PIN, GET_BIT(copy_u8Command, 1));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D6_PIN, GET_BIT(copy_u8Command, 2));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D7_PIN, GET_BIT(copy_u8Command, 3));

	GPIO_voidSetPinValue(LCD_CTRL_PORT, EN_PIN, LOGIC_HIGH);
	_delay_ms(2);
	GPIO_voidSetPinValue(LCD_CTRL_PORT, EN_PIN, LOGIC_LOW);
}



void LCD_voidSendData(u8 copy_u8Data)
{
	GPIO_voidSetPinValue(LCD_CTRL_PORT, RS_PIN, LOGIC_HIGH);

	// Sends the Data
	GPIO_voidSetPinValue(LCD_DATA_PORT, D4_PIN, GET_BIT(copy_u8Data, 4));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D5_PIN, GET_BIT(copy_u8Data, 5));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D6_PIN, GET_BIT(copy_u8Data, 6));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D7_PIN, GET_BIT(copy_u8Data, 7));

	GPIO_voidSetPinValue(LCD_CTRL_PORT, EN_PIN, LOGIC_HIGH);
	_delay_ms(2);
	GPIO_voidSetPinValue(LCD_CTRL_PORT, EN_PIN, LOGIC_LOW);

	// Sends the COmmand
	GPIO_voidSetPinValue(LCD_DATA_PORT, D4_PIN, GET_BIT(copy_u8Data, 0));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D5_PIN, GET_BIT(copy_u8Data, 1));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D6_PIN, GET_BIT(copy_u8Data, 2));
	GPIO_voidSetPinValue(LCD_DATA_PORT, D7_PIN, GET_BIT(copy_u8Data, 3));

	GPIO_voidSetPinValue(LCD_CTRL_PORT, EN_PIN, LOGIC_HIGH);
	_delay_ms(2);
	GPIO_voidSetPinValue(LCD_CTRL_PORT, EN_PIN, LOGIC_LOW);
}



void LCD_voidSetCursor(u8 copy_u8Col, u8 copy_u8Row)
{
	u8 LOC_u8DDRAMAddress;
	if(copy_u8Row == 0)
	{
		/*Check if in first line*/
		LOC_u8DDRAMAddress = copy_u8Col;
	}
	else if(copy_u8Row == 1)
	{
		/*Check if in second line*/
		LOC_u8DDRAMAddress = 0x40 + copy_u8Col;
	}
	//Local_u8DDRAMAddress=0x40*Copy_u8YPos+Copy_u8XPos
	/*Setbit number 7 for SetDDRAM Address command then send the command*/

	LCD_voidSendCommand(LOC_u8DDRAMAddress + 128);
}


void LCD_voidSendString(cu8 *copy_cu8String)
{
	u8 LOC_u8Counter = 0;

	while(copy_cu8String[LOC_u8Counter] != '\0')
	{
		LCD_voidSendData(copy_cu8String[LOC_u8Counter]);
		LOC_u8Counter++;
	}
}



void LCD_voidWriteNumber(u32 copy_u32Number)
{
	u8 arr[20];
	u8 i = 0 , j;
	if (copy_u32Number == 0)
	{
		LCD_voidSendData('0');
	}
	if (copy_u32Number < 0)
	{
		copy_u32Number = copy_u32Number * -1;
		LCD_voidSendData('-');
	}

	while(copy_u32Number)
	{
		arr[i++] = copy_u32Number % 10 + '0';
		copy_u32Number /= 10;
	}
	for (j = i ; j > 0 ; --j)
	{
		LCD_voidSendData(arr[j - 1]);
	}
}



void LCD_voidClear(void)
{
	LCD_voidWrite(0, 0x01);
}



