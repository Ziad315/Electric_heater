/*
 * main.c
 *
 *  Created on: 28 Dec 2023
 *      Author: Ziad Yakoot
 */
#include<util/delay.h>
#include"STD_types.h"
#include"bitMath.h"
#include"DIO_interface.h"
#include"ADC_interface.h"

int main(void)
{
	uint8 ADC_read=0;
	uint32 analog=0;
	uint16 temp=0;
	ADC_init();
	DIO_setPinDirection(DIO_PORTD,PIN0,OUTPUT);   //HEATER
	while(1)
	{
		ADC_read=ADC_StartConversion(ADC0);
		analog=((uint32)ADC_read*5000UL)/256UL;
		temp=analog/10;
		if(temp<=30)
		{
			DIO_setPinValue(DIO_PORTD,PIN0,HIGH);
		}
		else if(temp>30)
		{
			DIO_setPinValue(DIO_PORTD,PIN0,LOW);
		}
	}

}
