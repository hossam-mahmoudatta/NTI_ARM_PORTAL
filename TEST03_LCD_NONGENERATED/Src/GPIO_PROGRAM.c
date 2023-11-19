 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_PROGRAM.c
 *
 * Description: Source file for the GPIO Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              							Include Libraries						                       		   *
 *******************************************************************************/

#include "GPIO_INTERFACE.h"

/*******************************************************************************
 *                              					GPIO Function Implementations									   	*
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
				GPIO_A_REG->GPIOx_CRL.CRL_u32Value &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_A_REG->GPIOx_CRL.CRL_u32Value |= ((copy_u8Mode) << (copy_u8PinID * 4));

			}
			else if(copy_u8PinID <= 15)
			{
				// CR High
				copy_u8PinID -= 8;
				GPIO_A_REG->GPIOx_CRH.CRH_u32Value &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_A_REG->GPIOx_CRH.CRH_u32Value |= ((copy_u8Mode) << (copy_u8PinID * 4));
			}
		break;
		case PORT_B:
			if(copy_u8PinID <= 7 )
			{
				//CR LOW
				GPIO_B_REG->GPIOx_CRL.CRL_u32Value &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_B_REG->GPIOx_CRL.CRL_u32Value |= ((copy_u8Mode) << (copy_u8PinID * 4));

			}
			else if(copy_u8PinID <= 15)
			{
				// CR High
				copy_u8PinID -= 8;
				GPIO_B_REG->GPIOx_CRH.CRH_u32Value &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_B_REG->GPIOx_CRH.CRH_u32Value |= ((copy_u8Mode) << (copy_u8PinID * 4));
			}
		break;
		case PORT_C:
			if(copy_u8PinID <= 7 )
			{
				//CR LOW
				GPIO_C_REG->GPIOx_CRL.CRL_u32Value &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_C_REG->GPIOx_CRL.CRL_u32Value |= ((copy_u8Mode) << (copy_u8PinID * 4));

			}
			else if(copy_u8PinID <= 15)
			{
				// CR High
				copy_u8PinID -= 8;
				GPIO_C_REG->GPIOx_CRH.CRH_u32Value &= ~ ((0b1111) << (copy_u8PinID * 4));
				GPIO_C_REG->GPIOx_CRH.CRH_u32Value |= ((copy_u8Mode) << (copy_u8PinID * 4));
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
				//GPIO_A_REG->GPIOx_ODR.ODR_u32Value |= ((GPIO_ODR_HIGH) << (copy_u8PinID));
				SET_BIT(GPIO_A_REG->GPIOx_ODR, copy_u8PinID);
			}
			else if(copy_u8pinValue == GPIO_ODR_LOW)
			{
				//GPIO_A_REG->GPIOx_ODR.ODR_u32Value |= ((GPIO_ODR_LOW) << (copy_u8PinID));
				CLR_BIT(GPIO_A_REG->GPIOx_ODR, copy_u8PinID);
			}
		break;

		case PORT_B:
			if(copy_u8pinValue == GPIO_ODR_HIGH)
			{
				//GPIO_B_REG->GPIOx_ODR.ODR_u32Value |= ((GPIO_ODR_HIGH) << (copy_u8PinID));
				SET_BIT(GPIO_B_REG->GPIOx_ODR, copy_u8PinID);
			}
			else if(copy_u8pinValue == GPIO_ODR_LOW)
			{
				//GPIO_B_REG->GPIOx_ODR.ODR_u32Value |= ((GPIO_ODR_LOW) << (copy_u8PinID));
				CLR_BIT(GPIO_B_REG->GPIOx_ODR, copy_u8PinID);
			}
		break;

		case PORT_C:
			if(copy_u8pinValue == GPIO_ODR_HIGH)
			{
				//GPIO_C_REG->GPIOx_ODR.ODR_u32Value |= ((GPIO_ODR_HIGH) << (copy_u8PinID));
				SET_BIT(GPIO_C_REG->GPIOx_ODR, copy_u8PinID);
			}
			else if(copy_u8pinValue == GPIO_ODR_LOW)
			{
				//GPIO_C_REG->GPIOx_ODR.ODR_u32Value |= ((GPIO_ODR_LOW) << (copy_u8PinID));
				CLR_BIT(GPIO_C_REG->GPIOx_ODR, copy_u8PinID);
			}
		break;
	}
}



u8 GPIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8PinID)
{
	// Setup the pin direction as required
	u8 u8Value = 0;

	switch(copy_u8PortID) {
		case PORT_A:
			//u8Value = GPIO_A_REG->GPIOx_IDR.IDR_u32Value;
			u8Value = GET_BIT(GPIO_A_REG->GPIOx_IDR, copy_u8PinID);
		break;
		case PORT_B:
			//u8Value = GPIO_B_REG->GPIOx_IDR.IDR_u32Value;
			u8Value = GET_BIT(GPIO_B_REG->GPIOx_IDR, copy_u8PinID);
		break;
		case PORT_C:
			//u8Value = GPIO_C_REG->GPIOx_IDR.IDR_u32Value;
			u8Value = GET_BIT(GPIO_C_REG->GPIOx_IDR, copy_u8PinID);
		break;
	}
	return u8Value;
}
