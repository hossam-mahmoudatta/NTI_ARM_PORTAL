#include <stdint.h>

#include "ERROR_STATUS.h"
#include "MACROS.h"
#include "TYPES.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "DELAY_INTERFACE.h"
#include "MOTOR_interface.h"
#include "TIMER_interface.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER3_interface.h"
#include "TIMER3_private.h"
#include "NVIC_INTERFACE.h"
#include "USART_INTERFACE.h"

#define CA_ADAS_FORWARD_STATE 	1
#define CA_ADAS_RIGHT_STATE 			2
#define CA_ADAS_LEFT_STATE 			3
#define CA_ADAS_REVERSE_STATE 		4

u8 g_u8Flag = CA_ADAS_FORWARD_STATE;




u32 volatile IC1_Val1 = 0;
u32 volatile IC1_Val2 = 0;
u32 volatile Difference1 = 0;
u8 volatile Is_First_Captured1 = 0;  // is the first value captured ?
u8 volatile Distance1  = 0;

u32 volatile IC2_Val1 = 0;
u32 volatile IC2_Val2 = 0;
u32 volatile Difference2 = 0;
u8 volatile Is_First_Captured2 = 0;  // is the first value captured ?
u8 volatile Distance2  = 0;

u32 volatile IC3_Val1 = 0;
u32 volatile IC3_Val2 = 0;
u32 volatile Difference3 = 0;
u8 volatile Is_First_Captured3 = 0;  // is the first value captured ?
u8 volatile Distance3  = 0;

u32 volatile IC4_Val1 = 0;
u32 volatile IC4_Val2 = 0;
u32 volatile Difference4 = 0;
u8 volatile Is_First_Captured4 = 0;  // is the first value captured ?
u8 volatile Distance4  = 0;

u32 volatile IC5_Val1 = 0;
u32 volatile IC5_Val2 = 0;
u32 volatile Difference5 = 0;
u8 volatile Is_First_Captured5 = 0;  // is the first value captured ?
u8 volatile Distance5  = 0;

u8 Received_distanceOne=0,Received_distanceTwo=0;
u8 Received_distanceThree=0,Received_distanceFour=0, Received_distanceFive = 0;

