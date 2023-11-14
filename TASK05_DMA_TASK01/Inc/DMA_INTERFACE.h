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
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#include <DMA_CONFIG.h>

/*******************************************************************************
 *                              						RCC Function Prototypes					               			     *
 *******************************************************************************/

// Initializes the RCC Module with the necessary Configurations
void SYSTICK_voidInitialization(void);

// Chooses the clock type and enables it
void SYSTICK_voidSetDelay_ms(u32 copy_u32Delay);

// Chooses the clock type and disables it
void SYSTICK_voidSetDelay_ms_ISR(u32 copy_u32Delay, void(*Copy_voidPTF)(void));

void SysTick_Handler(void);


#endif
