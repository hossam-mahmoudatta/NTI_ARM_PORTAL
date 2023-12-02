 /******************************************************************************
 *
 * Module: USART
 *
 * File Name: USART_CONFIG.h
 *
 * Description: Header file for the USART Driver MACRO DECLARATIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       		   *
 *******************************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#include "USART_PRIVATE.h"

/*******************************************************************************
 *                              				USART Macro Definitions					               				     *
 *******************************************************************************/

#define F_CPU                    8000000UL

// Choose Word Length
#define USART_8BIT_WORD				0
#define USART_9BIT_WORD				1
#define USART1_WORD_LENGTH			USART_8BIT_WORD

// Choose Parity Type
#define USART_PARITY_DISABLE		0
#define USART_EVEN_PARITY				1
#define USART_ODD_PARITY				2
#define USART1_PARITY						USART_PARITY_DISABLE

// Configure Interrupt Mode
#define USART_INT_DISABLE				0
#define USART_TXE_INT_ENABLE					1
#define USART_TCE_INT_ENABLE					3
#define USART_RXNE_INT_ENABLE					5
#define USART1_INTERRUPT				USART_INT_DISABLE

// Transmitter / Receiver Mode
#define USART_TX_DISABLE		0
#define USART_TX_ENABLE		1
#define USART1_TX       				USART_TX_ENABLE

#define USART_RX_DISABLE		0
#define USART_RX_ENABLE		1
#define USART1_RX         			USART_RX_ENABLE

// Stop Bits Configuration
#define USART_ONE_STOP_BIT            				0
#define USART_HALF_STOP_BIT           				1
#define USART_TWO_STOP_BIT            				2
#define USART_ONE_AND_HALF_STOP_BIT   		3
#define USART1_STOP_BITS         						USART_ONE_STOP_BIT

#define USART1_STATUS            ENABLE
#define USART1_BAUD_RATE      (u32)9600


#endif /* USART */
