/*
 *  File Name : main.c
 *  Created on: þ8/5þ/2026 at 10:44 ã
 *  Author    : Ziad_Elmeakwy
 *  Description : Main program : Blink LED
 */

#define F_CPU	8000000UL
#include "util/delay.h"


#include "HAL/SSD/SSD_Interface.h"

// Common Cathode
SSD_Type ssd1 =
{
		.DataPort = SSD_PORTC ,
		.Type = SSD_COMMON_CATHODE
};

// Common Anode
SSD_Type ssd2 =
{
		.DataPort = SSD_PORTD ,
		.Type = SSD_COMMON_ANODE
};

int main()
{

	SSD_InitialDataPort(ssd1);
	SSD_InitialDataPort(ssd2);

	while(1)
	{
		for (u8 i =0 ; i<=9 ; i++)
		{
			SSD_SendNumber(ssd1 , i );
			_delay_ms(500);
		}
		for (u8 i =0 ; i<=9 ; i++)
		{
			SSD_SendNumber(ssd2 , i );
			_delay_ms(500);
		}
	}

	return 0 ;
}
