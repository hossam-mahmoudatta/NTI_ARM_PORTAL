 /******************************************************************************
 *
 * Module: GPIO Module
 *
 * File Name: GPIO_PRIVATE.h
 *
 * Description: Header file for the RCC Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*******************************************************************************
 *                              							RCC Registers					                   				     *
 *******************************************************************************/

typedef struct {
	volatile u32 GPIOx_CRL;
	volatile u32 GPIOx_CRH;
	volatile u32 GPIOx_IDR;
	volatile u32 GPIOx_ODR;
	volatile u32 GPIOx_BSRR;
	volatile u32 GPIOx_BRR;
	volatile u32 GPIOx_LCKR;
} GPIOx_GENERAL_REG;

#define GPIO_A_REG	((volatile GPIOx_GENERAL_REG*) 0x40010800)	// GPIO PORT A Register
#define GPIO_B_REG	((volatile GPIOx_GENERAL_REG*) 0x40010C00)
#define GPIO_C_REG	((volatile GPIOx_GENERAL_REG*) 0x40010000)

typedef struct {
	u8 PIN0_MODE: 		2;
	u8 PIN0_CONFIG: 	2;
	u8 PIN1_MODE: 		2;
	u8 PIN1_CONFIG: 	2;
	u8 PIN2_MODE: 		2;
	u8 PIN2_CONFIG: 	2;
	u8 PIN3_MODE: 		2;
	u8 PIN3_CONFIG: 	2;
	u8 PIN4_MODE: 		2;
	u8 PIN4_CONFIG: 	2;
	u8 PIN5_MODE: 		2;
	u8 PIN5_CONFIG: 	2;
	u8 PIN6_MODE: 		2;
	u8 PIN6_CONFIG: 	2;
	u8 PIN7_MODE: 		2;
	u8 PIN7_CONFIG: 	2;
} GPIOx_CRL_PINS;
#define GPIO_A_CRL_REG		((volatile GPIOx_CRL_PINS*) 0x40010800)			// GPIO PORT A Register


typedef struct {
	u8 PIN8_MODE: 		2;
	u8 PIN8_CONFIG: 	2;
	u8 PIN9_MODE: 		2;
	u8 PIN9_CONFIG: 	2;
	u8 PIN10_MODE: 		2;
	u8 PIN10_CONFIG: 	2;
	u8 PIN11_MODE: 		2;
	u8 PIN11_CONFIG: 	2;
	u8 PIN12_MODE: 		2;
	u8 PIN12_CONFIG: 	2;
	u8 PIN13_MODE: 		2;
	u8 PIN13_CONFIG: 	2;
	u8 PIN14_MODE: 		2;
	u8 PIN14_CONFIG: 	2;
	u8 PIN15_MODE: 		2;
	u8 PIN15_CONFIG: 	2;
} GPIOx_CRH_PINS;
#define GPIO_A_CRH_REG		((volatile GPIOx_CRH_PINS*) 0x40010804)			// GPIO PORT A Register


typedef struct {
	u8 IDR0: 			1;
	u8 IDR1: 			1;
	u8 IDR2: 			1;
	u8 IDR3: 			1;
	u8 IDR4: 			1;
	u8 IDR5: 			1;
	u8 IDR6: 			1;
	u8 IDR7: 			1;
	u8 IDR8: 			1;
	u8 IDR9: 			1;
	u8 IDR10: 			1;
	u8 IDR11: 			1;
	u8 IDR12: 			1;
	u8 IDR13: 			1;
	u8 IDR14: 			1;
	u8 IDR15: 			1;
	u16      :			16;
} GPIOx_IDR_PINS;
#define GPIO_A_IDR_REG		((volatile GPIOx_IDR_PINS*) 0x40010808)			// GPIO PORT A Register


typedef struct {
	u8 ODR0: 			1;
	u8 ODR1: 			1;
	u8 ODR2: 			1;
	u8 ODR3: 			1;
	u8 ODR4: 			1;
	u8 ODR5: 			1;
	u8 ODR6: 			1;
	u8 ODR7: 			1;
	u8 ODR8: 			1;
	u8 ODR9: 			1;
	u8 ODR10: 			1;
	u8 ODR11: 			1;
	u8 ODR12: 			1;
	u8 ODR13: 			1;
	u8 ODR14: 			1;
	u8 ODR15: 			1;
	u16      :			16;
} GPIOx_ODR_PINS;
#define GPIO_A_ODR_REG		((volatile GPIOx_ODR_PINS*) 0x4001080C)			// GPIO PORT A Register

#endif
