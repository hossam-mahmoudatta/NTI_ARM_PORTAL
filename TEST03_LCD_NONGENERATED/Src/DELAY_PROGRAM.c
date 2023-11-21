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


#include "../Inc/DELAY_INTERFACE.h"

/*******************************************************************************
 *                              					Delay Function Implementations									   	*
 *******************************************************************************/

void _delay_ms( u32 Copy_u32Time ){

	STK_voidInitialization();

	/* Disable INT */
	STK_voidDisableInterrupt();
	STK_voidSetDelay_ms(Copy_u32Time);

	/* Wait Flag Polling */
	while(STK_REG->STK_CTRL.STK_CTRL_COUNTFLAG == 0);
//	while( MSTK_u8ReadFlag() == 0 );
}


/* Suppose That The Clock System (AHB) = 8MHZ EXT & The Systick Clock Is = AHB/8 */
void _delay_us( u32 Copy_u32Time ){

	STK_voidInitialization();

	/* Disable INT */
	STK_voidDisableInterrupt();
	STK_voidSetDelay_ms(Copy_u32Time / 1000);

	/* Wait Flag Polling */
	while(STK_REG->STK_CTRL.STK_CTRL_COUNTFLAG == 0);

}
