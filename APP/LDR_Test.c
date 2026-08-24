
#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

#define F_CPU 8000000UL

LED_Type led1 =
{
	.Port = DIO_PORTD ,
	.Pin = DIO_PIN0
};

LED_Type led2 =
{
	.Port = DIO_PORTD ,
	.Pin = DIO_PIN1
};

LED_Type led3 =
{
	.Port = DIO_PORTD ,
	.Pin = DIO_PIN2
};



int main()
{
	u16 result = 0;

	DIO_enumSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_PIN_INPUT);

	LED_voidInit(led1);
	LED_voidInit(led2);
	LED_voidInit(led3);
	ADC_voidInit();


	while(1)
	{
		ADC_u8GetResultSync(ADC_CHANNEL_0 , &result);
		result = result *(5000 /1024);
		if((result>0) && (result<1000))
		{
			LED_voidOn(led1);
			LED_voidOff(led2);
			LED_voidOff(led3);
		}

	}
	return 0 ;
}

