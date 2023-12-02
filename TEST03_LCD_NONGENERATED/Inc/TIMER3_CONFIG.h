 /******************************************************************************
 *
 * Module: TIMER3
 *
 * File Name: TIMER3_CONFIG.h
 *
 * Description: Header file for the TIMER3 Driver MACRO DECLARATIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER3_CONFIG_H_
#define TIMER3_CONFIG_H_

#include "TIMER_GENERAL_PRIVATE.h"
#include "ERROR_STATUS.h"


/*******************************************************************************
 *                              						TIMER3 Macro Definitions					               				     *
 *******************************************************************************/

#define TIMER3_CHANNEL1							1
#define TIMER3_CHANNEL2							2
#define TIMER3_CHANNEL3							3
#define TIMER3_CHANNEL4							4

#define TIMx_CCMRx_OCxM_FROZEN					0b000		// Output compare 1 mode
#define TIMx_CCMRx_OCxM_ACTIVE						0b001		// Output compare 1 mode
#define TIMx_CCMRx_OCxM_INACTIVE					0b010		// Output compare 1 mode
#define TIMx_CCMRx_OCxM_TOGGLE					0b011		// Output compare 1 mode
#define TIMx_CCMRx_OCxM_FORCEINACTIVE		0b100		// Output compare 1 mode
#define TIMx_CCMRx_OCxM_FORCEACTIVE			0b101		// Output compare 1 mode
#define TIMx_CCMRx_OCxM_PWM1							0b110		// Output compare 1 mode
#define TIMx_CCMRx_OCxM_PWM2							0b111		// Output compare 1 mode
#define TIMER3_CCMRx_OC1M_MODE						TIMx_CCMRx_OCxM_PWM2		// Output compare 1 mode
#define TIMER3_CCMRx_OC2M_MODE					TIMx_CCMRx_OCxM_PWM2		// Output compare 2 mode
#define TIMER3_CCMRx_OC3M_MODE					TIMx_CCMRx_OCxM_PWM2		// Output compare 3 mode
#define TIMER3_CCMRx_OC4M_MODE					TIMx_CCMRx_OCxM_PWM2		// Output compare 4 mode


#define TIMx_CCMRx_CCxS_OUTPUT					0b00	// Capture Config as Output
#define TIMx_CCMRx_CCxS_ICxTIx1						0b01		// Capture Config as input, ICx to TI
#define TIMx_CCMRx_CCxS_ICxTIx2						0b10		// Capture Config as Output
#define TIMx_CCMRx_CCxS_ICxTRC						0b11		// Capture Config as Output
#define TIMER3_CCMRx_CC1S_MODE					TIMx_CCMRx_CCxS_ICxTIx1
#define TIMER3_CCMRx_CC2S_MODE					TIMx_CCMRx_CCxS_ICxTIx1
#define TIMER3_CCMRx_CC3S_MODE					TIMx_CCMRx_CCxS_ICxTIx1
#define TIMER3_CCMRx_CC4S_MODE				TIMx_CCMRx_CCxS_ICxTIx1

#define TIMER3_RISING_EDGE 									0
#define TIMER3_FALLING_EDGE 								1

#define TIMER3_PSC_VALUE							7			// Prescaler Value
#define TIMER3_ARR_VALUE							100		// Prescaler Value In Auto Reload
#define TIMER3_CNT_VALUE							0		// Counter Value Register

#endif /* TIMER3_CONFIG_H_ */
