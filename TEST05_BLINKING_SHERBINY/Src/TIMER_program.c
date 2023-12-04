/**********************************************************/
/* Author    :  Hosny & Tariq                             */
/* Date      :  14 Nov 2023                               */
/* Version   :  V01                                       */
/**********************************************************/

#include "ERROR_STATUS.h"
#include "TYPES.h"
#include "MACROS.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"



//void TIMER2_Void_PwmInit(u8 Copy_U8_Channel)
//{
//	/* To disable timer , Enable auto Preload ARR */
//	TIMER_PSC = 15;
//	TIMER_CR1 = 0x0080;
//	TIMER_ARR = 100;
//	switch(Copy_U8_Channel)
//	{
//
//	case TIMER2_CHANNEL1  :
//		/* To Enable Preload register on CCR1 */
//		SET_BIT(TIMER_CCMR1,3);
//		/* To Select PWM MODE 2 */
//		SET_BIT(TIMER_CCMR1,4);
//		SET_BIT(TIMER_CCMR1,5);
//		SET_BIT(TIMER_CCMR1,6);
//		/* To Enable Capture compare to channel 1 */
//		SET_BIT(TIMER_CCER,0);                                 break;
//	case TIMER2_CHANNEL2  :
//		/* To Enable Preload register on CCR2 */
//		SET_BIT(TIMER_CCMR1,11);
//		/* To Select PWM MODE 2 */
//		SET_BIT(TIMER_CCMR1,12);
//		SET_BIT(TIMER_CCMR1,13);
//		SET_BIT(TIMER_CCMR1,14);
//		/* To Enable Capture compare to channel 2 */
//		SET_BIT(TIMER_CCER,4);                                 break;
//	case TIMER2_CHANNEL3 :
//		/* To Enable Preload register on CCR3 */
//		SET_BIT(TIMER_CCMR2,3);
//		/* To Select PWM MODE 2 */
//		SET_BIT(TIMER_CCMR2,4);
//		SET_BIT(TIMER_CCMR2,5);
//		SET_BIT(TIMER_CCMR2,6);
//		/* To Enable Capture compare to channel 3 */
//		SET_BIT(TIMER_CCER,8);                                 break;
//	default              :                                     break;
//
//
//	}
//
//}
//void TIMER2_Void_PwmSetDutyCycle(u8 Copy_U8_Channel,u32 Copy_U32_DutyCycle)
//{
//	switch(Copy_U8_Channel)
//	{
//	case TIMER2_CHANNEL1 :  TIMER_CCR1 = Copy_U32_DutyCycle;           break;
//	case TIMER2_CHANNEL2 :  TIMER_CCR2 = Copy_U32_DutyCycle;           break;
//	case TIMER2_CHANNEL3 :  TIMER_CCR3 = Copy_U32_DutyCycle;           break;
//	default              :                                             break;
//
//	}
//}
//void TIMER2_Void_PwmStart()
//{
//	SET_BIT(TIMER_CR1,0);
//}
//
//
//
//




void TIMER4_Void_PwmInit(u8 Copy_U8_Channel)
{
	/* To disable timer , Enable auto Preload ARR */
	TIMER4_PSC = 2000;
//	TIMER4_CR1 = 0x0080;
	//Auto-reload preload enable
	SET_BIT(TIMER4_CR1,7);
	TIMER4_ARR = 255;
	switch(Copy_U8_Channel)
	{

	case TIMER4_CHANNEL1  :
		/* To Enable Preload register on CCR1 */
		SET_BIT(TIMER4_CCMR1,3);
		/* To Select PWM MODE 2 */
		CLR_BIT(TIMER4_CCMR1,4);
		SET_BIT(TIMER4_CCMR1,5);
		SET_BIT(TIMER4_CCMR1,6);
		/* To Enable Capture compare to channel 1 */
		SET_BIT(TIMER4_CCER,0);                                 break;
	case TIMER4_CHANNEL2  :
		/* To Enable Preload register on CCR2 */
		SET_BIT(TIMER4_CCMR1,11);
		/* To Select PWM MODE 2 */
		CLR_BIT(TIMER4_CCMR1,12);
		SET_BIT(TIMER4_CCMR1,13);
		SET_BIT(TIMER4_CCMR1,14);
		/* To Enable Capture compare to channel 2 */
		SET_BIT(TIMER4_CCER,4);                                 break;

	case TIMER4_CHANNEL3 :
		/* To Enable Preload register on CCR3 */
		SET_BIT(TIMER4_CCMR2,3);
		/* To Select PWM MODE 2 */
		CLR_BIT(TIMER4_CCMR2,4);
		SET_BIT(TIMER4_CCMR2,5);
		SET_BIT(TIMER4_CCMR2,6);
		/* To Enable Capture compare to channel 3 */
		SET_BIT(TIMER4_CCER,8);break;
	case TIMER4_CHANNEL4 :
		/* To Enable Preload register on CCR4 */
		SET_BIT(TIMER4_CCMR2,11);
		/* To Select PWM MODE 2 */
		CLR_BIT(TIMER4_CCMR2,12);
		SET_BIT(TIMER4_CCMR2,13);
		SET_BIT(TIMER4_CCMR2,14);
		/* To Enable Capture compare to channel 3 */
		SET_BIT(TIMER4_CCER,12);
		break;
	default:
		break;

	}

//	TIMER4_CCR1=0;
//	TIMER4_CCR2=0;
//	TIMER4_CCR3=0;
//	TIMER4_CCR4=0;
	SET_BIT(TIMER4_CCMR2,10);
	SET_BIT(TIMER4_CCMR2,2);
	SET_BIT(TIMER4_CCMR2,3);
	// Enable Timer4 peripheral
	SET_BIT(TIMER4_CR1,0);
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
//void TIMER4_Void_PwmStart()
//{
//	SET_BIT(TIMER4_CR1,0);
//}



