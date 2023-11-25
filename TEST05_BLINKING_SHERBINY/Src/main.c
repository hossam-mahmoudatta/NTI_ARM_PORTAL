
#include <stdint.h>
#include "ERROR_STATUS.h"
#include "MACROS.h"
#include "TYPES.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "MOTOR_interface.h"
#include "TIMER_interface.h"
#include "DELAY_INTERFACE.h"
#include "USART_INTERFACE.h"
#include "TIMER_private.h"

int main(void)
{
	u8 LOC_u8NewData = 0 ;

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOA_RCC);
	MRCC_VidEnablePeripheralClock(APB2_BUS, GPIOB_RCC);

//	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM2_RCC);
//	MRCC_VidEnablePeripheralClock(APB1_BUS, TIM4_RCC);
//	MRCC_VidEnablePeripheralClock(APB2_BUS, AFIO_RCC);
//	MOTORS_Void_MotorInit();

	//blue
//	MRCC_VidEnablePeripheralClock ( APB2_BUS , USART1_RCC) ;

//	MGPIO_VidSetPinDirection      ( GPIOA , PIN9  , OUTPUT_SPEED_2MHZ_AFPP ) ;
//	MGPIO_VidSetPinDirection      ( GPIOA , PIN10 , INPUT_FLOATING         ) ;
//
//
//	MGPIO_VidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_2MHZ_PP);
//
//	MOTOR_RF_Void_MotorSetSpeed(255);
//	MOTOR_LF_Void_MotorSetSpeed(255);
//
//	MUSART_VidInit();

	MGPIO_VidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);


	/* Loop forever */
	while(1)
	{
		MGPIO_VidSetPinValue(GPIOA, PIN4, HIGH);
		_delay_ms(500);
		MGPIO_VidSetPinValue(GPIOA, PIN4, LOW);
		_delay_ms(500);
	}
}
