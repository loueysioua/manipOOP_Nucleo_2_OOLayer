#include "stm32f10x_usart.h"
#include "Port_Mode_Names.h"
#include "stm32f10x.h"

#ifndef __STM32_WRAPPER_USART_H
#define __STM32_WRAPPER_USART_H

#ifdef __cplusplus
extern "C" {
#endif

/* =======================================*/
/*    Functions For SERIAL Class --- */
/*----------------------------------------*/
	
void Usart_HAL_Init(COMPORT portNum,PortSpeed speed ,PortConfig config, PortMode mode);
void Serial_HAL_PrintByte(USART_TypeDef* USARTx, uint8_t data);
uint8_t Serial_HAL_ReadByte(USART_TypeDef* USARTx);
void Serial_HAL_PrintString(COMPORT comPort, const char* msg , int length);
char* Serial_HAL_ReadString(COMPORT comPort, int length);
void Serial_HAL_ITPrintString(COMPORT comPort, const char* msg , int length);
char* Serial_HAL_ITReadString(COMPORT comPort, int length);

#ifdef __cplusplus
}
#endif


#endif //__STM32_WRAPPER_USART_H
