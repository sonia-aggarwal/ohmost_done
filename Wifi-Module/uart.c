#include "uart.h"

void InitializeUART(){
    P1SEL |= ( BIT1 | BIT2 );
    P1SEL2 |= ( BIT1 | BIT2 );

    SWRESET_ON;

    UART_CTL1 |= UCSSEL_2;
    UART_CTL0 = 0;

    UART_BR0 = (char) BAUD_VAL;
    UART_BR1 = (char) (BAUD_VAL >> 8);

    UART_MCTL = UCBRS_6;

    SWRESET_OFF;

   // Interrupt Enables
    ENABLE_UART_RXIE;
    ENABLE_UART_TXIE;

}

