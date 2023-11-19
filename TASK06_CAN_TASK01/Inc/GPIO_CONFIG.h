 /******************************************************************************
 *
 * Module: RCC (Reset & Clock Control)
 *
 * File Name: RCC_CONFIG.h
 *
 * Description: Header file for the RCC Driver MACRO DECLARATIONS
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "GPIO_PRIVATE.h"

/*******************************************************************************
 *                              						GPIO Macro Definitions					               				     *
 *******************************************************************************/

#define PORT_A				0
#define PORT_B				1
#define PORT_C				2

#define PIN_0				0
#define PIN_1				1
#define PIN_2				2
#define PIN_3				3
#define PIN_4				4
#define PIN_5				5
#define PIN_6				6
#define PIN_7				7

#define PIN_8				8
#define PIN_9				9
#define PIN_10				10
#define PIN_11				11
#define PIN_12				12
#define PIN_13				13
#define PIN_14				14
#define PIN_15				15

//For Output Mode with Speed 10
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

#define PIN_INPUT_MODE		INPUT_PULLUP_PULLDOWN

//For Output Mode with Speed 10
#define OUTPUT_SPEED_10MHZ_PUSHPULL     0b0001
#define OUTPUT_SPEED_10MHZ_OPENDRAIN    0b0101
#define OUTPUT_SPEED_10MHZ_AFPUSHPULL   0b1001
#define OUTPUT_SPEED_10MHZ_AFOPENDRAIN  0b1101

//For Output Mode with Speed 2
#define OUTPUT_SPEED_2MHZ_PUSHPULL      0b0010
#define OUTPUT_SPEED_2MHZ_OPENDRAIN      0b0110
#define OUTPUT_SPEED_2MHZ_AFPUSHPULL    0b1010
#define OUTPUT_SPEED_2MHZ_AFOPENDRAIN    0b1110

//For Output Mode with Speed 50
#define OUTPUT_SPEED_50MHZ_PUSHPULL     0b0011
#define OUTPUT_SPEED_50MHZ_OPENDRAIN     0b0111
#define OUTPUT_SPEED_50MHZ_AFPUSHPULL  0b1011
#define OUTPUT_SPEED_50MHZ_AFOPENDRAIN   0b1111

#define PIN_OUTPUT_MODE		OUTPUT_SPEED_10MHZ_PUSHPULL

#define	GPIO_IDR_LOW				0
#define	GPIO_IDR_HIGH				1

#define	GPIO_ODR_LOW				0
#define	GPIO_ODR_HIGH				1

#define	GPIO_BSRR_LOW				0
#define	GPIO_BSRR_HIGH				1




//// Enabling and Disabling bits for Initializations
//#define	GPIO_CONFIG_IN_ANALOG		0b00
//#define	GPIO_CONFIG_IN_FLOATING		0b01
//#define	GPIO_CONFIG_IN_PULLUPDWN	0b10
//#define GPIO_CONFIG_IN				GPIO_CONFIG_PULLUPDWN
//
//
//#define	GPIO_CONFIG_OUT_PUSHPULL		0b00
//#define	GPIO_CONFIG_OUT_OPENDRAIN		0b01
//#define	GPIO_CONFIG_OUT_ALTPUSHPULL		0b10
//#define	GPIO_CONFIG_OUT_ALTOPENDRAIN	0b11
//#define GPIO_CONFIG_OUT					GPIO_CONFIG_OUT_OPENDRAIN
//
//#define	GPIO_MODE_INPUT					0b00
//#define	GPIO_MODE_OUT_10MHZ				0b01
//#define	GPIO_MODE_OUT_02MHZ				0b10
//#define	GPIO_MODE_OUT_50MHZ				0b11
//#define GPIO_MODE						GPIO_MODE_OUT_10MHZ





#endif
