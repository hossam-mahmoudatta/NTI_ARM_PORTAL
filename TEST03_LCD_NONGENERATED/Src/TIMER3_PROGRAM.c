 /******************************************************************************
 *
 * Module: TIMER3
 *
 * File Name: TIMER3_PROGRAM.c
 *
 * Description: Source file for the TIMER3 Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "../Inc/TIMER3_INTERFACE.h"

/*******************************************************************************
 *                              					TIMER3 Global Variables				               				     *
 *******************************************************************************/

/*Global pointer to function to hold the callback function address*/
static void (*TIMER3_pvICUCallBackFunc)(void) = NULL;

/*******************************************************************************
 *                              				TIMER3 Functions Implementation					               				     *
 *******************************************************************************/

void TIMER3_voidICUInitialization(u8 copy_u8ChannelNumber)
{
	// Set the Prescaler for 8MHz
	TIMER3_REG->TIMx_PSC = TIMER3_PSC_VALUE;

	// Inserting a value in the Counter Register
	TIMER3_REG->TIMx_CNT = TIMER3_CNT_VALUE;

	//configure input capture for selected channle
	switch(copy_u8ChannelNumber)
	{
		/******************** CHANNEL 1 ********************/
		case TIMER3_CHANNEL1:
			//CC1s channel is configured as input, IC1 is mapped on TI1
			TIMER3_REG->TIMx_CCMR1.TIMx_CCMR1_CC1S = TIMER3_CCMRx_CC1S_MODE;
//			SET_BIT(TIMER3_CCMR1,0);
//			CLR_BIT(TIMER3_CCMR1,1);

			// Enable capture on each channel
			TIMER3_REG->TIMx_CCER.TIMx_CCER_CC1E = ENABLE;
			TIMER3_REG->TIMx_CCER.TIMx_CCER_CC1P = DISABLE;
//			SET_BIT(TIMER3_CCER,0);
//			CLR_BIT(TIMER3_CCER,1);

			// Enable capture interrupt on each channel
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC1IE = ENABLE;
//			SET_BIT(TIMER3_DIER,1);
			break;

		/******************** CHANNEL 2 ********************/
		case TIMER3_CHANNEL2:
			//CC1s channel is configured as input, IC1 is mapped on TI1
			TIMER3_REG->TIMx_CCMR1.TIMx_CCMR1_CC2S = TIMER3_CCMRx_CC2S_MODE;
//			SET_BIT(TIMER3_CCMR1,0);
//			CLR_BIT(TIMER3_CCMR1,1);

			// Enable capture on each channel
			TIMER3_REG->TIMx_CCER.TIMx_CCER_CC2E = ENABLE;
			TIMER3_REG->TIMx_CCER.TIMx_CCER_CC2P = DISABLE;
//			SET_BIT(TIMER3_CCER,0);
//			CLR_BIT(TIMER3_CCER,1);

			// Enable capture interrupt on each channel
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC2IE = ENABLE;
//			SET_BIT(TIMER3_DIER,1);
			break;

		/******************** CHANNEL 3 ********************/
		case TIMER3_CHANNEL3:
			//CC1s channel is configured as input, IC1 is mapped on TI1
			TIMER3_REG->TIMx_CCMR2.TIMx_CCMR2_CC3S = TIMER3_CCMRx_CC3S_MODE;
	//			SET_BIT(TIMER3_CCMR1,0);
	//			CLR_BIT(TIMER3_CCMR1,1);

			// Enable capture on each channel
			TIMER3_REG->TIMx_CCER.TIMx_CCER_CC3E = ENABLE;
			TIMER3_REG->TIMx_CCER.TIMx_CCER_CC3P = DISABLE;
	//			SET_BIT(TIMER3_CCER,0);
	//			CLR_BIT(TIMER3_CCER,1);

			// Enable capture interrupt on each channel
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC3IE = ENABLE;
	//			SET_BIT(TIMER3_DIER,1);
			break;

		/******************** CHANNEL 3 ********************/
		case TIMER3_CHANNEL4:
			//CC1s channel is configured as input, IC1 is mapped on TI1
			TIMER3_REG->TIMx_CCMR2.TIMx_CCMR2_CC4S = TIMER3_CCMRx_CC4S_MODE;
	//			SET_BIT(TIMER3_CCMR1,0);
	//			CLR_BIT(TIMER3_CCMR1,1);

			// Enable capture on each channel
			TIMER3_REG->TIMx_CCER.TIMx_CCER_CC4E = ENABLE;
			TIMER3_REG->TIMx_CCER.TIMx_CCER_CC4P = DISABLE;
	//			SET_BIT(TIMER3_CCER,0);
	//			CLR_BIT(TIMER3_CCER,1);

			// Enable capture interrupt on each channel
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC4IE = ENABLE;
	//			SET_BIT(TIMER3_DIER,1);
			break;
	}
	// Enable Timer 3
	TIMER3_REG->TIMx_CR1.TIMx_CR1_CEN = ENABLE;

}



u8 TIMER3_u8ICUSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER3_pvICUCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
//		Local_u8ErrorState= NULL_POINTER;
	}
	return Local_u8ErrorState;
}



