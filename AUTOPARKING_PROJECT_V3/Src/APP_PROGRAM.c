/******************************************************************************
 *
 * Module: APP PROGRAM
 *
 * File Name: APP_PROGRAM.c
 *
 * Description: Source file for the functions that will be used on the main file
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       	*
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              				APP Global Variables				           			     *
 *******************************************************************************/

/* Assigns the Collision Avoidance Tracker Flag */
u8 g_u8CollisionAvoidance_StateFlag = CA_ADAS_FORWARD_STATE;

/* Assigns the Car Operation Mode Flag */
u8 g_u8CarOPMode_StateFlag = CAR_OPERATION_AUTOPARKING;

/*******************************************************************************
 *                              			APP Function Implementations									 *
 *******************************************************************************/

void APP_voidSystemInitialization(void)
{
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM2_RCC);
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM3_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOA_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOB_RCC);
	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM4_RCC);

	/*Enable Interrupt for each timer*/
	MNVIC_VidEnablePeripheral(TIM2_C);
	MNVIC_VidEnablePeripheral(TIM3_C);

	/* Ultrasonic Sensors Initializations */
	HCSR04_voidInitialization();

	/* Set CallBack Functions for both Timers */
	Timer2_u8InputCaptureSetCallBack(&TIM2);
	Timer3_u8InputCaptureSetCallBack(&TIM3);

	/* Initialize Channels */
	TIMER2_VoidInitInputCapture(Channle1);
	TIMER2_VoidInitInputCapture(Channle2);
	TIMER3_VoidInitInputCapture(Channle1);
	TIMER3_VoidInitInputCapture(Channle2);
	TIMER3_VoidInitInputCapture(Channle4);

	/* Initialize Motors */
	MOTORS_Void_MotorInit();

	/* Initialize UART Module for Bluetooth Usage */
	MUSART_VidInit();
	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN9  , OUTPUT_SPEED_2MHZ_AFPP ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN10 , INPUT_FLOATING         ) ;

	/* Set Initial Speed for Motors */
	MOTOR_RF_Void_MotorSetSpeed(90);
	MOTOR_LF_Void_MotorSetSpeed(90);

	g_u8CollisionAvoidance_StateFlag = CA_ADAS_FORWARD_STATE;
}


