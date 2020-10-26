#include "GPIO.h"

void GPIO_Setup(GPIO_TypeDef *PORT, uint8_t pin, uint8_t type)
{
	
	PORT -> MODER   |= (uint8_t)((type & (uint8_t)0xC0) << (pin*2));
	PORT -> OTYPER  |= (uint8_t)((type & (uint8_t)0x20) << pin);
	PORT -> OSPEEDR |= (uint8_t)((type & (uint8_t)0x18) << (pin*2));
	PORT -> PUPDR   |= (uint8_t)((type & (uint8_t)0x06) << (pin*2));
}
//

void GPIO_ALT_Setup(GPIO_TypeDef *PORT, uint8_t pin, uint8_t function)
{
	if(pin < 8)
	{
		PORT -> AFR[0] |= (uint8_t)(function << (pin * 4));
	}
		else
		{
			PORT -> AFR[1] |= (uint8_t)(function << (pin * 4));
		}
}
//


uint32_t GPIO_Read_PORT(GPIO_TypeDef *PORT)
{
	return (PORT -> ODR);
}
//


void GPIO_Write_Port(GPIO_TypeDef *PORT, uint16_t data)
{
	PORT -> ODR = data;
}
//


void GPIO_Pin_Set(GPIO_TypeDef *PORT, uint8_t pin)
{
	PORT -> BSRR |= 1 << pin;
	
}

void GPIO_Pin_Reset(GPIO_TypeDef *PORT, uint8_t pin)
{
	PORT ->BSRR |= 1 << (pin * 2);
}
//

uint16_t GPIO_Read_Pin(GPIO_TypeDef *PORT, uint8_t pin)
{
	return (PORT->IDR & pin);
}
//

