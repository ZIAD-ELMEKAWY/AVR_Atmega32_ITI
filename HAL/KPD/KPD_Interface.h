/*
 *  file Name : KPD_Interface.h
 *  Created on: ??‏/??‏/???? at ?:??:?? م
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#include "../../MCAL/DIO/DIO_Interface.h"

#define NOTPRESSED 0xff

void KPD_Init(void);
u8   KPD_u8GetPressed( void );


#endif /* HAL_KPD_KPD_INTERFACE_H_ */

