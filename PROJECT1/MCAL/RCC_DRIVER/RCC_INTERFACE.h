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

// Chooses the clok type and enables it
void RCC_voidEnableClock(u8 copy_BusID, u8 copy_PeripheralID);



#endif
