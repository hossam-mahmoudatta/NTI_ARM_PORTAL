 /******************************************************************************
 *
 * Module: USART Module
 *
 * File Name: USART_PRIVATE.h
 *
 * Description: Header file for the USART Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       		   *
 *******************************************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              					USART Registers					                   				     *
 *******************************************************************************/

// Contains all the USART Registers
typedef struct {
	volatile u32  	USARTx_SR;				// USART Status Register
	volatile u32 	USARTx_DR;				// USART Data Register
	volatile u32 	USARTx_BRR;			// USART Baud Rate Register
	volatile u32 	USARTx_CR1;			// USART Control Register 1
	volatile u32 	USARTx_CR2;			// USART Control Register 2
	volatile u32 	USARTx_CR3;			// USART Control Register 3
	volatile u32 	USARTx_GTPR;			// USART Guard Time & Prescaler Register
} USARTx_GENERAL_REG;

#define USART1_BASE_ADDRESS		0x40013800
#define USART1_REG	((volatile USARTx_GENERAL_REG*) USART1_BASE_ADDRESS)	// USART1 Register

#endif /* USART_PRIVATE_H */