void TIM2(void)
{
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


void TIM3(void)
{
	Is_First_Captured3++;
	Is_First_Captured4++;
	Is_First_Captured5++;
	if(GET_BIT(TIMER3_SR,1)==1)
	{

		SET_BIT(TIMER3_SR,1);

		if(Is_First_Captured3==1)
		{

			IC3_Val1=Timer3_VoidGetCapturedValue(Channle1);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			Timer3_VoidChangePolarityOnEachChannle(Channle1,TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured3==2)   // if the first is already captured
		{
			IC3_Val2 = Timer3_VoidGetCapturedValue(Channle1) ; // read second value

			// Now change the polarity to rising edge

			Timer3_VoidChangePolarityOnEachChannle(Channle1,TIMER3_RISING_EDGE);
			// disable capture interrupt on each channel
			Timer3_VoidDisableIntOnEachChannle(Channle1);


		}
	}
	if(GET_BIT(TIMER3_SR,2)==1)
	{

		SET_BIT(TIMER3_SR,2);

		if(Is_First_Captured4==1)
		{

			IC4_Val1=Timer3_VoidGetCapturedValue(Channle2);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer3_VoidChangePolarityOnEachChannle(Channle2,TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured4==2)   // if the first is already captured
		{
			IC4_Val2 = Timer3_VoidGetCapturedValue(Channle2) ; // read second value

			// Now change the polarity to rising edge

			Timer3_VoidChangePolarityOnEachChannle(Channle2,TIMER3_RISING_EDGE);
			// disable capture interrupt on each channel
			Timer3_VoidDisableIntOnEachChannle(Channle2);
		}
	}
	if(GET_BIT(TIMER3_SR,3)==1)
	{
		SET_BIT(TIMER3_SR,3);

		if(Is_First_Captured5==1)
		{

			IC5_Val1=Timer3_VoidGetCapturedValue(Channle3);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer3_VoidChangePolarityOnEachChannle(Channle3,TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured5==2)   // if the first is already captured
		{
			IC5_Val2 = Timer3_VoidGetCapturedValue(Channle3) ; // read second value

			// Now change the polarity to rising edge

			Timer3_VoidChangePolarityOnEachChannle(Channle3,TIMER3_RISING_EDGE);
			// disable capture interrupt on each channel
			Timer3_VoidDisableIntOnEachChannle(Channle3);
		}
	}
	if(GET_BIT(TIMER3_SR,4)==1)
	{
		SET_BIT(TIMER3_SR,4);

		if(Is_First_Captured5==1)
		{

			IC5_Val1=Timer3_VoidGetCapturedValue(Channle4);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer3_VoidChangePolarityOnEachChannle(Channle4,TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured5==2)   // if the first is already captured
		{
			IC5_Val2 = Timer3_VoidGetCapturedValue(Channle4) ; // read second value

			// Now change the polarity to rising edge

			Timer3_VoidChangePolarityOnEachChannle(Channle4,TIMER3_RISING_EDGE);
			// disable capture interrupt on each channel
			Timer3_VoidDisableIntOnEachChannle(Channle4);
		}
	}
}



void Ultrasonic_TrigOne (void)
{
	MGPIO_VidSetPinValue(GPIOB, PIN5, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOB, PIN5, LOW);  // pull the TRIG pin low
}
void Ultrasonic_TrigTwo (void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN2, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOA, PIN2, LOW);  // pull the TRIG pin low
}
void Ultrasonic_TrigThree (void)
{
	MGPIO_VidSetPinValue(GPIOB, PIN0, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOB, PIN0, LOW);  // pull the TRIG pin low
}
void Ultrasonic_TrigFour (void)
{
	MGPIO_VidSetPinValue(GPIOB, PIN10, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOB, PIN10, LOW);  // pull the TRIG pin low
}
void Ultrasonic_TrigFive (void)
{
	MGPIO_VidSetPinValue(GPIOA, PIN3, HIGH);  // pull the TRIG pin HIGH
	_delay_us(10);  // wait for 10 us
	MGPIO_VidSetPinValue(GPIOA, PIN3, LOW);  // pull the TRIG pin low
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
	return Distance1+1;

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
	Timer3_VoidSetPreload(0);
	Ultrasonic_TrigThree();
	while(Is_First_Captured3<2);
	Difference3 = IC3_Val2-IC3_Val1;
	Distance3 = (Difference3 /58);
	Is_First_Captured3=0;
	Timer3_VoidEnableIntOnEachChannle(Channle1);
	return Distance3;
}
u8 Ultrasonic_ReadFour (void)
{
	Timer3_VoidSetPreload(0);
	Ultrasonic_TrigFour();
	while(Is_First_Captured4<2);
	Difference4 = IC4_Val2-IC4_Val1;
	Distance4 = (Difference4 /58);
	Is_First_Captured4=0;
	Timer3_VoidEnableIntOnEachChannle(Channle2);
	return Distance4;
}

u8 Ultrasonic_ReadFive (void)
{
	Timer3_VoidSetPreload(0);
	Ultrasonic_TrigFive();
	while(Is_First_Captured5<2);
	Difference5 = IC5_Val2-IC5_Val1;
	Distance5 = (Difference5 /58);
	Is_First_Captured5=0;
	Timer3_VoidEnableIntOnEachChannle(Channle4);
	return Distance5;
}



void APP_voidAutoParking()
{
	//		Received_distanceTwo=Ultrasonic_ReadTwo();
	//		_delay_ms(100);
	//		while(Received_distanceTwo>10)
	//		{
	//			Received_distanceTwo=Ultrasonic_ReadTwo();
	//
	//			MOTOR_RF_GO_BACKWARD();
	//			MOTOR_LF_GO_BACKWARD();
	//			_delay_ms(100);
	//		}
	//		MOTOR_RF_STOP();
	//		MOTOR_LF_STOP();


	//    Received_distanceOne=Ultrasonic_ReadOne();
	//    _delay_ms(100);
	//	Received_distanceTwo=Ultrasonic_ReadTwo();
	//	_delay_ms(100);
	Received_distanceThree=Ultrasonic_ReadThree();
	_delay_ms(100);
	Received_distanceFour=Ultrasonic_ReadFour();
	_delay_ms(100);
	if(Received_distanceThree>20  && Received_distanceFour>20 )
	{
		Received_distanceFour=Ultrasonic_ReadFour();
		_delay_ms(100);
		while(Received_distanceFour>20)
		{
			Received_distanceFour=Ultrasonic_ReadFour();
			_delay_ms(100);
			MOTOR_RF_GO_FORWARD();
			MOTOR_LF_GO_FORWARD();

		}
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();

		MOTOR_RF_GO_BACKWARD();
		MOTOR_LF_GO_BACKWARD();
		_delay_ms(400);
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();

		//move LF backward
		MOTOR_LF_GO_BACKWARD();
		_delay_ms(1000);
		MOTOR_LF_STOP();




		MOTOR_LF_Void_MotorSetSpeed(110);
		//			MOTOR_RF_GO_BACKWARD();
		//			MOTOR_LF_GO_BACKWARD();
		//			_delay_ms(1000);
		//			MOTOR_RF_STOP();
		//			MOTOR_LF_STOP();
		Received_distanceTwo=Ultrasonic_ReadTwo();
		_delay_ms(100);
		if(Received_distanceTwo>2)
		{
			while(Received_distanceTwo>20)
			{
				Received_distanceTwo=Ultrasonic_ReadTwo();
				_delay_ms(100);
				MOTOR_RF_GO_BACKWARD();
				MOTOR_LF_GO_BACKWARD();

			}
			MOTOR_RF_STOP();
			MOTOR_LF_STOP();

		}

		// p>>B
		MOTOR_LF_Void_MotorSetSpeed(100);
		MOTOR_LF_GO_FORWARD();
		MOTOR_RF_GO_BACKWARD();
		_delay_ms(500);
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();

		_delay_ms(1000);

		MOTOR_RF_Void_MotorSetSpeed(55);
		MOTOR_LF_Void_MotorSetSpeed(65);
		Received_distanceOne=Ultrasonic_ReadOne();
		_delay_ms(100);
		if(Received_distanceOne>7)
		{
			while(Received_distanceOne>7)
			{
				Received_distanceOne=Ultrasonic_ReadOne();
				_delay_ms(100);
				MOTOR_RF_GO_FORWARD();
				MOTOR_LF_GO_FORWARD();

			}
			MOTOR_RF_STOP();
			MOTOR_LF_STOP();

		}
		while(1);
	}
	else
	{
		MOTOR_RF_Void_MotorSetSpeed(75);
		MOTOR_LF_Void_MotorSetSpeed(75);
		MOTOR_RF_GO_FORWARD();
		MOTOR_LF_GO_FORWARD();
	}
}



void APP_voidCollisionAvoidance(void)
{
	/* Reads the Distances for the responsible sensors */
	Received_distanceOne = Ultrasonic_ReadOne();
	_delay_ms(100);
	Received_distanceTwo = Ultrasonic_ReadTwo();
	_delay_ms(100);
	Received_distanceThree = Ultrasonic_ReadThree();
	_delay_ms(100);
//	Received_distanceFour = Ultrasonic_ReadFour();
//	_delay_ms(100);
	Received_distanceFive = Ultrasonic_ReadFive();
	_delay_ms(100);

	switch(g_u8Flag)
	{
	/***************************************************************************/
		case CA_ADAS_FORWARD_STATE:
			if(Received_distanceOne > 10)
			{
				MOTOR_RF_GO_FORWARD();
				MOTOR_LF_GO_FORWARD();
			}
			else
			{
				MOTOR_RF_STOP();
				MOTOR_LF_STOP();
				_delay_ms(1500);
				g_u8Flag = CA_ADAS_RIGHT_STATE;
			}
			break;
		/***************************************************************************/
		case CA_ADAS_RIGHT_STATE:
			if(Received_distanceThree > 20)
			{
				MOTOR_RF_GO_BACKWARD();
				MOTOR_LF_GO_FORWARD();
				_delay_ms(400);
				MOTOR_RF_STOP();
				MOTOR_LF_STOP();
				_delay_ms(1500);
				g_u8Flag = CA_ADAS_FORWARD_STATE;
			}
			else
			{
				g_u8Flag = CA_ADAS_LEFT_STATE;
			}
			break;
		/***************************************************************************/
		case CA_ADAS_LEFT_STATE:
			if(Received_distanceFive > 20)
			{
				MOTOR_RF_GO_FORWARD();
				MOTOR_LF_GO_BACKWARD();
				_delay_ms(400);
				MOTOR_RF_STOP();
				MOTOR_LF_STOP();
				_delay_ms(1500);
				g_u8Flag = CA_ADAS_FORWARD_STATE;
			}
			else
			{
				g_u8Flag = CA_ADAS_REVERSE_STATE;
			}
			break;
		/***************************************************************************/
		case CA_ADAS_REVERSE_STATE:
			if(Received_distanceTwo > 20)
			{
				if(Received_distanceThree < 20)
				{
					MOTOR_RF_GO_BACKWARD();
					MOTOR_LF_GO_BACKWARD();
				}
				else if(Received_distanceThree > 20)
				{
					MOTOR_RF_STOP();
					MOTOR_LF_STOP();
					_delay_ms(1500);
					g_u8Flag = CA_ADAS_RIGHT_STATE;
				}
			}
			else
			{
				MOTOR_RF_STOP();
				MOTOR_LF_STOP();
			}
			break;
	}
}



void APP_voidUltrasonicUnitTest(void)
{

	u16 LOC_u16ReadDistance;

	LOC_u16ReadDistance = Ultrasonic_ReadFour();
	_delay_ms(100);

	if(LOC_u16ReadDistance < 10)
	{
//		MOTOR_RF_STOP();
		MOTOR_LF_STOP();
		//MOTOR_LF_GO_BACKWARD();
		//MOTOR_RF_GO_BACKWARD();
		MOTOR_RF_GO_FORWARD();
	}
	else if(LOC_u16ReadDistance > 10)
	{

		MOTOR_LF_GO_FORWARD();
		MOTOR_RF_STOP();
	}

}

int main(void)
{

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM2_RCC);
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM3_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOA_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOB_RCC);
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM4_RCC);

	/*Enable Interupt for each timer*/
	MNVIC_VidEnablePeripheral(TIM2_C);
	MNVIC_VidEnablePeripheral(TIM3_C);
	//timer2
	/*Echo1*/
	MGPIO_VidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);
	/*Echo2*/
	MGPIO_VidSetPinDirection(GPIOA,PIN1,INPUT_FLOATING);
	/*Echo3*/
	MGPIO_VidSetPinDirection(GPIOA,PIN6,INPUT_FLOATING);
	/*Echo4*/
	MGPIO_VidSetPinDirection(GPIOA,PIN7,INPUT_FLOATING);
	/*Echo5*/
	MGPIO_VidSetPinDirection(GPIOB,PIN1,INPUT_FLOATING);

	/*TIRG1*/
	MGPIO_VidSetPinDirection(GPIOB, PIN5, OUTPUT_SPEED_10MHZ_PP);
	/*TIRG2*/
	MGPIO_VidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_PP);
	/*TIRG3*/
	MGPIO_VidSetPinDirection(GPIOB, PIN0, OUTPUT_SPEED_10MHZ_PP);
	/*TIRG4*/
	MGPIO_VidSetPinDirection(GPIOB, PIN10, OUTPUT_SPEED_10MHZ_PP);
	/*TIRG5*/
	MGPIO_VidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_10MHZ_PP);

	/*SetCallBack*/
	Timer2_u8InputCaptureSetCallBack(&TIM2);
	Timer3_u8InputCaptureSetCallBack(&TIM3);
	/*Inizailize channle*/
	TIMER2_VoidInitInputCapture(Channle1);
	TIMER2_VoidInitInputCapture(Channle2);
	TIMER3_VoidInitInputCapture(Channle1);
	TIMER3_VoidInitInputCapture(Channle2);
	TIMER3_VoidInitInputCapture(Channle4);


	MOTORS_Void_MotorInit();

	//
	//	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC) ;
	//
	//	MGPIO_VidSetPinDirection      ( GPIOA , PIN9  , OUTPUT_SPEED_2MHZ_AFPP ) ;
	//	MGPIO_VidSetPinDirection      ( GPIOA , PIN10 , INPUT_FLOATING         ) ;


	//	MGPIO_VidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_2MHZ_PP);




	MUSART_VidInit();


	MOTOR_RF_Void_MotorSetSpeed(100);
	MOTOR_LF_Void_MotorSetSpeed(100);
	//	CLCD_voidInit();

//	MOTOR_RF_Void_MotorSetSpeed(75);
//	MOTOR_LF_Void_MotorSetSpeed(75);

	/* Loop forever */
	for(;;)
	{
		APP_voidCollisionAvoidance();
	}
}
