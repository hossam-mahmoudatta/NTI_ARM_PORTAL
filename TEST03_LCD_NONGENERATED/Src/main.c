
#include <MOTOR_INTERFACE.h>
#include <stdint.h>
#include <TIMER2_INTERFACE.h>
#include <TIMER2_PRIVATE.h>
#include <TIMER4_INTERFACE.h>

#include "ERROR_STATUS.h"
#include "MACROS.h"
#include "TYPES.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "lcd.h"
#include "SYSTICK_INTERFACE.h"
#include "DELAY_INTERFACE.h"
#include "NVIC_INTERFACE.h"

u32 volatile IC2_Val1 = 0;
u32 volatile IC2_Val2 = 0;
u32 volatile Difference2 = 0;
u8 volatile Is_First_Captured2 = 0;  // is the first value captured ?
u8 volatile Distance2  = 0;

u32 volatile IC1_Val1 = 0;
u32 volatile IC1_Val2 = 0;
u32 volatile Difference1 = 0;
u8 volatile Is_First_Captured1 = 0;  // is the first value captured ?
u8 volatile Distance1  = 0;
u8 Received_distanceOne=0,Received_distanceTwo=0;
//void TIM3(void)
//{
//	MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
//	Is_First_Captured++;
//	if(GET_BIT(TIMER3_SR,1)==1)
//	{
//
//		SET_BIT(TIMER3_SR,1);
//
//	if(Is_First_Captured==1)
//	{
//
//		IC_Val1=TIMER3_CCR1;
//		//Is_First_Captured = 1;  // set the first captured as true
//		// Now change the polarity to falling edge
//		SET_BIT(TIMER3_CCER,1);
//	}
//	else if (Is_First_Captured==2)   // if the first is already captured
//	{
//		IC_Val2 = TIMER3_CCR1 ; // read second value
//
//		// Now change the polarity to rising edge
//		CLR_BIT(TIMER3_CCER,1);
//		// disable capture interrupt on each channel
//		CLR_BIT(TIMER3_DIER,1);
//
//
//	}
//	}
//}

//void TIM(void)
//{
//	MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
//	Is_First_Captured++;
//	if(GET_BIT(TIMER2_SR,1)==1)
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

void TIM2(void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
	Is_First_Captured2++;
	Is_First_Captured1++;
	if(GET_BIT(TIMER2_SR,1)==1)
	{
		SET_BIT(TIMER2_SR,1);
		if(Is_First_Captured1==1)
		{

			IC1_Val1=Timer2_VoidGetCapturedValue(Channle1);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer2_VoidChangePolarityOnEachChannle(Channle1,TIMER2_FALLING_EDGE);
		}
		else if (Is_First_Captured1==2)   // if the first is already captured
		{
			IC1_Val2 = Timer2_VoidGetCapturedValue(Channle1) ; // read second value

			// Now change the polarity to rising edge

			Timer2_VoidChangePolarityOnEachChannle(Channle1,TIMER2_RISING_EDGE);
			// disable capture interrupt on each channel
			Timer2_VoidDisableIntOnEachChannle(Channle1);


		}

	}
	if(GET_BIT(TIMER2_SR,2)==1)
	{

		SET_BIT(TIMER2_SR,2);

		if(Is_First_Captured2==1)
		{

			IC2_Val1=Timer2_VoidGetCapturedValue(Channle2);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer2_VoidChangePolarityOnEachChannle(Channle2,TIMER2_FALLING_EDGE);
		}
		else if (Is_First_Captured2==2)   // if the first is already captured
		{
			IC2_Val2 = Timer2_VoidGetCapturedValue(Channle2) ; // read second value

			// Now change the polarity to rising edge

			Timer2_VoidChangePolarityOnEachChannle(Channle2,TIMER2_RISING_EDGE);
			// disable capture interrupt on each channel
			Timer2_VoidDisableIntOnEachChannle(Channle2);


		}
	}
}

void Ultrasonic_TrigOne (void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN6, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOA, PIN6, LOW);  // pull the TRIG pin low
}
void Ultrasonic_TrigTwo (void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN5, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOA, PIN5, LOW);  // pull the TRIG pin low
}

