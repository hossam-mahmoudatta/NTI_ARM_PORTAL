 /******************************************************************************
 *
 * Module: RCC (Reset & Clock Control)
 *
 * File Name: RCC_PRIVATE.h
 *
 * Description: Header file for the RCC Driver Registers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#include <BIT_MATH.h>
#include <STD_TYPES.h>

/*******************************************************************************
 *                              							RCC Registers					                   				     *
 *******************************************************************************/

#define DMA_BASE_ADDRESS	0x40020000

typedef struct {
	u32 DMA_CCRx_EN;
	u32 DMA_CCRx_TCIE;
	u32 DMA_CCRx_HTIE;
	u32 DMA_CCRx_TEIE;
	u32 DMA_CCRx_DIR;
	u32 DMA_CCRx_CIRC;
	u32 DMA_CCRx_PINC;
	u32 DMA_CCRx_MINC;
	u32 DMA_CCRx_PSIZE;
	u32 DMA_CCRx_MSIZE;
	u32 DMA_CCRx_PL;
	u32 DMA_CCRx_MEM2MEM;
} CCRx;

typedef struct {
	CCRx DMA_CCRx;
	u32 DMA_CNDTRx;
	u32 DMA_CPARx;
	u32 DMA_CMARx;
} DMAx;


typedef struct {
	u32 DMA_ISR;
	u32 DMA_IFCR;
	DMAx DMA_CHx[7];
} DMA;

#define DMA_REG *((volatile DMA*) DMA_BASE_ADDRESS)


#define STK_CTRL_ENABLE 	0
#define STK_CTRL_TICKINT 	1
#define STK_CTRL_CLKSOURCE 	2
#define STK_CTRL_COUNTFLAG 	16
#define STK_CTRL_REG    *((volatile u32*) 0xE000E010)			// RCC CLOCK CONTROL REGISTER

#define STK_LOAD_REG    *((volatile u32*) 0xE000E014)			// RCC CLOCK CONTROL REGISTER

#define STK_VAL_REG    	*((volatile u32*) 0xE000E018)			// RCC CLOCK CONTROL REGISTER

#define STK_CALIB_REG   *((volatile u32*) 0xE000E00C)			// RCC CLOCK CONTROL REGISTER



#endif
