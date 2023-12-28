/*
 * ADC_cfg.h
 *
 *  Created on: 22 Dec 2023
 *      Author: Ziad Yakoot
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*Select reference voltage
 * 00 AREF and internal voltage
 * 01 AVCC with external capacitor
 * 10 reserved
 * 11 internal 2.65v
 * */

#define AREF               1
#define AVCC               2
#define INTERNAL_2_56      3
#define ADC_mode           AVCC

#define ADC_RESOLUTION_8_BITS    1
#define ADC_RESOLUTION_10_BITS   2

#define ADC_RESOLUTION_MODE     ADC_RESOLUTION_8_BITS

#define  SINGLE_CONVERSION_MODE          1
#define FREE_RUNNING_MODE                2
#define CONVERSION_MODE     SINGLE_CONVERSION_MODE



#define Divide_By_2              1
#define Divide_By_4              2
#define Divide_By_16             3
#define Divide_By_32             4
#define Divide_By_64             5
#define Divide_By_128            7
#define PRESCALER         Divide_By_128
#endif /* ADC_CFG_H_ */
