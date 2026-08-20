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

typedef enum
{
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE

} EXTI_SenseControl_t;


void EXTI_Init(u8 exti_line, EXTI_SenseControl_t sense_control);
void EXTI_Signal_Latch(u8 exti_line, void (*Copy_pvSignalFunc)(void));

// Function Declaration
void EXTI_Enable	(u8 exti_line);
void EXTI_Disable	(u8 exti_line);

void EXTI_Clear_Flag	(u8 exti_line);
u8   EXTI_Get_Flag		(u8 exti_line);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
