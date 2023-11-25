#include "BIT_MATH.h"
#include "TYPES.h"
#include "ERROR_STATUS.h"
#include "RCC_INTERFACE.h"
#include "TIMER3_interface.h"
#include "TIMER3_private.h"
#include "NVIC_INTERFACE.h"

/*Global pointer to function to hold the callback function address*/
static void (*TIMER3_pvInputCaptureCallBackFunc)(void) = NULL;

void TIMER3_VoidInitInputCapture(u8 Copy_ChannleNumber)
{

	//prescaler for 8Mhz
	TIMER3_PSC=8-1;

	TIMER3_CNT=0;

	//configure input capture for selected channle
	switch(Copy_ChannleNumber)
	{
	case Channle1:

		//CC1s channel is configured as input, IC1 is mapped on TI1
		SET_BIT(TIMER3_CCMR1,0);
		CLR_BIT(TIMER3_CCMR1,1);
		// Enable capture on each channel
		SET_BIT(TIMER3_CCER,0);
		CLR_BIT(TIMER3_CCER,1);

		// Enable capture interrupt on each channel
		SET_BIT(TIMER3_DIER,1);
		break;
	}
	// Enable Timer 3
	SET_BIT(TIMER3_CR1,0);

}
u8 Timer3_u8InputCaptureSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER3_pvInputCaptureCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		//		Local_u8ErrorState= NULL_POINTER;
	}

	return Local_u8ErrorState;

}

void Timer3_VoidSetPreload(u8 Copy_u8Preload)
{
	TIMER3_CNT = Copy_u8Preload;
}


void Timer3_VoidEnableIntOnEachChannle(u8 Copy_ChannleNumber)
{
	switch(Copy_ChannleNumber)
	{
	case Channle1:
		SET_BIT(TIMER3_DIER,1);
		break;
	case Channle2:
		SET_BIT(TIMER3_DIER,2);
		break;
	}
}
void Timer3_VoidDisableIntOnEachChannle(u8 Copy_ChannleNumber)
{
		switch(Copy_ChannleNumber)
		{
		case Channle1:
			CLR_BIT(TIMER3_DIER,1);
			break;
		case Channle2:
			CLR_BIT(TIMER3_DIER,2);
			break;
		}
}

void Timer3_VoidChangePolarityOnEachChannle(u8 Copy_ChannleNumber,u8 Copy_Edge)
{
	switch(Copy_Edge)
	{
	case TIMER3_RISING_EDGE:
		switch(Copy_ChannleNumber)
		{
		case Channle1:
			CLR_BIT(TIMER3_CCER,1);
			break;
		case Channle2:
			CLR_BIT(TIMER3_CCER,5);
			break;
		}
		break;

		case TIMER3_FALLING_EDGE:
			switch(Copy_ChannleNumber)
			{
			case Channle1:
				SET_BIT(TIMER3_CCER,1);
				break;
			case Channle2:
				SET_BIT(TIMER3_CCER,5);
				break;
			}
			break;
	   }
}

u32  Timer3_VoidGetCapturedValue(u8 Copy_ChannleNumber)
{
u32 Value1,Value2;
	switch(Copy_ChannleNumber)
	{
	case Channle1:
		Value1=TIMER3_CCR1;
		return Value1;
		break;
	case Channle2:
	    Value2=TIMER3_CCR2;
	    return Value2;
		break;
	}
}


/*Timer3 ISR*/
void TIM3_IRQHandler(void)
{
	if(TIMER3_pvInputCaptureCallBackFunc != NULL)
	{
		TIMER3_pvInputCaptureCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}
}


