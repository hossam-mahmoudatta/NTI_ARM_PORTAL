
#include <stdint.h>

#include "ERROR_STATUS.h"
#include "MACROS.h"
#include "TYPES.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "lcd.h"
#include "SYSTICK_INTERFACE.h"
#include "DELAY_INTERFACE.h"
#include "MOTOR_interface.h"
//#include "TIMER4_interface.h"
#include "TIMER3_interface.h"
#include "TIMER3_private.h"

#include "NVIC_INTERFACE.h"

u32 volatile IC_Val1 = 0;
u32 volatile IC_Val2 = 0;
u32 volatile Difference = 0;
u8 volatile Is_First_Captured = 0;  // is the first value captured ?
u8 volatile Distance  = 0;

void TIM3(void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
	Is_First_Captured++;
	if(GET_BIT(TIMER3_SR,1)==1)
	{

		SET_BIT(TIMER3_SR,1);

	if(Is_First_Captured==1)
	{

		IC_Val1=TIMER3_CCR1;
		//Is_First_Captured = 1;  // set the first captured as true
		// Now change the polarity to falling edge
		SET_BIT(TIMER3_CCER,1);
	}
	else if (Is_First_Captured==2)   // if the first is already captured
	{
		IC_Val2 = TIMER3_CCR1 ; // read second value

		// Now change the polarity to rising edge
		CLR_BIT(TIMER3_CCER,1);
		// disable capture interrupt on each channel
		CLR_BIT(TIMER3_DIER,1);


	}
	}
}

//void TIM3(void)
//{
//	MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
//	Is_First_Captured++;
//	if(GET_BIT(TIMER_SR,1)==1)
//	{
//
//		SET_BIT(TIMER2_SR,1);
//
//	if(Is_First_Captured==1)
//	{
//
//		IC_Val1=TIMER2_CCR1;
//		//Is_First_Captured = 1;  // set the first captured as true
//		// Now change the polarity to falling edge
//		SET_BIT(TIMER2_CCER,1);
//	}
//	else if (Is_First_Captured==2)   // if the first is already captured
//	{
//		IC_Val2 = TIMER2_CCR1 ; // read second value
//
//		// Now change the polarity to rising edge
//		CLR_BIT(TIMER2_CCER,1);
//		// disable capture interrupt on each channel
//		CLR_BIT(TIMER2_DIER,1);
//
//
//	}
//	}
//}

void HCSR04_Read (void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN5, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOA, PIN5, LOW);  // pull the TRIG pin low
}
int main(void)
{

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM2_RCC);
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM3_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOA_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOB_RCC);

	//MNVIC_VidEnablePeripheral(TIM2_C);
	MNVIC_VidEnablePeripheral(TIM3_C);
	/*Echo*/
	MGPIO_VidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);
	//Echo timer3
	MGPIO_VidSetPinDirection(GPIOA,PIN6,INPUT_FLOATING);
	/*TIRG*/
	MGPIO_VidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_PP);

	/*led*/
	MGPIO_VidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);
	// Enable the clock for Timer 3

	Timer3_u8InputCaptureSetCallBack(&TIM3);
	CLCD_voidInit();



	CLCD_voidSendData('B');
	_delay_ms(1000);
//	TIMER2_VoidInitInputCapture(Channle1);
//	TIMER3_VoidInitInputCapture(Channle1);
	/* Loop forever */
	for(;;){
		 Timer3_VoidSetPreload(0);

		HCSR04_Read();
		CLCD_voidSendString("  ");
		CLCD_voidGoToXY(0, 0);
		while(Is_First_Captured<2);
		Difference = IC_Val2-IC_Val1;
		Distance = (Difference /58);

		CLCD_voidWriteNumber(Distance);
		Is_First_Captured=0;

		_delay_ms(800);
		SET_BIT(TIMER3_DIER,1);



	}
}
