 /******************************************************************************
 *
 * Module: Delay
 *
 * File Name: DELAY_PROGRAM.c
 *
 * Description: Source file for the Delay Driver Relying on SYSTICK
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/


#include "DELAY_INTERFACE.h"

/*******************************************************************************
 *                              					Delay Function Implementations									   	*
 *******************************************************************************/

void _delay_ms( u32 Copy_u32Time )
{
	STK_voidInitialization();

	STK_voidSetDelay_ms(Copy_u32Time);
}


/* Suppose That The Clock System (AHB) = 8MHZ EXT & The Systick Clock Is = AHB/8 */
void _delay_us( u32 Copy_u32Time )
{
	STK_voidInitialization();

	STK_voidSetDelay_ms(Copy_u32Time / 1000);
}
