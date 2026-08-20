/*
 *  file Name : Motor_Program.c
 *  Created on: ??‏/??‏/???? at ?:??:?? م
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#include "Motor_Interface.h"


/* <<<<<<<<<<<<<<<<<<<<<<<<<<< User Interface Definition  >>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/***
 * @name				DC_Motor_init
 * @brief				Initializes a DC motor by setting its control pin as an output and ensuring it's initially off.
 * @argument motor		A structure `motor_t` containing the port and pin information for the DC motor.
 * @return				void
 */
void DC_Motor_init 	(motor_t motor)
{
	if((motor.Port>= DIO_PORTA) && (motor.Port<= DIO_PORTD) )
	{
		if((motor.Pin >= DIO_PIN0) && (motor.Pin <= DIO_PIN7))
		{
			DIO_enumSetPinDirection(motor.Port, motor.Pin , DIO_PIN_OUTPUT);
			DIO_enumSetPinValue(motor.Port , motor.Pin , DIO_PIN_LOW);
		}
	}
}

/***
 * @name				DC_Motor_ON
 * @brief				Turns on the DC motor by setting its control pin to a high value.
 * @argument motor		A structure `motor_t` containing the port and pin information for the DC motor.
 * @return				void
 */
void DC_Motor_ON 	(motor_t motor)
{
	if((motor.Port>= DIO_PORTA) && (motor.Port<= DIO_PORTD) )
	{
		if((motor.Pin >= DIO_PIN0) && (motor.Pin <= DIO_PIN7))
		{
			DIO_enumSetPinValue(motor.Port , motor.Pin , DIO_PIN_HIGH);
		}
	}
}

/***
 * @name				DC_Motor_OFF
 * @brief				Turns off the DC motor by setting its control pin to a low value.
 * @argument motor		A structure `motor_t` containing the port and pin information for the DC motor.
 * @return				void
 */
void DC_Motor_OFF (motor_t motor)
{
	if((motor.Port >= DIO_PORTA) && (motor.Port<= DIO_PORTD) )
	{
		if((motor.Pin >= DIO_PIN0) && (motor.Pin <= DIO_PIN7))
		{
			DIO_enumSetPinValue(motor.Port , motor.Pin , DIO_PIN_LOW);
		}
	}
}

