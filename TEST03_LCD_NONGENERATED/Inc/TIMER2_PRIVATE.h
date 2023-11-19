 /******************************************************************************
 *
 * Module: TIMER2 Module
 *
 * File Name: TIMER2_PRIVATE.h
 *
 * Description: Header file for the TIMER2 Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              							TIMER2 Registers					                   				     *
 *******************************************************************************/

#define TIMER2_BASE_ADDRESS      0x40000000

#define TIMER2_CR1                           	*((volatile u32*)(TIMER2_BASE_ADDRESS +0x00))
#define TIMER2_DIER                          	*((volatile u32*)(TIMER2_BASE_ADDRESS +0x0C))
#define TIMER2_SR                            	*((volatile u32*)(TIMER2_BASE_ADDRESS +0x10))
#define TIMER2_CCER                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x20))
#define TIMER2_SMCR                         *((volatile u32*)(TIMER2_BASE_ADDRESS +0x08))

#define TIMER2_CCMR1                       *((volatile u32*)(TIMER2_BASE_ADDRESS +0x18))
#define TIMER2_CCMR2                       *((volatile u32*)(TIMER2_BASE_ADDRESS +0x1C))
#define TIMER2_CCER                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x20))
#define TIMER2_PSC 						 	 *((volatile u32*)(TIMER2_BASE_ADDRESS +0x28))
#define TIMER2_CNT 							 *((volatile u32*)(TIMER2_BASE_ADDRESS +0x24))
#define TIMER2_CCR1                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x34))
#define TIMER2_CCR2                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x38))
#define TIMER2_CCR3                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x3C))
#define TIMER2_ARR                           *((volatile u32*)(TIMER2_BASE_ADDRESS +0x2C))


#endif /* TIMER2_PRIVATE_H_ */
