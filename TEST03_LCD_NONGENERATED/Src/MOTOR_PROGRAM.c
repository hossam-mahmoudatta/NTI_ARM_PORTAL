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

#include "../Inc/MOTOR_INTERFACE.h"

/*******************************************************************************
 *                              			DC Motor Global Variables				               				     *
 *******************************************************************************/

/*Global pointer to function to hold the callback function address*/

/*******************************************************************************
 *                              		DC Motor Function Implementations		     				     *
 *******************************************************************************/

void MOTOR_voidInitialization()
{
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

	/************** TIMERS INITIALIZATION ***********************/

	/* To Initiate TIMER4 PWM Channels 1, 2, 3, & 4 */
	TIMER4_voidPWMInitialization(TIMER4_CHANNEL1);
	TIMER4_voidPWMInitialization(TIMER4_CHANNEL2);
	TIMER4_voidPWMInitialization(TIMER4_CHANNEL3);
	TIMER4_voidPWMInitialization(TIMER4_CHANNEL4);
}



void MOTOR_voidFR_MotorSetSpeed(u32 Copy_u32Speed)
{
	TIMER4_voidPWMSetDutyCycle(TIMER4_CHANNEL1, Copy_u32Speed);
}
void MOTOR_voidFL_FWD()
{
	GPIO_voidSetPinValue(MOTOR_FR_IN1, LOGIC_HIGH);
	GPIO_voidSetPinValue(MOTOR_FR_IN2, LOGIC_LOW);
}
void MOTOR_voidFL_BWD()
{
	GPIO_voidSetPinValue(MOTOR_FR_IN1, LOGIC_LOW);
	GPIO_voidSetPinValue(MOTOR_FR_IN2, LOGIC_HIGH);
}
void MOTOR_RF_STOP()
{
	MGPIO_VidSetPinValue(MOTOR_RF_IN1_PORT , MOTOR_RF_IN1_PIN , LOW);
	MGPIO_VidSetPinValue(MOTOR_RF_IN2_PORT , MOTOR_RF_IN2_PIN , LOW);
}









void MOTOR_LF_Void_MotorSetSpeed(u32 Copy_U32_Speed)
{
	TIMER4_Void_PwmSetDutyCycle(TIMER4_CHANNEL4,Copy_U32_Speed);
}
void MOTOR_LF_GO_FORWARD ()
{
	MGPIO_VidSetPinValue(MOTOR_LF_IN1_PORT , MOTOR_LF_IN1_PIN , HIGH);
	MGPIO_VidSetPinValue(MOTOR_LF_IN2_PORT , MOTOR_LF_IN2_PIN , LOW);
}
void MOTOR_LF_GO_BACKWARD ()
{

	MGPIO_VidSetPinValue(MOTOR_LF_IN1_PORT , MOTOR_LF_IN1_PIN , LOW);
	MGPIO_VidSetPinValue(MOTOR_LF_IN2_PORT , MOTOR_LF_IN2_PIN , HIGH);
}

void MOTOR_LF_STOP()
{

	MGPIO_VidSetPinValue(MOTOR_LF_IN1_PORT , MOTOR_LF_IN1_PIN , LOW);
	MGPIO_VidSetPinValue(MOTOR_LF_IN2_PORT , MOTOR_LF_IN2_PIN , LOW);
}






void MOTOR_RB_Void_MotorSetSpeed(u32 Copy_U32_Speed)
{
	TIMER4_Void_PwmSetDutyCycle(TIMER4_CHANNEL1,Copy_U32_Speed);
}
void MOTOR_RB_GO_FORWARD ()
{
	MGPIO_VidSetPinValue(MOTOR_RB_IN1_PORT , MOTOR_RB_IN1_PIN , HIGH);
	MGPIO_VidSetPinValue(MOTOR_RB_IN2_PORT , MOTOR_RB_IN2_PIN , LOW);
}
void MOTOR_RB_GO_BACKWARD (){
	MGPIO_VidSetPinValue(MOTOR_RB_IN1_PORT , MOTOR_RB_IN1_PIN , LOW);
	MGPIO_VidSetPinValue(MOTOR_RB_IN2_PORT , MOTOR_RB_IN2_PIN , HIGH);
}
void MOTOR_RB_STOP(){
	MGPIO_VidSetPinValue(MOTOR_RB_IN1_PORT , MOTOR_RB_IN1_PIN , LOW);
	MGPIO_VidSetPinValue(MOTOR_RB_IN2_PORT , MOTOR_RB_IN2_PIN , LOW);
}






void MOTOR_LB_Void_MotorSetSpeed(u32 Copy_U32_Speed)
{
	TIMER4_Void_PwmSetDutyCycle(TIMER4_CHANNEL2,Copy_U32_Speed);
}
void MOTOR_LB_GO_FORWARD ()
{
	MGPIO_VidSetPinValue(MOTOR_LB_IN1_PORT , MOTOR_LB_IN1_PIN , HIGH);
	MGPIO_VidSetPinValue(MOTOR_LB_IN2_PORT , MOTOR_LB_IN2_PIN , LOW);
}
void MOTOR_LB_GO_BACKWARD ()
{
	MGPIO_VidSetPinValue(MOTOR_LB_IN1_PORT , MOTOR_LB_IN1_PIN , LOW);
	MGPIO_VidSetPinValue(MOTOR_LB_IN2_PORT , MOTOR_LB_IN2_PIN , HIGH);
}
void MOTOR_LB_STOP()
{
	MGPIO_VidSetPinValue(MOTOR_LB_IN1_PORT , MOTOR_LB_IN1_PIN , LOW);
	MGPIO_VidSetPinValue(MOTOR_LB_IN2_PORT , MOTOR_LB_IN2_PIN , LOW);
}









