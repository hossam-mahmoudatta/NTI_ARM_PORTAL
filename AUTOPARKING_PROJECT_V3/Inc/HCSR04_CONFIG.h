 /******************************************************************************
 *
 * Module: HCSR04
 *
 * File Name: HCSR04_CONFIG.h
 *
 * Description: Header file for the HCSR04 Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					Include Libraries						                       	*
 *******************************************************************************/

#ifndef HCSR04_CONFIG_H_
#define HCSR04_CONFIG_H_

#include "DELAY_INTERFACE.h"
#include "TIMER2_INTERFACE.h"
#include "TIMER3_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "ERROR_STATUS.h"

/*******************************************************************************
 *                              			HCSR04 Macro Definitions				      				     *
 *******************************************************************************/

#define HCSR04_S1_TRIGGER		GPIOB, PIN5
#define HCSR04_S2_TRIGGER		GPIOA, PIN2
#define HCSR04_S3_TRIGGER		GPIOB, PIN0
#define HCSR04_S4_TRIGGER	GPIOB, PIN10
#define HCSR04_S5_TRIGGER		GPIOA, PIN3

#define HCSR04_S1_ECHO			GPIOA, PIN0
#define HCSR04_S2_ECHO			GPIOA, PIN1
#define HCSR04_S3_ECHO			GPIOA, PIN6
#define HCSR04_S4_ECHO			GPIOA, PIN7
#define HCSR04_S5_ECHO			GPIOB, PIN1

/**
 * HCSR04_S1 == FRONT
 * HCSR04_S2 == REAR
 * HCSR04_S3 == FRONT RIGHT
 * HCSR04_S4 == REAR RIGHT
 * HCSR04_S5 == FRONT LEFT
 */

#endif /* HCSR04_CONFIG_H_ */
