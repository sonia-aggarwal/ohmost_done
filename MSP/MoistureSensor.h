#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

#include <msp430.h>


// Prototypes
void InitializeMoistureSensorPins(void);
void ReadData(void);
void SendData(void);
void CrossLowThreshold(int);

#endif
