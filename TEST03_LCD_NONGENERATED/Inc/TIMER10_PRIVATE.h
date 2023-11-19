 /******************************************************************************
 *
 * Module: TIMER10
 *
 * File Name: TIMER10_PRIVATE.h
 *
 * Description: Header file for the TIMER10 Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						               		   *
 *******************************************************************************/

#ifndef TIMER10_PRIVATE_H
#define TIMER10_PRIVATE_H

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              				TIMER 10-11 Registers					                   		*
 *******************************************************************************/

typedef struct
{
	volatile u32 TIMx_CR1;
	volatile u32 TIMx_RES;
	volatile u32 TIMx_SMCR;
	volatile u32 TIMx_DIER;
	volatile u32 TIMx_SR;
	volatile u32 TIMx_EGR;
	volatile u32 TIMx_CCMR1;
	volatile u32 TIMx_RES2;
	volatile u32 TIMx_CCER;
	volatile u32 TIMx_CNT;
	volatile u32 TIMx_PSC;
	volatile u32 TIMx_ARR;
	volatile u32 TIMx_RES3;
	volatile u32 TIMx_CCR1;
} TIMERx_REGISTERS;

#define TIMER10_REG	((volatile TIMERx_REGISTERS*) 0x40015000)	// TIMER10 Pointer to TIMERx Registers
#define TIMER11_REG	((volatile TIMERx_REGISTERS*) 0x40015400)	// TIMER11 Pointer to TIMERx Registers


#endif
