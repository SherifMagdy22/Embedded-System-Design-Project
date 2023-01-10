
#include "Common_Macros"
#include "Basic_Comm_Module.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Speed_Sensor.h"
#include "Door_Sensor.h"
#include "Light_Switch.h"

void Speed_Task(){
    uint16_t* speed;
    for( ;; ){
        get_Speed(speed);
        BCM_Send(ID1, speed, 2);

        vTaskDelayUntil(5);
    }
}

void Door_Task(){
    uint8_t* door_state;
    for( ;; ){
        get_door_State(door_state);
        BCM_Send(ID2, door_state, 1);

        vTaskDelayUntil(10);
    }
}

void Light_Switch_Task(){
    uint8_t* light_switch;
    for( ;; ){
        get_switch_State(PIN4, light_switch);
        BCM_Send(ID3, light_switch, 1);

        vTaskDelayUntil(20);
    }
}
 

int main(void){
    BCM_Init(500);
    speed_sensor_Init(PIN2, PIN3, KMH);
    door_sensor_Init(PIN0, PIN1);

    xTaskCreate(Speed_Task);
    xTaskCreate(Door_Task);
    xTaskCreate(Light_Switch_Task);

    vTaskStartScheduler();

	for( ;; );
}


