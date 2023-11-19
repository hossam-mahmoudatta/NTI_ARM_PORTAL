

#ifndef INC_LCD_INTERFACE_H_
#define INC_LCD_INTERFACE_H_


#define LCD_CONTROL_PORT     GPIOA
#define RS    PIN11
#define EN    PIN10


#define LCD_DATA_PORT     GPIOB
#define D4				PIN15
#define D5				PIN14
#define D6				PIN13
#define D7				PIN12



void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char *Copy_pchString);

void CLCD_voidWriteNumber(u32 Number);
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);


#endif /* INC_LCD_INTERFACE_H_ */
