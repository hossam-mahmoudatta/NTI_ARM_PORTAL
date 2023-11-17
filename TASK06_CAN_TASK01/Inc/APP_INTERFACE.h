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

#include "RCC_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "STD_FUNCTIONS.h"

/*******************************************************************************
 *                              						HAL Libraries						          	           	*
 *******************************************************************************/

#include "LCD_INTERFACE.h"

/*******************************************************************************
 *                              				APP Function Declarations								   	*
 *******************************************************************************/

void APP_voidSystemInitialization(void);
void APP_voidExecution(void);
void APP_voidISRFunction(void);

#endif /* APP_INTERFACE_H_ */
