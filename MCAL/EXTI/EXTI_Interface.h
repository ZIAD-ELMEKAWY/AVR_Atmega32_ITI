/*
 *  file Name : EXTI_Interface.h
 *  Created on: ??‏/??‏/???? at ??:??:?? ص
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"



#define EXTI_LINE0	6
#define EXTI_LINE1	7
#define EXTI_LINE2	5




// Function Declaration
void EXTI_Enable	(u8 exti_line);
void EXTI_Disable	(u8 exti_line);

void EXTI_Clear_Flag	(u8 exti_line);
u8   EXTI_Get_Flag		(u8 exti_line);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
