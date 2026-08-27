/*
 *  file Name : Stepper_Motor_Interface.h
 *  Created on: ??‏/??‏/???? at ??:??:?? ص
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


#define STEPPER_FULL_STEP    1
#define STEPPER_HALF_STEP    0

#define STEPPER_CLOCK_WISE       1
#define STEPPER_ANTI_CLOCK_WISE  0

void STEPPER_voidInit( void );
void STEPPER_voidOff ( void );
void STEPPER_voidOn  ( u8 Copy_u8StepType , u8 Copy_u8Direction , u8 Copy_u8Speed , u16 Copy_u16Degree );

#endif /* HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_ */
