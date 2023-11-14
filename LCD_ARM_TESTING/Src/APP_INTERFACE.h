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

#include "../Inc/MCAL/RCC_DRIVER/RCC_INTERFACE.h"
#include "../Inc/MCAL/SYSTICK_DRIVER/SYSTICK_INTERFACE.h"
#include "../Inc/MCAL/GPIO_DRIVER/GPIO_INTERFACE.h"

/*******************************************************************************
 *                              						HAL Libraries						          	           	*
 *******************************************************************************/

#include "../Inc/HAL/LCD_DRIVER/LCD_INTERFACE.h"

/*******************************************************************************
 *                              				APP Function Declarations								   	*
 *******************************************************************************/

void APP_voidSystemInitialization(void);
void APP_voidExecution(void);
void APP_voidISRFunction(void);

#endif /* APP_INTERFACE_H_ */
