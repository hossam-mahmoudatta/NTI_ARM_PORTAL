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
#define RCC_HSI						0
#define RCC_HSE_CRYSTAL	1
#define RCC_HSE_RC				2
#define RCC_PLL						4
#define RCC_CLOCKTYPE		RCC_HSI

#define RCC_AHB       0
#define RCC_APB1      1
#define RCC_APB2      2


// Enabling and Disabling bits for Initializations
#define RCC_DISABLE		0
#define RCC_ENABLE			1

#define PERIPHERAL_DISABLE		0
#define PERIPHERAL_ENABLE		1

#define HSION_STATE		RCC_ENABLE
#define HSIRDY_STATE		RCC_ENABLE

#define HSEON_STATE		RCC_ENABLE
#define HSERDY_STATE		RCC_ENABLE

#define HSEBYP_DISABLE	0
#define HSEBYP_ENABLE	1

#define CSSON_STATE		RCC_ENABLE

#define PLL_STATE				RCC_ENABLE
#define PLL_RDY					RCC_ENABLE
#define PLL_SRC					RCC_ENABLE
#define PLL_XPTRE				RCC_ENABLE


// Declaring the System Clock Switch
#define CFGR_SW_HSI 		0b00
#define CFGR_SW_HSE 		0b01
#define CFGR_SW_PLL 		0b10
#define CFGR_SW_STATE	CFGR_SW_HSI

// Declaring the System Clock Switch
#define CFGR_SWS_HSI 		0b00
#define CFGR_SWS_HSE 		0b01
#define CFGR_SWS_PLL 		0b10
#define CFGR_SWS_STATE	CFGR_SWS_HSI

// Declaring the AHB Prescaler
#define CFGR_HPRE_DIV0  	0b0000
#define CFGR_HPRE_DIV2		0b1000
#define CFGR_HPRE_DIV4 		0b1001
#define CFGR_HPRE_DIV8 		0b1010
#define CFGR_HPRE_DIV16 	0b1011
#define CFGR_HPRE_DIV64 	0b1100
#define CFGR_HPRE_DIV128 	0b1101
#define CFGR_HPRE_DIV256 	0b1110
#define CFGR_HPRE_DIV512 	0b1111
#define CFGR_HPRE_PRESCALER		CFGR_HPRE_DIV128

// Declaring the APB1 Prescaler
#define CFGR_PPRE1_DIV0 	0b000
#define CFGR_PPRE1_DIV2		0b100
#define CFGR_PPRE1_DIV4		0b101
#define CFGR_PPRE1_DIV8		0b110
#define CFGR_PPRE1_DIV16	0b111
#define CFGR_PPRE1_PRESCALER		CFGR_PPRE1_DIV4

// Declaring the APB2 Prescaler
#define CFGR_PPRE2_DIV0 	0b000
#define CFGR_PPRE2_DIV2		0b100
#define CFGR_PPRE2_DIV4	0b101
#define CFGR_PPRE2_DIV8		0b110
#define CFGR_PPRE2_DIV16	0b111
#define CFGR_PPRE2_PRESCALER		CFGR_PPRE2_DIV4

// Declaring the PLL CLOCK SOURCE
#define PLLSRC_HSI 	0
#define PLLSRC_HSE	1
#define PLLSRC_SELECT	PLLSRC_HSE

// Declaring the HSE Divider for PLL Entry
#define PLLXPTRE_HSE_NOTDIV 	0
#define PLLXPTRE_HSE_DIV			1
#define PLLXPTRE_SELECT			PLLXPTRE_HSE_DIV

//		PLL multiplication factor
#define CFGR_PLLMULx2		0b0000
#define CFGR_PLLMULx3 		0b0001
#define CFGR_PLLMULx4		0b0010
#define CFGR_PLLMULx5		0b0011
#define CFGR_PLLMULx6		0b0100
#define CFGR_PLLMULx7		0b0101
#define CFGR_PLLMULx8		0b0110
#define CFGR_PLLMULx9		0b0111
#define CFGR_PLLMULx10		0b1000
#define CFGR_PLLMULx11		0b1001
#define CFGR_PLLMULx12		0b1010
#define CFGR_PLLMULx13		0b1011
#define CFGR_PLLMULx14		0b1100
#define CFGR_PLLMULx15		0b1101
#define CFGR_PLLMULx16		0b1110
#define CFGR_PLLMUL_FACTOR		CFGR_PLLMULx6

// MCO (Microcontroller Clock Output)
#define CFGR_MCO_NOCLK		0b000
#define CFGR_MCO_SYSCLK		0b100
#define CFGR_MCO_HSICLK		0b101
#define CFGR_MCO_HSECLK		0b110
#define CFGR_MCO_PLLCLK		0b111
#define CFGR_MSO_CLK			CFGR_MCO_HSICLK


#endif
