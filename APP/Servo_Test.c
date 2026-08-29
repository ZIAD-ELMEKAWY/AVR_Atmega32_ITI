/*
 *  file Name : Servo_Test.c
 *  Description : Servo motor control using TIMER1 Fast PWM (ICR1 TOP mode)
 *
 *  Hardware   : Servo signal wire -> PD5 (OC1A)
 *  Clock      : F_CPU = 8MHz , Timer1 Prescaler = 8  =>  1 tick = 1us
 *  Period     : ICR1 = 20000  =>  20ms  (50Hz, standard servo refresh rate)
 *  Pulse      : OCR1A in us   =>  1000us = 0deg , 1500us = 90deg , 2000us = 180deg
 *
 *  NOTE: Timer_Config.h in this repo is already set for Servo PWM:
 *        TIMER1_WAVEFORM_GENERATION_MODE = TIMER1_FAST_PWM_ICR1_MODE
 *        TIMER1_PRESCALER                = TIMER_DIVISION_FACTOR_8
 *        TIMER1_ICR1_VAL                 = 20000
 *        TIMER1_OCR1A_MODE               = TIMER_CLR_ON_CTC_SET_ON_TOP  (non-inverting PWM on OC1A)
 */

#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/Timer/Timer_Interface.h"

#define F_CPU 8000000UL

/* Servo pulse-width limits (in timer ticks == microseconds) */
#define SERVO_MIN_PULSE_US		1000U	/* 0   degrees */
#define SERVO_MID_PULSE_US		1500U	/* 90  degrees */
#define SERVO_MAX_PULSE_US		2000U	/* 180 degrees */

/* Converts an angle (0 -> 180) into the OCR1A compare value (pulse width in us) */
u16 SERVO_u16AngleToPulse(u8 Copy_u8Angle)
{
	u32 Local_u32Pulse;

	if (Copy_u8Angle > 180)
	{
		Copy_u8Angle = 180;
	}

	/* Linear mapping: 0->1000us , 180->2000us */
	Local_u32Pulse = SERVO_MIN_PULSE_US +
			(((u32)(SERVO_MAX_PULSE_US - SERVO_MIN_PULSE_US) * Copy_u8Angle) / 180);

	return (u16)Local_u32Pulse;
}

void SERVO_voidSetAngle(u8 Copy_u8Angle)
{
	TIMER1_voidSetCTCA(SERVO_u16AngleToPulse(Copy_u8Angle));
}

int main(void)
{
	u8 Local_u8Angle;

	GIE_Enable();

	/* OC1A = PD5 (on ATmega32) -> must be output for the PWM signal to appear on the pin */
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);

	/* Starts Timer1 in Fast PWM (ICR1 top) mode as configured in Timer_Config.h */
	TIMER1_voidInit();

	/* Center the servo at power-up */
	SERVO_voidSetAngle(90);
	_delay_ms(500);

	while (1)
	{
		/* Sweep 0 -> 180 degrees */
		for (Local_u8Angle = 0; Local_u8Angle <= 180; Local_u8Angle += 1)
		{
			SERVO_voidSetAngle(Local_u8Angle);
			_delay_ms(15);
		}

		_delay_ms(300);

		/* Sweep 180 -> 0 degrees */
		for (Local_u8Angle = 180; Local_u8Angle > 0; Local_u8Angle -= 1)
		{
			SERVO_voidSetAngle(Local_u8Angle - 1);
			_delay_ms(15);
		}

		_delay_ms(300);
	}

	return 0;
}

