/******************************************************************************
 *
 * Module: RCC (Reset & Clock Control)
 *
 * File Name: RCC_PROGRAM.c
 *
 * Description: Source file for the RCC Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "SYSTICK_INTERFACE.h"

/*******************************************************************************
 *                              					RCC Function Implementations									   	*
 *******************************************************************************/

// cALLBACK Function
static void (*CallBackPtr_SYSTICK)(void) = NULL;

volatile u32 STK_SingleInterval = 0;
volatile u32 STK_MultipleINterval = 0;

volatile u32 STK_delayComplete = 0;

// Initializes the RCC Module with the necessary Configurations
void SYSTICK_voidInitialization(void)
{
	// CHOOSING THE CLK SOURCE FOR THE SYSTICK
	SET_BIT(STK_CTRL_REG, STK_CTRL_CLKSOURCE);

#if (SYSTICK_ISR_ENABLE)
	SET_BIT(STK_CTRL_REG, STK_CTRL_TICKINT);
#endif
	STK_delayComplete = 0;
}



// Chooses the clock type and enables it
void SYSTICK_voidSetDelay_ms(u32 copy_u32Delay)
{
	u32 ClockTicks = 0;

	// Calculate the number of ticks for the given delay
	ClockTicks = copy_u32Delay * SYSTICK_TICKS;

	// Load the number of ticks into the SysTick LOAD register
	STK_LOAD_REG = ClockTicks - 1;

	// Clear the SysTick current value
	STK_VAL_REG = 0;

	SET_BIT(STK_CTRL_REG, STK_CTRL_ENABLE);

	// Wait until the COUNTFLAG bit in the SysTick CTRL register is set
	while (GET_BIT(STK_CTRL_REG, STK_CTRL_COUNTFLAG) == 0) {
		// Wait for the COUNTFLAG to become 1
	}
	// Disable Timer
	CLR_BIT(STK_CTRL_REG, STK_CTRL_ENABLE);
	STK_LOAD_REG = 0;
	STK_VAL_REG = 0;

}


// Chooses the clock type and enables it
void SYSTICK_voidSetDelay_ms_ISR(u32 copy_u32Delay, void(*Copy_voidPTF)(void))
{
	if(Copy_voidPTF != NULL_PTR)
	{
		u32 ClockTicks = 0;

		// Calculate the number of ticks for the given delay
		ClockTicks = copy_u32Delay * SYSTICK_TICKS;

		// Load the number of ticks into the SysTick LOAD register
		STK_LOAD_REG = ClockTicks - 1;

		// Clear the SysTick current value
		STK_VAL_REG = 0;

		CallBackPtr_SYSTICK = Copy_voidPTF;
		//SYSTICK_CallBackFunction_msDelay(Copy_voidPTF);
		SET_BIT(STK_CTRL_REG, STK_CTRL_ENABLE);
	}
	else
	{
		// Return Error
	}
}


void SYSTICK_CallBackFunction_msDelay(void (*Ptr_STK)(void))
{
	CallBackPtr_SYSTICK = Ptr_STK;
}



// the Systick ISR function
// Should be written like this
void SysTick_Handler(void)
{
	if(CallBackPtr_SYSTICK != NULL)
	{
		CallBackPtr_SYSTICK();
	}

	//Clear the flag by Reading it
	GET_BIT(STK_CTRL_REG, STK_CTRL_COUNTFLAG);

}

