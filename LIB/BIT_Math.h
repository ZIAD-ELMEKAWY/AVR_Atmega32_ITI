/*
 *  file Name : BIT_Math.h
 *  Created on: ??þ/??þ/???? at ?:??:?? Õ
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define GET_BIT(reg,bit)    (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)

#endif /* LIB_BIT_MATH_H_ */
