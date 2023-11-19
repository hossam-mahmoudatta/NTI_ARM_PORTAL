 /******************************************************************************
 *
 * Module: TIMER10 (Reset & Clock Control)
 *
 * File Name: TIMER10_CONFIG.h
 *
 * Description: Header file for the TIMER10 Driver MACRO DECLARATIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER10_CONFIG_H
#define TIMER10_CONFIG_H

#include "TIMER10_PRIVATE.h"

/*******************************************************************************
 *                              						TIMER10 Macro Definitions					               				     *
 *******************************************************************************/
// Choosing the Clock Type		##IMPORTANT##

#define TIMER10_CHANNEL_1			 	1
#define TIMER10_CHANNEL_2			 	2
#define TIMER10_CHANNEL_3			 	3
#define TIMER10_CHANNEL_4			 	4
#define TIMER10_CHANNEL_SELECT	TIMER10_CHANNEL_1

#endif
