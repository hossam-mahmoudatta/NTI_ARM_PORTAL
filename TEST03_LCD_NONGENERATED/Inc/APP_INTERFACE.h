/******************************************************************************
 *
 * Module: APP PROGRAM
 *
 * File Name: APP_INTERFACE.c
 *
 * Description: Header file for the functions that will be used on the main file
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       	*
 *******************************************************************************/

#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

/*******************************************************************************
 *                              						MCAL Libraries						                  	*
 *******************************************************************************/

#include <stdint.h>
#include "TIMER2_INTERFACE.h"
#include "TIMER3_INTERFACE.h"
#include "TIMER4_INTERFACE.h"

#include "ERROR_STATUS.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "DELAY_INTERFACE.h"
#include "NVIC_INTERFACE.h"
#include "USART_INTERFACE.h"

/*******************************************************************************
 *                              						HAL Libraries						          	           	*
 *******************************************************************************/

#include "HCSR04_INTERFACE.h"
#include "MOTOR_INTERFACE.h"
//#include "LCD_INTERFACE.h"

/*******************************************************************************
 *                              				APP Function Declarations								   	*
 *******************************************************************************/

void APP_voidSystemInitialization(void);
void APP_voidCollisionAvoidance(void);
void APP_voidAutoParking(void);
void APP_voidRCCar(void);
void APP_voidISRFunction(void);
void TIM2_voidCallBack(void);
void TIM3_voidCallBack(void);

#endif /* APP_INTERFACE_H_ */
