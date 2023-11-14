 /******************************************************************************
 *
 * Module: RCC (Reset & Clock Control)
 *
 * File Name: RCC_INTERFACE.h
 *
 * Description: Header file for the RCC Driver FUNCTION PROTOTYPES
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "GPIO_CONFIG.h"

/*******************************************************************************
 *                              						RCC Function Prototypes					               			     *
 *******************************************************************************/

// Initializes the RCC Module with the necessary Configurations

void GPIO_voidSetPinDirection(u8 copy_u8PinID, u8 copy_u8PortID, u8 copy_u8Mode);

void GPIO_voidSetPinValue(u8 copy_u8PinID, u8 copy_u8PortID, u8 copy_u8pinValue);

u8 GPIO_u8GetPinValue(u8 copy_u8PinID, u8 copy_u8PortID);



#endif
