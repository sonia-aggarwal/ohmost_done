#ifndef WATERLEVELSENSOR_H
#define WATERLEVELSENSOR_H

#include <msp430.h>


// Prototypes
void ReadData(void);
void SendData(void);
void SendNotification(int percent);


#endif
