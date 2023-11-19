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

#define STK_CTRL_ENABLE 	0
#define STK_CTRL_TICKINT 	1
#define STK_CTRL_CLKSOURCE 	2
#define STK_CTRL_COUNTFLAG 	16

#define STK_CTRL_REG    *((volatile u32*) 0xE000E010)			// RCC CLOCK CONTROL REGISTER

#define STK_LOAD_REG    *((volatile u32*) 0xE000E014)			// RCC CLOCK CONTROL REGISTER

#define STK_VAL_REG    	*((volatile u32*) 0xE000E018)			// RCC CLOCK CONTROL REGISTER

#define STK_CALIB_REG   *((volatile u32*) 0xE000E00C)			// RCC CLOCK CONTROL REGISTER



#endif
