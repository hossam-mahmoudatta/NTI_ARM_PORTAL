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
	// Initialize the RCC Module
		RCC_voidInitialization();

		// Enables the RCC for TIMER2, TIMER3, GPIO_A, GPIO_B
		RCC_voidPeripheralClockEnable(RCC_APB1, APB1_TIM2EN);
		RCC_voidPeripheralClockEnable(RCC_APB1, APB1_TIM3EN);
		RCC_voidPeripheralClockEnable(RCC_APB2, APB2_IOPAEN);
		RCC_voidPeripheralClockEnable(RCC_APB2, APB2_IOPBEN);

		/* TESTING LED */
		GPIO_voidSetPinDirection(PORT_A, PIN_4, OUTPUT_SPEED_10MHZ_PUSHPULL);
}


void APP_voidExecution(void)
{
	GPIO_voidSetPinValue(PORT_A, PIN_4, LOGIC_HIGH);
	_delay_ms(100);
	GPIO_voidSetPinValue(PORT_A, PIN_4, LOGIC_LOW);
	_delay_ms(100);
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


