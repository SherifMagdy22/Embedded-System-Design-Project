
#include "Common_Macros"
#include "Basic_Comm_Module.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Buzzer_Driver.h"
#include "Lights_Driver.h"

uint16_t* speed = 0;
uint8_t* door_state = CLOSED;
uint8_t* light_switch = UNPRESSED;
light_t RL = {5, LOW};
light_t LL = {6, LOW};
TimerHandle_t Timer1;

void vTimerCallback(TimerHandle_t xTimer){
    LL.state = LIGHT_OFF;
    RL.state = LIGHT_OFF;
}

void Check_Speed(){
    for( ;; ){
        BCM_Receive(ID1, speed);
        vTaskDelayUntil(5);
    }
}

void Check_Door(){
    for( ;; ){
        BCM_Receive(ID2, door_state);
        vTaskDelayUntil(10);
    }
}

void Check_Light_Switch(){
    for( ;; ){
        BCM_Receive(ID3, light_switch);
        vTaskDelayUntil(20);
    }
}

void Logic_Task(){
    for( ;; ){
        if(door_state == OPEN && speed>0){
            Buzzer_On();
            LL.state = LIGHT_OFF;
            RL.state = LIGHT_OFF;
        }
        else if(door_state == OPEN && speed == 0){
            Buzzer_Off();
            LL.state = LIGHT_ON;
            RL.state = LIGHT_ON;
        }

        if((door_state == CLOSED) && (LL.state == LIGHT_ON) && (RL.state == LIGHT_ON)){
            xTimerStart(Timer1, 0);
        }
        
        if(speed>0 && lights_switch == PRESSED){
            Buzzer_Off();
            LL.state = LIGHT_ON;
            RL.state = LIGHT_ON;
        }
        else if(speed == 0 && lights_switch == PRESSED){
            Buzzer_On();
            LL.state = LIGHT_ON;
            RL.state = LIGHT_ON;
        }
        lights_driver_Set(&LL);
        lights_driver_Set(&RL);

        vTaskDelayUntil(4);
    }
}


int main(void){
    BCM_Init(500);
    buzzer_driver_Init(PIN0, 1000);
    lights_driver_Init(&RL, &LL);

    xTaskCreate(Check_Light_Switch);
    xTaskCreate(Check_Speed);
    xTaskCreate(Check_Door);
    xTaskCreate(Logic_Task);

    Timer1 = xTimerCreate
                 ("Timer1",
                   pdMS_TO_TICKS(3000),
                   pdFALSE,
                   ( void * ) 0,
                   vTimerCallback);

    vTaskStartScheduler();

	for( ;; );
}

