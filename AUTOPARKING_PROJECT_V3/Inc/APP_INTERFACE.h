/******************************************************************************
 *
 * Module: APP INTERFACE
 *
 * File Name: APP_INTERFACE.h
 *
 * Description: Header file for the functions that will be used on the main file
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              						Include Libraries						                   	*
 *******************************************************************************/

#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

/*******************************************************************************
 *                              						MCAL Libraries						                  	*
 *******************************************************************************/

#include <stdint.h>
#include "ERROR_STATUS.h"
#include "MACROS.h"
#include "TYPES.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "DELAY_INTERFACE.h"
#include "TIMER_interface.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER3_interface.h"
#include "TIMER3_private.h"
#include "NVIC_INTERFACE.h"
#include "USART_INTERFACE.h"

/*******************************************************************************
 *                              						HAL Libraries						          	           	*
 *******************************************************************************/

#include "MOTOR_INTERFACE.h"
#include "HCSR04_INTERFACE.h"

/*******************************************************************************
 *                              				APP Global Variables				           			     *
 *******************************************************************************/

#define CA_ADAS_FORWARD_STATE 	1
#define CA_ADAS_RIGHT_STATE 			2
#define CA_ADAS_LEFT_STATE 			3
#define CA_ADAS_REVERSE_STATE 	4
extern u8 	g_u8CollisionAvoidance_StateFlag;

#define CAR_OPERATION_AUTOPARKING 	1
#define CAR_OPERATION_AUTOPARKING_2 	2
#define CAR_OPERATION_COLLISIONAVOID	3
#define CAR_OPERATION_RCCAR		4
extern u8 g_u8CarOPMode_StateFlag;

/*******************************************************************************
 *                              				APP Function Declarations								   	*
 *******************************************************************************/

void APP_voidSystemInitialization(void);
void APP_voidCollisionAvoidance(void);
void APP_voidAutoParking(void);
void APP_voidAutoParking_MODE2(void);
void APP_voidRemoteControl(void);
void APP_voidUltrasonicUnitTest(void);
void APP_voidISRFunction(void);
void TIM2(void);
void TIM3(void);

#endif /* APP_INTERFACE_H_ */
