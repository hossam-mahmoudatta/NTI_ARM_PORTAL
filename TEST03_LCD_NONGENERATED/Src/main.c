 /******************************************************************************
 *
 * Module: Main.c
 *
 * File Name: main.c
 *
 * Description: Source file for the application main
 *
 * Author: Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              						Include Libraries						                       		   *
 *******************************************************************************/
#include <stdint.h>
#include "../Inc/MOTOR_INTERFACE.h"
#include "../Inc/TIMER2_INTERFACE.h"
#include "../Inc/TIMER3_INTERFACE.h"
#include "../Inc/TIMER4_INTERFACE.h"
#include "../Inc/HCSR04_INTERFACE.h"

#include "../Inc/ERROR_STATUS.h"
#include "../Inc/RCC_INTERFACE.h"
#include "../Inc/GPIO_INTERFACE.h"
#include "../Inc/SYSTICK_INTERFACE.h"
#include "../Inc/DELAY_INTERFACE.h"
#include "../Inc/NVIC_INTERFACE.h"
#include "../Inc/LCD_INTERFACE.h"



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



int main(void)
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

	/* TESTING LED */
	GPIO_voidSetPinDirection(PORT_A, PIN_4, OUTPUT_SPEED_10MHZ_PUSHPULL);

	// Enable the clock for Timer 3
	TIMER2_u8ICUSetCallBack(&TIM2_voidCallBack);

	// Initializes the LCD Module
	LCD_voidInitialization();
//	CLCD_voidInit();

	// Sends a Random String
	LCD_voidPuts(0, 0, "HOSA");
//	CLCD_voidSendString("Hosny");
	_delay_ms(1000);

	TIMER2_voidICUInitialization(TIMER2_CHANNEL1);
	TIMER2_voidICUInitialization(TIMER2_CHANNEL2);

	//	TIMER3_VoidInitInputCapture(Channle1);
	/* Loop forever */
	for(;;){
		CLCD_voidGoToXY(0, 0);
		CLCD_voidSendString("D1:");
		Received_distanceOne=Ultrasonic_ReadOne();
		CLCD_voidWriteNumber(Received_distanceOne);
		//CLCD_voidSendString("   ");
		_delay_ms(200);

		CLCD_voidGoToXY(0, 1);
		CLCD_voidSendString("D2:");
		Received_distanceTwo=Ultrasonic_ReadTwo();
		CLCD_voidWriteNumber(Received_distanceTwo);
		_delay_ms(200);

		//CLCD_voidSendString("   ");
		//		CLCD_voidGoToXY(0, 0);
		//		CLCD_voidSendString("D1:");
		//		CLCD_voidGoToXY(0, 1);
		//		CLCD_voidSendString("D2:");
		//		Received_distanceOne=Ultrasonic_ReadOne();
		//		Received_distanceTwo=Ultrasonic_ReadTwo();
		//		CLCD_voidGoToXY(3, 0);
		//		CLCD_voidWriteNumber(Received_distanceOne);
		//		CLCD_voidGoToXY(3, 1);
		//		CLCD_voidWriteNumber(Received_distanceTwo);
		//		CLCD_voidSendString("   ");
		//		_delay_ms(800);
	}
}

//void TIM3(void)
//{
//	MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
//	Is_First_Captured++;
//	if(GET_BIT(TIMER3_SR,1)==1)
//	{
//
//		SET_BIT(TIMER3_SR,1);
//
//	if(Is_First_Captured==1)
//	{
//
//		IC_Val1=TIMER3_CCR1;
//		//Is_First_Captured = 1;  // set the first captured as true
//		// Now change the polarity to falling edge
//		SET_BIT(TIMER3_CCER,1);
//	}
//	else if (Is_First_Captured==2)   // if the first is already captured
//	{
//		IC_Val2 = TIMER3_CCR1 ; // read second value
//
//		// Now change the polarity to rising edge
//		CLR_BIT(TIMER3_CCER,1);
//		// disable capture interrupt on each channel
//		CLR_BIT(TIMER3_DIER,1);
//
//
//	}
//	}
//}

//void TIM(void)
//{
//	MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
//	Is_First_Captured++;
//	if(GET_BIT(TIMER2_SR,1)==1)
//	{
//
//		SET_BIT(TIMER2_SR,1);
//
//	if(Is_First_Captured==1)
//	{
//
//		IC_Val1=TIMER2_CCR1;
//		//Is_First_Captured = 1;  // set the first captured as true
//		// Now change the polarity to falling edge
//		SET_BIT(TIMER2_CCER,1);
//	}
//	else if (Is_First_Captured==2)   // if the first is already captured
//	{
//		IC_Val2 = TIMER2_CCR1 ; // read second value
//
//		// Now change the polarity to rising edge
//		CLR_BIT(TIMER2_CCER,1);
//		// disable capture interrupt on each channel
//		CLR_BIT(TIMER2_DIER,1);
//
//
//	}
//	}
//}
