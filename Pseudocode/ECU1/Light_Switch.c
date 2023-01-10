
#include "Light_Switch.h"
#include "GPIO.h"

void get_switch_State(pinX_t pinNum, uint8_t* statePtr){
    GPIO_Pin_Read(pinNum, statePtr);
}

