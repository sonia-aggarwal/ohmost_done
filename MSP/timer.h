#ifndef TIMER_H
#define TIMER_H

#include <msp430.h>

//divide TA0CCR0 by 4, in order
#define TA0CCR0_VALUE (62500-1)

// Prototypes
void ConfigureTimer(void);

#endif
