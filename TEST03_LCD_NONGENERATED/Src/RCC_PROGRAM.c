 /******************************************************************************
 *
 * Module: RCC (Reset & Clock Control)
 *
 * File Name: RCC_PROGRAM.c
 *
 * Description: Source file for the RCC Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "../Inc/RCC_INTERFACE.h"

/*******************************************************************************
 *                              					RCC Function Implementations									   	*
 *******************************************************************************/

// Initializes the RCC Module with the necessary Configurations
void RCC_voidInitialization(void)
{
	u32 LOC_u32TimeOut = 0;		// Variable for counting a timeout if system stuck
	/***************************************************************************/
#if	RCC_CLOCKTYPE == RCC_HSI
	RCC_CR_REG->HSION = HSION_STATE;
	RCC_CR_REG->HSITRIM = 0b10000; 		// Default Value @ 16
	RCC_CFGR_REG->SW = CFGR_SW_HSI;

	// Check for timeout for HSI Instability
	while((RCC_CR_REG->HSIRDY == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
	if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }
	/***************************************************************************/
#elif	RCC_CLOCKTYPE == RCC_HSE_CRYSTAL
	RCC_CR_REG->HSEON = HSEON_STATE;	// HSE Clock Enable
	RCC_CR_REG->HSEBYP = DISABLE;	// Ext High Speed Clk not Bypassed
	RCC_CFGR_REG->SW = CFGR_SW_HSE;		// Selects HSE as System Clk

	// Check for timeout for HSI Instability
	while((RCC_CR_REG->HSERDY == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
	if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }
	/***************************************************************************/
#elif	RCC_CLOCKTYPE == RCC_HSE_RC
	RCC_CR_REG->HSEON = HSEON_STATE;
	RCC_CR_REG->HSEBYP = ENABLE;
	RCC_CFGR_REG->SW = CFGR_SW_HSE;
	/***************************************************************************/
#elif	RCC_CLOCKTYPE == RCC_PLL
	RCC_CR_REG->PLLON = PLL_STATE;
	RCC_CFGR_REG->SW = CFGR_SW_PLL;
	RCC_CFGR_REG->PLLSRC		= 	PLLSRC_SELECT;
	RCC_CFGR_REG->PLLXTPRE	= 	PLLXPTRE_SELECT;
	RCC_CFGR_REG->PLLMUL		= 	CFGR_PLLMUL_FACTOR;
	/***************************************************************************/
#else
		#error("CLOCK TYPE UNDEFINED!")
#endif
	/***************************************************************************/
	// Other Initializations
	RCC_CR_REG->CSSON 			=	CSSON_STATE;	// Clock Security Mode
//	RCC_CFGR_REG->HPRE 			= 	CFGR_HPRE_PRESCALER;
//	RCC_CFGR_REG->PPRE1 		=	CFGR_PPRE1_PRESCALER;
//	RCC_CFGR_REG->PPRE2			= 	CFGR_PPRE2_PRESCALER;
//	RCC_CFGR_REG->MCO			= 	CFGR_MSO_CLK;
}


// Chooses the clock type and enables it
void RCC_voidPeripheralClockEnable(u8 copy_u8BusID, u8 copy_u8PeripheralID)
{
	if (copy_u8PeripheralID <= 31)
	{
		switch (copy_u8BusID)
		{
			case RCC_AHB  :
				SET_BIT(RCC_AHBENR_REG, copy_u8PeripheralID);
				break;
			case RCC_APB1 :
				SET_BIT(RCC_APB1ENR_REG, copy_u8PeripheralID);
				break;
			case RCC_APB2 :
				SET_BIT(RCC_APB2ENR_REG, copy_u8PeripheralID);
				break;
		}
	}
	else
	{

	}
}


// Chooses the clock type and disables it
void RCC_voidPeripheralClockDisable(u8 copy_u8BusID, u8 copy_u8PeripheralID)
{
	if (copy_u8PeripheralID <= 31)
	{
		switch (copy_u8BusID)
		{
		case RCC_AHB  :
			CLR_BIT(RCC_AHBENR_REG, copy_u8PeripheralID);
			break;
		case RCC_APB1 :
			CLR_BIT(RCC_APB1ENR_REG, copy_u8PeripheralID);
			break;
		case RCC_APB2 :
			CLR_BIT(RCC_APB2ENR_REG, copy_u8PeripheralID);
			break;
		}
	}
	else
	{

	}
}

