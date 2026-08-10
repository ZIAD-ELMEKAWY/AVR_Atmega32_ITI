/*
 *  file Name : SSD_Program.c
 *  Created on: ??þ/??þ/???? at ?:??:?? ã
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */


#include "SSD_Interface.h"


static u8 Local_u8SSDNumbers[10] = {0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111} ;


/**
 * Description : This Function initialize the port which connected to 7 Seg leds as output pins ( 8 Pins or Port )
 *
 */
void SSD_InitialDataPort  ( SSD_Type ssd )
{
	DIO_enumSetPortDirection(ssd.DataPort , DIO_PORT_OUTPUT);
}

void SSD_SendNumber       ( SSD_Type ssd , u8 number )
{
	if (ssd.Type == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPortValue(ssd.DataPort , Local_u8SSDNumbers[number]);
	}
	else if (ssd.Type == SSD_COMMON_ANODE)
	{
		DIO_enumSetPortValue(ssd.DataPort , ~(Local_u8SSDNumbers[number]));
	}

}


