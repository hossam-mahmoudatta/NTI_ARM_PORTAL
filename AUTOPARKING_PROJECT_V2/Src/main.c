 /******************************************************************************
 *
 * Module: Main.c
 *
 * File Name: main.c
 *
 * Description: Source file for the application main
 *
 * Author: Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              						Include Libraries						                       		   *
 *******************************************************************************/

#include "APP_INTERFACE.h"

/*******************************************************************************
 *                              			Main Function Implementations									 *
 *******************************************************************************/

int main(void)
{
	APP_voidSystemInitialization();

	u8 LOC_u8OperationMode;
	LOC_u8OperationMode = 0;

	/* Loop forever */
	for(;;)
	{
		g_Front_SensorDistance = HCSR04_u8Read_Front();
		if(g_Front_SensorDistance > 20)
		{
			MOTOR_voidRR_FWD();
			MOTOR_voidRL_BWD();
			_delay_ms(2500);
		}
		else if(g_Front_SensorDistance < 15)
		{
			MOTOR_voidRR_STOP();
			MOTOR_voidRL_STOP();
			_delay_ms(2500);
		}


//		switch(LOC_u8OperationMode)
//		{
//			case 0:		// Collision Avoidance Mode
//				APP_voidCollisionAvoidance();
//				break;
//
//			case 1:		// Auto-Parking Mode
//				APP_voidAutoParking();
//				break;
//
//			case 2:		// RC Car Mode
//				APP_voidRCCar();
//				break;
//
//			default:
//				break;
//		}
	}
}
