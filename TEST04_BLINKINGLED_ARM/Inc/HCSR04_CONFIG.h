 /******************************************************************************
 *
 * Module: HCSR04
 *
 * File Name: HCSR04_PRIVATE.h
 *
 * Description: Header file for the HCSR04 Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef HCSR04_CONFIG_H_
#define HCSR04_CONFIG_H_

#include "DELAY_INTERFACE.h"
#include "TIMER2_INTERFACE.h"
#include "TIMER3_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "ERROR_STATUS.h"

/*******************************************************************************
 *                              						HCSR04 Macro Definitions					               				     *
 *******************************************************************************/

#define HCSR04_S1_TRIGGER		PORT_A, PIN_2
#define HCSR04_S2_TRIGGER		PORT_A, PIN_3
#define HCSR04_S3_TRIGGER		PORT_B, PIN_0
#define HCSR04_S4_TRIGGER	PORT_B, PIN_1

#define HCSR04_S1_ECHO			PORT_A, PIN_0
#define HCSR04_S2_ECHO			PORT_A, PIN_1
#define HCSR04_S3_ECHO			PORT_A, PIN_6
#define HCSR04_S4_ECHO			PORT_A, PIN_7


#endif /* TIMER2_CONFIG_H_ */
