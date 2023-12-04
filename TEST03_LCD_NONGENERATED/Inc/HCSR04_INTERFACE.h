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

extern u32 volatile ICU1_Value1;
extern u32 volatile ICU1_Value2;
extern u32 volatile Difference1;
extern u8 volatile Is_First_Captured1;  // is the first value captured ?
extern u8 volatile Distance1;

extern u32 volatile ICU2_Value1;
extern u32 volatile ICU2_Value2;
extern u32 volatile Difference2;
extern u8   volatile Is_First_Captured2;  // is the first value captured ?
extern u8 volatile Distance2;

extern u32 volatile ICU3_Value1;
extern u32 volatile ICU3_Value2;
extern u32 volatile Difference3;
extern u8   volatile Is_First_Captured3;  // is the first value captured ?
extern u8 volatile Distance3;

extern u32 volatile ICU4_Value1;
extern u32 volatile ICU4_Value2;
extern u32 volatile Difference4;
extern u8   volatile Is_First_Captured4;  // is the first value captured ?
extern u8 volatile Distance4;

extern u32 volatile ICU5_Value1;
extern u32 volatile ICU5_Value2;
extern u32 volatile Difference5;
extern u8   volatile Is_First_Captured5;  // is the first value captured ?
extern u8 volatile Distance5;

extern u8 Received_distanceOne;
extern u8 Received_distanceTwo;
extern u8 Received_distanceThree;
extern u8 Received_distanceFour;
extern u8 Received_distanceFive;

/*******************************************************************************
 *                              				HCSR04 Function Prototypes					               				     *
 *******************************************************************************/

void HCSR04_voidInitialization(void);

// Front
void HCSR04_voidTriggerOne(void);

// Back
void HCSR04_voidTriggerTwo(void);

// Front Right
void HCSR04_voidTriggerThree(void);

// Rear Right
void HCSR04_voidTriggerFour(void);

// Front Left
void HCSR04_voidTriggerFive(void);

u8 HCSR04_u8ReadOne(void);

u8 HCSR04_u8ReadTwo(void);

u8 HCSR04_u8ReadThree(void);

u8 HCSR04_u8ReadFour(void);

u8 HCSR04_u8ReadFive(void);


#endif /* HCSR04_INTERFACE_H_ */
