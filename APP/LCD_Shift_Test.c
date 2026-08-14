/*
 *  file Name : LCD_Interface.h
 *  Created on: 14/8/2026
 *  Author    : Ziad_Elmeakwy
 *  Description : Main Program for testing LCD shift
 */


#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>

#define F_CPU 8000000UL

int main(void)
{
    LCD_Init();


    while(1)
    {
    	/*========== Example 1: Shift entire display left 3 steps ==========*/
		LCD_Send_String("Ziad Elmekawy ");
		_delay_ms(1000);
		LCD_Shift_Display(LCD_SHIFT_LEFT, 5, 100);
    }

    return 0;
}
