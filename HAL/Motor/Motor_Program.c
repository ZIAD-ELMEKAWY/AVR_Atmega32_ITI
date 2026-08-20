/*
 *  file Name : Motor_Program.c
 *  Created on: ??‏/??‏/???? at ?:??:?? م
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#include "Motor_Interface.h"


void DCMOTOR_uint8Control (DCMOTOR_CONFIG * DcMotor , u8 Copy_uint8State)
{

	switch (Copy_uint8State)
	{
	case DCMOTOR_CW :
		 DIO_enumSetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_PIN_LOW) ;
		 DIO_enumSetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_PIN_HIGH) ;
		 break ;
	case DCMOTOR_CCW :
		 DIO_enumSetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_PIN_LOW) ;
		 DIO_enumSetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_PIN_HIGH) ;
		 break ;
	case DCMOTOR_STOP :
		 DIO_enumSetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_PIN_LOW) ;
		 DIO_enumSetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_PIN_LOW) ;
		 break ;
	}
}

