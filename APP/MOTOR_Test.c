
#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/Motor/Motor_Interface.h"



#define F_CPU 8000000UL

motor_t motor1 =
{
	.Port = DIO_PORTC ,
	.Pin = DIO_PIN0
};
motor_t motor2 =
{
	.Port = DIO_PORTC ,
	.Pin = DIO_PIN1
};

void Motor (void);

int main()
{
	GIE_Enable();
	DC_Motor_init(motor1);
	DC_Motor_init(motor2);


	while(1)
	{
		DC_Motor_ON(motor1);
		DC_Motor_OFF(motor2);
		_delay_ms(1000);
		DC_Motor_OFF(motor1);
		DC_Motor_OFF(motor2);
		_delay_ms(500);
		DC_Motor_OFF(motor1);
		DC_Motor_ON(motor2);
		_delay_ms(1000);
	}
	return 0 ;
}

