 /******************************************************************************
 *
 * Module: TIMER4
 *
 * File Name: TIMER4_PRIVATE.h
 *
 * Description: Header file for the TIMER4 Driver Registers
 *
 * Author: Tariq, Hosny & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER4_PRIVATE_H_
#define TIMER4_PRIVATE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              							TIMER4 Registers					                   				     *
 *******************************************************************************/


typedef struct
{
	u32 TIMx_CR1;
	u32 TIMx_CR2;
	u32 TIMx_SMCR;
	u32 TIMx_DIER;
	u32 TIMx_SR;
	u32 TIMx_EGR;
	u32 TIMx_CCMR1;
	u32 TIMx_CCMR2;
	u32 TIMx_CCER;
	u32 TIMx_CNT;
	u32 TIMx_PSC;
	u32 TIMx_ARR;
	u32 TIMx_CCR1;
	u32 TIMx_CCR2;
	u32 TIMx_CCR3;
	u32 TIMx_CCR4;
	u32 TIMx_RES1;
	u32 TIMx_DCR;
	u32 TIMx_DMAR;
} TIMx_REGISTERS;

#define TIMER4_BASE_ADDRESS        0x40000800
#define TIMER4_REG                          		((volatile TIMx_REGISTERS*)(TIMER4_BASE_ADDRESS))

typedef struct
{
	u32 TIMx_CCMR1_CC1S: 		2;
	u32 TIMx_CCMR1_OC1FE: 	1;
	u32 TIMx_CCMR1_OC1PE:		1;
	u32 TIMx_CCMR1_OC1M:		3;
	u32 TIMx_CCMR1_OC1CE:	1;
	u32 TIMx_CCMR1_CC2S: 		2;
	u32 TIMx_CCMR1_OC2FE: 	1;
	u32 TIMx_CCMR1_OC2PE:		1;
	u32 TIMx_CCMR1_OC2M:		3;
	u32 TIMx_CCMR1_OC2CE:	1;
} TIMx_CCMR1;






//#define TIMER4_CR1                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x00))
//#define TIMER4_CR2                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x04))
//#define TIMER4_SMCR                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x08))
//#define TIMER4_DIER                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x0C))
//#define TIMER4_SR                           *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x10))
//#define TIMER4_EGR                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x14))
//#define TIMER4_CCMR1                        *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x18))
//#define TIMER4_CCMR2                        *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x1C))
//#define TIMER4_CCER                         *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x20))
//#define TIMER4_CNT                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x24))
//#define TIMER4_PSC                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x28))
//#define TIMER4_CCR1                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x34))
//#define TIMER4_CCR2                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x38))
//#define TIMER4_CCR3                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x3C))
//#define TIMER4_CCR4                          *((volatile u32*)(TIMER4_BASE_ADDRESS +0x40))
//#define TIMER4_ARR                          *((volatile u32*)(TIMER4_BASE_ADDRESS + 0x2C))


#endif /* TIMER4_PRIVATE_H_ */
