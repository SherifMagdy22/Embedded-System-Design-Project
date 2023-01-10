
#include "Lights_Driver.h"
#include "GPIO.h"

void lights_driver_Init(light_t* light1, light_t* light2){
  GPIO_Pin_Init(light1->light_pin, OUTPUT);
  GPIO_Pin_Init(light2->light_pin, OUTPUT);
  GPIO_Pin_Write(light1->light_pin, LOW);
  GPIO_Pin_Write(light2->light_pin, LOW);
}

void lights_driver_Set(light_t* light){
  switch(light_t->Light_state){
    case LIGHT_OFF:
        GPIO_Pin_Write(light_t->Light_pin, LOW);
      break;
    case LIGHT_ON:
        GPIO_Pin_Write(light_t->Light_pin, HIGH);
      break;
    default:
      break;    
  }
}


