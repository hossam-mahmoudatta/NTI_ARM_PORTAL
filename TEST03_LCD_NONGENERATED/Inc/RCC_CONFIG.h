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

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

#include "RCC_PRIVATE.h"

/*******************************************************************************
 *                              						RCC Macro Definitions					               				     *
 *******************************************************************************/

// Choosing the Clock Type		##IMPORTANT##
#define RCC_CLOCKTYPE		RCC_HSE_CRYSTAL

// Choosing Clock Security Mode
#define CSSON_STATE		DISABLE

// HSI Configuration
#define HSION_STATE			ENABLE
#define HSIRDY_STATE		ENABLE

// HSE Configuration
#define HSEON_STATE		ENABLE
#define HSERDY_STATE		ENABLE

// PLL Configuration
#define PLL_STATE				ENABLE
#define PLL_RDY					ENABLE
#define PLL_SRC					ENABLE
#define PLL_XPTRE				ENABLE

// Declaring the System Clock Switch
#define CFGR_SW_STATE					CFGR_SW_HSI

// Declaring the System Clock Switch
#define CFGR_SWS_STATE				CFGR_SWS_HSI

// Declaring the AHB Prescaler
#define CFGR_HPRE_PRESCALER		CFGR_HPRE_DIV128

// Declaring the APB1 Prescaler
#define CFGR_PPRE1_PRESCALER		CFGR_PPRE1_DIV4

// Declaring the APB2 Prescaler
#define CFGR_PPRE2_PRESCALER		CFGR_PPRE2_DIV4

// Declaring the PLL CLOCK SOURCE
#define PLLSRC_SELECT					PLLSRC_HSE

// Declaring the HSE Divider for PLL Entry
#define PLLXPTRE_SELECT				PLLXPTRE_HSE_DIV

//	PLL Multiplication Factor
#define CFGR_PLLMUL_FACTOR			CFGR_PLLMULx6

// MCO (Microcontroller Clock Output)
#define CFGR_MSO_CLK						CFGR_MCO_HSICLK


#endif
