 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: MOTOR_PROGRAM.c
 *
 * Description: Source file for the DC Motor Driver
 *
 * Author: Hosny, Tariq & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       		   *
 *******************************************************************************/

#include "MOTOR_INTERFACE.h"

/*******************************************************************************
 *                              			DC Motor Global Variables				               				     *
 *******************************************************************************/

/*Global pointer to function to hold the callback function address*/

/*******************************************************************************
 *                              		DC Motor Function Implementations		     				     *
 *******************************************************************************/

void MOTOR_voidInitialization()
{
	/********************************************************************************/
	#if (MOTOR_DRIVE_MODE == MOTOR_ALL_DRIVE)
		/************** TIMERS INITIALIZATION ***********************/
		/* To Initiate TIMER4 PWM Channels 1, 2, 3, & 4 */
		TIMER4_voidPWMInitialization(TIMER4_CHANNEL1);
		TIMER4_voidPWMInitialization(TIMER4_CHANNEL2);
		TIMER4_voidPWMInitialization(TIMER4_CHANNEL3);
		TIMER4_voidPWMInitialization(TIMER4_CHANNEL4);
		/**************** RF MOTOR PINS ****************************/
		GPIO_voidSetPinDirection(MOTOR_FR_IN1, OUTPUT_SPEED_10MHZ_PUSHPULL);
		GPIO_voidSetPinDirection(MOTOR_FR_IN2, OUTPUT_SPEED_10MHZ_PUSHPULL);
		// L298 ENABLE-PIN as Alternating Push Pull
		GPIO_voidSetPinDirection(MOTOR_FR_ENABLE, OUTPUT_SPEED_10MHZ_AFPUSHPULL);

		/**************** FL MOTOR PINS ****************************/
		GPIO_voidSetPinDirection(MOTOR_FL_IN1, OUTPUT_SPEED_10MHZ_PUSHPULL);
		GPIO_voidSetPinDirection(MOTOR_FL_IN2, OUTPUT_SPEED_10MHZ_PUSHPULL);
		// L298 ENABLE-PIN as Alternating Push Pull
		GPIO_voidSetPinDirection(MOTOR_FL_ENABLE, OUTPUT_SPEED_10MHZ_AFPUSHPULL);

		/**************** RB MOTOR PINS ****************************/
		GPIO_voidSetPinDirection(MOTOR_RR_IN1, OUTPUT_SPEED_10MHZ_PUSHPULL);
		GPIO_voidSetPinDirection(MOTOR_RR_IN2, OUTPUT_SPEED_10MHZ_PUSHPULL);
		// L298 ENABLE-PIN as Alternating Push Pull
		GPIO_voidSetPinDirection(MOTOR_RR_ENABLE, OUTPUT_SPEED_10MHZ_AFPUSHPULL);

		/**************** LB MOTOR PINS ****************************/
		GPIO_voidSetPinDirection(MOTOR_RL_IN1, OUTPUT_SPEED_10MHZ_PUSHPULL);
		GPIO_voidSetPinDirection(MOTOR_RL_IN2, OUTPUT_SPEED_10MHZ_PUSHPULL);
		// L298 ENABLE-PIN as Alternating Push Pull
		GPIO_voidSetPinDirection(MOTOR_RL_ENABLE, OUTPUT_SPEED_10MHZ_AFPUSHPULL);
	/********************************************************************************/
	#elif (MOTOR_DRIVE_MODE == MOTOR_FRONT_DRIVE)
		/************** TIMERS INITIALIZATION ***********************/
		/* To Initiate TIMER4 PWM Channels 1, 2, 3, & 4 */
		TIMER4_voidPWMInitialization(TIMER4_CHANNEL1);
		TIMER4_voidPWMInitialization(TIMER4_CHANNEL2);

		/**************** RF MOTOR PINS ****************************/
		GPIO_voidSetPinDirection(MOTOR_FR_IN1, OUTPUT_SPEED_10MHZ_PUSHPULL);
		GPIO_voidSetPinDirection(MOTOR_FR_IN2, OUTPUT_SPEED_10MHZ_PUSHPULL);
		// L298 ENABLE-PIN as Alternating Push Pull
		GPIO_voidSetPinDirection(MOTOR_FR_ENABLE, OUTPUT_SPEED_10MHZ_AFPUSHPULL);

		/**************** FL MOTOR PINS ****************************/
		GPIO_voidSetPinDirection(MOTOR_FL_IN1, OUTPUT_SPEED_10MHZ_PUSHPULL);
		GPIO_voidSetPinDirection(MOTOR_FL_IN2, OUTPUT_SPEED_10MHZ_PUSHPULL);
		// L298 ENABLE-PIN as Alternating Push Pull
		GPIO_voidSetPinDirection(MOTOR_FL_ENABLE, OUTPUT_SPEED_10MHZ_AFPUSHPULL);
	/********************************************************************************/
	#elif (MOTOR_DRIVE_MODE == MOTOR_REAR_DRIVE)
		/************** TIMERS INITIALIZATION ***********************/
		/* To Initiate TIMER4 PWM Channels 1, 2, 3, & 4 */
		TIMER4_voidPWMInitialization(TIMER4_CHANNEL3);
		TIMER4_voidPWMInitialization(TIMER4_CHANNEL4);

		/**************** RR MOTOR PINS ****************************/
		GPIO_voidSetPinDirection(MOTOR_RR_IN1, OUTPUT_SPEED_10MHZ_PUSHPULL);
		GPIO_voidSetPinDirection(MOTOR_RR_IN2, OUTPUT_SPEED_10MHZ_PUSHPULL);
		// L298 ENABLE-PIN as Alternating Push Pull
		GPIO_voidSetPinDirection(MOTOR_RR_ENABLE, OUTPUT_SPEED_10MHZ_AFPUSHPULL);

		/**************** RL MOTOR PINS ****************************/
		GPIO_voidSetPinDirection(MOTOR_RL_IN1, OUTPUT_SPEED_10MHZ_PUSHPULL);
		GPIO_voidSetPinDirection(MOTOR_RL_IN2, OUTPUT_SPEED_10MHZ_PUSHPULL);
		// L298 ENABLE-PIN as Alternating Push Pull
		GPIO_voidSetPinDirection(MOTOR_RL_ENABLE, OUTPUT_SPEED_10MHZ_AFPUSHPULL);
	#endif
	/********************************************************************************/
}


