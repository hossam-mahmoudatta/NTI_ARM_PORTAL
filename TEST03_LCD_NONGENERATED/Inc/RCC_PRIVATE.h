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

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              							RCC Registers					                   				     *
 *******************************************************************************/

typedef struct {
	u8 HSION: 	1;		// Internal high-speed clock enable
	u8 HSIRDY: 	1;		// Internal high-speed clock ready flag
	u8              : 	1;		// Res
	u8 HSITRIM: 	5;		// Internal high-speed clock trimming
	u8 HSICAL: 	8;		// Internal high-speed clock calibration
	u8 HSEON: 	1;		// HSE clock enable
	u8 HSERDY: 	1;		// External high-speed clock ready flag
	u8 HSEBYP: 	1;		// External high-speed clock bypass
	u8 CSSON: 	1;		// Clock security system enable
	u8              :	4;		// Res
	u8 PLLON:	1;		// PLL enable
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
#define RCC_CFGR_REG    	((volatile RCC_CFGR*) 0x40021004)			// RCC CLOCK CONFIG REGISTER

// Not Yet Declared, just defined registers
#define RCC_CIR_REG        			*((volatile u32*) 0x40021008)			// RCC Clock interrupt register
#define RCC_APB2RSTR_REG   	*((volatile u32*) 0x4002100C)			// RCC APB2 peripheral reset register
#define RCC_APB1RSTR_REG   	*((volatile u32*) 0x40021010)			// RCC APB1 peripheral reset register
#define RCC_AHBENR_REG     		*((volatile u32*)0x40021014)


#define APB2_IOPAEN				2		// IO PORT A clock enable
#define APB2_IOPBEN				3		// IO PORT B clock enable
#define APB2_IOPCEN				4		// IO PORT C clock enable
#define APB2_IOPDEN				5		// IO PORT D clock enable
#define APB2_IOPEEN				6		// IO PORT E clock enable
#define APB2_IOPFEN				9		// IO PORT F clock enable
#define APB2_IOPGEN				10		// IO PORT G clock enable
#define APB2_TIM1EN				11		// TIMER 1 clock enable
#define APB2_USART1EN		14		// USART 1 clock enable
#define RCC_APB2ENR_REG   	*((volatile u32*)0x40021018)


#define APB1_TIM2EN				0		// IO PORT A clock enable
#define APB1_TIM3EN				1		// IO PORT B clock enable
#define APB1_TIM4EN				2		// IO PORT C clock enable
#define APB1_TIM5EN				3		// IO PORT D clock enable
#define APB1_TIM6EN				4		// IO PORT E clock enable
#define APB1_TIM7EN				5		// IO PORT F clock enable
#define APB1_UART2EN			17		// IO PORT F clock enable
#define APB1_UART3EN			18		// IO PORT F clock enable
#define APB1_UART4EN			19		// IO PORT F clock enable
#define APB1_UART5EN			20		// IO PORT F clock enable
#define RCC_APB1ENR_REG    	*((volatile u32*)0x4002101C)

#define RCC_BDCR_REG       		*((volatile u32*)0x40021020)			// RCC Backup domain control register
#define RCC_CSR_REG       		*((volatile u32*)0x40021024)			// RCC Control/status register

/*******************************************************************************
 *                              					RCC Configurations					                   				     *
 *******************************************************************************/

// Choosing the Clock Type		##IMPORTANT##
#define RCC_HSI						0
#define RCC_HSE_CRYSTAL	1
#define RCC_HSE_RC				2
#define RCC_PLL						4

// Defining Buses
#define RCC_AHB       0
#define RCC_APB1      1
#define RCC_APB2      2

// Declaring the System Clock Switch
#define CFGR_SW_HSI 		0b00
#define CFGR_SW_HSE 		0b01
#define CFGR_SW_PLL 		0b10

// Declaring the System Clock Switch
#define CFGR_SWS_HSI 		0b00
#define CFGR_SWS_HSE 		0b01
#define CFGR_SWS_PLL 		0b10

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

// Declaring the APB1 Prescaler
#define CFGR_PPRE1_DIV0 	0b000
#define CFGR_PPRE1_DIV2		0b100
#define CFGR_PPRE1_DIV4		0b101
#define CFGR_PPRE1_DIV8		0b110
#define CFGR_PPRE1_DIV16		0b111

// Declaring the APB2 Prescaler
#define CFGR_PPRE2_DIV0 	0b000
#define CFGR_PPRE2_DIV2		0b100
#define CFGR_PPRE2_DIV4	0b101
#define CFGR_PPRE2_DIV8		0b110
#define CFGR_PPRE2_DIV16	0b111

// Declaring the PLL CLOCK SOURCE
#define PLLSRC_HSI 	0
#define PLLSRC_HSE	1

// Declaring the HSE Divider for PLL Entry
#define PLLXPTRE_HSE_NOTDIV 	0
#define PLLXPTRE_HSE_DIV			1

//	PLL Multiplication Factor
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

// MCO (Microcontroller Clock Output)
#define CFGR_MCO_NOCLK		0b000
#define CFGR_MCO_SYSCLK		0b100
#define CFGR_MCO_HSICLK		0b101
#define CFGR_MCO_HSECLK		0b110
#define CFGR_MCO_PLLCLK		0b111

#endif







//typedef struct {
//	u8 DMA1EN	: 1;		// DMA1 clock enable
//	u8 DMA2EN: 1;		// DMA2 clock enable
//	u8 SRAMEN: 1;		// SRAM interface clock enable
//	u8                : 1;		// Res
//	u8 FLITFEN	: 1; 		// FLITF clock enable
//	u8              	: 1;		// Res
//	u8 CRCEN	: 1;		// CRC clock enable
//	u8             	: 1;		// Res
//	u8 FSMCEN: 1;		// FSMC clock enable
//	u8               	: 1;		// Res
//	u8 SDIOEN	: 1;		// SDIO clock enable
//	u32 				: 21;		// Res
//} RCC_AHBENR;
//#define RCC_AHBENR_REG     	((volatile RCC_AHBENR*) 0x40021014)			// RCC AHB peripheral clock enable register


//typedef struct {
//	u8 AFIOEN	: 1;		// Alternate function IO clock enable
//	u8          : 1;		// Res
//	u8 IOPAEN	: 1;		// IO PORT A clock enable
//	u8 IOPBEN	: 1;		// IO PORT B clock enable
//	u8 IOPCEN	: 1;		// IO PORT C clock enable
//	u8 IOPDEN	: 1;		// IO PORT D clock enable
//	u8 IOPEEN	: 1;		// IO PORT E clock enable
//	u8 IOPFEN	: 1;		// IO PORT F clock enable
//	u8 IOPGEN	: 1;		// IO PORT G clock enable
//	u8 ADC1EN	: 1;		// ADC 1 clock enable
//	u8 ADC2EN	: 1;		// ADC 2 clock enable
//	u8 TIM1EN	: 1;		// TIM 1 clock enable
//	u8 SPI1EN	: 1;		// SPI 1 clock enable
//	u8 TIM8EN	: 1;		// TIM 8 clock enable
//	u8 USART1EN	: 1;	// USART 1 clock enable
//	u8 ADC3EN	: 1;		// ADC 3 clock enable
//	u8                : 3;		// Res
//	u8 TIM9EN	: 1;		// TIM 9 clock enable
//	u8 TIM10EN	: 1;		// TIM 10 clock enable
//	u8 TIM11EN	: 1;		// TIM 11 clock enable
//	u16                : 10;		// Res
//} RCC_APB2ENR;
//#define RCC_APB2ENR_REG   	((volatile RCC_APB2ENR*) 0x40021018)			// RCC APB2 peripheral clock enable register


//typedef struct {
//	u8 TIM2EN	: 1;		// TIM 2 clock enable
//	u8 TIM3EN	: 1;		// TIM 3 clock enable
//	u8 TIM4EN	: 1;		// TIM 4 clock enable
//	u8 TIM5EN	: 1;		// TIM 5 clock enable
//	u8 TIM6EN	: 1;		// TIM 6 clock enable
//	u8 TIM7EN	: 1;		// TIM 7 clock enable
//	u8 TIM12EN	: 1;		// TIM 12 clock enable
//	u8 TIM13EN	: 1;		// TIM 13 clock enable
//	u8 TIM14EN	: 1;		// TIM 14 clock enable
//	u8                : 2;		// Res
//	u8 WWDGEN	: 1;		// IO PORT A clock enable
//	u8                : 2;		// Res
//	u8 SPI2EN	: 1;		// SPI 2 clock enable
//	u8 SPI3EN	: 1;		// SPI 3 clock enable
//	u8                : 1;		// Res
//	u8 USART2EN	: 1;	// USART 2 clock enable
//	u8 USART3EN	: 1;	// USART 3 clock enable
//	u8 USART4EN	: 1;	// USART 4 clock enable
//	u8 USART5EN	: 1;	// USART 5 clock enable
//	u8 I2C1EN	: 1;		// I2C 1 clock enable
//	u8 I2C2EN	: 1;		// I2C 2 clock enable
//	u8 USBEN	: 1;		// USB clock enable
//	u8                : 1;		// Res
//	u8 CANEN	: 1;		// CAN clock enable
//	u8                : 1;		// Res
//	u8 BKPEN	: 1;		// Backup interface clock enable
//	u8 PWREN	: 1;		// Power interface clock enable
//	u8 DACEN	: 1;		// DAC interface clock enable
//	u8                : 2;		// Res
//} RCC_APB1ENR;
//#define RCC_APB1ENR_REG    	((volatile RCC_APB1ENR*) 0x4002101C)		// RCC APB1 peripheral clock enable register