void Ultrasonic_TrigThree (void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN2, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOA, PIN6, LOW);  // pull the TRIG pin low
}
void Ultrasonic_TrigFour (void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN3, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOA, PIN5, LOW);  // pull the TRIG pin low
}


u8 Ultrasonic_ReadOne (void)
{
	Timer2_VoidSetPreload(0);
	Ultrasonic_TrigOne();
	while(Is_First_Captured1<2);
	Difference1 = IC1_Val2-IC1_Val1;
	Distance1 = (Difference1 /58);
	Is_First_Captured1=0;
	Timer2_VoidEnableIntOnEachChannle(Channle1);
	return Distance1;

}
u8 Ultrasonic_ReadTwo (void)
{
	Timer2_VoidSetPreload(0);
	Ultrasonic_TrigTwo();
	while(Is_First_Captured2<2);
	Difference2 = IC2_Val2-IC2_Val1;
	Distance2 = (Difference2 /58);
	Is_First_Captured2=0;
	Timer2_VoidEnableIntOnEachChannle(Channle2);
	return Distance2;
}
u8 Ultrasonic_ReadThree (void)
{
	Timer2_VoidSetPreload(0);
	Ultrasonic_TrigThree();
	while(Is_First_Captured1<2);
	Difference3 = IC1_Val2-IC1_Val1;
	Distance1 = (Difference1 /58);
	Is_First_Captured1=0;
	Timer2_VoidEnableIntOnEachChannle(Channle1);
	return Distance1;

}
u8 Ultrasonic_ReadFour (void)
{
	Timer2_VoidSetPreload(0);
	Ultrasonic_TrigFour();
	while(Is_First_Captured2<2);
	Difference4 = IC2_Val2-IC2_Val1;
	Distance2 = (Difference2 /58);
	Is_First_Captured2=0;
	Timer2_VoidEnableIntOnEachChannle(Channle2);
	return Distance2;
}


int main(void)
{

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM2_RCC);
	//	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM3_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOA_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOB_RCC);

	MNVIC_VidEnablePeripheral(TIM2_C);
	//	MNVIC_VidEnablePeripheral(TIM3_C);
	/*Echo1*/
	MGPIO_VidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);
	/*Echo2*/
	MGPIO_VidSetPinDirection(GPIOA,PIN1,INPUT_FLOATING);
	//	//Echo timer3
	//	MGPIO_VidSetPinDirection(GPIOA,PIN6,INPUT_FLOATING);

	/*TIRG1*/
	MGPIO_VidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_PP);
	/*TIRG2*/
	MGPIO_VidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_PP);

	/*led*/
	MGPIO_VidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);
	// Enable the clock for Timer 3

	Timer2_u8InputCaptureSetCallBack(&TIM2);
	CLCD_voidInit();



	//	CLCD_voidSendData('C');
	CLCD_voidSendString("Hosny");
	_delay_ms(1000);
	TIMER2_VoidInitInputCapture(Channle2);
	TIMER2_VoidInitInputCapture(Channle1);
	//	TIMER3_VoidInitInputCapture(Channle1);
	/* Loop forever */
	for(;;){
		CLCD_voidGoToXY(0, 0);
		CLCD_voidSendString("D1:");
		Received_distanceOne=Ultrasonic_ReadOne();
		CLCD_voidWriteNumber(Received_distanceOne);
		//CLCD_voidSendString("   ");
		_delay_ms(200);

		CLCD_voidGoToXY(0, 1);
		CLCD_voidSendString("D2:");
		Received_distanceTwo=Ultrasonic_ReadTwo();
		CLCD_voidWriteNumber(Received_distanceTwo);
		_delay_ms(200);

		//CLCD_voidSendString("   ");
		//		CLCD_voidGoToXY(0, 0);
		//		CLCD_voidSendString("D1:");
		//		CLCD_voidGoToXY(0, 1);
		//		CLCD_voidSendString("D2:");
		//		Received_distanceOne=Ultrasonic_ReadOne();
		//		Received_distanceTwo=Ultrasonic_ReadTwo();
		//		CLCD_voidGoToXY(3, 0);
		//		CLCD_voidWriteNumber(Received_distanceOne);
		//		CLCD_voidGoToXY(3, 1);
		//		CLCD_voidWriteNumber(Received_distanceTwo);
		//		CLCD_voidSendString("   ");
		//		_delay_ms(800);




	}
}
