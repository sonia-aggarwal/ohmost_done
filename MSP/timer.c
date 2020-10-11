#include "timer.h"

void ConfigureTimer(void)
{
    // Stop the timer and clear it.
    TA0CTL = (MC_0 | TACLR);

    // Assign a value to TA0CCR0
    TA0CCR0 = TA0CCR0_VALUE;

    // TACCR0 interrupt enabled (see Section 12.2.6 of User's Guide)
    TA0CCTL0 |= CCIE;

    // Start the timer in up mode, using the SMCLK as an the clock source
    TA0CTL |= (TASSEL_2 | MC_1);

    // dividing the input clock appropriately.
    TA0CTL = (TASSEL_2 | MC_1 | ID_2);
}

