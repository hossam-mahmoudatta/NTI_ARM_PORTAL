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

		// Enables the RCC for TIMER2, TIMER3, GPIO_A, GPIO_B, USART1
		RCC_voidPeripheralClockEnable(RCC_APB1, APB1_TIM2EN);
		RCC_voidPeripheralClockEnable(RCC_APB1, APB1_TIM3EN);
		RCC_voidPeripheralClockEnable(RCC_APB1, APB1_TIM4EN);
		RCC_voidPeripheralClockEnable(RCC_APB2, APB2_IOPAEN);
		RCC_voidPeripheralClockEnable(RCC_APB2, APB2_IOPBEN);
		RCC_voidPeripheralClockEnable(RCC_APB2, APB2_USART1EN);

		// Enables the NVIC Module for TIMER2 & TIMER3
		NVIC_voidEnablePeripheral(TIM2_C);
		NVIC_voidEnablePeripheral(TIM3_C);

		// Initializing the Ultrasonic Sensors
		HCSR04_voidInitialization();

		// Initializing the Motor Drivers
		MOTOR_voidInitialization();

		// Initializing the USART Module
		GPIO_voidSetPinDirection(PORT_A, PIN_9, OUTPUT_SPEED_2MHZ_AFPUSHPULL);
		GPIO_voidSetPinDirection(PORT_A, PIN_10, INPUT_FLOATING);
		USART_voidInitialization();

		// Sets the ISR for the Ultrasonic Sensors
		TIMER2_u8ICUSetCallBack(&TIM2_voidCallBack);
		TIMER3_u8ICUSetCallBack(&TIM3_voidCallBack);

		_delay_ms(1000);

		// Initializes the timers for the Ultrasonic Sensors
		TIMER2_voidICUInitialization(TIMER2_CHANNEL1);
		TIMER2_voidICUInitialization(TIMER2_CHANNEL2);
		TIMER3_voidICUInitialization(TIMER3_CHANNEL1);
		TIMER3_voidICUInitialization(TIMER3_CHANNEL2);
		TIMER3_voidICUInitialization(TIMER3_CHANNEL3);

		/* TESTING LED that all initializations carried successfully*/
		GPIO_voidSetPinDirection(PORT_A, PIN_4, OUTPUT_SPEED_10MHZ_PUSHPULL);

		/* LED for Collision Avoidance Mode */
		GPIO_voidSetPinDirection(PORT_A, PIN_5, OUTPUT_SPEED_10MHZ_PUSHPULL);

		/* LED for Auto Parking Mode */
		GPIO_voidSetPinDirection(PORT_B, PIN_10, OUTPUT_SPEED_10MHZ_PUSHPULL);

		/* LED for RC Car Mode */
		GPIO_voidSetPinDirection(PORT_B, PIN_11, OUTPUT_SPEED_10MHZ_PUSHPULL);
}


void APP_voidCollisionAvoidance(void)
{
	GPIO_voidSetPinValue(PORT_A, PIN_5, LOGIC_HIGH);
	MOTOR_voidFR_MotorSetSpeed(75);
	MOTOR_voidFL_MotorSetSpeed(75);

	Received_distanceThree = HCSR04_u8ReadThree();
	_delay_ms(100);
	Received_distanceFour = HCSR04_u8ReadFour();
	_delay_ms(100);

	if((Received_distanceThree > 20) && (Received_distanceFour > 20))
	{
		Received_distanceFour = HCSR04_u8ReadFour();
		_delay_ms(100);

		while(Received_distanceFour > 20)
		{
			Received_distanceFour = HCSR04_u8ReadFour();
			_delay_ms(100);
			MOTOR_voidFR_FWD();
			MOTOR_voidFL_FWD();
		}

		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();
		_delay_ms(200);

		MOTOR_voidFR_BWD();
		MOTOR_voidFL_BWD();
		_delay_ms(400);

		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();

		//move LF backward
		MOTOR_voidFL_BWD();
		_delay_ms(1000);
		MOTOR_voidFL_STOP();

		MOTOR_voidFL_MotorSetSpeed(110);

		Received_distanceTwo = HCSR04_u8ReadTwo();
		_delay_ms(100);

		if(Received_distanceTwo > 2)
		{
			while(Received_distanceTwo > 20)
			{
				Received_distanceTwo = HCSR04_u8ReadTwo();
				_delay_ms(100);

				MOTOR_voidFR_BWD();
				MOTOR_voidFL_BWD();
			}

			MOTOR_voidFR_STOP();
			MOTOR_voidFL_STOP();
		}


		// p>>B ?
		MOTOR_voidFL_MotorSetSpeed(100);
		MOTOR_voidFL_FWD();
		MOTOR_voidFR_BWD();
		_delay_ms(500);

		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();

		_delay_ms(1000);

		MOTOR_voidFR_MotorSetSpeed(55);
		MOTOR_voidFL_MotorSetSpeed(65);
		Received_distanceOne = HCSR04_u8ReadOne();
		_delay_ms(100);

		if(Received_distanceOne > 7)
		{
			while(Received_distanceOne > 7)
			{
				Received_distanceOne = HCSR04_u8ReadOne();
				_delay_ms(100);

				MOTOR_voidFR_FWD();
				MOTOR_voidFL_FWD();

			}
			MOTOR_voidFR_STOP();
			MOTOR_voidFL_STOP();
		}
		while(1);
	}
	else
	{
		MOTOR_voidFR_MotorSetSpeed(75);
		MOTOR_voidFL_MotorSetSpeed(75);
		MOTOR_voidFR_FWD();
		MOTOR_voidFL_FWD();
	}
}


