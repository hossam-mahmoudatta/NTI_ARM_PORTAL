/******************************************************************************
 *
 * Module: NVIC (NESTED VECTOR INTERRUPT)
 *
 * File Name: NVIC_PROGRAM.h
 *
 * Description: SOURCE file for NVIC Driver Function Declarations
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "NVIC_INTERFACE.h"

/*******************************************************************************
 *                              				NVIC Function Implementations					                   				     *
 *******************************************************************************/

void NVIC_voidEnablePeripheral ( u8 Copy_u8INTID )
{
	NVIC_REG->NVIC_ISER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
}

void MNVIC_VidDisablePeripheral ( u8 Copy_u8INTID )
{
	NVIC_REG->NVIC_ICER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
}


void NVIC_voidSetPending ( u8 Copy_u8INTID )
{
	NVIC_REG->NVIC_ISPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
}

void NVIC_voidClearPending ( u8 Copy_u8INTID )
{
	NVIC_REG->NVIC_ICPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;
}


u8   NVIC_u8GetActive( u8 Copy_u8INTID )
{
	u8 LOC_u8Active = GET_BIT( (NVIC_REG->NVIC_IAPR[ Copy_u8INTID/32 ]) , ( Copy_u8INTID % 32 ) );
	return LOC_u8Active ;
}


void NVIC_voidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group )
{
	u8 Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 )  ;
	//Core Peripheral
	if( Copy_u8INTID < 0 )
	{
		if( Copy_u8INTID == MEMORY_MANAGE || Copy_u8INTID == BUS_FAULT || Copy_u8INTID == USAGE_FAULT )
		{
			Copy_u8INTID += 3;
			SCB_REG->SHPR1 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );
		}
		else if ( Copy_u8INTID == SV_CALL )
		{
			Copy_u8INTID += 7;
			SCB_REG->SHPR2 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );
		}
		else if( Copy_u8INTID == PEND_SV || Copy_u8INTID == SYSTICK )
		{
			Copy_u8INTID += 8;
			SCB_REG->SHPR3 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );
		}
	}
    //External Peripheral
	else if( Copy_u8INTID >= 0 )
	{
		NVIC_REG->NVIC_IPR[ Copy_u8INTID ] = Priority << 4 ;
	}
	SCB_REG->AIRCR = Copy_u8Group ;
}

