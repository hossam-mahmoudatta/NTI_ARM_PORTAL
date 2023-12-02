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

#include "../Inc/APP_INTERFACE.h"

/*******************************************************************************
 *                              			Main Function Implementations									 *
 *******************************************************************************/

int main(void)
{
	APP_voidSystemInitialization();

	u8 LOC_u8OperationMode;
	LOC_u8OperationMode = 1;

	/* Loop forever */
	for(;;)
	{
		switch(LOC_u8OperationMode)
		{
			case 0:		// Collision Avoidance Mode
				APP_voidCollisionAvoidance();
				break;

			case 1:		// Auto-Parking Mode
				APP_voidAutoParking();
				break;

			case 2:		// RC Car Mode
				APP_voidRCCar();
				break;

			default:
				break;
		}
	}
}
