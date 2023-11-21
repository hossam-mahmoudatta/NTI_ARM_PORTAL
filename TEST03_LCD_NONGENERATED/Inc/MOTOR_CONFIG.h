 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: MOTOR_CONFIG.c
 *
 * Description: Header file for the DC Motor Macro Declarations
 *
 * Author: Hosny, Tariq & Hossam
 *
 *******************************************************************************/

/*******************************************************************************
 *                              						Include Libraries						                       		   *
 *******************************************************************************/

#ifndef MOTOR_CONFIG_H_
#define MOTOR_CONFIG_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ERROR_STATUS.h"
#include "GPIO_INTERFACE.h"
#include "TIMER4_INTERFACE.h"

/*******************************************************************************
 *                              			DC Motor Macro Declarations		     				     *
 *******************************************************************************/

/************************ MOTOR Front Right *********************/
#define MOTOR_FR_IN1                       PORT_B, PIN_12
#define MOTOR_FR_IN2                      PORT_B, PIN_13
#define MOTOR_FR_ENABLE              PORT_B, PIN_6		// Binded to TIMERx Channelx

/************************ MOTOR Front Left *********************/
#define MOTOR_FL_IN1                       PORT_B, PIN_14
#define MOTOR_FL_IN2                      PORT_B, PIN_15
#define MOTOR_FL_ENABLE              PORT_B, PIN_7		// Binded to TIMERx Channelx

/************************ MOTOR Rear Right *********************/
#define MOTOR_RR_IN1                       PORT_A, PIN_8
#define MOTOR_RR_IN2                      PORT_A, PIN_9
#define MOTOR_RR_ENABLE              PORT_B, PIN_8		// Binded to TIMERx Channelx

/************************ MOTOR Rear Left *********************/
#define MOTOR_RL_IN1                       PORT_A, PIN_10
#define MOTOR_RL_IN2                      PORT_A, PIN_11
#define MOTOR_RL_ENABLE              PORT_B, PIN_9		// Binded to TIMERx Channelx


#endif /* MOTOR_CONFIG_H_ */
