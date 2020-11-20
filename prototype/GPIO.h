/*
 * GPIO.h
 *
 *  Created on: Nov 4, 2020
 *      Author: cjbla
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <msp430.h>
#include <stdint.h>

typedef enum
{
    NO_LED,
    LED1,
    LED2
} ledEnum;

typedef enum
{
    NO_PUMP,
    PUMP1,
    PUMP2
} pumpEnum;

/*!
    \brief          Initialize the LEDs

    \param[in]      none

    \return         none

    \note

    \warning
*/
void initLEDs();

int DisableLED(char LEDNum);

void EnableLED(char LEDNum, int value);

/*!
    \brief          Turn on the LED

    \param[in]      ledNum - LED to be turned on

    \return         none

    \note

    \warning
*/
void turnLedOn(char ledNum);

/*!
    \brief          Turn off the LED

    \param[in]      ledNum - LED to be turned of

    \return         none

    \note

    \warning
*/
void turnLedOff(char ledNum);

/*!
    \brief          Toggle the LED

    \param[in]      ledNum - LED to be toggled

    \return         none

    \note

    \warning
*/
void toggleLed(char ledNum);

/*!
    \brief          Get the LED status

    \param[in]      none

    \return         unsigned char - byte containing the status of LED

    \note

    \warning
*/
unsigned char GetLEDStatus();


/*!
    \brief          Initialize the Pumps

    \param[in]      none

    \return         none

    \note

    \warning
*/
void initPumps();

/*!
    \brief          Turn on the Pumps

    \param[in]      pumpNum - Pump to be turned on

    \return         none

    \note

    \warning
*/
void turnPumpOn(char pumpNum);

/*!
    \brief          Turn off the Pump

    \param[in]      pumpNum - Pump to be turned of

    \return         none

    \note

    \warning
*/
void turnPumpOff(char pumpNum);

/*!
    \brief          Toggle the Pump

    \param[in]      pumpNum - Pump to be toggled

    \return         none

    \note

    \warning
*/
void togglePump(char pumpNum);

/*!
    \brief          Get the Pump status

    \param[in]      none

    \return         unsigned char - byte containing the status of Pumps

    \note

    \warning
*/
unsigned char GetPumpStatus();


#endif /* GPIO_H_ */
