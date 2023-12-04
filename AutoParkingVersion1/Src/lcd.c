
#include "TYPES.h"
#include "lcd.h"
#include "GPIO_INTERFACE.h"
#include "BIT_MATH.h"
#include "DELAY_INTERFACE.h"


void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*1- Set RS to Low: for command*/
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, RS, LOW);


	/*Send the command*/
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D4, GET_BIT(Copy_u8Command,4));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D5, GET_BIT(Copy_u8Command,5));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D6, GET_BIT(Copy_u8Command,6));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D7, GET_BIT(Copy_u8Command,7));



	/*Send the Enable pulse*/
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, EN, HIGH);
	_delay_ms(2);
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, EN, LOW);

	MGPIO_VidSetPinValue(LCD_DATA_PORT, D4, GET_BIT(Copy_u8Command,0));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D5, GET_BIT(Copy_u8Command,1));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D6, GET_BIT(Copy_u8Command,2));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D7, GET_BIT(Copy_u8Command,3));



	/*Send the Enable pulse*/
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, EN, HIGH);
	_delay_ms(2);
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, EN, LOW);

}
void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*1- Set RS to High: for data*/
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, RS, HIGH);



	/*Send the data*/

	MGPIO_VidSetPinValue(LCD_DATA_PORT, D4, GET_BIT(Copy_u8Data,4));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D5, GET_BIT(Copy_u8Data,5));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D6, GET_BIT(Copy_u8Data,6));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D7, GET_BIT(Copy_u8Data,7));


	/*Send the Enable pulse*/
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, EN, HIGH);
	_delay_ms(2);
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, EN, LOW);

	MGPIO_VidSetPinValue(LCD_DATA_PORT, D4 , GET_BIT(Copy_u8Data,0));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D5 , GET_BIT(Copy_u8Data,1));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D6 , GET_BIT(Copy_u8Data,2));
	MGPIO_VidSetPinValue(LCD_DATA_PORT, D7 , GET_BIT(Copy_u8Data,3));




	/*Send the Enable pulse*/
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, EN, HIGH);
	_delay_ms(2);
	MGPIO_VidSetPinValue(LCD_CONTROL_PORT, EN, LOW);
}

void CLCD_voidInit(void)
{
	MGPIO_VidSetPinDirection(LCD_CONTROL_PORT,RS,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(LCD_CONTROL_PORT,EN,OUTPUT_SPEED_10MHZ_PP);

	MGPIO_VidSetPinDirection(LCD_DATA_PORT,D4,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(LCD_DATA_PORT,D5,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(LCD_DATA_PORT,D6,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(LCD_DATA_PORT,D7,OUTPUT_SPEED_10MHZ_PP);

	/*1- wait for more then 30ms*/
	_delay_ms(50);

	/*2- Function set command: 2Lines, 5x7 Font size*/
	CLCD_voidSendCommand(0x02);
	_delay_ms(1);

	CLCD_voidSendCommand(0x28);
	_delay_ms(1);
	CLCD_voidSendCommand(0x0c);
	_delay_ms(1);
	CLCD_voidSendCommand(0x01);
	_delay_ms(20);
	CLCD_voidSendCommand(0x06);
	CLCD_voidSendCommand(0x80);

}
void CLCD_voidWriteNumber(u32 Copy_u32Number)
{
	/*u32 Local_u32Reserved=1;

	while(Copy_u32Number!=0)
	{	Local_u32Reserved = Local_u32Reserved*10 + Copy_u32Number%10;
	Copy_u32Number/=10;

	}
	do
	{
		CLCD_voidSendData((Local_u32Reserved%10)+ '0');
		Local_u32Reserved/=10;
	}
	while(Local_u32Reserved!=1);*/
	u8 arr[20];
	u8 i = 0 , j;
	if (Copy_u32Number == 0)
	{
		CLCD_voidSendData('0');
	}
	if (Copy_u32Number < 0)
	{
		Copy_u32Number = Copy_u32Number * -1;
		CLCD_voidSendData('-');
	}

	while(Copy_u32Number)
	{
		arr[i++] = Copy_u32Number%10 + '0';
		Copy_u32Number /= 10;
	}
	for (j = i; j>0; --j)
	{
		CLCD_voidSendData(arr[j - 1]);
	}

}

void CLCD_voidSendString(const char* Copy_pchString)
{
	u8 Local_u8Counter=0;
	while(Copy_pchString[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pchString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRamAddress,Local_u8Counter;

	/*1- calculate CGRAM address knowing that every pattern consumes 8 bytes*/
	Local_u8CGRamAddress= Copy_u8PatternNumber*8;

	/*2-Send SET CGRAM address command to LCD with setting bit6 ,clearing bit7*/
	CLCD_voidSendCommand(Local_u8CGRamAddress+64);

	/*3- write the pattern into CGRAM*/
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
	}
	/*4- Back to the DDRAM to display the special pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*5- Display the special pattern*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8DDRAMAddress;
	if(Copy_u8YPos ==0)
	{
		/*Check if in first line*/
		Local_u8DDRAMAddress=Copy_u8XPos;
	}
	else if(Copy_u8YPos==1)
	{
		/*Check if in second line*/
		Local_u8DDRAMAddress=0x40+Copy_u8XPos;
	}
	//Local_u8DDRAMAddress=0x40*Copy_u8YPos+Copy_u8XPos
	/*Setbit number 7 for SetDDRAM Address command then send the command*/
	CLCD_voidSendCommand(Local_u8DDRAMAddress+128);
}
