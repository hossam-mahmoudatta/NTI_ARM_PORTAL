 /******************************************************************************
 *
 * Module: GPIO Module
 *
 * File Name: GPIO_PRIVATE.h
 *
 * Description: Header file for the GPIO Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              							GPIO Registers					                   				     *
 *******************************************************************************/

// GPIO CRL Register
typedef union
{
	struct {
		volatile u32 PIN0_MODE: 		2;
		volatile u32 PIN0_CONFIG: 	2;
		volatile u32 PIN1_MODE: 		2;
		volatile u32 PIN1_CONFIG: 	2;
		volatile u32 PIN2_MODE: 		2;
		volatile u32 PIN2_CONFIG: 	2;
		volatile u32 PIN3_MODE: 		2;
		volatile u32 PIN3_CONFIG: 	2;
		volatile u32 PIN4_MODE: 		2;
		volatile u32 PIN4_CONFIG: 	2;
		volatile u32 PIN5_MODE: 		2;
		volatile u32 PIN5_CONFIG: 	2;
		volatile u32 PIN6_MODE: 		2;
		volatile u32 PIN6_CONFIG: 	2;
		volatile u32 PIN7_MODE: 		2;
		volatile u32 PIN7_CONFIG: 	2;
	};
	volatile u32 CRL_u32Value;
} GPIOx_CRL_CONFIG;


// GPIO CRH Register
typedef union {
	struct
	{
		volatile u32 PIN8_MODE: 		2;
		volatile u32 PIN8_CONFIG: 	2;
		volatile u32 PIN9_MODE: 		2;
		volatile u32 PIN9_CONFIG: 	2;
		volatile u32 PIN10_MODE: 	2;
		volatile u32 PIN10_CONFIG: 	2;
		volatile u32 PIN11_MODE: 		2;
		volatile u32 PIN11_CONFIG: 	2;
		volatile u32 PIN12_MODE: 	2;
		volatile u32 PIN12_CONFIG: 	2;
		volatile u32 PIN13_MODE: 		2;
		volatile u32 PIN13_CONFIG: 	2;
		volatile u32 PIN14_MODE: 	2;
		volatile u32 PIN14_CONFIG: 	2;
		volatile u32 PIN15_MODE: 	2;
		volatile u32 PIN15_CONFIG: 	2;
	};
	volatile u32 CRH_u32Value;
} GPIOx_CRH_CONFIG;


// GPIO IDR Register
typedef union
{
	struct {
		volatile u32 IDR0: 			1;
		volatile u32 IDR1: 			1;
		volatile u32 IDR2: 			1;
		volatile u32 IDR3: 			1;
		volatile u32 IDR4: 			1;
		volatile u32 IDR5: 			1;
		volatile u32 IDR6: 			1;
		volatile u32 IDR7: 			1;
		volatile u32 IDR8: 			1;
		volatile u32 IDR9: 			1;
		volatile u32 IDR10: 			1;
		volatile u32 IDR11: 			1;
		volatile u32 IDR12: 			1;
		volatile u32 IDR13: 			1;
		volatile u32 IDR14: 			1;
		volatile u32 IDR15: 			1;
		volatile u32      :			16;
	};
	volatile u32 IDR_u32Value;
} GPIOx_IDR_CONFIG;


// GPIO ODR Register
typedef union
{
	struct {
		volatile u32 ODR0: 			1;
		volatile u32 ODR1: 			1;
		volatile u32 ODR2: 			1;
		volatile u32 ODR3: 			1;
		volatile u32 ODR4: 			1;
		volatile u32 ODR5: 			1;
		volatile u32 ODR6: 			1;
		volatile u32 ODR7: 			1;
		volatile u32 ODR8: 			1;
		volatile u32 ODR9: 			1;
		volatile u32 ODR10: 			1;
		volatile u32 ODR11: 			1;
		volatile u32 ODR12: 			1;
		volatile u32 ODR13: 			1;
		volatile u32 ODR14: 			1;
		volatile u32 ODR15: 			1;
		volatile u32      :			16;
	};
	volatile u32 ODR_u32Value;
} GPIOx_ODR_CONFIG;


// Contains all the GPIO Registers
typedef struct {
	GPIOx_CRL_CONFIG  	GPIOx_CRL;		// Port configuration register low
	GPIOx_CRH_CONFIG 	GPIOx_CRH;			// Port configuration register high
	volatile u32 	GPIOx_IDR;			// Port input data register
	volatile u32 	GPIOx_ODR;			// Port output data register
	volatile u32 	GPIOx_BSRR;						// Port bit set / reset register
	volatile u32 	GPIOx_BRR;						// Port bit reset register
	volatile u32 	GPIOx_LCKR;						// Port lock register
} GPIOx_GENERAL_REG;

#define GPIO_A_REG	((volatile GPIOx_GENERAL_REG*) 0x40010800)		// GPIO PORT A Register
#define GPIO_B_REG	((volatile GPIOx_GENERAL_REG*) 0x40010C00)		// GPIO PORT B Register
#define GPIO_C_REG	((volatile GPIOx_GENERAL_REG*) 0x40011000)		// GPIO PORT C Register

#define GPIO_A_IDR	((volatile GPIOx_GENERAL_REG*) 0x40010800 + 0x08)		// GPIO PORT A Register
#define GPIO_B_IDR		((volatile GPIOx_GENERAL_REG*) 0x40010C00 + 0x08)		// GPIO PORT C Register
#define GPIO_C_IDR	((volatile GPIOx_GENERAL_REG*) 0x40011000 + 0x08)		// GPIO PORT C Register

#define GPIO_A_ODR	((volatile GPIOx_GENERAL_REG*) 0x40010800 + 0x0C)		// GPIO PORT A Register
#define GPIO_B_ODR	((volatile GPIOx_GENERAL_REG*) 0x40010C00 + 0x0C)		// GPIO PORT C Register
#define GPIO_C_ODR	((volatile GPIOx_GENERAL_REG*) 0x40011000 + 0x0C)		// GPIO PORT C Register

#endif




//typedef struct {
//	u32 PIN0_MODE: 		2;
//	u32 PIN0_CONFIG: 	2;
//	u32 PIN1_MODE: 		2;
//	u32 PIN1_CONFIG: 	2;
//	u32 PIN2_MODE: 		2;
//	u32 PIN2_CONFIG: 	2;
//	u32 PIN3_MODE: 		2;
//	u32 PIN3_CONFIG: 	2;
//	u32 PIN4_MODE: 		2;
//	u32 PIN4_CONFIG: 	2;
//	u32 PIN5_MODE: 		2;
//	u32 PIN5_CONFIG: 	2;
//	u32 PIN6_MODE: 		2;
//	u32 PIN6_CONFIG: 	2;
//	u32 PIN7_MODE: 		2;
//	u32 PIN7_CONFIG: 	2;
//} GPIOx_CRL_PINS;