/************************ MOTOR Front Right *********************/
void MOTOR_voidFR_MotorSetSpeed(u32 Copy_u32Speed)
{
	TIMER4_voidPWMSetDutyCycle(TIMER4_CHANNEL1, Copy_u32Speed);
}
void MOTOR_voidFR_FWD()
{
	GPIO_voidSetPinValue(MOTOR_FR_IN1, LOGIC_HIGH);
	GPIO_voidSetPinValue(MOTOR_FR_IN2, LOGIC_LOW);
}
void MOTOR_voidFR_BWD()
{
	GPIO_voidSetPinValue(MOTOR_FR_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_FR_IN2, LOGIC_HIGH);
}
void MOTOR_voidFR_STOP()
{
	GPIO_voidSetPinValue(MOTOR_FR_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_FR_IN2, LOGIC_LOW);
}


/****************************** MOTOR Front Left *********************/
void MOTOR_voidFL_MotorSetSpeed(u32 Copy_u32Speed)
{
	TIMER4_voidPWMSetDutyCycle(TIMER4_CHANNEL2, Copy_u32Speed);
}
void MOTOR_voidFL_FWD()
{
	GPIO_voidSetPinValue(MOTOR_FL_IN1, LOGIC_HIGH);
	GPIO_voidSetPinValue(MOTOR_FL_IN2, LOGIC_LOW);
}
void MOTOR_voidFL_BWD()
{
	GPIO_voidSetPinValue(MOTOR_FL_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_FL_IN2, LOGIC_HIGH);
}
void MOTOR_voidFL_STOP()
{
	GPIO_voidSetPinValue(MOTOR_FL_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_FL_IN2, LOGIC_LOW);
}


/************************ MOTOR Rear Right *********************/
void MOTOR_voidRR_MotorSetSpeed(u32 Copy_u32Speed)
{
	TIMER4_voidPWMSetDutyCycle(TIMER4_CHANNEL3, Copy_u32Speed);
}
void MOTOR_voidRR_FWD()
{
	GPIO_voidSetPinValue(MOTOR_RR_IN1, LOGIC_HIGH);
	GPIO_voidSetPinValue(MOTOR_RR_IN2, LOGIC_LOW);
}
void MOTOR_voidRR_BWD()
{
	GPIO_voidSetPinValue(MOTOR_RR_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_RR_IN2, LOGIC_HIGH);
}
void MOTOR_voidRR_STOP()
{
	GPIO_voidSetPinValue(MOTOR_RR_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_RR_IN2, LOGIC_LOW);
}


/************************ MOTOR Rear Left *********************/
void MOTOR_voidRL_MotorSetSpeed(u32 Copy_u32Speed)
{
	TIMER4_voidPWMSetDutyCycle(TIMER4_CHANNEL4, Copy_u32Speed);
}
void MOTOR_voidRL_FWD()
{
	GPIO_voidSetPinValue(MOTOR_RL_IN1, LOGIC_HIGH);
	GPIO_voidSetPinValue(MOTOR_RL_IN2, LOGIC_LOW);
}
void MOTOR_voidRL_BWD()
{
	GPIO_voidSetPinValue(MOTOR_RL_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_RL_IN2, LOGIC_HIGH);
}
void MOTOR_voidRL_STOP()
{
	GPIO_voidSetPinValue(MOTOR_RL_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_RL_IN2, LOGIC_LOW);
}

