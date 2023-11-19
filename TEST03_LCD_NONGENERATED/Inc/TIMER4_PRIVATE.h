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
	u32 TIMx_CR1_CEN: 	1;		// Counter enable
	u32 TIMx_CR1_UDIS: 	1;		// Update disable
	u32 TIMx_CR1_URS:		1;		// Update request source
	u32 TIMx_CR1_OPM:		1;		// One Pulse Mode
	u32 TIMx_CR1_DIR:		1;		// Direction
	u32 TIMx_CR1_CMS: 	2;		// Center aligned mode
	u32 TIMx_CR1_ARPE: 	1;		// Auto Reload Preload Enable
	u32 TIMx_CR1_CKD:		2;		// Clock Division
	u32 TIMx_CR1_RES:		22;	// Reserved bits
} TIMx_CR1;



typedef struct
{
	u32 TIMx_CCMR1_CC1S: 		2;
	u32 TIMx_CCMR1_OC1FE: 	1;
	u32 TIMx_CCMR1_OC1PE:		1;
	u32 TIMx_CCMR1_OC1M:		3;
	u32 TIMx_CCMR1_OC1CE:		1;
	u32 TIMx_CCMR1_CC2S: 		2;
	u32 TIMx_CCMR1_OC2FE: 	1;
	u32 TIMx_CCMR1_OC2PE:		1;
	u32 TIMx_CCMR1_OC2M:		3;
	u32 TIMx_CCMR1_OC2CE:	1;
	u32 TIMx_CCMR1_RES:			16;
} TIMx_CCMR1;



typedef struct
{
	TIMx_CR1 TIMx_CR1;
	volatile u32 TIMx_CR2;
	volatile u32 TIMx_SMCR;
	volatile u32 TIMx_DIER;
	volatile u32 TIMx_SR;
	volatile u32 TIMx_EGR;
	TIMx_CCMR1 TIMx_CCMR1;
	volatile u32 TIMx_CCMR2;
	volatile u32 TIMx_CCER;
	volatile u32 TIMx_CNT;
	volatile u32 TIMx_PSC;
	volatile u32 TIMx_ARR;
	volatile u32 TIMx_CCR1;
	volatile u32 TIMx_CCR2;
	volatile u32 TIMx_CCR3;
	volatile u32 TIMx_CCR4;
	volatile u32 TIMx_RES1;
	volatile u32 TIMx_DCR;
	volatile u32 TIMx_DMAR;
} TIMx_REGISTERS;

#define TIMER4_BASE_ADDRESS        0x40000800
#define TIMER4_REG                          		((volatile TIMx_REGISTERS*)(TIMER4_BASE_ADDRESS))







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
