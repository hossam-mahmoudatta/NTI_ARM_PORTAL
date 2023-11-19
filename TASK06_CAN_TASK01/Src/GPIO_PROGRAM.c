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

#include "GPIO_INTERFACE.h"

/*******************************************************************************
 *                              					RCC Function Implementations									   	*
 *******************************************************************************/

// Initializes the RCC Module with the necessary Configurations
void GPIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Mode)
{
	// Setup the pin direction as required
	switch(copy_u8PortID) {
		case PORT_A:
			if(copy_u8PinID <= 7 )
			{
				//CR LOW
				GPIO_A_REG->GPIOx_CRL &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_A_REG->GPIOx_CRL |= ((copy_u8Mode) << (copy_u8PinID * 4));

			}
			else if(copy_u8PinID <= 15)
			{
				// CR High
				copy_u8PinID -= 8;
				GPIO_A_REG->GPIOx_CRH &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_A_REG->GPIOx_CRH |= ((copy_u8Mode) << (copy_u8PinID * 4));
			}
		break;
		case PORT_B:
			if(copy_u8PinID <= 7 )
			{
				//CR LOW
				GPIO_B_REG->GPIOx_CRL &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_B_REG->GPIOx_CRL |= ((copy_u8Mode) << (copy_u8PinID * 4));

			}
			else if(copy_u8PinID <= 15)
			{
				// CR High
				copy_u8PinID -= 8;
				GPIO_B_REG->GPIOx_CRH &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_B_REG->GPIOx_CRH |= ((copy_u8Mode) << (copy_u8PinID * 4));
			}
		break;
		case PORT_C:
			if(copy_u8PinID <= 7 )
			{
				//CR LOW
				GPIO_C_REG->GPIOx_CRL &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_C_REG->GPIOx_CRL |= ((copy_u8Mode) << (copy_u8PinID * 4));

			}
			else if(copy_u8PinID <= 15)
			{
				// CR High
				copy_u8PinID -= 8;
				GPIO_C_REG->GPIOx_CRH &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_C_REG->GPIOx_CRH |= ((copy_u8Mode) << (copy_u8PinID * 4));
			}
		break;
	}
}



void GPIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8pinValue)
{
	// Setup the pin direction as required
	switch(copy_u8PortID) {
		case PORT_A:
			if(copy_u8pinValue == GPIO_ODR_HIGH)
			{
				//CR LOW
				SET_BIT(GPIO_A_REG->GPIOx_ODR, copy_u8PinID);
			}
			else if(copy_u8pinValue == GPIO_ODR_LOW)
			{
				CLR_BIT(GPIO_A_REG->GPIOx_ODR, copy_u8PinID);
			}
		break;

		case PORT_B:
			if(copy_u8pinValue == GPIO_ODR_HIGH)
			{
				//CR LOW
				SET_BIT(GPIO_B_REG->GPIOx_ODR, copy_u8PinID);
			}
			else if(copy_u8pinValue == GPIO_ODR_LOW)
			{
				CLR_BIT(GPIO_B_REG->GPIOx_ODR, copy_u8PinID);
			}
		break;

		case PORT_C:
			if(copy_u8pinValue == GPIO_ODR_HIGH)
			{
				SET_BIT(GPIO_C_REG->GPIOx_ODR, copy_u8PinID);
			}
			else if(copy_u8pinValue == GPIO_ODR_LOW)
			{
				CLR_BIT(GPIO_C_REG->GPIOx_ODR, copy_u8PinID);
			}
		break;
	}
}



u8 GPIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID)
{
	// Setup the pin direction as required
	u8 Value = 0;

	switch(copy_u8PortID) {
		case PORT_A:
			Value = GET_BIT(GPIO_A_REG->GPIOx_IDR, copy_u8PinID);
		break;
		case PORT_B:
			Value = GET_BIT(GPIO_B_REG->GPIOx_IDR, copy_u8PinID);
		break;
		case PORT_C:
			Value = GET_BIT(GPIO_C_REG->GPIOx_IDR, copy_u8PinID);
		break;
	}
	return Value;
}
