#ifndef _GPIO_H_
#define _GPIO_H_


#include "stm32f746xx.h"



#define OUT_Gen_Push_Pull	           0b01011000
#define OUT_Gen_Pull_and_Pull_UP     0b01011010
#define OUT_Gen_Pull_and_Pull_UD     0b01011100
#define OUT_Gen_Open_Drain           0b01111000
#define OUT_Gen_Open_Drain_Pull_UP   0b01111010
#define OUT_Gen_Open_Drain_Pull_Down 0b01111110

#define OUT_Alt_Push_Pull	           0b10011000
#define OUT_Alt_Pull_and_Pull_UP     0b10011010
#define OUT_Alt_Pull_and_Pull_UD     0b10011100
#define OUT_Alt_Open_Drain           0b10111000
#define OUT_Alt_Open_Drain_Pull_UP   0b10111010
#define OUT_Alt_Open_Drain_Pull_Down 0b10111110

#define IN_Floating                  0b11000000
#define IN_Pull_UP                   0b00000010
#define IN_Pull_Down                 0b00000100
#define IN_Analog                    0b00000000

void GPIO_Setup(GPIO_TypeDef *PORT, uint8_t pin, uint8_t type);

void GPIO_ALT_Setup(GPIO_TypeDef *PORT, uint8_t pin, uint8_t function);

uint32_t GPIO_Read_PORT(GPIO_TypeDef *PORT);

void GPIO_Write_Port(GPIO_TypeDef *PORT, uint16_t data);

void GPIO_Pin_Set(GPIO_TypeDef *PORT, uint8_t pin);

void GPIO_Pin_Reset(GPIO_TypeDef *PORT, uint8_t pin);

uint16_t GPIO_Read_Pin(GPIO_TypeDef *PORT, uint8_t pin);





#endif
