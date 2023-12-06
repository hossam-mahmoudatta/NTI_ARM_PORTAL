 /******************************************************************************
 *
 * Module: USART
 *
 * File Name: USART_INTERFACE.h
 *
 * Description: Header file for the USART Driver FUNCTION PROTOTYPES
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       		   *
 *******************************************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "USART_CONFIG.h"

/*******************************************************************************
 *                              			USART Function Prototypes					               			     *
 *******************************************************************************/

// Initializes the USART Module with the necessary Configurations

void USART_voidInitialization( void                ) ;

void USART1_voidSendCharSynchronous( u8 Copy_u8Char      ) ;

void USART1_voidSendStringSynchronous( u8 * Copy_ptrString ) ;

u8   USART1_u8ReceiveCharSynchronous( void                ) ;

u8  *USART1_ptrReadStringSynchronous( void                ) ;

void USART1_voidSetCallBack     ( void (*ptr) (void)  ) ;


#endif /* USART_INTERFACE_H_ */
