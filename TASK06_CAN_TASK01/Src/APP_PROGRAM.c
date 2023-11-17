/******************************************************************************
 *
 * Module: APP PROGRAM
 *
 * File Name: APP_PROGRAM.c
 *
 * Description: Source file for the functions that will be used on the main file
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       	*
 *******************************************************************************/

#include "../Inc/APP_INTERFACE.h"

/*******************************************************************************
 *                              			APP Function Implementations									 *
 *******************************************************************************/

void APP_voidSystemInitialization(void)
{
	// SYSTick Initialization
	SYSTICK_voidInitialization();

	// RCC Initialization
	RCC_voidInitialization();
	RCC_voidPeripheralClockEnable(RCC_APB2, APB2_IOPAEN);
	RCC_voidPeripheralClockEnable(RCC_APB2, APB2_IOPBEN);

	// PORTB Pins Initialization
	GPIO_voidSetPinDirection(PORT_B, PIN_1, PIN_OUTPUT_MODE);
	GPIO_voidSetPinDirection(PORT_B, PIN_2, PIN_OUTPUT_MODE);
	GPIO_voidSetPinDirection(PORT_B, PIN_3, PIN_OUTPUT_MODE);
	GPIO_voidSetPinDirection(PORT_B, PIN_4, PIN_OUTPUT_MODE);

	// PORTA Pins Initialization
	GPIO_voidSetPinDirection(PORT_A, PIN_3, PIN_OUTPUT_MODE);
	GPIO_voidSetPinDirection(PORT_A, PIN_4, PIN_OUTPUT_MODE);
	GPIO_voidSetPinDirection(PORT_A, PIN_5, PIN_OUTPUT_MODE);

	// LCD Initialization
	LCD_voidInitialization();
	LCD_voidPuts(0, 0, "Welcome to Cortex M3");
	LCD_voidPuts(1, 0, "Welcome to Cortex M4");

}


void APP_voidExecution(void)
{
	GPIO_voidSetPinValue(PORT_B, PIN_1, GPIO_ODR_HIGH);
	GPIO_voidSetPinValue(PORT_B, PIN_2, GPIO_ODR_HIGH);
	GPIO_voidSetPinValue(PORT_B, PIN_3, GPIO_ODR_HIGH);
	GPIO_voidSetPinValue(PORT_B, PIN_4, GPIO_ODR_HIGH);
	SYSTICK_voidSetDelay_ms(1000);
	GPIO_voidSetPinValue(PIN_1, PORT_B, GPIO_ODR_LOW);
	GPIO_voidSetPinValue(PIN_2, PORT_B, GPIO_ODR_LOW);
	GPIO_voidSetPinValue(PIN_3, PORT_B, GPIO_ODR_LOW);
	GPIO_voidSetPinValue(PIN_4, PORT_B, GPIO_ODR_LOW);
	SYSTICK_voidSetDelay_ms(1000);


//	LCD_voidSetCursor(1, 0);
//	LCD_voidDisplayString("Working!");
//	GPIO_voidSetPinValue(PIN_3, PORT_A, GPIO_ODR_HIGH);
//	delay(500);
//	GPIO_voidSetPinValue(PIN_3, PORT_A, GPIO_ODR_LOW);
//	delay(500);
}


void APP_voidISRFunction(void)
{
	static u8 counter = 0;
	counter++;
	if(counter == 1)
	{
		GPIO_voidSetPinValue(PORT_A, PIN_1, GPIO_ODR_HIGH);
		GPIO_voidSetPinValue(PORT_A, PIN_2, GPIO_ODR_HIGH);
		GPIO_voidSetPinValue(PORT_A, PIN_3, GPIO_ODR_HIGH);
	}
	else if(counter == 2)
	{
		GPIO_voidSetPinValue(PORT_A, PIN_1, GPIO_ODR_LOW);
		GPIO_voidSetPinValue(PORT_A, PIN_2, GPIO_ODR_LOW);
		GPIO_voidSetPinValue(PORT_A, PIN_3, GPIO_ODR_LOW);
		counter = 0;
	}
}


