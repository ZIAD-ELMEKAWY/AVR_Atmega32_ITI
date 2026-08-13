/*
 *  file Name : LCD_Config.h
 *  Created on: ??‏/??‏/???? at ?:??:?? ص
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#include "../../MCAL/DIO/DIO_Interface.h"

#define LCD_DATA_PORT		DIO_PORTC
#define LCD_CONTROL_PORT	DIO_PORTD

#define LCD_RS		DIO_PIN0
#define LCD_RW		DIO_PIN1
#define LCD_EN		DIO_PIN2

#endif /* HAL_LCD_LCD_CONFIG_H_ */
