#ifndef __PORT_MODE_NAMES_H
#define __PORT_MODE_NAMES_H

typedef enum {
	COM1 = 0x01,
	COM2 = 0x02,
	COM3 = 0x03,
	COM_Default = 0x02,
}COMPORT;

typedef enum  {
  Low = 9600,
  Medium = 19200,
  High = 115200, 
	DefaultSpeed = 9600,
}PortSpeed;

typedef enum  {
    CONFIG_8N1,
    CONFIG_8N2,
    CONFIG_8E1,
    CONFIG_8E2,
    CONFIG_8O1,
    CONFIG_8O2,
    CONFIG_9N1,
    CONFIG_9N2,
    CONFIG_9E1,
    CONFIG_9E2,
    CONFIG_9O1,
    CONFIG_9O2
}PortConfig;

typedef enum  {
    MODE_TX,
    MODE_RX,
    MODE_TX_RX
}PortMode;
# endif //__PORT_MODE_NAMES_H
