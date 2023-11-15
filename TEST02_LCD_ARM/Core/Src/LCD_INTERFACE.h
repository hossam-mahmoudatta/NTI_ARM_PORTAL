#ifndef		__LCDTXT_H
#define		__LCDTXT_H

#include "stm32f1xx_hal.h"


/*------------- Define LCD Use -----------------*/

/*Note: Comment which not use */

//#define LCD16xN //For lcd16x2 or lcd16x4
#define LCD20xN //For lcd20x4

/*------------- Define For Connection -----------------*/

#define RS_PORT		GPIOB
#define RS_PIN		GPIO_PIN_15

#define EN_PORT		GPIOB
#define EN_PIN		GPIO_PIN_14

#define D7_PORT		GPIOB
#define D7_PIN		GPIO_PIN_10

#define D6_PORT		GPIOB
#define D6_PIN		GPIO_PIN_11

#define D5_PORT		GPIOB
#define D5_PIN		GPIO_PIN_12

#define D4_PORT		GPIOB
#define D4_PIN		GPIO_PIN_13


/*------------ Declaring Private Macro -----------------*/

#define PIN_LOW(PORT, PIN)	HAL_GPIO_WritePin(PORT,PIN, GPIO_PIN_RESET);
#define PIN_HIGH(PORT, PIN)	HAL_GPIO_WritePin(PORT,PIN, GPIO_PIN_SET);

/*------------ Declaring Function Prototype -------------*/

void LCD_voidInitialization(void);
void LCD_voidWrite(uint8_t copy_u8Type, uint8_t copy_u8Data);
void LCD_voidPuts(uint8_t copy_u8Col, uint8_t copy_u8Row, int8_t *copy_int8String);
void LCD_voidClear(void);

#endif

