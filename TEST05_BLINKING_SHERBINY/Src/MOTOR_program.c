/**********************************************************/
/* Author    :  Hosny & Tariq                             */
/* Date      :  14 Nov 2023                               */
/* Version   :  V01                                       */
/**********************************************************/

#include "ERROR_STATUS.h"
#include "TYPES.h"
#include "MACROS.h"


#include "GPIO_INTERFACE.h"
#include "TIMER_interface.h"

#include "MOTOR_interface.h"
#include "MOTOR_config.h"
#include "MOTOR_private.h"


void MOTORS_Void_MotorInit()
{
	/**************** RF MOTOR PINS ****************************/
	MGPIO_VidSetPinDirection(MOTOR_RF_IN1_PORT , MOTOR_RF_IN1_PIN , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(MOTOR_RF_IN2_PORT , MOTOR_RF_IN2_PIN , OUTPUT_SPEED_10MHZ_PP);

	/********************** RF ENABLE PINS as alternating ******************/
	MGPIO_VidSetPinDirection(MOTOR_RF_ENA_PORT , MOTOR_RF_ENA_PIN , OUTPUT_SPEED_10MHZ_AFPP);
//	MGPIO_VidSetPinDirection(MOTOR_RF_ENA_PORT , MOTOR_RF_ENA_PIN , OUTPUT_SPEED_10MHZ_PP);



	/**************** LF MOTOR PINS ****************************/
	MGPIO_VidSetPinDirection(MOTOR_LF_IN1_PORT , MOTOR_LF_IN1_PIN , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(MOTOR_LF_IN2_PORT , MOTOR_LF_IN2_PIN , OUTPUT_SPEED_10MHZ_PP);

	/********************** LF ENABLE PINS as alternating ******************/
	MGPIO_VidSetPinDirection(MOTOR_LF_ENA_PORT , MOTOR_LF_ENA_PIN , OUTPUT_SPEED_10MHZ_AFPP);



	/**************** RB MOTOR PINS ****************************/
	MGPIO_VidSetPinDirection(MOTOR_RB_IN1_PORT , MOTOR_RB_IN1_PIN , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(MOTOR_RB_IN2_PORT , MOTOR_RB_IN2_PIN , OUTPUT_SPEED_10MHZ_PP);

	/********************** RB ENABLE PINS as alternating ******************/
	MGPIO_VidSetPinDirection(MOTOR_RB_ENA_PORT , MOTOR_RB_ENA_PIN , OUTPUT_SPEED_10MHZ_AFPP);




	/**************** LB MOTOR PINS ****************************/
	MGPIO_VidSetPinDirection(MOTOR_LB_IN1_PORT , MOTOR_LB_IN1_PIN , OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(MOTOR_LB_IN2_PORT , MOTOR_LB_IN2_PIN , OUTPUT_SPEED_10MHZ_PP);

	/********************** LB ENABLE PINS as alternating ******************/
	MGPIO_VidSetPinDirection(MOTOR_LB_ENA_PORT , MOTOR_LB_ENA_PIN , OUTPUT_SPEED_10MHZ_AFPP);





	/*************************TIMERS INTIALZATION *****************/

	/* To Initiate PWM Channel 2 & 3 (TIMER2) */
	TIMER4_Void_PwmInit(TIMER4_CHANNEL3);
	TIMER4_Void_PwmInit(TIMER4_CHANNEL4);

//	TIMER4_Void_PwmStart();


	/* To Initiate PWM Channel 1 & 2 (TIMER4) */
	TIMER4_Void_PwmInit(TIMER4_CHANNEL1);
	TIMER4_Void_PwmInit(TIMER4_CHANNEL2);

//	TIMER4_Void_PwmStart();

}





void MOTOR_RF_Void_MotorSetSpeed(u32 Copy_U32_Speed)
{
	TIMER4_Void_PwmSetDutyCycle(TIMER4_CHANNEL3,Copy_U32_Speed);

}
void MOTOR_RF_GO_FORWARD ()
{
	MGPIO_VidSetPinValue(MOTOR_RF_IN1_PORT , MOTOR_RF_IN1_PIN , HIGH);
	MGPIO_VidSetPinValue(MOTOR_RF_IN2_PORT , MOTOR_RF_IN2_PIN , LOW);
}
void MOTOR_RF_GO_BACKWARD ()
{
	MGPIO_VidSetPinValue(MOTOR_RF_IN1_PORT , MOTOR_RF_IN1_PIN , LOW);
	MGPIO_VidSetPinValue(MOTOR_RF_IN2_PORT , MOTOR_RF_IN2_PIN , HIGH);
}

void MOTOR_RF_STOP()
{
	MGPIO_VidSetPinValue(MOTOR_RF_IN1_PORT , MOTOR_RF_IN1_PIN , HIGH);
	MGPIO_VidSetPinValue(MOTOR_RF_IN2_PORT , MOTOR_RF_IN2_PIN , HIGH);
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









