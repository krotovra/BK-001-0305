/*
 * UART.h
 *
 *  Created on: 29 θών. 2020 γ.
 *      Author: VasinS
 */

#ifndef UART_H_
#define UART_H_

#include "CircularBuffer.h"

void UART_WriteByte(char b);
void UART_WriteString(char* SendBuf, int len);
void UART_StartTransmit();
void UART_Recive();
void UART_Transmit();
void UART_Init();

#endif /* UART_H_ */
