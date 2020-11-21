/*
 * main.c - TCP socket sample application
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Application Name     -   TCP socket
 * Application Overview -   This is a sample application demonstrating how to open
 *                          and use a standard TCP socket with CC3100.
 * Application Details  -   http://processors.wiki.ti.com/index.php/CC31xx_TCP_Socket_Application
 *                          doc\examples\tcp_socket.pdf
 */

#include "tcp_socket.h"
#include "ADC.h"
#include "board.h"
#include "GPIO.h"
#include "timer_a.h"
#include <stdio.h>

volatile int SM1_value;
volatile int SM2_value;

extern unsigned long mintTimer;

int main(int argc, char** argv)
{
    /* Stop WDT and initialize the system-clock of the MCU
     These functions needs to be implemented in PAL */
    stopWDT();
    initClk();

    /* Configure command line interface */
    CLI_Configure();

    platform_timer_init();

    initADC();
    initPumps();
    initLEDs();

    int StartLightsMintTimer = 0;
    int StartLightsBasilTimer = 0;
    int StartSensorTimer = 0;

    int MaxMintLightsOn = 1;
    int MaxBasilLightsOn = 1;

    int MaxMintLightsOff = 1;
    int MaxBasilLightsOff = 1;

    int MintLightsOn = 0;
    int BasilLightsOn = 0;

    int SensorInterval = 1;

    int CurrentTime = 0;

    while (1)
    {

        CurrentTime = platform_get_time_in_mins();

        if (CurrentTime - StartLightsMintTimer >= MaxMintLightsOn
                && MintLightsOn)
        {
            turnLedOff(LED1);
            StartLightsMintTimer = CurrentTime;
            MintLightsOn = 0;
        }
        else if (CurrentTime - StartLightsMintTimer >= MaxMintLightsOff
                && !MintLightsOn)
        {
            turnLedOn(LED1);
            StartLightsMintTimer = CurrentTime;
            MintLightsOn = 1;
        }

        if (CurrentTime - StartLightsBasilTimer >= MaxBasilLightsOn
                && BasilLightsOn)
        {
            turnLedOff(LED2);
            StartLightsBasilTimer = CurrentTime;
            BasilLightsOn = 0;
        }
        else if (CurrentTime - StartLightsBasilTimer >= MaxBasilLightsOff
                && !BasilLightsOn)
        {
            turnLedOn(LED2);
            StartLightsBasilTimer = CurrentTime;
            BasilLightsOn = 1;
        }

        if (CurrentTime - StartSensorTimer >= SensorInterval)
        {
            int pumpsRun = 0;

            if (SMM_Avg() > 2800)
            {
                int value;
                value = DisableLED(LED1);
                turnPumpOn(PUMP1);
                //Delay(15000);
                Delay(500);
                turnPumpOff(PUMP1);
                EnableLED(LED1, value);
                pumpsRun++;
            }

            if (SMB_Avg() > 2800)
            {
                int value;
                value = DisableLED(LED2);
                turnPumpOn(PUMP2);
                //Delay(15000);
                Delay(500);
                turnPumpOff(PUMP2);
                EnableLED(LED2, value);
                pumpsRun++;
            }
            StartSensorTimer = CurrentTime;

            if (pumpsRun)
            {
                connectToServer(WL_Level(WL_Ref(), WL_Avg()), "WLD");
            }
        }


        if (platform_get_time_in_mins() % 5 == 0
                && platform_get_time_in_secs() % 60 == 0)
        {
            connectToServer(WL_Level(WL_Ref(), WL_Avg()), "WLN");
            Delay(10);
            connectToServer(SMM_Avg(), "SMM");
            Delay(10);
            connectToServer(SMB_Avg(), "SMB");
        }
    }
    return 0;
}

