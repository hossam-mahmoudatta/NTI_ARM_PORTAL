 /******************************************************************************
 *
 * Module: TIMER4
 *
 * File Name: TIMER4_PROGRAM.c
 *
 * Description: Source file for the TIMER4 Driver
 *
 * Author: Tariq, Hosny & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "TIMER4_INTERFACE.h"

/*******************************************************************************
 *                              				TIMER4 Function Implementations		     				     *
 *******************************************************************************/

void TIMER4_voidPWMInitialization(u8 copy_u8ChannelNumber)
{
	/* To disable timer , Enable auto Preload ARR */
	TIMER4_REG->TIMx_CR1.TIMx_CR1_ARPE = ENABLE;

	/* Set a value of the prescaler */
	TIMER4_REG->TIMx_PSC = TIMER4_PSC_VALUE;

	/* Set a value of the prescaler in the Auto Reload Register */
	TIMER4_REG->TIMx_ARR = TIMER4_ARR_VALUE;

	switch(copy_u8ChannelNumber)
	{
		/******************** CHANNEL 1 ********************/
		case TIMER4_CHANNEL1  :
			/* To Enable Preload register on CCR1 */
			TIMER4_REG->TIMx_CCMR1.TIMx_CCMR1_OC1PE = SET;

			/* To Select PWM MODE 2 */
			TIMER4_REG->TIMx_CCMR1.TIMx_CCMR1_OC1M = TIMER4_CCMRx_OC1M_MODE;

			/* To Enable Capture compare to channel 1 */
			TIMER4_REG->TIMx_CCER.TIMx_CCER_CC1E = ENABLE;
			break;

		/******************** CHANNEL 2 ********************/
		case TIMER4_CHANNEL2  :
			/* To Enable Preload register on CCR2 */
			TIMER4_REG->TIMx_CCMR1.TIMx_CCMR1_OC2PE = SET;

			/* To Select PWM MODE 2 */
			TIMER4_REG->TIMx_CCMR1.TIMx_CCMR1_OC2M = TIMER4_CCMRx_OC2M_MODE;

			/* To Enable Capture compare to channel 2 */
			TIMER4_REG->TIMx_CCER.TIMx_CCER_CC2E = SET;
			break;

		/******************** CHANNEL 3 ********************/
		case TIMER4_CHANNEL3 :
			/* To Enable Preload register on Channel3 */
			TIMER4_REG->TIMx_CCMR2.TIMx_CCMR2_OC3PE = SET;

			/* To Enable Fast Enable for Channel 3 */
			TIMER4_REG->TIMx_CCMR2.TIMx_CCMR2_OC3FE = ENABLE;

			/* To Select PWM MODE 2 */
			TIMER4_REG->TIMx_CCMR2.TIMx_CCMR2_OC3M = TIMER4_CCMRx_OC3M_MODE;

			/* To Enable Capture compare to channel 3 */
			TIMER4_REG->TIMx_CCER.TIMx_CCER_CC3E = SET;
			break;

		/******************** CHANNEL 4 ********************/
		case TIMER4_CHANNEL4 :
			/* To Enable Preload register on CCR4 */
			TIMER4_REG->TIMx_CCMR2.TIMx_CCMR2_OC4PE = SET;

			/* To Select PWM MODE 2 */
			TIMER4_REG->TIMx_CCMR2.TIMx_CCMR2_OC4M = TIMER4_CCMRx_OC4M_MODE;

			/* To Enable Fast Enable for Channel 4 */
			TIMER4_REG->TIMx_CCMR2.TIMx_CCMR2_OC4FE = ENABLE;

			/* To Enable Capture compare to channel 3 */
			TIMER4_REG->TIMx_CCER.TIMx_CCER_CC4E = SET;
			break;

		default:
			break;
	}

	// Starts the Timer4
	TIMER4_REG->TIMx_CR1.TIMx_CR1_CEN = ENABLE;
}



void TIMER4_voidPWMSetDutyCycle(u8 copy_u8ChannelNumber ,u32 copy_u32DutyCycle)
{
	switch(copy_u8ChannelNumber)
	{
	case TIMER4_CHANNEL1 :  TIMER4_REG->TIMx_CCR1 = copy_u32DutyCycle;           break;
	case TIMER4_CHANNEL2 :  TIMER4_REG->TIMx_CCR2 = copy_u32DutyCycle;           break;
	case TIMER4_CHANNEL3 :  TIMER4_REG->TIMx_CCR3 = copy_u32DutyCycle;           break;
	case TIMER4_CHANNEL4 :  TIMER4_REG->TIMx_CCR4 = copy_u32DutyCycle;           break;
	default              :                                             break;
	}
}


void TIMER4_voidPWMStart()
{
	TIMER4_REG->TIMx_CR1.TIMx_CR1_CEN = ENABLE;
}



