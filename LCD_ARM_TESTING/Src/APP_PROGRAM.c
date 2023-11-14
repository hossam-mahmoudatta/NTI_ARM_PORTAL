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
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              					APP Function Implementations									   	*
 *******************************************************************************/

void APP_voidSystemInitialization(void)
{
	RCC_voidInitialization();
	RCC_voidPeripheralClockEnable(2,2);
	GPIO_voidSetPinDirection(PIN_0, PORT_A, PIN_OUTPUT_MODE);
	SYSTICK_voidInitialization();
}


void APP_voidExecution(void)
{
	SYSTICK_voidSetDelay_ms_ISR(750, APP_voidISRFunction);
}


void APP_voidISRFunction(void)
{
	static u8 counter = 0;
	counter++;
	if(counter == 1)
	{
		GPIO_voidSetPinValue(PIN_0, PORT_A, GPIO_ODR_HIGH);
	}
	else if(counter == 2)
	{
		GPIO_voidSetPinValue(PIN_0, PORT_A, GPIO_ODR_LOW);
		counter = 0;
	}
}


