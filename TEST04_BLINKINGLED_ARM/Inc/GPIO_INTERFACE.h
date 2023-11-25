 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_INTERFACE.h
 *
 * Description: Header file for the GPIO Driver FUNCTION PROTOTYPES
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       		   *
 *******************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_CONFIG.h"

/*******************************************************************************
 *                              				GPIO Function Prototypes					               			     *
 *******************************************************************************/

// Initializes the RCC Module with the necessary Configurations

void GPIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Mode);

void GPIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8pinValue);

u8 GPIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID);



#endif
