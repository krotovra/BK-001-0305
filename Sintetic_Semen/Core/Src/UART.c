/*
 * UART.c
 *
 *  Created on: 29 июн. 2020 г.
 *      Author: VasinS
 */

#include "UART.h"
#include "stm32f1xx_hal.h"

//входной кольцевой буфер
#define SizeInCb 256
char InCbMemory[SizeInCb];
CircularBuffer InCb;

//выходной кольцевой буфер
#define SizeOutCb 256
char OutCbMemory[SizeOutCb];
CircularBuffer OutCb;

//----------------------------------------------------
//  команды дл¤ работы с UART
//----------------------------------------------------

void UART_WriteByte(char b)
{
	CBuff_AddChar(&OutCb, b);
}

void UART_WriteString(char* SendBuf, int len)
{
	for(int i=0; i<len; i++)
	{
		UART_WriteByte(SendBuf[i]);
	}
}

void UART_StartTransmit()
{
	if(!CBuff_IsEmpty(&OutCb))
	{
		USART1->DR = CBuff_GetChar(&OutCb);
		HAL_Delay(200);
	}
}

void UART_Recive()
{
	//пока что - то приходит по UART
	if(USART1->SR & USART_SR_RXNE)
	{
		//читаем символ из UART
		CBuff_AddChar(&InCb, USART1->DR);
	}
}


void UART_Transmit()
{
	if((USART1->SR & USART_SR_TC)!=0)
	{
	    USART1->SR &= ~USART_SR_TC;

		if(!CBuff_IsEmpty(&OutCb))
		{
			USART1->DR = CBuff_GetChar(&OutCb);
		}
	}

}

void UART_Init()
{
	//разрешаем прерывани¤ по uart
	USART1->CR1 |= USART_CR1_TCIE;     //прерывание по окончанию передачи
	USART1->CR1 |= USART_CR1_RXNEIE;   //прерывание по приему данных
	USART1->CR3 |= USART_CR3_EIE;      //в случае если активируютс¤ флажки ORE,FE,NF из SR это будет генерировать прерывани¤

	//инициализируем входные и
	//выходные кольцевые буферы
	CBuff_Init(&InCb,  (char*)InCbMemory,  SizeInCb);
	CBuff_Init(&OutCb, (char*)OutCbMemory, SizeOutCb);
}
