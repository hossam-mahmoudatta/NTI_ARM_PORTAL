 /******************************************************************************
 *
 * Module: Main.c
 *
 * File Name: main.c
 *
 * Description: Source file for the main application
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
	g_u8CollisionAvoidance_StateFlag = CA_ADAS_FORWARD_STATE;
	/* Loop forever */
	for(;;)
	{
		switch(g_u8CarOPMode_StateFlag)
		{
			case CAR_OPERATION_COLLISIONAVOID:		// Collision Avoidance Mode
				APP_voidCollisionAvoidance();
				break;

			case CAR_OPERATION_AUTOPARKING:		// Auto-Parking Mode
				APP_voidAutoParking();
				break;

			case CAR_OPERATION_AUTOPARKING_2:		// Auto-Parking Mode
				APP_voidAutoParking_MODE2();
				break;

			case CAR_OPERATION_RCCAR:		// RC Car Mode
				APP_voidRemoteControl();
				break;

			default:
				break;
		}
	}
}

