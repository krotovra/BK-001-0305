/*
 * ExtendedBoard_PinWork.c
 *
 *  Created on: 28 èþë. 2020 ã.
 *      Author: VasinS
 */

#include "ExtendedBoard_PinWork.h"

void ExB0_SetClkPinState(uint8_t State)
{
	HAL_GPIO_WritePin(ExtB_CLK_port_0, ExtB_CLK_pin_0, State);
	asm ("nop""\n\tnop""\n\tnop""\n\tnop""\n\tnop""\n\tnop");
	asm ("nop""\n\tnop""\n\tnop""\n\tnop""\n\tnop""\n\tnop");
	//HAL_Delay(10);
}

void ExB0_SetEnPinState(uint8_t State)
{
	HAL_GPIO_WritePin(ExtB_EN_port_0, ExtB_EN_pin_0, State);
	asm ("nop""\n\tnop""\n\tnop""\n\tnop""\n\tnop""\n\tnop");
	asm ("nop""\n\tnop""\n\tnop""\n\tnop""\n\tnop""\n\tnop");
	//HAL_Delay(10);
}

void ExB0_SetDataPinState(uint8_t State)
{
	HAL_GPIO_WritePin(ExtB_DATA_port_0, ExtB_DATA_pin_0, State);
	asm ("nop""\n\tnop""\n\tnop""\n\tnop""\n\tnop""\n\tnop");
	asm ("nop""\n\tnop""\n\tnop""\n\tnop""\n\tnop""\n\tnop");
	//HAL_Delay(10);
}