// The ISR Function for the Timer2 to use for the Ultrasonic Sensors
void TIM2(void)
{
	Is_First_Captured2++;
	Is_First_Captured1++;
	if(GET_BIT(TIMER2_SR,1)==1)
	{
		SET_BIT(TIMER2_SR,1);
		if(Is_First_Captured1==1)
		{

			ICU1_Value1=Timer2_VoidGetCapturedValue(Channle1);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer2_VoidChangePolarityOnEachChannle(Channle1,TIMER2_FALLING_EDGE);
		}
		else if (Is_First_Captured1==2)   // if the first is already captured
		{
			ICU1_Value2 = Timer2_VoidGetCapturedValue(Channle1) ; // read second value

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

			ICU2_Value1=Timer2_VoidGetCapturedValue(Channle2);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer2_VoidChangePolarityOnEachChannle(Channle2,TIMER2_FALLING_EDGE);
		}
		else if (Is_First_Captured2==2)   // if the first is already captured
		{
			ICU2_Value2 = Timer2_VoidGetCapturedValue(Channle2) ; // read second value

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
			ICU3_Value1=Timer3_VoidGetCapturedValue(Channle1);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			Timer3_VoidChangePolarityOnEachChannle(Channle1,TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured3==2)   // if the first is already captured
		{
			ICU3_Value2 = Timer3_VoidGetCapturedValue(Channle1) ; // read second value

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

			ICU4_Value1=Timer3_VoidGetCapturedValue(Channle2);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer3_VoidChangePolarityOnEachChannle(Channle2,TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured4==2)   // if the first is already captured
		{
			ICU4_Value2 = Timer3_VoidGetCapturedValue(Channle2) ; // read second value

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

			ICU5_Value1=Timer3_VoidGetCapturedValue(Channle3);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer3_VoidChangePolarityOnEachChannle(Channle3,TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured5==2)   // if the first is already captured
		{
			ICU5_Value2 = Timer3_VoidGetCapturedValue(Channle3) ; // read second value

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

			ICU5_Value1=Timer3_VoidGetCapturedValue(Channle4);
			//Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge

			Timer3_VoidChangePolarityOnEachChannle(Channle4,TIMER3_FALLING_EDGE);
		}
		else if (Is_First_Captured5==2)   // if the first is already captured
		{
			ICU5_Value2 = Timer3_VoidGetCapturedValue(Channle4) ; // read second value

			// Now change the polarity to rising edge

			Timer3_VoidChangePolarityOnEachChannle(Channle4,TIMER3_RISING_EDGE);
			// disable capture interrupt on each channel
			Timer3_VoidDisableIntOnEachChannle(Channle4);
		}
	}
}





void APP_voidAutoParking()
{
//	g_Rear_SensorDistance = HCSR04_u8Read_Rear();
//	_delay_ms(100);
//	while(Received_distanceTwo>10)
//	{
//		g_Rear_SensorDistance = HCSR04_u8Read_Rear();
//		_delay_ms(100);
//
//		MOTOR_RF_GO_BACKWARD();
//		MOTOR_LF_GO_BACKWARD();
//		_delay_ms(100);
//	}
//	MOTOR_RF_STOP();
//	MOTOR_LF_STOP();


	g_Front_SensorDistance = HCSR04_u8Read_Front();
	_delay_ms(100);
	g_Rear_SensorDistance = HCSR04_u8Read_Rear();
	_delay_ms(100);


	g_FrontRight_SensorDistance = HCSR04_u8Read_FrontRight();
	_delay_ms(100);
	g_RearRight_SensorDistance = HCSR04_u8Read_RearRight();
	_delay_ms(100);

	if(g_FrontRight_SensorDistance > 20  && g_RearRight_SensorDistance > 20 )
	{
		g_RearRight_SensorDistance = HCSR04_u8Read_RearRight();
		_delay_ms(100);
		while(g_RearRight_SensorDistance > 20)
		{
			g_RearRight_SensorDistance = HCSR04_u8Read_RearRight();
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
		_delay_ms(400);
		MOTOR_LF_STOP();




		MOTOR_LF_Void_MotorSetSpeed(70);
		MOTOR_RF_Void_MotorSetSpeed(70);
		//			MOTOR_RF_GO_BACKWARD();
		//			MOTOR_LF_GO_BACKWARD();
		//			_delay_ms(1000);
		//			MOTOR_RF_STOP();
		//			MOTOR_LF_STOP();
		g_Rear_SensorDistance = HCSR04_u8Read_Rear();
		_delay_ms(100);
		if(g_Rear_SensorDistance>4)
		{
			while(g_Rear_SensorDistance>20)
			{
				g_Rear_SensorDistance = HCSR04_u8Read_Rear();
				_delay_ms(100);
				MOTOR_RF_GO_BACKWARD();
				MOTOR_LF_GO_BACKWARD();

			}
			MOTOR_RF_STOP();
			MOTOR_LF_STOP();

		}

		// p>>B
		MOTOR_LF_Void_MotorSetSpeed(90);
		MOTOR_LF_GO_FORWARD();
		MOTOR_RF_GO_BACKWARD();
		_delay_ms(400);
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();

		_delay_ms(1000);

		MOTOR_RF_Void_MotorSetSpeed(55);
		MOTOR_LF_Void_MotorSetSpeed(65);
		g_Front_SensorDistance = HCSR04_u8Read_Front();
		_delay_ms(100);
		if(g_Front_SensorDistance>7)
		{
			while(g_Front_SensorDistance>7)
			{
				g_Front_SensorDistance = HCSR04_u8Read_Front();
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
	g_Front_SensorDistance = HCSR04_u8Read_Front();
	_delay_ms(100);
	g_Rear_SensorDistance = HCSR04_u8Read_Rear();
	_delay_ms(100);
	g_FrontRight_SensorDistance = HCSR04_u8Read_FrontRight();
	_delay_ms(100);
	g_FrontLeft_SensorDistance = HCSR04_u8Read_FrontLeft();
	_delay_ms(100);

	switch(g_u8CollisionAvoidance_StateFlag)
	{
	/***************************************************************************/
		case CA_ADAS_FORWARD_STATE:
			while(g_Front_SensorDistance > 20 && g_FrontRight_SensorDistance > 10 && g_FrontLeft_SensorDistance > 10)
			{
				MOTOR_RF_GO_FORWARD();
				MOTOR_LF_GO_FORWARD();
				g_Front_SensorDistance = HCSR04_u8Read_Front();
				_delay_ms(100);
				g_FrontRight_SensorDistance = HCSR04_u8Read_FrontRight();
				_delay_ms(100);
				g_FrontLeft_SensorDistance = HCSR04_u8Read_FrontLeft();
				_delay_ms(100);
			}
			MOTOR_RF_STOP();
			MOTOR_LF_STOP();
			_delay_ms(1000);
			g_u8CollisionAvoidance_StateFlag = CA_ADAS_RIGHT_STATE;
			break;
		/***************************************************************************/
		case CA_ADAS_RIGHT_STATE:
			if(g_FrontRight_SensorDistance > 35)
			{
				MOTOR_RF_GO_BACKWARD();
				MOTOR_LF_GO_FORWARD();
				_delay_ms(700);
				MOTOR_RF_STOP();
				MOTOR_LF_STOP();
				_delay_ms(1000);
				g_u8CollisionAvoidance_StateFlag = CA_ADAS_FORWARD_STATE;
			}
			else
			{
				g_u8CollisionAvoidance_StateFlag = CA_ADAS_LEFT_STATE;
			}
			break;
		/***************************************************************************/
		case CA_ADAS_LEFT_STATE:
			if(g_FrontLeft_SensorDistance > 35)
			{
				MOTOR_RF_GO_FORWARD();
				MOTOR_LF_GO_BACKWARD();
				_delay_ms(700);
				MOTOR_RF_STOP();
				MOTOR_LF_STOP();
				_delay_ms(1000);
				g_u8CollisionAvoidance_StateFlag = CA_ADAS_FORWARD_STATE;
			}
			else
			{
				g_u8CollisionAvoidance_StateFlag = CA_ADAS_REVERSE_STATE;
			}
			break;
		/***************************************************************************/
		case CA_ADAS_REVERSE_STATE:
			if(g_Rear_SensorDistance > 20)
			{
				while(g_FrontRight_SensorDistance < 20 && g_FrontLeft_SensorDistance < 20)
				{
					MOTOR_RF_GO_BACKWARD();
					MOTOR_LF_GO_BACKWARD();
					//_delay_ms(1000);

					g_FrontRight_SensorDistance = HCSR04_u8Read_FrontRight();
					_delay_ms(100);
					g_FrontLeft_SensorDistance = HCSR04_u8Read_FrontLeft();
					_delay_ms(100);
				}
				if(g_FrontRight_SensorDistance > 20)
				{
					MOTOR_RF_STOP();
					MOTOR_LF_STOP();
					_delay_ms(700);
					g_u8CollisionAvoidance_StateFlag = CA_ADAS_RIGHT_STATE;
				}
				else if(g_FrontLeft_SensorDistance > 20)
				{
					MOTOR_RF_STOP();
					MOTOR_LF_STOP();
					_delay_ms(700);
					g_u8CollisionAvoidance_StateFlag = CA_ADAS_LEFT_STATE;
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

	LOC_u16ReadDistance = HCSR04_u8Read_RearRight();
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


/********************************************************************************/
void APP_voidRemoteControl(void)
{
	// Receive new data from Bluetooth
	u8 LOC_u8NewData;
	LOC_u8NewData = MUSART1_u8RecCharSynch();
	_delay_ms(100);

	// Motor control based on received data
	switch (LOC_u8NewData) {
	case '1':
		// Move forward
		MOTOR_RF_GO_FORWARD();
		MOTOR_LF_GO_FORWARD();
		_delay_ms(250);
		// Stop after a short delay
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();
		break;

	case '2':
		// Turn right
		MOTOR_RF_GO_FORWARD();
		MOTOR_LF_STOP();
		_delay_ms(250);
		// Stop after a short delay
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();
		break;

	case '3':
		// Turn left
		MOTOR_LF_GO_FORWARD();
		MOTOR_RF_STOP();
		_delay_ms(250);
		// Stop after a short delay
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();
		break;

	case '4':
		// Move backward
		MOTOR_RF_GO_BACKWARD();
		MOTOR_LF_GO_BACKWARD();
		_delay_ms(250);
		// Stop after a short delay
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();
		break;

	default:
		// Stop if the received command is not recognized
		MOTOR_RF_STOP();
		MOTOR_LF_STOP();
		break;
	}
}

