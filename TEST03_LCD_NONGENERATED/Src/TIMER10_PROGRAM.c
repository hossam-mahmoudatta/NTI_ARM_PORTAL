 /******************************************************************************
 *
 * Module: TIMER10
 *
 * File Name: TIMER10_PROGRAM.c
 *
 * Description: Source file for the TIMER10 Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       	*
 *******************************************************************************/

#include "TIMER10_INTERFACE.h"

/*******************************************************************************
 *                              		TIMER10 Function Implementations								*
 *******************************************************************************/

// Initializes Timer 10 into PWM Mode
void TIMER10_voidPWMInitialization(u8 copy_u8Channel)
{
	/* To disable timer , Enable auto Preload ARR */
	TIMER10_REG->TIMx_PSC = 15;
	TIMER10_REG->TIMx_CR1 = 0x0080;
	TIMER10_REG->TIMx_ARR = 100;
	switch(copy_u8Channel)
	 {
	   case TIMER2_CHANNEL1  :
		   /* To Enable Preload register on CCR1 */
		   SET_BIT(TIMER_CCMR1,3);
		   /* To Select PWM MODE 1 */
		   SET_BIT(TIMER_CCMR1,4);
		   SET_BIT(TIMER_CCMR1,5);
		   SET_BIT(TIMER_CCMR1,6);
		   /* To Enable Capture compare to channel 1 */
		   SET_BIT(TIMER_CCER,0);
		   break;
	   case TIMER2_CHANNEL2  :
		   /* To Enable Preload register on CCR2 */
		   SET_BIT(TIMER_CCMR1,11);
		   /* To Select PWM MODE 1 */
		   SET_BIT(TIMER_CCMR1,12);
		   SET_BIT(TIMER_CCMR1,13);
		   SET_BIT(TIMER_CCMR1,14);
		   /* To Enable Capture compare to channel 2 */
		   SET_BIT(TIMER_CCER,4);
		   break;
	   case TIMER2_CHANNEL3 :
		   /* To Enable Preload register on CCR3 */
		   SET_BIT(TIMER_CCMR2,3);
		   /* To Select PWM MODE 1 */
		   SET_BIT(TIMER_CCMR2,4);
		   SET_BIT(TIMER_CCMR2,5);
		   SET_BIT(TIMER_CCMR2,6);
		   /* To Enable Capture compare to channel 3 */
		   SET_BIT(TIMER_CCER,8);
		   break;
	   default              :
		   break;
	 }
}

// Sets the Duty Cycle of Timer 10
void TIMER10_voidPWMSetDutyCycle(u8, u32)
{
	switch(Copy_U8_Channel)
	{
	case TIMER2_CHANNEL1 :  TIMER_CCR1 = Copy_U32_DutyCycle;           break;
	case TIMER2_CHANNEL2 :  TIMER_CCR2 = Copy_U32_DutyCycle;           break;
	case TIMER2_CHANNEL3 :  TIMER_CCR3 = Copy_U32_DutyCycle;           break;
	default              :                                             break;

	}
}

// Starts Timer 10 into PWM Mode
void TIMER10_voidPWMStart()
{
	SET_BIT(TIMER_CR1,0);
}
