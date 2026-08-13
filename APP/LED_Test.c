/*
 *  File Name : main.c
 *  Created on: ‏8/5‏/2026 at 10:44 م
 *  Author    : Ziad_Elmeakwy
 *  Description : Main program : Blink LED
 */

#define F_CPU	8000000UL
#include "util/delay.h"
#include "HAL/LED/LED_Interface.h"

#define F_CPU 8000000UL

LED_Type led1 =
{
		.Port = LED_PORTC ,
		.Pin = LED_PIN0 ,
		.Active_State = ACTIVE_LOW
};
LED_Type led2 =
{
		.Port = LED_PORTC ,
		.Pin = LED_PIN1 ,
		.Active_State = ACTIVE_HIGH
};
LED_Type led3 =
{
		.Port = LED_PORTC ,
		.Pin = LED_PIN2 ,
		.Active_State = ACTIVE_LOW
};
LED_Type led4 =
{
		.Port = LED_PORTC ,
		.Pin = LED_PIN3 ,
		.Active_State = ACTIVE_HIGH
};
LED_Type led5 =
{
		.Port = LED_PORTC ,
		.Pin = LED_PIN4 ,
		.Active_State = ACTIVE_LOW
};
LED_Type led6 =
{
		.Port = LED_PORTC ,
		.Pin = LED_PIN5 ,
		.Active_State = ACTIVE_HIGH
};

int main()
{

	// LED Initialization
	LED_voidInit(led1);
	LED_voidInit(led2);
	LED_voidInit(led3);
	LED_voidInit(led4);
	LED_voidInit(led5);
	LED_voidInit(led6);

	while(1)
	{
		LED_voidToggle(led1);
		LED_voidToggle(led2);
		LED_voidToggle(led3);
		LED_voidToggle(led4);
		LED_voidToggle(led5);
		LED_voidToggle(led6);
		_delay_ms(1000);

	}

	return 0 ;
}
