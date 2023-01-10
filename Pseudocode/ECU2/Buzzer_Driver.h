#ifndef BUZZER_DRIVER_H
#define BUZZER_DRIVER_H

#include "Common_Macros"
#include "GPIO.h"

buzzer_driver_Init(pinX_t pinNum, uint16_t frequency);    //frequency in hz
Buzzer_On();
Buzzer_Off();

#endif