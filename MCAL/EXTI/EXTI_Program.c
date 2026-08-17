/*
 *  file Name : EXTI_Program.c
 *  Created on: ??‏/??‏/???? at ??:??:?? ص
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */


#include "EXTI_Interface.h"
#include "EXTI__Private.h"


/*
 * Parameter : 	 EXTI_LINE0
				 EXTI_LINE1
				 EXTI_LINE2
 */
void EXTI_Enable	(u8 exti_line)
{
	if((exti_line >= EXTI_LINE0 ) && (exti_line >= EXTI_LINE2 ))
	{
		SET_BIT(GICR , exti_line);
	}

}

/*
 * Parameter : 	 EXTI_LINE0
				 EXTI_LINE1
				 EXTI_LINE2
 */
void EXTI_Disable	(u8 exti_line)
{
	if((exti_line >= EXTI_LINE0 ) && (exti_line >= EXTI_LINE2 ))
	{
		CLR_BIT(GICR , exti_line);
	}

}

/*
 * Parameter : 	 EXTI_LINE0
				 EXTI_LINE1
				 EXTI_LINE2
 */
void EXTI_Clear_Flag	(u8 exti_line)
{
	SET_BIT(GIFR , exti_line);
}

/*
 * Parameter : 	 EXTI_LINE0
				 EXTI_LINE1
				 EXTI_LINE2
 */
u8   EXTI_Get_Flag		(u8 exti_line)
{
	return GET_BIT(GIFR , exti_line);
}
