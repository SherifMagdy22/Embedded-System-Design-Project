#ifndef BASIC_COMM_MODULE_H
#define BASIC_COMM_MODULE_H

#include "Common_Macros"
#include "FreeRTOS.h"
#include "task.h"

#define ID1 0x00000001
#define ID2 0x00000002
#define ID3 0x00000003

BCM_Init(uint32_t baud_rate);  // In kbps
BCM_Send(uint32_t id, uint16_t* message, uint8_t data_length);
BCM_Receive(uint32_t id, uint16_t* message);

#endif