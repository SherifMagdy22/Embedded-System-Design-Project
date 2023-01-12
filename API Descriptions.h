Basic Communication Module (BCM) API:
BCM.init()
    Description: Initialize the BCM
    Arguments: 
        baud_rate (uint32_t) - CAN Bus data transfer speed, range 125 to 1000
    Return: None

BCM.Send(message, id)
    Description: Send a message on the CAN bus
    Arguments: 
        id (uint32_t) - the message identifier, range 0x00000001 to 0x00000003
        message (char*) - the message to be sent, range char[1] to char[8] for standard CAN Bus frame
    Return: None

BCM.Receive()
    Description: Receive a message from the CAN bus
    Arguments:     
        id (uint32_t) - the message identifier, range 0x00000001 to 0x00000003
        message (char*) - the message to be received, range char[1] to char[8] for standard CAN Bus frame
    Return: None

-------------------------------------

Buzzer Driver API:
Buzzer.init(frequency)
    Description: Initialize the buzzer driver
    Arguments: 
        pinNum (pinX_t) - the pin used to connect to the buzzer
        frequency (uint16_t) - the frequency of the buzzer tone in Hz, range 20 to 20000 Hz
    Return: None

Buzzer.on()
    Description: Turn the buzzer on
    Arguments: None
    Return: None

Buzzer.off()
    Description: Turn the buzzer off
    Arguments: None
    Return: None

-------------------------------------

Lights Driver API:
Lights_Driver.init()
    Description: Initialize the lights driver
    Arguments: 
        light1 (light_t*) - struct containing the pin connecting to the first light and the default state
        light2 (light_t*) - struct containing the pin connecting to the second light and the default state
    Return: None

Lights_Driver.set(light)
    Description: Change the state of a specific light 
    Arguments: 
        light (light_t*) - the light to be turned on
    Return: None

-------------------------------------

Light Switch API:
Light_Switch.get_switch_State()
    Description: Read the current state of the light switch
    Arguments: 
        pinNum (pinX_t) - light switch pin 
        statePtr (uint8_t*) - pointer to save the state, either HIGH or LOW
    Return: None

-------------------------------------

Speed Sensor API:
Speed_Sensor.init()
    Description: Initialize the speed sensor
    Arguments: 
        pinNum1 (pinX_t) , pinNum2 (pinX_t) - pins connecting to the speed sensor
    Return: None

Speed_Sensor.get_speed()
    Description: get the current speed from the sensor
    Arguments: 
        speedPtr (int16*) - pointer to store the speed value, range 0 to 250 km/h
    Return: 

Speed_Sensor.sleep()
    Description: puts the sensor in sleep mode
    Arguments: None
    Return: None

Speed_Sensor.wake()
    Description: wakes the sensor from sleep mode
    Arguments: None
    Return: None

-------------------------------------

Door Sensor API:
Door_sensor.init()
    Description: Initialize the door sensor
    Arguments:
        pinNum1 (pinX_t), pinNum2 (pinX_t)
    Return: None

Door_sensor.get_door_state()
    Description: Read the current state of the door sensor
    Arguments: 
        door_state_ptr (uint8_t*) - pointer to store the door state, either HIGH or LOW
    Return: None

Door_sensor.sleep()
    Description: puts the sensor in sleep mode
    Arguments: None
    Return: None

Door_sensor.wake()
    Description: wakes the sensor from sleep mode
    Arguments: None
    Return: None

