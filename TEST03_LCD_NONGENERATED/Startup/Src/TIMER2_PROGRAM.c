 /******************************************************************************
 *
 * Module: TIMER2
 *
 * File Name: TIMER2_PROGRAM.c
 *
 * Description: Source file for the TIMER2 Driver
 *
 * Author: Sherbiny & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						               		   *
 *******************************************************************************/

#include "../Inc/TIMER2_INTERFACE.h"

/*******************************************************************************
 *                              				TIMER2 Global Variables				           			     *
 *******************************************************************************/

/*Global pointer to function to hold the callback function address*/
static void (*TIMER2_pvICUCallBackFunc)(void) = NULL;

/*******************************************************************************
 *                              				TIMER2 Function Implementations		     				     *
 *******************************************************************************/

void TIMER2_voidICUInitialization(u8 copy_u8ChannelNumber)
{
	// Set the Prescaler for 8MHz
	TIMER2_REG->TIMx_PSC = TIMER2_PSC_VALUE;

	// Inserting a value in the Counter Register
	TIMER2_REG->TIMx_CNT = TIMER2_CNT_VALUE;

	//configure input capture for selected channel
	switch(copy_u8ChannelNumber)
	{
		/******************** CHANNEL 1 ********************/
		case TIMER2_CHANNEL1:
			//CC1s channel is configured as input, IC1 is mapped on TI1
			TIMER2_REG->TIMx_CCMR1.TIMx_CCMR1_CC1S = TIMER2_CCMRx_CC1S_MODE;
//			SET_BIT(TIMER2_CCMR1,0);
//			CLR_BIT(TIMER2_CCMR1,1);

			// Enable capture on each channel
			TIMER2_REG->TIMx_CCER.TIMx_CCER_CC1E = ENABLE;
			TIMER2_REG->TIMx_CCER.TIMx_CCER_CC1P = DISABLE;
//			SET_BIT(TIMER2_CCER,0);
//			CLR_BIT(TIMER2_CCER,1);

			// Enable capture interrupt on each channel
			TIMER2_REG->TIMx_DIER.TIMx_DIER_CC1IE = ENABLE;
//			SET_BIT(TIMER2_DIER,1);
			break;

		/******************** CHANNEL 2 ********************/
		case TIMER2_CHANNEL2:
			//CC2 channel is configured as input, IC2 is mapped on TI2
			TIMER2_REG->TIMx_CCMR1.TIMx_CCMR1_CC2S = TIMER2_CCMRx_CC1S_MODE;
//			SET_BIT(TIMER2_CCMR1,8);
//			CLR_BIT(TIMER2_CCMR1,9);

			// Enable capture on each channel,CC2E: Capture/Compare 2 output enable
			TIMER2_REG->TIMx_CCER.TIMx_CCER_CC2E = ENABLE;
			TIMER2_REG->TIMx_CCER.TIMx_CCER_CC2P = DISABLE;
//			SET_BIT(TIMER2_CCER,4);
//			CLR_BIT(TIMER2_CCER,5);


			// Enable capture interrupt on each channel
			TIMER2_REG->TIMx_DIER.TIMx_DIER_CC2IE = ENABLE;
//			SET_BIT(TIMER2_DIER,2);
			break;
	}



	// Enable Timer 2
	TIMER2_REG->TIMx_CR1.TIMx_CR1_CEN = ENABLE;
}



u8 TIMER2_u8ICUSetCallBack(void (*copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(copy_pvCallBackFunc != NULL)
	{
		TIMER2_pvICUCallBackFunc = copy_pvCallBackFunc;
	}
	else
	{
		//		Local_u8ErrorState= NULL_POINTER;
	}

	return Local_u8ErrorState;

}



void 	TIMER2_voidSetPreload(u8 copy_u8Preload)
{
	TIMER2_REG->TIMx_CNT = copy_u8Preload;
}



void 	TIMER2_voidEnableInterrupt(u8 copy_u8ChannelNumber)
{
	switch(copy_u8ChannelNumber)
	{
		case TIMER2_CHANNEL1:
			TIMER2_REG->TIMx_DIER.TIMx_DIER_CC1IE = ENABLE;
//			SET_BIT(TIMER2_DIER,1);
			break;
		case TIMER2_CHANNEL2:
			TIMER2_REG->TIMx_DIER.TIMx_DIER_CC2IE = ENABLE;
//			SET_BIT(TIMER2_DIER,2);
			break;
	}
}



void 	TIMER2_voidDisableInterrupt(u8 copy_u8ChannelNumber)
{
	switch(copy_u8ChannelNumber)
	{
		case TIMER2_CHANNEL1:
			TIMER2_REG->TIMx_DIER.TIMx_DIER_CC1IE = DISABLE;
//			SET_BIT(TIMER2_DIER,1);
			break;
		case TIMER2_CHANNEL2:
			TIMER2_REG->TIMx_DIER.TIMx_DIER_CC2IE = DISABLE;
//			SET_BIT(TIMER2_DIER,2);
			break;
	}
}



void 	TIMER2_voidChangePolarity(u8 copy_u8ChannelNumber, u8 copy_u8Edge)
{
	switch(copy_u8Edge)
	{
		case TIMER2_RISING_EDGE:
			switch(copy_u8ChannelNumber)
			{
			case TIMER2_CHANNEL1:
				TIMER2_REG->TIMx_CCER.TIMx_CCER_CC1P = DISABLE;
//				CLR_BIT(TIMER2_CCER,1);
				break;
			case TIMER2_CHANNEL2:
				TIMER2_REG->TIMx_CCER.TIMx_CCER_CC2P = DISABLE;
//				CLR_BIT(TIMER2_CCER,5);
				break;
			}
			break;

			case TIMER2_FALLING_EDGE:
				switch(copy_u8ChannelNumber)
				{
				case TIMER2_CHANNEL1:
					TIMER2_REG->TIMx_CCER.TIMx_CCER_CC1P = ENABLE;
//					SET_BIT(TIMER2_CCER,1);
					break;
				case TIMER2_CHANNEL2:
					TIMER2_REG->TIMx_CCER.TIMx_CCER_CC2P = ENABLE;
//					SET_BIT(TIMER2_CCER,5);
					break;
				}
				break;
	}
}



u32  	TIMER2_u32GetICUValue(u8 copy_u8ChannelNumber)
{
	u32 u32Value1, u32Value2, returnValue;
	switch(copy_u8ChannelNumber)
	{
		case TIMER2_CHANNEL1:
			u32Value1 = TIMER2_REG->TIMx_CCR1;
			returnValue = u32Value1;
//			u32Value1 = TIMER2_CCR1;
			break;
		case TIMER2_CHANNEL2:
			u32Value2 = TIMER2_REG->TIMx_CCR2;
			returnValue = u32Value2;
//			u32Value2 = TIMER2_CCR2;
			break;
	}
	return returnValue;
}



/*Timer2 ISR*/
void TIM2_IRQHandler(void)
{
	if(TIMER2_pvICUCallBackFunc != NULL)
	{
		TIMER2_pvICUCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}



