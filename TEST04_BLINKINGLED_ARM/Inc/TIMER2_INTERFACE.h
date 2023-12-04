 /******************************************************************************
 *
 * Module: TIMER2
 *
 * File Name: TIMER2_INTERFACE.h
 *
 * Description: Header file for the TIMER2 Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

#include "TIMER2_CONFIG.h"

/*******************************************************************************
 *                              				TIMER2 Function Prototypes					               				     *
 *******************************************************************************/

void 	TIMER2_voidICUInitialization(u8 copy_u8ChannelNumber);
u8 	TIMER2_u8ICUSetCallBack(void (*copy_pvCallBackFunc)(void));
void 	TIMER2_voidSetPreload(u8 copy_u8Preload);

void 	TIMER2_voidEnableInterrupt(u8 copy_u8ChannelNumber);
void 	TIMER2_voidDisableInterrupt(u8 copy_u8ChannelNumber);

void 	TIMER2_voidChangePolarity(u8 copy_u8ChannelNumber, u8 copy_u8Edge);
u32  	TIMER2_u32GetICUValue(u8 copy_u8ChannelNumber);


#endif /* TIMER2_INTERFACE_H_ */
