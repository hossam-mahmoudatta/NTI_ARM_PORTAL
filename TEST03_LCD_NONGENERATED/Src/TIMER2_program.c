#include <TIMER2_INTERFACE.h>
#include <TIMER2_PRIVATE.h>
#include "BIT_MATH.h"
#include "TYPES.h"
#include "ERROR_STATUS.h"

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