void 	TIMER3_voidSetPreload(u8 copy_u8Preload)
{
	TIMER3_REG->TIMx_CNT = copy_u8Preload;
}



void 	TIMER3_voidEnableInterrupt(u8 copy_u8ChannelNumber)
{
	switch(copy_u8ChannelNumber)
	{
		case TIMER3_CHANNEL1:
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC1IE = ENABLE;
//			SET_BIT(TIMER2_DIER,1);
			break;
		case TIMER3_CHANNEL2:
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC2IE = ENABLE;
//			SET_BIT(TIMER2_DIER,2);
			break;
		case TIMER3_CHANNEL3:
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC3IE = ENABLE;
//			SET_BIT(TIMER2_DIER,2);
			break;
		case TIMER3_CHANNEL4:
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC4IE = ENABLE;
//			SET_BIT(TIMER2_DIER,2);
			break;
	}
}



void 	TIMER3_voidDisableInterrupt(u8 copy_u8ChannelNumber)
{
	switch(copy_u8ChannelNumber)
	{
		case TIMER3_CHANNEL1:
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC1IE = DISABLE;
//			SET_BIT(TIMER2_DIER,1);
			break;
		case TIMER3_CHANNEL2:
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC2IE = DISABLE;
//			SET_BIT(TIMER2_DIER,2);
			break;
		case TIMER3_CHANNEL3:
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC3IE = DISABLE;
//			SET_BIT(TIMER2_DIER,3);
			break;
		case TIMER3_CHANNEL4:
			TIMER3_REG->TIMx_DIER.TIMx_DIER_CC4IE = DISABLE;
//			SET_BIT(TIMER2_DIER,3);
			break;
	}
}



void 	TIMER3_voidChangePolarity(u8 copy_u8ChannelNumber, u8 copy_u8Edge)
{
	switch(copy_u8Edge)
	{
		case TIMER3_RISING_EDGE:
			switch(copy_u8ChannelNumber)
			{
			case TIMER3_CHANNEL1:
				TIMER3_REG->TIMx_CCER.TIMx_CCER_CC1P = DISABLE;
//				CLR_BIT(TIMER2_CCER,1);
				break;
			case TIMER3_CHANNEL2:
				TIMER3_REG->TIMx_CCER.TIMx_CCER_CC2P = DISABLE;
//				CLR_BIT(TIMER2_CCER,5);
				break;
			case TIMER3_CHANNEL3:
				TIMER3_REG->TIMx_CCER.TIMx_CCER_CC3P = DISABLE;
//				CLR_BIT(TIMER2_CCER,5);
				break;
			case TIMER3_CHANNEL4:
				TIMER3_REG->TIMx_CCER.TIMx_CCER_CC4P = DISABLE;
//				CLR_BIT(TIMER2_CCER,5);
				break;
			}
			break;

		case TIMER3_FALLING_EDGE:
			switch(copy_u8ChannelNumber)
			{
			case TIMER3_CHANNEL1:
				TIMER3_REG->TIMx_CCER.TIMx_CCER_CC1P = ENABLE;
//					SET_BIT(TIMER2_CCER,1);
				break;
			case TIMER3_CHANNEL2:
				TIMER3_REG->TIMx_CCER.TIMx_CCER_CC2P = ENABLE;
//					SET_BIT(TIMER2_CCER,5);
				break;
			case TIMER3_CHANNEL3:
				TIMER3_REG->TIMx_CCER.TIMx_CCER_CC3P = ENABLE;
//					SET_BIT(TIMER2_CCER,5);
				break;
			case TIMER3_CHANNEL4:
				TIMER3_REG->TIMx_CCER.TIMx_CCER_CC4P = ENABLE;
//					SET_BIT(TIMER2_CCER,5);
				break;
			}
			break;
	}
}



u32  	TIMER3_u32GetICUValue(u8 copy_u8ChannelNumber)
{
	u32 u32Value1, u32Value2, u32Value3, u32Value4, returnValue;
	switch(copy_u8ChannelNumber)
	{
		case TIMER3_CHANNEL1:
			u32Value1 = TIMER3_REG->TIMx_CCR1;
			returnValue = u32Value1;
//			u32Value1 = TIMER2_CCR1;
			break;
		case TIMER3_CHANNEL2:
			u32Value2 = TIMER3_REG->TIMx_CCR2;
			returnValue = u32Value2;
//			u32Value2 = TIMER2_CCR2;
			break;
		case TIMER3_CHANNEL3:
			u32Value2 = TIMER3_REG->TIMx_CCR3;
			returnValue = u32Value3;
//			u32Value2 = TIMER2_CCR2;
			break;
		case TIMER3_CHANNEL4:
			u32Value2 = TIMER3_REG->TIMx_CCR4;
			returnValue = u32Value4;
//			u32Value2 = TIMER2_CCR2;
			break;
	}
	return returnValue;
}



/*Timer3 ISR*/
void TIM3_IRQHandler(void)
{
	if(TIMER3_pvICUCallBackFunc != NULL)
	{
		TIMER3_pvICUCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}


