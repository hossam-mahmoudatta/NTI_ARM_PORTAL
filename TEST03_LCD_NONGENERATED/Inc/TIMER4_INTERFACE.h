 /******************************************************************************
 *
 * Module: TIMER4
 *
 * File Name: TIMER4_INTERFACE.h
 *
 * Description: Header file for the TIMER4 Driver Function Declarations
 *
 * Author: Tariq, Hosny & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER4_INTERFACE_H_
#define TIMER4_INTERFACE_H_

#include "TIMER4_CONFIG.h"

/*******************************************************************************
 *                              				TIMER4 Function Prototypes					               				     *
 *******************************************************************************/

void TIMER4_voidPWMInitialization(u8 copy_u8ChannelNumber);
void TIMER4_voidPWMSetDutyCycle(u8 copy_u8ChannelNumber, u32 copy_u32DutyCycle);
void TIMER4_voidPWMStart();


#endif /* TIMER4_INTERFACE_H_ */
