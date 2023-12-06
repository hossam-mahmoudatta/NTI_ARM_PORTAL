/******************************************************************************
 *
 * Module: SYSTICK (SYSTEM TIMER)
 *
 * File Name: SYSTICK_PROGRAM.c
 *
 * Description: Source file for the SYSTICK Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              						Include Libraries						                       		   *
 *******************************************************************************/

#include "SYSTICK_INTERFACE.h"

/*******************************************************************************
 *                              				SYSTICK Global Variables				               				     *
 *******************************************************************************/

/*Global pointer to function to hold the callback function address*/
static void (*STK_pvCallBackPtr)(void) = NULL;

volatile u32 STK_SingleInterval = 0;
volatile u32 STK_MultipleInterval = 0;
volatile u32 STK_delayComplete = 0;

/*******************************************************************************
 *                              			SYSTICK Function Implementations									   	*
 *******************************************************************************/

// Initializes the RCC Module with the necessary Configurations
void STK_voidInitialization(void)
{
	// CHOOSING THE CLK SOURCE FOR THE SYSTICK
	STK_REG->STK_CTRL.STK_CTRL_CLKSOURCE = CLKSOURCE_SELECT;
	STK_REG->STK_LOAD 	= STK_LOAD_INITIAL;
	STK_REG->STK_VAL		= STK_VAL_INITIAL;

	// Disable Timer
	STK_REG->STK_CTRL.STK_CTRL_ENABLE = DISABLE;

	// Disable Interrupt
	STK_REG->STK_CTRL.STK_CTRL_TICKINT = DISABLE;
}



// Chooses the clock type and enables it
void STK_voidSetDelay_ms(u32 copy_u32Delay)
{
	u32 ClockTicks = 0;

	// Calculate the number of ticks for the given delay
	ClockTicks = copy_u32Delay * STK_TICKS;

	// Load the number of ticks into the SysTick LOAD register
	// STK_LOAD = (CPU_FREQ / INTERRUPT FREQ) - 1
	STK_REG->STK_LOAD = ClockTicks - 1;

	// Clear the SysTick current value
	STK_REG->STK_VAL		= STK_VAL_INITIAL;

	// Enables the Counter
	STK_REG->STK_CTRL.STK_CTRL_ENABLE = ENABLE;

	// Wait until the COUNTFLAG bit in the SysTick CTRL register is set
	while(STK_REG->STK_CTRL.STK_CTRL_COUNTFLAG == 0);
	// Wait for the COUNTFLAG to become 1

	// Disable Timer
	STK_REG->STK_CTRL.STK_CTRL_ENABLE = DISABLE;
	STK_REG->STK_LOAD = CLR;
	STK_REG->STK_VAL = STK_VAL_INITIAL;
}



// Chooses the clock type and enables it
void STK_voidSetDelay_ms_ISR(u32 copy_u32Delay, void(*Copy_voidPTF)(void))
{
	if(Copy_voidPTF != NULL_PTR)
	{
		u32 ClockTicks = 0;

		// Calculate the number of ticks for the given delay
		ClockTicks = copy_u32Delay * STK_TICKS;

		// Load the number of ticks into the SysTick LOAD register
		STK_REG->STK_LOAD = ClockTicks - 1;

		// Clear the SysTick current value
		STK_REG->STK_VAL		= STK_VAL_INITIAL;

		STK_pvCallBackPtr = Copy_voidPTF;

		// Enables the Counter
		STK_REG->STK_CTRL.STK_CTRL_ENABLE = ENABLE;
	}
	else
	{
		// Return Error
	}
}



void STK_voidEnableInterrupt(void)
{
	STK_REG->STK_CTRL.STK_CTRL_TICKINT = ENABLE;
}


void STK_voidDisableInterrupt(void)
{
	STK_REG->STK_CTRL.STK_CTRL_TICKINT = DISABLE;
}



// Callback Function that will be passed to the ISR
void STK_CallBackFunction(void (*Ptr_STK)(void))
{
	STK_pvCallBackPtr = Ptr_STK;
}



// The ISR Handler for the SYSTICK
void SysTick_Handler(void)
{
	if(STK_pvCallBackPtr != NULL)
	{
		STK_pvCallBackPtr();
	}
	//Clear the flag by Reading it
	STK_REG->STK_CTRL.STK_CTRL_COUNTFLAG;
//	GET_BIT(STK_CTRL_REG, STK_CTRL_COUNTFLAG);
}

