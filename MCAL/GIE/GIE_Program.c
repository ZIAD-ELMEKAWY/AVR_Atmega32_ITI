/*
 *  file Name : GIE_Program.c
 *  Created on: ??‏/??‏/???? at ??:??:?? ص
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */


#include "GIE_Interface.h"
#include "GIE_Private.h"

void GIE_Enable(void)
{
	SET_BIT(SREG , SREG_I);
}
void GIE_Disable(void)
{
	CLR_BIT(SREG , SREG_I);
}
