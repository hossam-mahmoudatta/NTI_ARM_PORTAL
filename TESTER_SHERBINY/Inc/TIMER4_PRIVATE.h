 /******************************************************************************
 *
 * Module: TIMER4 Module
 *
 * File Name: TIMER4_PRIVATE.h
 *
 * Description: Header file for the TIMER4 Driver Registers
 *
 * Author: Hosny & Tariq
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER4_PRIVATE_H_
#define TIMER4_PRIVATE_H_

#include "MACROS.h"
#include "TYPES.h"

/*******************************************************************************
 *                              							TIMER4 Registers					                   				     *
 *******************************************************************************/

/**
 * Timer4 will be used for the DC Motors
 * All 4 Channels will be used
 */

#define TIMER4_BASE_ADDRESS    0x40000800

#define TIMER4_CR1                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x00))
#define TIMER4_CR2                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x04))
#define TIMER4_SMCR                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x08))
#define TIMER4_DIER                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x0C))
#define TIMER4_SR                           *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x10))
#define TIMER4_EGR                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x14))

#define TIMER4_CCMR1                        *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x18))
#define TIMER4_CCMR2                        *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x1C))
#define TIMER4_CCER                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x20))
#define TIMER4_CNT                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x24))
#define TIMER4_PSC                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x28))
#define TIMER4_CCR1                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x34))
#define TIMER4_CCR2                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x38))
#define TIMER4_CCR3                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x3C))
#define TIMER4_CCR4                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x40))
#define TIMER4_ARR                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x2C))


#endif /* TIMER4_PRIVATE_H_ */
