 /******************************************************************************
 *
 * Module: RCC (Reset & Clock Control)
 *
 * File Name: RCC_PRIVATE.h
 *
 * Description: Header file for the RCC Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*******************************************************************************
 *                              							RCC Registers					                   				     *
 *******************************************************************************/


// CTRL Registers
typedef struct
{
	volatile u32 STK_CTRL_ENABLE:  			1;
	volatile u32 STK_CTRL_TICKINT: 				1;
	volatile u32 STK_CTRL_CLKSOURCE: 		1;
	volatile u32                                      : 		13;
	volatile u32 STK_CTRL_COUNTFLAG:		1;
} STK_CTRL;

typedef struct
{
	STK_CTRL STK_CTRL ;
	volatile u32 STK_LOAD ;
	volatile u32 STK_VAL  ;
	volatile u32 STK_CALIB;
} STK;
#define STK_REG    ((volatile STK*) 0xE000E010)			// STK REGISTER


#define STK_LOAD_REG    *((volatile u32*) 0xE000E014)			// RCC CLOCK CONTROL REGISTER

#define STK_VAL_REG    	*((volatile u32*) 0xE000E018)			// RCC CLOCK CONTROL REGISTER

#define STK_CALIB_REG   *((volatile u32*) 0xE000E00C)			// RCC CLOCK CONTROL REGISTER



#endif

//#define STK_CTRL_ENABLE 	0
//#define STK_CTRL_TICKINT 	1
//#define STK_CTRL_CLKSOURCE 	2
//#define STK_CTRL_COUNTFLAG 	16
