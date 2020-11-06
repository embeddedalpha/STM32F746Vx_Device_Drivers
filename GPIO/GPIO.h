#ifndef _GPIO_H_
#define _GPIO_H_


#include "stm32f746xx.h"



#define OUT_Gen_Push_Pull	           (uint8_t)88
#define OUT_Gen_Pull_and_Pull_UP     (uint8_t)90
#define OUT_Gen_Pull_and_Pull_UD     (uint8_t)92
#define OUT_Gen_Open_Drain           (uint8_t)120
#define OUT_Gen_Open_Drain_Pull_UP   (uint8_t)122
#define OUT_Gen_Open_Drain_Pull_Down (uint8_t)126

#define OUT_Alt_Push_Pull	           (uint8_t)152
#define OUT_Alt_Pull_and_Pull_UP     (uint8_t)154
#define OUT_Alt_Pull_and_Pull_UD     (uint8_t)156
#define OUT_Alt_Open_Drain           (uint8_t)184
#define OUT_Alt_Open_Drain_Pull_UP   (uint8_t)186
#define OUT_Alt_Open_Drain_Pull_Down (uint8_t)190

#define IN_Floating                  (uint8_t)192
#define IN_Pull_UP                   (uint8_t)2
#define IN_Pull_Down                 (uint8_t)4
#define IN_Analog                    (uint8_t)0

void GPIO_Setup(GPIO_TypeDef *port,uint8_t pin,uint8_t mode);

uint32_t GPIO_Read_PORT(GPIO_TypeDef *PORT);

void GPIO_Write_Port(GPIO_TypeDef *PORT, uint16_t data);

void GPIO_Pin_Set(GPIO_TypeDef *PORT, uint8_t pin);

void GPIO_Pin_Reset(GPIO_TypeDef *PORT, uint8_t pin);

uint16_t GPIO_Read_Pin(GPIO_TypeDef *PORT, uint8_t pin);





#endif
