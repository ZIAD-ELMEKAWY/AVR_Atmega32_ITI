/*
 *  file Name : SSD_Interface.h
 *  Created on: ??þ/??þ/???? at ?:??:?? ã
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"


#define SSD_COMMON_CATHODE 0
#define SSD_COMMON_ANODE   1

// Port Defines
#define  SSD_PORTA  0
#define  SSD_PORTB  1
#define  SSD_PORTC  2
#define  SSD_PORTD  3

// PIN Defines
#define SSD_PIN0   0
#define SSD_PIN1   1
#define SSD_PIN2   2
#define SSD_PIN3   3
#define SSD_PIN4   4
#define SSD_PIN5   5
#define SSD_PIN6   6
#define SSD_PIN7   7

typedef struct {
		u8 Type       ;                 // SSD_COMMON_CATHODE or SSD_COMMON_ANODE
		u8 DataPort   ;                 // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD

}SSD_Type;


void SSD_InitialDataPort  ( SSD_Type ssd );
void SSD_SendNumber       ( SSD_Type ssd , u8 number );

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
