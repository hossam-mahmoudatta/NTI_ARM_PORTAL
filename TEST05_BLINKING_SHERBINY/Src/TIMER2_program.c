#include "BIT_MATH.h"
#include "TYPES.h"
#include "ERROR_STATUS.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"

/*Global pointer to function to hold the callback function address*/
static void (*TIMER2_pvInputCaptureCallBackFunc)(void) = NULL;

void TIMER2_VoidInitInputCapture(u8 Copy_ChannleNumber)
{

	//prescaler for 8Mhz
	TIMER2_PSC=8-1;

	TIMER2_CNT=0;

	//configure input capture for selected channle
	switch(Copy_ChannleNumber)
	{
	case Channle1:

		//CC1s channel is configured as input, IC1 is mapped on TI1
		SET_BIT(TIMER2_CCMR1,0);
		CLR_BIT(TIMER2_CCMR1,1);
		// Enable capture on each channel
		SET_BIT(TIMER2_CCER,0);
		CLR_BIT(TIMER2_CCER,1);


		// Enable capture interrupt on each channel
		SET_BIT(TIMER2_DIER,1);
		break;
	case Channle2:

		//CC2 channel is configured as input, IC2 is mapped on TI2
		SET_BIT(TIMER2_CCMR1,8);
		CLR_BIT(TIMER2_CCMR1,9);
		// Enable capture on each channel,CC2E: Capture/Compare 2 output enable
		SET_BIT(TIMER2_CCER,4);

		CLR_BIT(TIMER2_CCER,5);


		// Enable capture interrupt on each channel
		SET_BIT(TIMER2_DIER,2);
		break;
	}

	// Enable Timer 3
	SET_BIT(TIMER2_CR1,0);

}
u8 Timer2_u8InputCaptureSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER2_pvInputCaptureCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		//		Local_u8ErrorState= NULL_POINTER;
	}

	return Local_u8ErrorState;

}

void Timer2_VoidSetPreload(u8 Copy_u8Preload)
{
	TIMER2_CNT = Copy_u8Preload;
}

void Timer2_VoidEnableIntOnEachChannle(u8 Copy_ChannleNumber)
{
	switch(Copy_ChannleNumber)
	{
	case Channle1:
		SET_BIT(TIMER2_DIER,1);
		break;
	case Channle2:
		SET_BIT(TIMER2_DIER,2);
		break;

	}
}
void Timer2_VoidDisableIntOnEachChannle(u8 Copy_ChannleNumber)
{
	switch(Copy_ChannleNumber)
	{
	case Channle1:
		CLR_BIT(TIMER2_DIER,1);
		break;
	case Channle2:
		CLR_BIT(TIMER2_DIER,2);
		break;

	}

}
void Timer2_VoidChangePolarityOnEachChannle(u8 Copy_ChannleNumber,u8 Copy_Edge)
{
	switch(Copy_Edge)
	{
	case TIMER2_RISING_EDGE:
		switch(Copy_ChannleNumber)
		{
		case Channle1:
			CLR_BIT(TIMER2_CCER,1);
			break;
		case Channle2:
			CLR_BIT(TIMER2_CCER,5);
			break;
		}
		break;

		case TIMER2_FALLING_EDGE:
			switch(Copy_ChannleNumber)
			{
			case Channle1:
				SET_BIT(TIMER2_CCER,1);
				break;
			case Channle2:
				SET_BIT(TIMER2_CCER,5);
				break;
			}
			break;
	}
}
u32  Timer2_VoidGetCapturedValue(u8 Copy_ChannleNumber)
{
	u32 Value1,Value2;
	switch(Copy_ChannleNumber)
	{
	case Channle1:
		 Value1=TIMER2_CCR1;
		return Value1;
		break;
	case Channle2:
		Value2=TIMER2_CCR2;
		return Value2;
		break;

	}

}
/*Timer2 ISR*/
void TIM2_IRQHandler(void)
{
	if(TIMER2_pvInputCaptureCallBackFunc != NULL)
	{
		TIMER2_pvInputCaptureCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}



