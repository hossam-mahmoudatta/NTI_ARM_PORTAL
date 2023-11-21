 /******************************************************************************
 *
 * Module: TIMER GENERAL
 *
 * File Name: TIMER_GENERAL_PRIVATE.h
 *
 * Description: Header file for TIMER2 -> TIMER5 Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER_GENERAL_PRIVATE_H_
#define TIMER_GENERAL_PRIVATE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              							TIMERS Registers					                   				     *
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
} TIMx_CR1_REG;



typedef union
{
	struct
	{
		u32 TIMx_DIER_UIE: 			1;		// Update interrupt enable
		u32 TIMx_DIER_CC1IE: 		1;		// Capture 1 interrupt enable
		u32 TIMx_DIER_CC2IE: 	1;		// Capture 2 interrupt enable
		u32 TIMx_DIER_CC3IE: 	1;		// Capture 3 interrupt enable
		u32 TIMx_DIER_CC4IE: 	1;		// Capture 4 interrupt enable
		u32							: 		1;
		u32 TIMx_DIER_TIE: 			1;		// Trigger interrupt enable
		u32							: 		1;
		u32 TIMx_DIER_UDE: 		1;		// Update DMA Request enable
		u32 TIMx_DIER_CC1DE: 	1;		// Capture 1 DMA request enable
		u32 TIMx_DIER_CC2DE: 	1;		// Capture 2 DMA request enable
		u32 TIMx_DIER_CC3DE: 	1;		// Capture 3 DMA request enable
		u32 TIMx_DIER_CC4DE: 	1;		// Capture 4 DMA request enable
		u32							: 		1;
		u32 TIMx_DIER_TDE: 		1;		// Trigger DMA Request enable
		u32							: 		1;
	};
	volatile u32 DIER_u32Value;
} TIMx_DIER_REG;



typedef union
{
	struct
	{
		u32 TIMx_SR_UIF: 			1;		// Update interrupt Flag
		u32 TIMx_SR_CC1IF: 		1;		// Capture 1 interrupt Flag
		u32 TIMx_SR_CC2IF: 	1;		// Capture 2 interrupt Flag
		u32 TIMx_SR_CC3IF: 	1;		// Capture 3 interrupt Flag
		u32 TIMx_SR_CC4IF: 	1;		// Capture 4 interrupt Flag
		u32							: 		1;
		u32 TIMx_SR_TIF: 			1;		// Trigger interrupt Flag
		u32							: 		2;
		u32 TIMx_SR_CC1OF: 		1;		// Capture 1 Overcapture Flag
		u32 TIMx_SR_CC2OF: 	1;		// Capture 2 Overcapture Flag
		u32 TIMx_SR_CC3OF: 	1;		// Capture 3 Overcapture Flag
		u32 TIMx_SR_CC4OF: 	1;		// Capture 4 Overcapture Flag
		u32							: 		3;
	};
	volatile u32 SR_u32Value;
} TIMx_SR_REG;



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
	u32 TIMx_CCMR1_RES:			16;
} TIMx_CCMR1_REG;


typedef struct
{
	u32 TIMx_CCMR2_CC3S: 		2;
	u32 TIMx_CCMR2_OC3FE: 	1;
	u32 TIMx_CCMR2_OC3PE:		1;
	u32 TIMx_CCMR2_OC3M:		3;
	u32 TIMx_CCMR2_OC3CE:	1;
	u32 TIMx_CCMR2_CC4S: 		2;
	u32 TIMx_CCMR2_OC4FE: 	1;
	u32 TIMx_CCMR2_OC4PE:		1;
	u32 TIMx_CCMR2_OC4M:		3;
	u32 TIMx_CCMR2_OC4CE:	1;
	u32 TIMx_CCMR2_RES:			16;
} TIMx_CCMR2_REG;



typedef union
{
	struct
	{
		u32 TIMx_CCER_CC1E: 		1;
		u32 TIMx_CCER_CC1P: 		1;
		u32                                :		2;
		u32 TIMx_CCER_CC2E:		1;
		u32 TIMx_CCER_CC2P:		1;
		u32                                :		2;
		u32 TIMx_CCER_CC3E:		1;
		u32 TIMx_CCER_CC3P:		1;
		u32                                :		2;
		u32 TIMx_CCER_CC4E:		1;
		u32 TIMx_CCER_CC4P:		1;
		u32                                :		2;
	};
	volatile u32 CCER_u32Value;
} TIMx_CCER_REG;



typedef struct
{
	TIMx_CR1_REG TIMx_CR1;
	volatile u32 TIMx_CR2;
	volatile u32 TIMx_SMCR;
	TIMx_DIER_REG TIMx_DIER;
	TIMx_SR_REG TIMx_SR;
	volatile u32 TIMx_EGR;
	TIMx_CCMR1_REG TIMx_CCMR1;
	TIMx_CCMR2_REG TIMx_CCMR2;
	TIMx_CCER_REG TIMx_CCER;
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

#define TIMER2_BASE_ADDRESS        0x40000000
#define TIMER3_BASE_ADDRESS        0x40000400
#define TIMER4_BASE_ADDRESS        0x40000800
#define TIMER2_REG                          		((volatile TIMx_REGISTERS*)(TIMER2_BASE_ADDRESS))
#define TIMER3_REG                          		((volatile TIMx_REGISTERS*)(TIMER3_BASE_ADDRESS))
#define TIMER4_REG                          		((volatile TIMx_REGISTERS*)(TIMER4_BASE_ADDRESS))







#endif /* TIMER_GENERAL_PRIVATE_H_ */





//#define TIMER2_BASE_ADDRESS                       0x40000000
//
//#define TIMER2_CR1                           *((volatile u32*)(TIMER2_BASE_ADDRESS +0x00))
//
//#define TIMER2_SMCR                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x08))
//#define TIMER2_DIER                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x0C))
//#define TIMER2_SR                            *((volatile u32*)(TIMER2_BASE_ADDRESS +0x10))
//
//#define TIMER2_CCMR1                         *((volatile u32*)(TIMER2_BASE_ADDRESS +0x18))
//#define TIMER2_CCMR2                         *((volatile u32*)(TIMER2_BASE_ADDRESS +0x1C))
//#define TIMER2_CCER                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x20))
//#define TIMER2_CNT 							 *((volatile u32*)(TIMER2_BASE_ADDRESS +0x24))
//#define TIMER2_PSC 						   	 *((volatile u32*)(TIMER2_BASE_ADDRESS +0x28))
//#define TIMER2_CCR1                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x34))
//#define TIMER2_CCR2                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x38))
//#define TIMER2_CCR3                          *((volatile u32*)(TIMER2_BASE_ADDRESS +0x3C))
//#define TIMER2_CCR4	                       *((volatile u32*)(TIMER2_BASE_ADDRESS +0x40))
//#define TIMER2_ARR                           *((volatile u32*)(TIMER2_BASE_ADDRESS +0x2C))
