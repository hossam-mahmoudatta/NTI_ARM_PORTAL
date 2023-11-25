 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: MOTOR_PROGRAM.c
 *
 * Description: Source file for the DC Motor Driver
 *
 * Author: Hosny, Tariq & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       		   *
 *******************************************************************************/

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "MOTOR_CONFIG.h"

/*******************************************************************************
 *                              		DC Motor Function Prototypes		     				     *
 *******************************************************************************/

void MOTOR_voidInitialization(void);

/************************ MOTOR Front Right *********************/

void MOTOR_voidFR_MotorSetSpeed(u32 Copy_u32Speed);
void MOTOR_voidFR_FWD();
void MOTOR_voidFR_BWD();
void MOTOR_voidFR_STOP();

/****************************** MOTOR Front Left *********************/

void MOTOR_voidFL_MotorSetSpeed(u32 Copy_u32Speed);
void MOTOR_voidFL_FWD();
void MOTOR_voidFL_BWD();
void MOTOR_voidFL_STOP();

/****************************** MOTOR Rear Right *********************/

void MOTOR_voidRR_MotorSetSpeed(u32 Copy_u32Speed);
void MOTOR_voidRR_FWD();
void MOTOR_voidRR_BWD();
void MOTOR_voidRR_STOP();

/****************************** MOTOR Rear Left *********************/

void MOTOR_voidRL_MotorSetSpeed(u32 Copy_u32Speed);
void MOTOR_voidRL_FWD();
void MOTOR_voidRL_BWD();
void MOTOR_voidRL_STOP();



#endif /* MOTOR_INTERFACE_H_ */
