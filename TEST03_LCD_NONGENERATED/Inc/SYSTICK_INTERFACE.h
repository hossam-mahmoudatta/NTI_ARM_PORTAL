 /******************************************************************************
 *
 * Module: STK (SYSTICK)
 *
 * File Name: STK_INTERFACE.h
 *
 * Description: Header file for the SYSTICK Driver FUNCTION PROTOTYPES
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              						Include Libraries						                       		   *
 *******************************************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#include "SYSTICK_CONFIG.h"

/*******************************************************************************
 *                              					RCC Function Prototypes					               			     *
 *******************************************************************************/

// Initializes the RCC Module with the necessary Configurations
void STK_voidInitialization(void);

// Chooses the clock type and enables it
void STK_voidSetDelay_ms(u32 copy_u32Delay);

// Chooses the clock type and disables it
void STK_voidSetDelay_ms_ISR(u32 copy_u32Delay, void(*Copy_voidPTF)(void));

// Enable Interrupt
void STK_voidEnableInterrupt(void);

// Disables Interrupt
void STK_voidDisableInterrupt(void);

// Callback Function that will be passed to the ISR
void STK_CallBackFunction(void (*Ptr_STK)(void));

// The ISR Handler for the SYSTICK
void SysTick_Handler(void);


#endif
