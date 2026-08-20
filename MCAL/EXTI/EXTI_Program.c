/*
 *  file Name : EXTI_Program.c
 *  Created on: ??‏/??‏/???? at ??:??:?? ص
 *  Author    : Ziad_Elmeakwy
 *  Description :
 */

#include "EXTI_Interface.h"
#include "EXTI_Private.h"


/* Global Pointer to Function Array
 * [0] --> EXTI0
 * [1] --> EXTI1
 * [2] --> EXTI2
 */
static void (*EXTI_CallBack[3])(void) = {NULL, NULL, NULL};


/*===========================================================
 * Function Name : EXTI_Init
 * Description   : Initialize External Interrupt
 * Parameters    : EXTI_LINE0 / EXTI_LINE1 / EXTI_LINE2
 *                 EXTI_LOW_LEVEL
 *                 EXTI_ANY_LOGICAL_CHANGE
 *                 EXTI_FALLING_EDGE
 *                 EXTI_RISING_EDGE
 * Return        : void
 *===========================================================*/

void EXTI_Init(u8 exti_line, EXTI_SenseControl_t sense_control)
{
	if ((exti_line == EXTI_LINE0) ||
		(exti_line == EXTI_LINE1) ||
		(exti_line == EXTI_LINE2))
	{
		/*===================================================
		 * EXTI0 and EXTI1
		 * Sense Control is configured using MCUCR
		 *
		 * ISC01 ISC00
		 *
		 * 00 --> Low Level
		 * 01 --> Any Logical Change
		 * 10 --> Falling Edge
		 * 11 --> Rising Edge
		 *===================================================*/

		if (exti_line == EXTI_LINE0)
		{
			switch (sense_control)
			{
				case EXTI_LOW_LEVEL:

					CLR_BIT(MCUCR, 0);
					CLR_BIT(MCUCR, 1);

					break;


				case EXTI_ANY_LOGICAL_CHANGE:

					SET_BIT(MCUCR, 0);
					CLR_BIT(MCUCR, 1);

					break;


				case EXTI_FALLING_EDGE:

					CLR_BIT(MCUCR, 0);
					SET_BIT(MCUCR, 1);

					break;


				case EXTI_RISING_EDGE:

					SET_BIT(MCUCR, 0);
					SET_BIT(MCUCR, 1);

					break;


				default:
					break;
			}

			/* Enable EXTI0 */
			SET_BIT(GICR, EXTI_LINE0);
		}


		else if (exti_line == EXTI_LINE1)
		{
			switch (sense_control)
			{
				case EXTI_LOW_LEVEL:

					CLR_BIT(MCUCR, 2);
					CLR_BIT(MCUCR, 3);

					break;


				case EXTI_ANY_LOGICAL_CHANGE:

					SET_BIT(MCUCR, 2);
					CLR_BIT(MCUCR, 3);

					break;


				case EXTI_FALLING_EDGE:

					CLR_BIT(MCUCR, 2);
					SET_BIT(MCUCR, 3);

					break;


				case EXTI_RISING_EDGE:

					SET_BIT(MCUCR, 2);
					SET_BIT(MCUCR, 3);

					break;


				default:
					break;
			}

			/* Enable EXTI1 */
			SET_BIT(GICR, EXTI_LINE1);
		}


		else if (exti_line == EXTI_LINE2)
		{
			/*===================================================
			 * EXTI2 uses MCUCSR bit 6
			 *
			 * 0 --> Falling Edge
			 * 1 --> Rising Edge
			 *
			 * EXTI2 does NOT support:
			 * Low Level
			 * Any Logical Change
			 *===================================================*/

			if (sense_control == EXTI_FALLING_EDGE)
			{
				CLR_BIT(MCUCSR, 6);
			}

			else if (sense_control == EXTI_RISING_EDGE)
			{
				SET_BIT(MCUCSR, 6);
			}

			/* Enable EXTI2 */
			SET_BIT(GICR, EXTI_LINE2);
		}
	}
}


/*===========================================================
 * Function Name : EXTI_Signal_Latch
 * Description   : Register Callback Function for EXTI
 * Parameters    : EXTI_LINE0 / EXTI_LINE1 / EXTI_LINE2
 *                 Pointer to Function
 * Return        : void
 *===========================================================*/

void EXTI_Signal_Latch(u8 exti_line, void (*Copy_pvSignalFunc)(void))
{
	if ((exti_line == EXTI_LINE0) && (Copy_pvSignalFunc != NULL))
	{
		EXTI_CallBack[0] = Copy_pvSignalFunc;
	}

	else if ((exti_line == EXTI_LINE1) && (Copy_pvSignalFunc != NULL))
	{
		EXTI_CallBack[1] = Copy_pvSignalFunc;
	}

	else if ((exti_line == EXTI_LINE2) && (Copy_pvSignalFunc != NULL))
	{
		EXTI_CallBack[2] = Copy_pvSignalFunc;
	}
}


/*===========================================================
 * Existing Functions
 *===========================================================*/

void EXTI_Enable(u8 exti_line)
{
	if ((exti_line == EXTI_LINE0) ||
		(exti_line == EXTI_LINE1) ||
		(exti_line == EXTI_LINE2))
	{
		SET_BIT(GICR, exti_line);
	}
}


void EXTI_Disable(u8 exti_line)
{
	if ((exti_line == EXTI_LINE0) ||
		(exti_line == EXTI_LINE1) ||
		(exti_line == EXTI_LINE2))
	{
		CLR_BIT(GICR, exti_line);
	}
}


void EXTI_Clear_Flag(u8 exti_line)
{
	SET_BIT(GIFR, exti_line);
}


u8 EXTI_Get_Flag(u8 exti_line)
{
	return GET_BIT(GIFR, exti_line);
}



void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	if (EXTI_CallBack[0] != NULL)
	{
		EXTI_CallBack[0]();
	}
}
void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	if (EXTI_CallBack[1] != NULL)
	{
		EXTI_CallBack[1]();
	}
}
void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
	if (EXTI_CallBack[2] != NULL)
	{
		EXTI_CallBack[2]();
	}
}


