 /******************************************************************************
 *
 * Module: NVIC (NESTED VECTOR INTERRUPT)
 *
 * File Name: NVIC_INTERFACE.h
 *
 * Description: Header file for NVIC Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include "NVIC_CONFIG.h"

/*******************************************************************************
 *                              					NVIC Function Prototypes					                   				     *
 *******************************************************************************/

// Enable Interrupt for a Peripheral
void NVIC_voidEnablePeripheral(u8 Copy_u8INTID);

void NVIC_voidDisablePeripheral ( u8 Copy_u8INTID );

void NVIC_voidSetPending        ( u8 Copy_u8INTID );

void NVIC_voidClearPending      ( u8 Copy_u8INTID );

u8   NVIC_u8GetActive          ( u8 Copy_u8INTID );

void NVIC_voidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group );



#endif /* NVIC_INTERFACE_H_ */
