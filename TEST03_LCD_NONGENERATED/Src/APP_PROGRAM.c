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

		// Enables the NVIC Module for TIMER2 & TIMER3
		NVIC_voidEnablePeripheral(TIM2_C);
		NVIC_voidEnablePeripheral(TIM3_C);

		// Initializing the Ultrasonic Sensors
		HCSR04_voidInitialization();

		// Initializing the Motor Drivers
		MOTOR_voidInitialization();

		/* TESTING LED */
		GPIO_voidSetPinDirection(PORT_A, PIN_4, OUTPUT_SPEED_10MHZ_PUSHPULL);

		// Enable the clock for Timer 3
		TIMER2_u8ICUSetCallBack(&TIM2_voidCallBack);

		// Initializes the LCD Module
		LCD_voidInitialization();
		//	CLCD_voidInit();

		// Sends a Random String
		LCD_voidSetCursor(0, 0);
		LCD_voidSendString("HOSA");

		_delay_ms(1000);

		TIMER2_voidICUInitialization(TIMER2_CHANNEL1);
		TIMER2_voidICUInitialization(TIMER2_CHANNEL2);
		TIMER3_voidICUInitialization(TIMER3_CHANNEL1);
		TIMER3_voidICUInitialization(TIMER3_CHANNEL2);
}


void APP_voidExecution(void)
{
	GPIO_voidSetPinValue(PORT_A, PIN_4, LOGIC_HIGH);

	LCD_voidSetCursor(0, 0);
	LCD_voidSendString("Distance1: ");
	Received_distanceOne = HCSR04_u8ReadOne();

	LCD_voidSetCursor(11, 0);
	LCD_voidWriteNumber(Received_distanceOne);
	_delay_ms(200);

	LCD_voidSetCursor(0, 1);
	LCD_voidSendString("Distance2: ");
	Received_distanceTwo = HCSR04_u8ReadTwo();

	LCD_voidSetCursor(11, 1);
	LCD_voidWriteNumber(Received_distanceTwo);
	_delay_ms(200);

	MOTOR_voidFR_MotorSetSpeed(60);
	MOTOR_voidFR_FWD();
}



void TIM2_voidCallBack(void)
{
	GPIO_voidSetPinValue(PORT_A, PIN_4, LOGIC_HIGH); // Tester LED
	// Each Time i get into the ISR, I increment these variables
	Is_First_Captured2++;
	Is_First_Captured1++;

	// Checks the Interrupt Flag
	if(TIMER2_REG->TIMx_SR.TIMx_SR_CC1IF == 1)
	{
		TIMER2_REG->TIMx_SR.TIMx_SR_CC1IF = SET;

		if(Is_First_Captured1 == 1)
		{
			ICU1_Value1 = TIMER2_u32GetICUValue(TIMER2_CHANNEL1);
			//Is_First_Captured = 1;  // set the first captured as true

			// Now change the polarity to falling edge
			TIMER2_voidChangePolarity(TIMER2_CHANNEL1, TIMER2_FALLING_EDGE);
		}
		else if (Is_First_Captured1 == 2)   // if the first is already captured
		{
			ICU1_Value2 = TIMER2_u32GetICUValue(TIMER2_CHANNEL1);

			// Now change the polarity to rising edge
			TIMER2_voidChangePolarity(TIMER2_CHANNEL1, TIMER2_RISING_EDGE);

			// disable capture interrupt on each channel
			TIMER2_voidDisableInterrupt(TIMER2_CHANNEL1);
		}
	}

	// Checks the Interrupt Flag
	if(TIMER2_REG->TIMx_SR.TIMx_SR_CC2IF == 1)
	{
		TIMER2_REG->TIMx_SR.TIMx_SR_CC2IF = SET;

		if(Is_First_Captured2 == 1)
		{
			ICU2_Value1 = TIMER2_u32GetICUValue(TIMER2_CHANNEL2);
			//Is_First_Captured = 1;  // set the first captured as true

			// Now change the polarity to falling edge
			TIMER2_voidChangePolarity(TIMER2_CHANNEL2, TIMER2_FALLING_EDGE);
		}
		else if (Is_First_Captured2 == 2)   // if the first is already captured
		{
			ICU2_Value2 = TIMER2_u32GetICUValue(TIMER2_CHANNEL1);

			// Now change the polarity to rising edge
			TIMER2_voidChangePolarity(TIMER2_CHANNEL2, TIMER2_RISING_EDGE);

			// disable capture interrupt on each channel
			TIMER2_voidDisableInterrupt(TIMER2_CHANNEL2);
		}
	}
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


