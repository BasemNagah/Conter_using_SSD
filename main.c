/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: hp
 */
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/SSD/SSD_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>



volatile u8 copy_value = 0 ;
volatile u8 ssd1_value = 0 ;
volatile u8 ssd2_value = 0 ;

void app(void)
{
	copy_value++ ;
	ssd1_value = copy_value/10 ;
	ssd2_value = copy_value%10 ;
}

int main(void)
{

	GIE_voidEnable();
	SSD_t SSD1 = { DIO_PORTA , SSD_COMMON_ANODE };
	SSD_t SSD2 = { DIO_PORTC , SSD_COMMON_ANODE };
	SSD_voidInit(&SSD1);
	SSD_voidInit(&SSD2);

	SSD_voidEnable( &SSD1 , 0 );
	SSD_voidEnable( &SSD2 , 0 );

	EXTI_voidChangeSenseControl(EXTI_INT2 , EXTI_FAILING_EDGE );
	EXTI_voidEnable(EXTI_INT2);
	EXTI_voidSetCallBack(EXTI_INT2 , app);

	while(1)
	{
		SSD_voidEnable( &SSD1 , ssd1_value );
		SSD_voidEnable( &SSD2 , ssd2_value );
	}

	return 0 ;
}



