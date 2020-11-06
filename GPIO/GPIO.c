#include "GPIO.h"

void GPIO_Setup(GPIO_TypeDef *port,uint8_t pin,uint8_t type)
{
	if(port == GPIOA)
	{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	}
	else if(port == GPIOB)
	{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	}
	else if(port == GPIOC)
	{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	}
	else if(port == GPIOD)
	{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	}
	else if(port == GPIOE)
	{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	}
		
	port -> MODER   |= (uint8_t)(((type & (uint8_t)0xC0) >> 6) << (pin * 2));
	port -> OTYPER  |= (uint8_t)(((type & (uint8_t)0x20) >> 5) << (pin * 1));
	port -> OSPEEDR |= (uint8_t)(((type & (uint8_t)0x18) >> 3) << (pin * 2));
	port -> PUPDR   |= (uint8_t)(((type & (uint8_t)0x06) >> 1) << (pin * 2));	
	
	if(pin >= 152 && pin <= 190)
	{
		if(pin < 8)
	{
		port -> AFR[0] |= (uint8_t)(type << (pin * 4));
	}
		else
		{
		  port -> AFR[1] |= (uint8_t)(type << (pin * 4));
		}
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
	PORT -> BSRR |= 1 << (pin*1);
	
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
