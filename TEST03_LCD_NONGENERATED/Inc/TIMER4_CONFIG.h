 /******************************************************************************
 *
 * Module: TIMER4
 *
 * File Name: TIMER4_CONFIG.h
 *
 * Description: Header file for the TIMER4 Driver CONFIGURATIONS
 *
 * Author: Tariq, Hosny & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER4_CONFIG_H_
#define TIMER4_CONFIG_H_

#include "TIMER4_PRIVATE.h"

/*******************************************************************************
 *                              						TIMER4 Macro Definitions					               				     *
 *******************************************************************************/

#define TIMER4_CHANNEL1							1
#define TIMER4_CHANNEL2							2
#define TIMER4_CHANNEL3							3
#define TIMER4_CHANNEL4							4

#define TIMx_CCER_CC1E_ENABLE			1			// Capture/Compare 1 output ENABLE
#define TIMx_CCER_CC1E_DISABLE			0			// Capture/Compare 1 output DISABLE

#define TIMx_CCMR1_OC1PE_ENABLE		1			// Output compare 1 preload ENABLE
#define TIMx_CCMR1_OC1PE_DISABLE		0			// Output compare 1 preload DISABLE

#define TIMx_CCMR1_OCxM_FROZEN					0b000		// Output compare 1 mode
#define TIMx_CCMR1_OCxM_ACTIVE					0b001		// Output compare 1 mode
#define TIMx_CCMR1_OCxM_INACTIVE				0b010		// Output compare 1 mode
#define TIMx_CCMR1_OCxM_TOGGLE					0b011		// Output compare 1 mode
#define TIMx_CCMR1_OCxM_FORCEINACTIVE		0b100		// Output compare 1 mode
#define TIMx_CCMR1_OCxM_FORCEACTIVE		0b101		// Output compare 1 mode
#define TIMx_CCMR1_OCxM_PWM1						0b110		// Output compare 1 mode
#define TIMx_CCMR1_OCxM_PWM2						0b111		// Output compare 1 mode
#define TIMx_CCMR1_OC1M_MODE						TIMx_CCMR1_OCxM_PWM2		// Output compare 1 mode
#define TIMx_CCMR1_OC2M_MODE						TIMx_CCMR1_OCxM_TOGGLE		// Output compare 1 mode


#define TIMx_CCMR1_OC1M0					4			// Output compare 1 mode
#define TIMx_CCMR1_OC1M1					5			// Output compare 1 mode
#define TIMx_CCMR1_OC1M2					6			// Output compare 1 mode

#define TIMx_CCMR1_OC2PE					11		// Output compare 1 preload enable
#define TIMx_CCMR1_OC2M0					12		// Output compare 1 mode
#define TIMx_CCMR1_OC2M1					13		// Output compare 1 mode
#define TIMx_CCMR1_OC2M2					14		// Output compare 1 mode


#endif /* TIMER4_CONFIG_H_ */
