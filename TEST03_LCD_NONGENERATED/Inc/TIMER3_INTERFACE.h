 /******************************************************************************
 *
 * Module: TIMER3
 *
 * File Name: TIMER3_INTERFACE.h
 *
 * Description: Header file for the TIMER3 Driver Function Declarations
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER3_INTERFACE_H_
#define TIMER3_INTERFACE_H_

#include "TIMER3_CONFIG.h"

/*******************************************************************************
 *                              				TIMER3 Function Prototypes					               				     *
 *******************************************************************************/

void 	TIMER3_voidICUInitialization(u8 copy_u8ChannelNumber);
u8 	TIMER3_u8ICUSetCallBack(void (*copy_pvCallBackFunc)(void));
void 	TIMER3_voidSetPreload(u8 copy_u8Preload);

void 	TIMER3_voidEnableInterrupt(u8 copy_u8ChannelNumber);
void 	TIMER3_voidDisableInterrupt(u8 copy_u8ChannelNumber);

void 	TIMER3_voidChangePolarity(u8 copy_u8ChannelNumber, u8 copy_u8Edge);
u32  	TIMER3_u32GetICUValue(u8 copy_u8ChannelNumber);

#endif /* TIMER3_INTERFACE_H_ */
