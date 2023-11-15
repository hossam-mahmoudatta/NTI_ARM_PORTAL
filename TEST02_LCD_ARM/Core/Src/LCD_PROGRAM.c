#include "LCD_INTERFACE.h"



/*--------------- Initialize LCD ------------------*/
void LCD_voidInitialization(void)
{
	
	HAL_Delay(30);
	
	PIN_LOW(D4_PORT, D4_PIN);
	PIN_HIGH(D5_PORT, D5_PIN);
	PIN_LOW(D6_PORT, D6_PIN);
	PIN_LOW(D7_PORT, D7_PIN);
	PIN_LOW(RS_PORT, RS_PIN);
	
	PIN_HIGH(EN_PORT, EN_PIN);
	PIN_LOW(EN_PORT, EN_PIN);
	
	LCD_voidWrite(0, 0x28);
	LCD_voidWrite(0, 0x0c);
	LCD_voidWrite(0, 0x06);
	LCD_voidWrite(0, 0x01);
}

/*--------------- Write To LCD ---------------*/
void LCD_voidWrite(uint8_t copy_u8Type, uint8_t copy_u8Data)
{
	HAL_Delay(2);
	if(copy_u8Type)
	{
		PIN_HIGH(RS_PORT, RS_PIN);
	}else
	{
		PIN_LOW(RS_PORT, RS_PIN);
	}
	
	//Send High Nibble
	if(copy_u8Data & 0x80)
	{
		PIN_HIGH(D7_PORT, D7_PIN);
	}
	else
	{
		PIN_LOW(D7_PORT, D7_PIN);
	}
	
	if(copy_u8Data & 0x40)
	{
		PIN_HIGH(D6_PORT, D6_PIN);
	}
	else
	{
		PIN_LOW(D6_PORT,D6_PIN);
	}
	
	if(copy_u8Data & 0x20)
	{
		PIN_HIGH(D5_PORT, D5_PIN);
	}
	else
	{
		PIN_LOW(D5_PORT, D5_PIN);
	}
	
	if(copy_u8Data & 0x10)
	{
		PIN_HIGH(D4_PORT, D4_PIN);
	}
	else
	{
		PIN_LOW(D4_PORT, D4_PIN);
	}
	PIN_HIGH(EN_PORT, EN_PIN);
	PIN_LOW(EN_PORT, EN_PIN);
	
	//Send Low Nibble
	if(copy_u8Data & 0x08)
	{
		PIN_HIGH(D7_PORT, D7_PIN);
	}else
	{
		PIN_LOW(D7_PORT, D7_PIN);
	}
	
	if(copy_u8Data & 0x04)
	{
		PIN_HIGH(D6_PORT, D6_PIN);
	}
	else
	{
		PIN_LOW(D6_PORT, D6_PIN);
	}
	
	if(copy_u8Data & 0x02)
	{
		PIN_HIGH(D5_PORT, D5_PIN);
	}
	else
	{
		PIN_LOW(D5_PORT, D5_PIN);
	}
	
	if(copy_u8Data & 0x01)
	{
		PIN_HIGH(D4_PORT, D4_PIN);
	}else
	{
		PIN_LOW(D4_PORT, D4_PIN);
	}
	PIN_HIGH(EN_PORT, EN_PIN);
	PIN_LOW(EN_PORT, EN_PIN);
}

void LCD_voidPuts(uint8_t copy_u8Col, uint8_t copy_u8Row, int8_t *copy_int8String)
{
	//Set Cursor Position
	#ifdef LCD16xN	//For LCD16x2 or LCD16x4
	switch(copy_u8Col)
	{
		case 0: //Row 0
			LCD_voidWrite(0, 0x80 + 0x00 + copy_u8Row);
			break;
		case 1: //Row 1
			LCD_voidWrite(0, 0x80 + 0x40 + copy_u8Row);
			break;
		case 2: //Row 2
			LCD_voidWrite(0, 0x80 + 0x10 + copy_u8Row);
			break;
		case 3: //Row 3
			LCD_voidWrite(0, 0x80 + 0x50 + copy_u8Row);
			break;
	}
	#endif
	
	#ifdef LCD20xN	//For LCD20x4
	switch(x)
	{
		case 0: //Row 0
			lcd_write(0,0x80+0x00+y);
			break;
		case 1: //Row 1
			lcd_write(0,0x80+0x40+y);
			break;
		case 2: //Row 2
			lcd_write(0,0x80+0x14+y);
			break;
		case 3: //Row 3
			lcd_write(0,0x80+0x54+y);
			break;
	}
	#endif
	
	while(*copy_int8String)
	{
		LCD_voidWrite(1, *copy_int8String);
		copy_int8String++;
	}
}
void LCD_voidClear(void)
{
	LCD_voidWrite(0, 0x01);
}



