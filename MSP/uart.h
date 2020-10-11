#ifndef UART_H
#define UART_H

#include <msp430.h>

#define BAUD_VAL    1666

// Initialization
#define UART_CTL0   UCA0CTL0
#define UART_CTL1   UCA0CTL1
#define UART_BR0    UCA0BR0
#define UART_BR1    UCA0BR1
#define UART_MCTL   UCA0MCTL
#define UART_STAT   UCA0STAT

#define UART_TX_BUF UCA0TXBUF
#define UART_RX_BUF UCA0RXBUF

#define ENABLE_UART_RXIE   IE2 |= UCA0RXIE
#define ENABLE_UART_TXIE   IE2 |= UCA0TXIE
#define DISABLE_UART_TXIE  IE2 &= ~UCA0TXIE
#define DISABLE_UART_RXIE  IE2 &= ~UCA0RXIE

#define SWRESET_ON      UART_CTL1 |= UCSWRST
#define SWRESET_OFF     UART_CTL1 &= ~(UCSWRST)

//Function Prototypes
void InitializeUART();

#endif /* UART_H_ */
