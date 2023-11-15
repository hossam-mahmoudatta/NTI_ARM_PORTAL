#ifndef		__LCDTXT_H
#define		__LCDTXT_H

#include "LCD_CONFIG.h"


/*------------- Define LCD Use -----------------*/

/*Note: Comment which not use */

//#define LCD16xN //For lcd16x2 or lcd16x4
#define LCD20xN //For lcd20x4

/*------------- Define For Connection -----------------*/



/*------------ Declaring Function Prototype -------------*/

void LCD_voidInitialization(void);
void LCD_voidWrite(u8 copy_u8Type, u8 copy_u8Data);
void LCD_voidPuts(u8 copy_u8Col, u8 copy_u8Row, cu8 *copy_cu8String);
void LCD_voidClear(void);

#endif

