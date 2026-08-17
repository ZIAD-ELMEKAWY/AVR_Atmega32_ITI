/*
 *  file Name : EXTI__Private.h
 *  Created on: ??‏/??‏/???? at ??:??:?? ص
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef MCAL_EXTI_EXTI__PRIVATE_H_
#define MCAL_EXTI_EXTI__PRIVATE_H_

#define MCUCSR			*((volatile u8 *)0x54)
#define MCUCR			*((volatile u8 *)0x55)
#define GIFR			*((volatile u8 *)0x5A)
#define GICR			*((volatile u8 *)0x5B)

#define NULL 0


#endif /* MCAL_EXTI_EXTI__PRIVATE_H_ */
