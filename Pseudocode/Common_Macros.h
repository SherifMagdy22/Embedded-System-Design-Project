#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H

typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;

#define HIGH 1
#define LOW 0

#define PRESSED 1
#define UNPRESSED 0

#define OPEN 1
#define CLOSED 0

typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	
}pinX_t;

#endif