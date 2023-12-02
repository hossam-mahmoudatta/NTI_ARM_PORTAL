 /******************************************************************************
 *
 * Module: HCSR04
 *
 * File Name: HCSR04_PROGRAM.c
 *
 * Description: Source file for the HCSR04 Driver
 *
 * Author: Sherbiny & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              						Include Libraries						                       		   *
 *******************************************************************************/

#include "../Inc/HCSR04_INTERFACE.h"

/*******************************************************************************
 *                              				HCSR04 Global Variables				               				     *
 *******************************************************************************/

u32 volatile ICU1_Value1 = 0;
u32 volatile ICU1_Value2 = 0;
u32 volatile Difference1 = 0;
u8   volatile Is_First_Captured1 = 0;  // is the first value captured ?
u8   volatile Distance1  = 0;

u32 volatile ICU2_Value1 = 0;
u32 volatile ICU2_Value2 = 0;
u32 volatile Difference2 = 0;
u8   volatile Is_First_Captured2 = 0;  // is the first value captured ?
u8   volatile Distance2  = 0;

u32 volatile ICU3_Value1 = 0;
u32 volatile ICU3_Value2 = 0;
u32 volatile Difference3 = 0;
u8   volatile Is_First_Captured3 = 0;  // is the first value captured ?
u8   volatile Distance3  = 0;

u32 volatile ICU4_Value1 = 0;
u32 volatile ICU4_Value2 = 0;
u32 volatile Difference4 = 0;
u8   volatile Is_First_Captured4 = 0;  // is the first value captured ?
u8   volatile Distance4  = 0;

u32 volatile ICU5_Value1 = 0;
u32 volatile ICU5_Value2 = 0;
u32 volatile Difference5 = 0;
u8   volatile Is_First_Captured5 = 0;  // is the first value captured ?
u8   volatile Distance5  = 0;

u8 Received_distanceOne = 0;
u8 Received_distanceTwo = 0;
u8 Received_distanceThree = 0;
u8 Received_distanceFour = 0;
u8 Received_distanceFive = 0;

/*******************************************************************************
 *                              		HCSR04 Function Implementations		     				     *
 *******************************************************************************/

// Initializes the Ultrasonic drivers, in our case, 4 ultrasonics
void HCSR04_voidInitialization(void)
{
	// Initializing the PINS For the Ultrasonic TRIGGER
	GPIO_voidSetPinDirection(HCSR04_S1_TRIGGER, OUTPUT_SPEED_10MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(HCSR04_S2_TRIGGER, OUTPUT_SPEED_10MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(HCSR04_S3_TRIGGER, OUTPUT_SPEED_10MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(HCSR04_S4_TRIGGER, OUTPUT_SPEED_10MHZ_PUSHPULL);

	// Initializing the PINS For the Ultrasonic ECHO
	GPIO_voidSetPinDirection(HCSR04_S1_ECHO, INPUT_FLOATING);
	GPIO_voidSetPinDirection(HCSR04_S2_ECHO, INPUT_FLOATING);
	GPIO_voidSetPinDirection(HCSR04_S3_ECHO, INPUT_FLOATING);
	GPIO_voidSetPinDirection(HCSR04_S4_ECHO, INPUT_FLOATING);
}


void HCSR04_voidTriggerOne(void)
{
	GPIO_voidSetPinValue(HCSR04_S1_TRIGGER, LOGIC_HIGH);	// pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	GPIO_voidSetPinValue(HCSR04_S1_TRIGGER, LOGIC_LOW);  // pull the TRIG pin low
}


void HCSR04_voidTriggerTwo(void)
{
	GPIO_voidSetPinValue(HCSR04_S2_TRIGGER, LOGIC_HIGH);	// pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	GPIO_voidSetPinValue(HCSR04_S2_TRIGGER, LOGIC_LOW);  // pull the TRIG pin low
}


void HCSR04_voidTriggerThree(void)
{
	GPIO_voidSetPinValue(HCSR04_S3_TRIGGER, LOGIC_HIGH);	// pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	GPIO_voidSetPinValue(HCSR04_S3_TRIGGER, LOGIC_LOW);  // pull the TRIG pin low
}


void HCSR04_voidTriggerFour(void)
{
	GPIO_voidSetPinValue(HCSR04_S4_TRIGGER, LOGIC_HIGH);	// pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	GPIO_voidSetPinValue(HCSR04_S4_TRIGGER, LOGIC_LOW);  // pull the TRIG pin low
}



u8 HCSR04_u8ReadOne(void)
{
	TIMER2_voidSetPreload(0);
	HCSR04_voidTriggerOne();

	while(Is_First_Captured1 < 2);
	Difference1 = ICU1_Value2 - ICU1_Value1;
	Distance1 = (Difference1 / 58);
	Is_First_Captured1 = 0;
	TIMER2_voidEnableInterrupt(TIMER2_CHANNEL1);
	return Distance1;
}


u8 HCSR04_u8ReadTwo(void)
{
	TIMER2_voidSetPreload(0);
	HCSR04_voidTriggerTwo();

	while(Is_First_Captured2 < 2);
	Difference2 = ICU2_Value2 - ICU2_Value1;
	Distance2 = (Difference2 / 58);
	Is_First_Captured2 = 0;
	TIMER2_voidEnableInterrupt(TIMER2_CHANNEL2);
	return Distance2;
}


u8 HCSR04_u8ReadThree(void)
{
	TIMER3_voidSetPreload(0);
	HCSR04_voidTriggerThree();

	while(Is_First_Captured3 < 2);
	Difference3 = ICU3_Value2 - ICU3_Value1;
	Distance3 = (Difference3 / 58);
	Is_First_Captured3 = 0;
	TIMER3_voidEnableInterrupt(TIMER3_CHANNEL1);
	return Distance3;
}


u8 HCSR04_u8ReadFour(void)
{
	TIMER2_voidSetPreload(0);
	HCSR04_voidTriggerFour();

	while(Is_First_Captured4 < 2);
	Difference4 = ICU4_Value2 - ICU4_Value1;
	Distance4 = (Difference4 / 58);
	Is_First_Captured4 = 0;
	TIMER3_voidEnableInterrupt(TIMER3_CHANNEL2);
	return Distance4;
}


