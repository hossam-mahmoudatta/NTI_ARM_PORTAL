 /******************************************************************************
 *
 * Module: Delay
 *
 * File Name: DELAY_INTERFACE.c
 *
 * Description: Source file for the Delay Driver Relying on SYSTICK
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              						Include Libraries						                       		   *
 *******************************************************************************/

#ifndef DELAY_INTERFACE_H_
#define DELAY_INTERFACE_H_

#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"

/*******************************************************************************
 *                              				Delay Function Prototypes									   	*
 *******************************************************************************/

void _delay_ms( u32 Copy_u32Time );
void _delay_us( u32 Copy_u32Time );

#endif /* DELAY_INTERFACE_H_ */
