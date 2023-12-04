 /******************************************************************************
 *
 * Module: USART
 *
 * File Name: USART_PROGRAM.c
 *
 * Description: Source file for the USART Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       		   *
 *******************************************************************************/

#include "../Inc/USART_INTERFACE.h"

/*******************************************************************************
 *                              				USART Global Variables				               				     *
 *******************************************************************************/

#define THRESHOLD_VALUE  9000000UL
static void (*USART1_pvCallBackFunc)(void) = NULL;

/*******************************************************************************
 *                              		USART Function Implementations									   	*
 *******************************************************************************/


void USART_voidInitialization ( void ){

	u32 LOC_u32Mantissa = ( F_CPU ) / ( 16 * USART1_BAUD_RATE ) ;

	u32 LOC_u32Fraction = ( ( ( F_CPU * 100 ) / ( 16 * USART1_BAUD_RATE )  ) % 100 ) * 16 ;

	if( LOC_u32Fraction > 1500 )
	{
		LOC_u32Mantissa += 1 ;
		LOC_u32Fraction  = 0 ;
	}

	#if USART1_STATUS == ENABLE
	USART1_REG -> USARTx_SR = CLR ;

		#if   USART1_WORD_LENGTH == USART_8BIT_WORD
					CLR_BIT(USART1_REG -> USARTx_CR1, 12);
		#elif USART1_WORD_LENGTH == USART_9BIT_WORD
					SET_BIT(USART1_REG -> USARTx_CR1, 12);
		#endif

		#if   USART1_PARITY == USART_PARITY_DISABLE
					CLR_BIT(USART1_REG -> USARTx_CR1, 10 );
		#elif USART1_PARITY == USART_EVEN_PARITY
					SET_BIT(USART1_REG -> USARTx_CR1, 10 );
					CLR_BIT(USART1_REG -> USARTx_CR1, 11 );
		#elif USART1_PARITY == USART_ODD_PARITY
					SET_BIT(USART1_REG -> USARTx_CR1, 10 );
					SET_BIT(USART1_REG -> USARTx_CR1, 11 );
		#endif

		#if  USART1_INTERRUPT == USART_INT_DISABLE
					CLR_BIT(USART1_REG -> USARTx_CR1, 5 );
					CLR_BIT(USART1_REG -> USARTx_CR1, 6 );
					CLR_BIT(USART1_REG -> USARTx_CR1, 7 );
		#elif USART1_INTERRUPT == USART_TXE_INT_ENABLE
					SET_BIT(USART1_REG -> USARTx_CR1, 7 );
		#elif USART1_INTERRUPT == USART_TCE_INT_ENABLE
					SET_BIT(USART1_REG -> USARTx_CR1, 6 );
		#elif USART1_INTERRUPT == USART_RXNE_INT_ENABLE
					SET_BIT(USART1_REG -> USARTx_CR1, 5 );
		#endif

		#if   USART1_TX == USART_TX_ENABLE
					SET_BIT(USART1_REG -> USARTx_CR1, 3 );
		#elif USART1_TX == USART_TX_DISABLE
					CLR_BIT(USART1_REG -> USARTx_CR1, 3 );
		#endif

		#if   USART1_RX == USART_RX_ENABLE
					SET_BIT(USART1_REG -> USARTx_CR1, 2 );
		#elif USART1_RX == USART_RX_DISABLE
					CLR_BIT(USART1_REG -> USARTx_CR1, 2 );
		#endif

		#if   USART1_STOP_BITS == USART_ONE_STOP_BIT
					CLR_BIT(USART1_REG -> USARTx_CR2, 12 );
					CLR_BIT(USART1_REG -> USARTx_CR2, 13 );
		#elif USART1_STOP_BITS == USART_HALF_STOP_BIT
					SET_BIT(USART1_REG -> USARTx_CR2, 12 );
					CLR_BIT(USART1_REG -> USARTx_CR2, 13 );
		#elif USART1_STOP_BITS == USART_TWO_STOP_BIT
					CLR_BIT(USART1_REG -> USARTx_CR2, 12 );
					SET_BIT(USART1_REG -> USARTx_CR2, 13 );
		#elif USART1_STOP_BITS == USART_ONE_AND_HALF_STOP_BIT
					SET_BIT(USART1_REG -> USARTx_CR2, 12 );
					SET_BIT(USART1_REG -> USARTx_CR2, 13 );
		#endif

		USART1_REG -> USARTx_BRR = ( LOC_u32Mantissa << 4  ) | ( LOC_u32Fraction / 100 ) ;
		SET_BIT(USART1_REG -> USARTx_CR1, 13 );

	#elif USART1_STATUS == DISABLE
		CLR_BIT( USART1_REG -> USARTx_CR1 , 0 );
	#endif

}


void USART1_voidSendCharSynchronous( u8 Copy_u8Char){

	USART1_REG -> USARTx_DR = Copy_u8Char ;

	while( GET_BIT( USART1_REG -> USARTx_SR , 6 ) == 0 );

	CLR_BIT( USART1_REG -> USARTx_SR , 6 );
}


void USART1_voidSendStringSynchronous ( u8 * Copy_ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while ( Copy_ptrString[ LOC_u8Iterator ] != '\0' ){
		USART1_voidSendCharSynchronous(Copy_ptrString[ LOC_u8Iterator ]);
		LOC_u8Iterator++ ;
	}
}


u8 USART1_u8ReceiveCharSynchronous( void ){

	u8  LOC_u8Data  = 0 ;
	u32 LOC_u32TimeOut = 0 ;

	CLR_BIT(USART1_REG -> USARTx_SR, 5);

	while( ( GET_BIT(USART1_REG -> USARTx_SR, 5) == 0 ));

	if( LOC_u32TimeOut == THRESHOLD_VALUE )
	{
		LOC_u8Data = 255;
	}
	else
	{
		LOC_u8Data = USART1_REG -> USARTx_DR;
	}

	return LOC_u8Data;

}

u8 LOC_u8String[20];

u8 * USART1_ptrReadStringSynchronous(void){

	u8 LOC_u8Iterator = 0;
	u8 LOC_u8DataReceived ;

	while( ( LOC_u8DataReceived = USART1_u8ReceiveCharSynchronous() ) != 13 ){
		LOC_u8String[ LOC_u8Iterator ] = LOC_u8DataReceived ;
		LOC_u8Iterator++;
	}

	LOC_u8String[LOC_u8Iterator] = '\0';

	return ( LOC_u8String );
}


void USART1_voidSetCallBack( void (*ptr) (void) ){

	USART1_pvCallBackFunc = ptr ;
}



void USART1_IRQHandler(void){

	USART1_REG -> USARTx_SR = 0 ;
	USART1_pvCallBackFunc();
}
