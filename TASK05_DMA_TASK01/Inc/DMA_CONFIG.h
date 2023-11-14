 /******************************************************************************
 *
 * Module: RCC (Reset & Clock Control)
 *
 * File Name: RCC_CONFIG.h
 *
 * Description: Header file for the RCC Driver MACRO DECLARATIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

#include <DMA_PRIVATE.h>

/*******************************************************************************
 *                              						RCC Macro Definitions					               				     *
 *******************************************************************************/
// Choosing the Clock Type		##IMPORTANT##

#define DMA_CH_DISABLE		0
#define DMA_CH_ENABLE		1
#define SYSTICK_COUNTER_DISABLE 0
#define SYSTICK_COUNTER_ENABLE 	1

#define SYSTICK_TICKINT_DISABLE 0
#define SYSTICK_TICKINT_ENABLE 	1

#define SYSTICK_CLKSOURCE_AHB8  0
#define SYSTICK_CLKSOURCE_AHB   1

#define SYSTICK_ISR_ENABLE 		1


#define SYSTICK_TICKS     		8000

#endif
