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
 *                              						Include Libraries						                     *
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

extern u8 g_Front_SensorDistance;
extern u8 g_Rear_SensorDistance;
extern u8 g_FrontRight_SensorDistance;
extern u8 g_RearRight_SensorDistance;
extern u8 g_FrontLeft_SensorDistance;

/*******************************************************************************
 *                              				HCSR04 Function Prototypes					               				     *
 *******************************************************************************/

// Initializes the Ultrasonic Module
void HCSR04_voidInitialization(void);

// Front Ultrasonic Trigger
void HCSR04_voidTrig_Front(void);

// Back Ultrasonic Trigger
void HCSR04_voidTrig_Rear(void);

// Front Right Ultrasonic Trigger
void HCSR04_voidTrig_FrontRight(void);

// Rear Right Ultrasonic Trigger
void HCSR04_voidTrig_RearRight(void);

// Front Left Ultrasonic Trigger
void HCSR04_voidTrig_FrontLeft(void);

// Read the front Ultrasonic Sensor
u8 HCSR04_u8Read_Front(void);

// Read the rear Ultrasonic Sensor
u8 HCSR04_u8Read_Rear(void);

// Read the rear right Ultrasonic Sensor
u8 HCSR04_u8Read_RearRight(void);

// Read the front right Ultrasonic Sensor
u8 HCSR04_u8Read_FrontRight(void);

// Read the front left Ultrasonic Sensor
u8 HCSR04_u8Read_FrontLeft(void);


#endif /* HCSR04_INTERFACE_H_ */
