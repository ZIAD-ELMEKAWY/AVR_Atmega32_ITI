/*
 *  File Name : main.c
 *  Created on: �8/5�/2026 at 10:44 �
 *  Author    : Ziad_Elmeakwy
 *  Description : Main program : test keypad with LCD
 */

#define F_CPU	8000000UL
#include "util/delay.h"


#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KPD/KPD_Interface.h"


int main()
{
	u8 Pressed_Value = 0 ;

	KPD_Init();
	LCD_Init();
	LCD_Clear_Screen();
	while(1)
	{
		Pressed_Value = KPD_u8GetPressed();
		LCD_Send_Data(Pressed_Value);
		_delay_ms(2000);
		LCD_Clear_Screen();

	}

	return 0 ;
}