void APP_voidAutoParking(void)
{
	GPIO_voidSetPinValue(PORT_B, PIN_10, LOGIC_HIGH);
	MOTOR_voidFR_MotorSetSpeed(75);
	MOTOR_voidFL_MotorSetSpeed(75);

	Received_distanceThree = HCSR04_u8ReadThree();
	_delay_ms(100);
	Received_distanceFour = HCSR04_u8ReadFour();
	_delay_ms(100);

	if((Received_distanceThree > 20) && (Received_distanceFour > 20))
	{
		Received_distanceFour = HCSR04_u8ReadFour();
		_delay_ms(100);

		while(Received_distanceFour > 20)
		{
			Received_distanceFour = HCSR04_u8ReadFour();
			_delay_ms(100);
			MOTOR_voidFR_FWD();
			MOTOR_voidFL_FWD();
		}

		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();
		_delay_ms(200);

		MOTOR_voidFR_BWD();
		MOTOR_voidFL_BWD();
		_delay_ms(400);

		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();

		//move LF backward
		MOTOR_voidFL_BWD();
		_delay_ms(1000);
		MOTOR_voidFL_STOP();

		MOTOR_voidFL_MotorSetSpeed(110);

		Received_distanceTwo = HCSR04_u8ReadTwo();
		_delay_ms(100);

		if(Received_distanceTwo > 2)
		{
			while(Received_distanceTwo > 20)
			{
				Received_distanceTwo = HCSR04_u8ReadTwo();
				_delay_ms(100);

				MOTOR_voidFR_BWD();
				MOTOR_voidFL_BWD();
			}

			MOTOR_voidFR_STOP();
			MOTOR_voidFL_STOP();
		}


		// p>>B ?
		MOTOR_voidFL_MotorSetSpeed(100);
		MOTOR_voidFL_FWD();
		MOTOR_voidFR_BWD();
		_delay_ms(500);

		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();

		_delay_ms(1000);

		MOTOR_voidFR_MotorSetSpeed(55);
		MOTOR_voidFL_MotorSetSpeed(65);
		Received_distanceOne = HCSR04_u8ReadOne();
		_delay_ms(100);

		if(Received_distanceOne > 7)
		{
			while(Received_distanceOne > 7)
			{
				Received_distanceOne = HCSR04_u8ReadOne();
				_delay_ms(100);

				MOTOR_voidFR_FWD();
				MOTOR_voidFL_FWD();

			}
			MOTOR_voidFR_STOP();
			MOTOR_voidFL_STOP();
		}
		while(1);
	}
	else
	{
		MOTOR_voidFR_MotorSetSpeed(75);
		MOTOR_voidFL_MotorSetSpeed(75);
		MOTOR_voidFR_FWD();
		MOTOR_voidFL_FWD();
	}
}


void APP_voidRCCar(void)
{
	GPIO_voidSetPinValue(PORT_B, PIN_11, LOGIC_HIGH);
	MOTOR_voidFR_MotorSetSpeed(75);
	MOTOR_voidFL_MotorSetSpeed(75);
	u8 LOC_u8NewData = 0;

	// Receive new data from Bluetooth
	LOC_u8NewData = USART1_u8ReceiveCharSynchronous();
	_delay_ms(100);

	// Motor control based on received data
	switch (LOC_u8NewData) {
	case '1':
		// Move forward
		MOTOR_voidFR_FWD();
		MOTOR_voidFL_FWD();
		_delay_ms(250);

		// Stop after a short delay
		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();
		break;

	case '2':
		// Turn right
		MOTOR_voidFR_FWD();
		MOTOR_voidFL_STOP();
		_delay_ms(250);
		// Stop after a short delay
		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();
		break;

	case '3':
		// Turn left
		MOTOR_voidFL_FWD();
		MOTOR_voidFR_STOP();
		_delay_ms(250);
		// Stop after a short delay
		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();
		break;

	case '4':
		// Move backward
		MOTOR_voidFR_BWD();
		MOTOR_voidFL_BWD();
		_delay_ms(250);
		// Stop after a short delay
		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();
		break;

	default:
		// Stop if the received command is not recognized
		MOTOR_voidFR_STOP();
		MOTOR_voidFL_STOP();
		break;
	}
}



