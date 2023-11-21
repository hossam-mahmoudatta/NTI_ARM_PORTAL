 /******************************************************************************
 *
 * Module: HCSR04 (Ultrasonic Sensor)
 *
 * File Name: HCSR04_INTERFACE.h
 *
 * Description: Header file for the HCSR04 Driver Function Prototypes
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef HCSR04_INTERFACE_H_
#define HCSR04_INTERFACE_H_

#include "HCSR04_CONFIG.h"

/*******************************************************************************
 *                              				HCSR04 Global Variables				               				     *
 *******************************************************************************/

u32 volatile ICU1_Value1 = 0;
u32 volatile ICU1_Value2 = 0;
u32 volatile Difference1 = 0;
u8 volatile Is_First_Captured1 = 0;  // is the first value captured ?
u8 volatile Distance1  = 0;

u32 volatile ICU2_Value1 = 0;
u32 volatile ICU2_Value2 = 0;
u32 volatile Difference2 = 0;
u8   volatile Is_First_Captured2 = 0;  // is the first value captured ?
u8 volatile Distance2  = 0;

u32 volatile ICU3_Value1 = 0;
u32 volatile ICU3_Value2 = 0;
u32 volatile Difference3 = 0;
u8   volatile Is_First_Captured3 = 0;  // is the first value captured ?
u8 volatile Distance3  = 0;

u32 volatile ICU4_Value1 = 0;
u32 volatile ICU4_Value2 = 0;
u32 volatile Difference4 = 0;
u8   volatile Is_First_Captured4 = 0;  // is the first value captured ?
u8 volatile Distance4  = 0;

u8 Received_distanceOne = 0;
u8 Received_distanceTwo = 0;
u8 Received_distanceThree = 0;
u8 Received_distanceFour = 0;

/*******************************************************************************
 *                              				HCSR04 Function Prototypes					               				     *
 *******************************************************************************/

void HCSR04_voidInitialization(void);

void HCSR04_voidTriggerOne(void);

void HCSR04_voidTriggerTwo(void);

void HCSR04_voidTriggerThree(void);

void HCSR04_voidTriggerFour(void);

u8 HCSR04_u8ReadOne(void);

u8 HCSR04_u8ReadTwo(void);

u8 HCSR04_u8ReadThree(void);

u8 HCSR04_u8ReadFour(void);


#endif /* HCSR04_INTERFACE_H_ */
