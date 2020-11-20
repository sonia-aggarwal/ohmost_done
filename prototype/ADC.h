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

void enableADCinterrupt();

void disableADCinterrupt();

int SMB_Avg();

int SMM_Avg();

int WL_Avg();


int WL_Level(int ref, int avg);

#endif /* ADC_H_ */
