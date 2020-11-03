/*
 * tcp_socket.h
 *
 *  Created on: Nov 2, 2020
 *      Author: cjbla
 */

#ifndef TCP_SOCKET_H_
#define TCP_SOCKET_H_

#include "simplelink.h"
#include "sl_common.h"

#define APPLICATION_VERSION "1.3.0"

#define HOST_NAME              "httpbin.org"
#define HOST_PORT              80

#define SL_STOP_TIMEOUT        0xFF

/* IP addressed of server side socket. Should be in long format,
 * E.g: 0xc0a8010a == 192.168.1.10 */
#define IP_ADDR         0xd8ef2436
#define PORT_NUM        80            /* Port number to be used */

#define BUF_SIZE        1400
#define NO_OF_PACKETS   1

/* Application specific status/error codes */
typedef enum{
    DEVICE_NOT_IN_STATION_MODE = -0x7D0,        /* Choosing this number to avoid overlap w/ host-driver's error codes */
    TCP_SEND_ERROR = DEVICE_NOT_IN_STATION_MODE - 1,
    TCP_RECV_ERROR = TCP_SEND_ERROR -1,

    STATUS_CODE_MAX = -0xBB8
}e_AppStatusCodes;

/*
 * GLOBAL VARIABLES -- Start
 */
union
{
    _u8 BsdBuf[BUF_SIZE];
    _u32 demobuf[BUF_SIZE/4];
} uBuf;

/*
 * GLOBAL VARIABLES -- End
 */

int connectToServer();



#endif /* TCP_SOCKET_H_ */
