 /******************************************************************************
 *
 * Module: TIMER10
 *
 * File Name: TIMER10_INTERFACE.h
 *
 * Description: Header file for the TIMER10 Driver FUNCTION PROTOTYPES
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER10_INTERFACE_H
#define TIMER10_INTERFACE_H

#include "TIMER10_CONFIG.h"

/*******************************************************************************
 *                              			Timer10 Function Prototypes				      			     *
 *******************************************************************************/

// Initializes Timer 10 into PWM Mode
void TIMER10_voidPWMInitialization(u8);

// Sets the Duty Cycle of Timer 10
void TIMER10_voidPWMSetDutyCycle(u8, u32);

// Starts Timer 10 into PWM Mode
void TIMER10_voidPWMStart();

// The ISR Handler for the TIMER10
void SysTick_Handler(void);


#endif
