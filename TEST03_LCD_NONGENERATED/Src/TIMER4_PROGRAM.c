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

#include "../Inc/TIMER4_PRIVATE.h"
#include "../Inc/TIMER4_CONFIG.h"
#include "../Inc/TIMER4_INTERFACE.h"

/*******************************************************************************
 *                              				TIMER4 Function Implementations		     				     *
 *******************************************************************************/

void TIMER4_voidPWMInitialization(u8 copy_u8ChannelNumber)
{
	/* To disable timer , Enable auto Preload ARR */
	TIMER4_PSC = 15;
	TIMER4_CR1 = 0x0080;
	TIMER4_ARR = 100;

	switch(copy_u8ChannelNumber)
	{
		case TIMER4_CHANNEL1  :
			/* To Enable Preload register on CCR1 */
			SET_BIT(TIMER4_CCMR1, TIMERx_CCMR1_OC1PE);

			/* To Select PWM MODE 2 */
			SET_BIT(TIMER4_CCMR1, TIMERx_CCMR1_OC1M0);
			SET_BIT(TIMER4_CCMR1, TIMERx_CCMR1_OC1M1);
			SET_BIT(TIMER4_CCMR1, TIMERx_CCMR1_OC1M2);

			/* To Enable Capture compare to channel 1 */
			SET_BIT(TIMER4_CCER, TIMERx_CCER_CC1E);
			break;
		case TIMER4_CHANNEL2  :
			/* To Enable Preload register on CCR2 */
			SET_BIT(TIMER4_CCMR1,TIMERx_CCMR1_OC2PE);
			/* To Select PWM MODE 2 */
			SET_BIT(TIMER4_CCMR1,TIMERx_CCMR1_OC2M0);
			SET_BIT(TIMER4_CCMR1,TIMERx_CCMR1_OC2M1);
			SET_BIT(TIMER4_CCMR1,TIMERx_CCMR1_OC2M2);
			/* To Enable Capture compare to channel 2 */
			SET_BIT(TIMER4_CCER,4);                                 break;

		case TIMER4_CHANNEL3 :
			/* To Enable Preload register on CCR3 */
			SET_BIT(TIMER4_CCMR2,3);
			/* To Select PWM MODE 2 */
			SET_BIT(TIMER4_CCMR2,4);
			SET_BIT(TIMER4_CCMR2,5);
			SET_BIT(TIMER4_CCMR2,6);
			/* To Enable Capture compare to channel 3 */
			SET_BIT(TIMER4_CCER,8);
		case TIMER4_CHANNEL4 :
			/* To Enable Preload register on CCR4 */
			SET_BIT(TIMER4_CCMR2,11);
			/* To Select PWM MODE 2 */
			SET_BIT(TIMER4_CCMR2,12);
			SET_BIT(TIMER4_CCMR2,13);
			SET_BIT(TIMER4_CCMR2,14);
			/* To Enable Capture compare to channel 3 */
			SET_BIT(TIMER4_CCER,12);
			break;
		default:
			break;

	}
}
void TIMER4_Void_PwmSetDutyCycle(u8 Copy_U8_Channel ,u32 Copy_U32_DutyCycle)
{
	switch(Copy_U8_Channel)
	{
	case TIMER4_CHANNEL1 :  TIMER4_CCR1 = Copy_U32_DutyCycle;           break;
	case TIMER4_CHANNEL2 :  TIMER4_CCR2 = Copy_U32_DutyCycle;           break;
	case TIMER4_CHANNEL3 :  TIMER4_CCR3 = Copy_U32_DutyCycle;           break;
	case TIMER4_CHANNEL4 :  TIMER4_CCR4 = Copy_U32_DutyCycle;           break;
	default              :                                             break;
	}
}
void TIMER4_Void_PwmStart()
{
	SET_BIT(TIMER4_CR1,0);
}



