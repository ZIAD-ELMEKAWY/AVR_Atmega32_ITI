/*
 *  File Name : ADC_LED_Test.c
 *  Author    : (based on Ziad_Elmeakwy's AVR_Atmega32_ITI framework)
 *  Description : Read potentiometer voltage on ADC Channel 0 and switch
 *                Red / Yellow / Green LEDs according to the voltage range:
 *                  0V   < Vin < 1.5V  -> Red LED ON
 *                  1.5V < Vin < 3V    -> Yellow LED ON
 *                  Vin  > 3V          -> Green LED ON
 */

#include "util/delay.h"

#include "LIB/STD_Types.h"
#include "LIB/BIT_Math.h"

#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/LED/LED_Interface.h"

#define F_CPU 8000000UL

/* ADC thresholds equivalent to 1.5V and 3V on a 5V reference (10-bit ADC) */
#define THRESH_1_5V   500u
#define THRESH_3V     614u

/* LED configuration - adjust Port/Pin/Active_State to match your circuit */
LED_Type RedLED =
{
		.Port         = LED_PORTC ,
		.Pin          = LED_PIN0  ,
		.Active_State = ACTIVE_HIGH
};

LED_Type YellowLED =
{
		.Port         = LED_PORTC ,
		.Pin          = LED_PIN1  ,
		.Active_State = ACTIVE_HIGH
};

LED_Type GreenLED =
{
		.Port         = LED_PORTC ,
		.Pin          = LED_PIN2  ,
		.Active_State = ACTIVE_HIGH
};

int main(void)
{
	u16 Local_u16ADCResult = 0 ;
	u8  Local_u8ErrorState ;

	/* Peripheral Initialization */
	ADC_voidInit();

	LED_voidInit(RedLED);
	LED_voidInit(YellowLED);
	LED_voidInit(GreenLED);

	while(1)
	{
		/* Read potentiometer voltage on ADC Channel 0 */
		Local_u8ErrorState = ADC_u8GetResultSync(ADC_CHANNEL_0 , &Local_u16ADCResult);

		if (Local_u8ErrorState == OK)
		{
			/* Turn all LEDs off before evaluating the new reading */
			LED_voidOff(RedLED);
			LED_voidOff(YellowLED);
			LED_voidOff(GreenLED);

			if ( (Local_u16ADCResult > 0) && (Local_u16ADCResult < THRESH_1_5V) )
			{
				/* 0V < Vin < 1.5V */
				LED_voidOn(RedLED);
			}
			else if ( (Local_u16ADCResult >= THRESH_1_5V) && (Local_u16ADCResult < THRESH_3V) )
			{
				/* 1.5V < Vin < 3V */
				LED_voidOn(YellowLED);
			}
			else if (Local_u16ADCResult >= THRESH_3V)
			{
				/* Vin > 3V */
				LED_voidOn(GreenLED);
			}
		}

		_delay_ms(100);
	}

	return 0 ;
}
