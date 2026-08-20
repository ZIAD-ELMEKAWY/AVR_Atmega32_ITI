/*
 *  file Name : Motor_Interface.h
 *  Created on: ??‏/??‏/???? at ?:??:?? م
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef HAL_MOTOR_MOTOR_INTERFACE_H_
#define HAL_MOTOR_MOTOR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"

	#define DCMOTOR_CW		0
	#define DCMOTOR_CCW		1
	#define DCMOTOR_STOP	2

	typedef struct
	{
		u8 Copy_uint8DcMotorPort ;
		u8 Copy_uint8DcMotorPinA ;
		u8 Copy_uint8DcMotorPinB ;
	} DCMOTOR_CONFIG ;

	void DCMOTOR_uint8Control (DCMOTOR_CONFIG * DcMotor , u8 Copy_uint8State) ;

#endif /* HAL_MOTOR_MOTOR_INTERFACE_H_ */

