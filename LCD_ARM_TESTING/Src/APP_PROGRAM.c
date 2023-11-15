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
	RCC_voidInitialization();
	RCC_voidPeripheralClockEnable(RCC_APB2, APB2_IOPAEN);
	GPIO_voidSetPinDirection(PIN_0, PORT_A, PIN_OUTPUT_MODE);
	GPIO_voidSetPinDirection(PIN_2, PORT_A, PIN_OUTPUT_MODE);
	GPIO_voidSetPinDirection(PIN_5, PORT_A, PIN_OUTPUT_MODE);
	SYSTICK_voidInitialization();
//	LCD_voidInitialization();
	RCC_voidPeripheralClockEnable(RCC_APB2, APB2_IOPBEN);
//	LCD_voidSetCursor(0, 0);
//	LCD_voidDisplayString("Welcome to Cortex M3");
}


void APP_voidExecution(void)
{
	GPIO_voidSetPinValue(PIN_2, PORT_A, GPIO_ODR_HIGH);
	SYSTICK_voidSetDelay_ms_ISR(1000, APP_voidISRFunction);

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
		GPIO_voidSetPinValue(PIN_0, PORT_A, GPIO_ODR_HIGH);
		GPIO_voidSetPinValue(PIN_2, PORT_A, GPIO_ODR_HIGH);
		GPIO_voidSetPinValue(PIN_5, PORT_A, GPIO_ODR_HIGH);
	}
	else if(counter == 2)
	{
		GPIO_voidSetPinValue(PIN_0, PORT_A, GPIO_ODR_LOW);
		GPIO_voidSetPinValue(PIN_2, PORT_A, GPIO_ODR_LOW);
		GPIO_voidSetPinValue(PIN_5, PORT_A, GPIO_ODR_LOW);
		counter = 0;
	}
}


