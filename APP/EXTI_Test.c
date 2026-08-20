#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "EXTI_Interface.h"
#include "GIE_Interface.h"


void INT0_CallBack(void)
{
	/* Toggle LED connected to PC0 */
	DIO_enumTogglePinValue(DIO_PORTC, DIO_PIN0);
}


int main(void)
{
	/*====================================================
	 * GPIO Configuration
	 *====================================================*/

	/* PC0 --> Output --> LED */
	DIO_enumSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);

	/* Initial LED state = LOW */
	DIO_enumSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);


	/* PD2 --> Input --> INT0 */
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);

	/* Enable internal Pull-Up resistor */
	DIO_enumSetPinValue(DIO_PORTD, DIO_PIN2, DIO_PIN_HIGH);


	/*====================================================
	 * EXTI Configuration
	 *====================================================*/

	/* Configure INT0 as Falling Edge */
	EXTI_Init(EXTI_LINE0, EXTI_FALLING_EDGE);

	/* Register callback function */
	EXTI_Signal_Latch(EXTI_LINE0, INT0_CallBack);


	/*====================================================
	 * Global Interrupt Enable
	 *====================================================*/

	GIE_Enable();


	while (1)
	{
		/* Main application */
	}

	return 0;
}
