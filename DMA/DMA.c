#include "DMA.h"

void DMA1_Enable(void)
{
RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
void DMA2_Enable(void)
{
RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	

void DMA_Setup(DMA_Stream_TypeDef *Stream,uint32_t peripheral_address, uint32_t memory_address,
	             uint8_t channel,uint8_t data_direction, uint8_t circular_mode, 
               uint8_t memory_increment_mode, uint8_t memory_data_size, uint8_t priority_level,
               uint16_t buffer_size
                  )
{
	Stream->PAR =   (uint32_t)peripheral_address;
	Stream->M0AR =  (uint32_t)memory_address;
	Stream->CR |= (uint32_t)( (channel << 25) | (priority_level << 16) | (memory_data_size << 13) | 
                            (2 << 11) | (memory_increment_mode << 10) | (circular_mode << 8) |
	                          (data_direction << 6) );
	Stream->NDTR = buffer_size;
	Stream->CR |= DMA_SxCR_EN;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
