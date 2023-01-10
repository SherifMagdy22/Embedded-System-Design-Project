#ifndef LIGHTS_DRIVER_H
#define LIGHTS_DRIVER_H

#include "Common_Macros"


typedef enum {
    LIGHT_OFF=0,
    LIGHT_ON,
    LIGHT_BLINKING,
} light_state_t;

typedef struct{
    pinX_t pin;
    light_state_t state;
} light_t;

void lights_driver_Init(light_t* light1, light_t* light2);
void lights_driver_Set(light_t* light);

#endif