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

#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

#include "SYSTICK_PRIVATE.h"

/*******************************************************************************
 *                              						RCC Macro Definitions					               				     *
 *******************************************************************************/
// Choosing the Clock Type		##IMPORTANT##

#define STK_LOAD_INITIAL					0x00FFFFFF
#define STK_VAL_INITIAL					0

#define STK_CLKSOURCE_AHB8  	0
#define STK_CLKSOURCE_AHB   	1
#define CLKSOURCE_SELECT   		STK_CLKSOURCE_AHB8

#define STK_ISR_ENABLE 		0

#define STK_1MHZ_TICKS			1000
#define STK_8MHZ_TICKS			8000
#define STK_72MHZ_TICKS			72000
#define STK_TICKS     				STK_1MHZ_TICKS

#endif
