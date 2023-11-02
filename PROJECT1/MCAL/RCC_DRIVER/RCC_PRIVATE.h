 /******************************************************************************
 *
 * Module: RCC (Reset & Clock Control)
 *
 * File Name: RCC_PRIVATE.h
 *
 * Description: Header file for the RCC Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

/*******************************************************************************
 *                              							RCC Registers					                   				     *
 *******************************************************************************/

typedef struct {
	u8 HSION: 		1;		// Internal high-speed clock enable
	u8 HSIRDY: 	1;		// Internal high-speed clock ready flag
	u8              : 	1;		// Res
	u8 HSITRIM: 	5;		// Internal high-speed clock trimming
	u8 HSICAL: 	8; 	// Internal high-speed clock calibration
	u8 HSEON: 		1;		// HSE clock enable
	u8 HSERDY: 	1;		// External high-speed clock ready flag
	u8 HSEBYP: 	1;		// External high-speed clock bypass
	u8 CSSON: 		1;		// Clock security system enable
	u8              :		4;		// Res
	u8 PLLON:		1;		// PLL enable
	u8 PLLRDY: 	1;		// PLL Clock Ready Flag
	u8              : 	6;		// Waveform Generation Mode
} RCC_CR;
#define RCC_CR_REG      ((volatile RCC_CR*) 0x40021000)			// RCC CLOCK CONTROL REGISTER

typedef struct {
	u8 SW: 			2;		// System clock switch
	u8 SWS: 			2;		// System clock switch status
	u8 HPRE:		 	4;		// AHB prescaler
	u8 PPRE1: 		3;		// APB low-speed prescaler (APB1)
	u8 PPRE2: 		3; 		// APB high-speed prescaler (APB2)
	u8 ADCPRE: 	2;		// ADC prescaler
	u8 PLLSRC: 	1;		// PLL entry clock source
	u8 PLLXTPRE: 1;		// HSE divider for PLL entry
	u8 PLLMUL: 	4;		// PLL multiplication factor, doesnt exceed 72 MHz
	u8 USBPRE:		1;		// USB prescaler
	u8              :		1;		// Res
	u8 MCO: 			3;		// Microcontroller clock output
	u8              : 	5;		// Res
} RCC_CFGR;
#define RCC_CFGR_REG    	((volatile RCC_CFGR*)0x40021004)			// RCC CLOCK CONFIG REGISTER



// Not Yet Declared, just defined registers
#define RCC_CIR_REG        			*((volatile u32*)0x40021008)			// RCC Clock interrupt register
#define RCC_APB2RSTR_REG   	*((volatile u32*)0x4002100C)			// RCC APB2 peripheral reset register
#define RCC_APB1RSTR_REG   	*((volatile u32*)0x40021010)			// RCC APB1 peripheral reset register
#define RCC_AHBENR_REG     	*((volatile u32*)0x40021014)			// RCC AHB peripheral clock enable register
#define RCC_APB2ENR_REG   	*((volatile u32*)0x40021018)			// RCC APB2 peripheral clock enable register
#define RCC_APB1ENR_REG    	*((volatile u32*)0x4002101C)			// RCC APB1 peripheral clock enable register
#define RCC_BDCR_REG       		*((volatile u32*)0x40021020)			// RCC Backup domain control register
#define RCC_CSR_REG       		*((volatile u32*)0x40021024)			// RCC Control/status register




#endif
