#ifndef _scc8660_h
#define _scc8660_h
#include "sensor.h"

typedef   signed          char int8;
typedef   signed short     int int16;
typedef   signed           int int32;

typedef unsigned          char uint8;
typedef unsigned short     int uint16;
typedef unsigned           int uint32;


void	scc8660_uart_init(void);
int 	scc8660_get_id1(unsigned char *id);
int 	scc8660_init(sensor_t *sensor);


#endif
