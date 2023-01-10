#ifndef DOOR_SENSOR_H
#define DOOR_SENSOR_H

#include "Common_Macros"
#include "GPIO.h"

void door_sensor_Init(pinX_t p1, pinX_t p2);
void get_door_State(uint8_t* door_state_ptr);
void door_sensor_Sleep();
void door_sensor_Wake();

#endif