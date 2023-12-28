/*
 * ADC_program.c
 *
 *  Created on: 22 Dec 2023
 *      Author: Ziad Yakoot
 */

#include "STD_types.h"
#include "bitMath.h"
#include "ADC_reg.h"
#include "ADC_cfg.h"
#include "ADC_interface.h"
#include "ADC_priv.h"


void ADC_init            (void              )
{
#if ADC_mode == AREF
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

#elif ADC_mode == AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

#elif ADC_mode == INTERNAL_2_56
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);


#endif

#if ADC_RESOLUTION_MODE  ==	 ADC_RESOLUTION_8_BITS
	SET_BIT(ADMUX,ADLAR);

#elif ADC_RESOLUTION_MODE  == ADC_RESOLUTION_10_BITS
	CLR_BIT(ADMUX,ADLAR);
#endif



#if CONVERSION_MODE	 == SINGLE_CONVERSION_MODE
	CLR_BIT(ADCSRA,ADATE);
	/*
	 * Continue configration of free running
	 */


#endif
 /*
  * continue interupt
  *
  */




	/*prescale*/
	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);

   ADCSRA |= PRESCALER;
SET_BIT(ADCSRA,ADEN);
}


uint8 ADC_StartConversion(uint8 copy_channal)
{
	    CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);

		ADMUX |=copy_channal;
		 SET_BIT(ADCSRA,ADSC);
		 while(!(GET_BIT(ADCSRA,ADIF))==LOW);
		 SET_BIT(ADCSRA,ADIF);
		 return ADCH;
}
