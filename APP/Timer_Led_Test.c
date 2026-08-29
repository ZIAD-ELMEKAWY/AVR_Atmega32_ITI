/*
 *  File Name : ADC_LED_Test.c
 *  Author    : (based on Ziad_Elmeakwy's AVR_Atmega32_ITI framework)
 *  Description : Read potentiometer voltage on ADC Channel 0 and switch
 *                Red / Yellow / Green LEDs according to the voltage range:
 *                  0V   < Vin < 1.5V  -> Red LED ON
 *                  1.5V < Vin < 3V    -> Yellow LED ON
 *                  Vin  > 3V          -> Green LED ON
 *
 *  Hardware:
 *    - Potentiometer wiper -> PA0 (ADC Channel 0)
 *    - Red LED    -> PORTC Pin0
 *    - Yellow LED -> PORTC Pin1
 *    - Green LED  -> PORTC Pin2
 *    (Change LED port/pin below to match your wiring)
 *
 *  Note:
 *    ADC_VREF is configured as AVCC (5V) in MCAL/ADC/ADC_Config.h,
 *    with RIGHT_ADJUSTMENT, so ADC_u8GetResultSync() returns a 10-bit
 *    value from 0 to 1023 representing 0V to 5V.
 *      1.5V -> (1.5/5.0)*1023 = ~307
 *      3.0V -> (3.0/5.0)*1023 = ~614
 */

#include "util/delay.h"

#include "LIB/STD_Types.h"
#include "LIB/BIT_Math.h"

#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "MCAL/Timer/Timer_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"

#define F_CPU 8000000UL

LED_Type led1=
{
		.Port = DIO_PORTB ,
		.Pin = DIO_PIN0,
		.Active_State = ACTIVE_LOW
};

u16 count = 0 ;

void LED_voidLedTog(void)
{
	count++;
	if(count == 1000)
	{
		TIMER0_voidSetPreload(124);
		LED_voidToggle(led1);
		count = 0 ;

	}

}

int main(void)
{
	LED_voidInit(led1);
	TIMER0_voidInit();

	TIMER_u8SetCallBack(&LED_voidLedTog , TIMER0_OVF_VECTOR_ID);
	
	GIE_Enable();

	while(1)
	{

	}

	return 0 ;
}
