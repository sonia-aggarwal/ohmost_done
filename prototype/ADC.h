/*
 * ADC.h
 *
 *  Created on: Oct 30, 2020
 *      Author: cjbla
 */

#ifndef ADC_H_
#define ADC_H_

#include <msp430.h>

#define   Num_of_Results   8

volatile unsigned int A0results[Num_of_Results];
volatile unsigned int A1results[Num_of_Results];
volatile unsigned int A2results[Num_of_Results];
volatile unsigned int A3results[Num_of_Results];

void initADC();

int calculateWaterLevel(int vRef, int Vmeas);

void enableADCinterrupt();

void disableADCinterrupt();


#endif /* ADC_H_ */
