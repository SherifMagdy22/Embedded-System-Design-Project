#ifndef SPEED_SENSOR_H
#define SPEED_SENSOR_H

#include "Common_Macros"
#include "GPIO.h"

#define KMH 0   // kilometers per hour
#define MS  1   // meters per second
#define MPH 2   // miles per hour
#define FTS 3   // feet per second

void speed_sensor_Init(pinX_t p1, pinX_t p2, uint8_t units);
void get_Speed(int16* speedPtr);
void speed_sensor_Sleep();
void speed_sensor_Wake();

#endif
