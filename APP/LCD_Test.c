/*
 *  File Name : main.c
 *  Created on: �8/5�/2026 at 10:44 �
 *  Author    : Ziad_Elmeakwy
 *  Description : Main program : LCD Test
 */

#define F_CPU	8000000UL
#include "util/delay.h"


#include "HAL/LCD/LCD_Interface.h"



int main()
{

	LCD_Init();
	LCD_Clear_Screen();
	while(1)
	{
		LCD_Send_Data('A');
		_delay_ms(1000);
		LCD_Clear_Screen();
		LCD_Send_Number(125);
		_delay_ms(1000);
		LCD_Clear_Screen();
		LCD_Set_Position(CLCD_ROW_1 , CLCD_COL_4);
		LCD_Send_String("Ziad Elmekawy");
		_delay_ms(1000);
		LCD_Clear_Screen();

	}

	return 0 ;
}
