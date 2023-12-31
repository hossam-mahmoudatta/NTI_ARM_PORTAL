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

#include "RCC_CONFIG.h"

/*******************************************************************************
 *                              						RCC Function Prototypes					               			     *
 *******************************************************************************/

// Initializes the RCC Module with the necessary Configurations
void RCC_voidInitialization_SYSTYPE(void);

// Chooses the clock type and enables it
void RCC_voidPeripheralClockEnable(u8 copy_u8BusID, u8 copy_u8PeripheralID);

// Chooses the clock type and disables it
void RCC_voidPeripheralClockDisable(u8 copy_u8BusID, u8 copy_u8PeripheralID);



#endif
