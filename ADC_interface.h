/*
 * ADC_interface.h
 *
 *  Created on: 22 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC0            00000
#define ADC1            00001
#define ADC2            00010
#define ADC3            00011
#define ADC4            00100
#define ADC5            00101
#define ADC6            00110
#define ADC7            00111

#define ADC0_ADC0_10x     01000
#define ADC1_ADC0_10x     01001
#define ADC0_ADC0_200x    01010
#define ADC1_ADC0_200x    01011



void ADC_init            (void              );
uint8 ADC_StartConversion(uint8 copy_channal);

#endif /* ADC_INTERFACE_H_ */