void TIM2_voidCallBack(void)
{
	GPIO_voidSetPinValue(PORT_A, PIN_4, LOGIC_HIGH); // Tester LED
	// Each Time i get into the ISR, I increment these variables
	Is_First_Captured2++;
	Is_First_Captured1++;

	// Checks the Interrupt Flag for Channel 1
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

	// Checks the Interrupt Flag for Channel 2
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



void TIM3_voidCallBack(void)
{
	GPIO_voidSetPinValue(PORT_A, PIN_4, LOGIC_HIGH); // Tester LED
	// Each Time i get into the ISR, I increment these variables
	Is_First_Captured3++;
	Is_First_Captured4++;
	Is_First_Captured5++;

	// Checks the Interrupt Flag For Channel 1
	if(TIMER3_REG->TIMx_SR.TIMx_SR_CC1IF == 1)
	{
		TIMER2_REG->TIMx_SR.TIMx_SR_CC1IF = SET;

		if(Is_First_Captured3 == 1)
		{
			ICU3_Value1 = TIMER3_u32GetICUValue(TIMER3_CHANNEL1);
			//Is_First_Captured = 1;  // set the first captured as true

			// Now change the polarity to falling edge
			TIMER3_voidChangePolarity(TIMER3_CHANNEL1, TIMER2_FALLING_EDGE);
		}
		else if (Is_First_Captured3 == 2)   // if the first is already captured
		{
			ICU3_Value2 = TIMER3_u32GetICUValue(TIMER3_CHANNEL1);

			// Now change the polarity to rising edge
			TIMER3_voidChangePolarity(TIMER3_CHANNEL1, TIMER3_RISING_EDGE);

			// disable capture interrupt on each channel
			TIMER3_voidDisableInterrupt(TIMER3_CHANNEL1);
		}
	}

	// Checks the Interrupt Flag For Channel 2
	if(TIMER3_REG->TIMx_SR.TIMx_SR_CC2IF == 1)
	{
		TIMER2_REG->TIMx_SR.TIMx_SR_CC2IF = SET;

		if(Is_First_Captured4 == 1)
		{
			ICU4_Value1 = TIMER3_u32GetICUValue(TIMER3_CHANNEL2);
			//Is_First_Captured = 1;  // set the first captured as true

			// Now change the polarity to falling edge
			TIMER3_voidChangePolarity(TIMER3_CHANNEL2, TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured4 == 2)   // if the first is already captured
		{
			ICU4_Value2 = TIMER3_u32GetICUValue(TIMER3_CHANNEL2);

			// Now change the polarity to rising edge
			TIMER3_voidChangePolarity(TIMER3_CHANNEL2, TIMER3_RISING_EDGE);

			// disable capture interrupt on each channel
			TIMER3_voidDisableInterrupt(TIMER3_CHANNEL2);
		}
	}

	// Checks the Interrupt Flag For Channel 3
	if(TIMER3_REG->TIMx_SR.TIMx_SR_CC3IF == 1)
	{
		TIMER2_REG->TIMx_SR.TIMx_SR_CC3IF = SET;

		if(Is_First_Captured5 == 1)
		{
			ICU5_Value1 = TIMER3_u32GetICUValue(TIMER3_CHANNEL3);
			//Is_First_Captured = 1;  // set the first captured as true

			// Now change the polarity to falling edge
			TIMER3_voidChangePolarity(TIMER3_CHANNEL3, TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured4 == 2)   // if the first is already captured
		{
			ICU5_Value2 = TIMER3_u32GetICUValue(TIMER3_CHANNEL3);

			// Now change the polarity to rising edge
			TIMER3_voidChangePolarity(TIMER3_CHANNEL3, TIMER3_RISING_EDGE);

			// disable capture interrupt on each channel
			TIMER3_voidDisableInterrupt(TIMER3_CHANNEL3);
		}
	}
}






void APP_voidISRFunction(void)
{

}


