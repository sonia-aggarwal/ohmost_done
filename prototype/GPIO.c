/*
 * GPIO.c
 *
 *  Created on: Nov 4, 2020
 *      Author: cjbla
 */

#include "GPIO.h"

void initPumps()
{
    P2OUT &= ~BIT6;
    P8OUT &= ~BIT2;

    P2DIR |= BIT6;
    P8DIR |= BIT1;

    P2OUT &= ~BIT6;
    P8OUT &= ~BIT1;
}

void turnPumpOn(char pumpNum)
{
    switch (pumpNum)
    {
    case PUMP1:
        P2OUT |= BIT6;
        break;
    case PUMP2:
        P8OUT |= BIT1;
        break;
    }
}

void turnPumpOff(char pumpNum)
{
    switch (pumpNum)
    {
    case PUMP1:
        P2OUT &= ~BIT6;
        break;
    case PUMP2:
        P8OUT &= ~BIT1;
        break;
    }
}

void togglePump(char pumpNum)
{
    switch (pumpNum)
    {
    case PUMP1:
        P2OUT ^= BIT6;
        break;
    case PUMP2:
        P8OUT ^= BIT1;
        break;
    }

}

unsigned char GetPumpStatus()
{
    unsigned char status = 0;

    if (P2OUT & BIT6)
        status |= (1 << 0);
    if (P8OUT & BIT2)
        status |= (1 << 1);

    return status;
}

void initLEDs()
{
    P2OUT &= ~BIT4;
    P2OUT &= ~BIT5;
    P2DIR |= BIT4;
    P2DIR |= BIT5;
    P2OUT &= ~BIT4;
    P2OUT &= ~BIT5;
}

int DisableLED(char LEDNum)
{
    int value = 0;
    switch (LEDNum)
    {
    case LED1:
        value = P2OUT & BIT4;
        P2OUT ^= value;
        break;
    case LED2:
        value = P2OUT & BIT5;
        P2OUT ^= value;
        break;
    }
    return value;
}

void EnableLED(char LEDNum, int value)
{
    P2OUT ^= value;
}

void turnLedOn(char ledNum)
{
    switch (ledNum)
    {
    case LED1:
        P2OUT |= BIT4;
        break;
    case LED2:
        P2OUT |= BIT5;
        break;
    }
}

void turnLedOff(char ledNum)
{
    switch (ledNum)
    {
    case LED1:
        P2OUT &= ~BIT4;
        break;
    case LED2:
        P2OUT &= ~BIT5;
        break;
    }
}

void toggleLed(char ledNum)
{
    switch (ledNum)
    {
    case LED1:
        P2OUT ^= BIT4;
        break;
    case LED2:
        P2OUT ^= BIT5;
        break;
    }

}

unsigned char GetLEDStatus()
{
    unsigned char status = 0;

    if (P2OUT & BIT4)
        status |= (1 << 0);
    if (P2OUT & BIT5)
        status |= (1 << 1);

    return status;
}

