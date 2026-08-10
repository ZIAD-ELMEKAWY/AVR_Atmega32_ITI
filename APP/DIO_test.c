/*
 *  file Name : main.c
 *  Created on: 7/8/2026 at 01:30 pm
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */


#include "util/delay.h"
#include "MCAL/DIO/DIO_Interface.h"

#define F_CPU	8000000UL

int main()
{
	// make PIN0 at PORTC output and high
	// From Data sheet :  If DDxn is written
	// logic one, Pxn is configured as an output pin.
	DIO_SetPinDirection(DIO_PORTC , DIO_PIN0 ,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC , DIO_PIN1 ,DIO_OUTPUT);

	DIO_SetPortDirection(DIO_PORTA,DIO_OUTPUT);
	while(1)
	{
		// make PIN0 at PORTC output and high
		DIO_SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_HIGH);
		_delay_ms(100);
		DIO_SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_LOW);
		// make PIN1 at PORTC output and LOW
		DIO_SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_HIGH);
		_delay_ms(100);
		DIO_SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_LOW);

		DIO_SetPortValue(PORTA_Register , DIO_HIGH);
	}

	return 0;
}
