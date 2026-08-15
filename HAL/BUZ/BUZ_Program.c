/*
 *  file Name : BUZ_Program.c
 *  Created on: ??‏/??‏/???? at ??:??:?? م
 *  Author    : Ziad_Elmeakwy
 *  Description : 
 */

#include "BUZ_Interface.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to led as output pin
* Parameters :
            => struct has the led port , pin , status
* return : void
*/
void BUZ_voidInit( BUZ_Type BUZ_Configuration )
{

	DIO_enumSetPinDirection( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_OUTPUT );

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set high on led pin ( led on )
* Parameters :
            => struct has the led port , pin , status
* return : void
*/
void BUZ_voidOn  ( BUZ_Type BUZ_Configuration )
{
	DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_HIGH );

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set low on led pin ( led off )
* Parameters :
             => struct has the led port , pin , status
* return : void
*/
void BUZ_voidOff ( BUZ_Type BUZ_Configuration )
{

	DIO_enumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_LOW  );

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function toggle led pin
* Parameters :
             => struct has the led port , pin , status
* return : void
*/
void BUZ_voidToggle      ( BUZ_Type BUZ_Configuration )
{
	DIO_enumTogglePinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
