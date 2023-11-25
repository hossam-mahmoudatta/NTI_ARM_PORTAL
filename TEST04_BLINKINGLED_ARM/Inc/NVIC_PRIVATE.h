 /******************************************************************************
 *
 * Module: NVIC (NESTED VECTOR INTERRUPT)
 *
 * File Name: NVIC_PRIVATE.h
 *
 * Description: Header file for NVIC Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              							NVIC Registers					                   				     *
 *******************************************************************************/

typedef struct
{
	volatile u32 NVIC_ISER    [ 32 ];		// Interrupt Set Enable Bits
	volatile u32 NVIC_ICER    [ 32 ];	// Interrupt Clear Enable Bits
	volatile u32 NVIC_ISPR    [ 32 ];		// Interrupt Set Pending Bits
	volatile u32 NVIC_ICPR    [ 32 ];		// Interrupt Clear Pending Bits
	volatile u32 NVIC_IAPR    [ 32 ];		// Interrupt Active Flags
	volatile u32 RESERVED [ 32 ];		// Reserved
	volatile u8 	NVIC_IPR      [ 128];		// Interrupt Priority Registers
} NVIC;
#define NVIC_REG      ((volatile NVIC *) 0xE000E100)

// Software Generated Interrupt IDs
#define NVIC_STIR  		((volatile u32*) 0xE000EF00)

//SCB
typedef struct{
	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMFAR;
	volatile u32 BFAR;
} SCB;
#define SCB_REG ((volatile SCB*) 0xE000ED00)



#endif /* NVIC_PRIVATE_H_ */
