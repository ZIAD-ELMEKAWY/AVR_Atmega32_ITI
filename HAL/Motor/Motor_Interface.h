/*
 *  file Name : Motor_Interface.h
 *  Created on: ??‏/??‏/???? at ?:??:?? م
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef HAL_MOTOR_MOTOR_INTERFACE_H_
#define HAL_MOTOR_MOTOR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"

/* <<<<<<<<<<<<<<<<<<<<<<< Data Types   >>>>>>>>>>>>>>>>>>>>>>>>>>>  */
typedef struct
{
	u8 Port ;
	u8 Pin;
}motor_t;
/* <<<<<<<<<<<<<<<<< User Interface Declaration >>>>>>>>>>>>>>> */
void DC_Motor_init 	(motor_t motor);
void DC_Motor_ON 	(motor_t motor);
void DC_Motor_OFF 	(motor_t motor);


#endif /* HAL_MOTOR_MOTOR_INTERFACE_H_ */
