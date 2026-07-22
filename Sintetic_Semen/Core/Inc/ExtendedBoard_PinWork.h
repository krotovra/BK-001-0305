


#ifndef EXTENDED_BOARD_PIN_WORK_H
#define EXTENDED_BOARD_PIN_WORK_H

#include "stm32f1xx_hal.h"

#define ExtB_CLK_port_0		GPIOA//A
#define ExtB_CLK_pin_0		GPIO_PIN_6//3
#define ExtB_EN_port_0		GPIOA//A
#define ExtB_EN_pin_0		GPIO_PIN_7//4
#define ExtB_DATA_port_0	GPIOB//A
#define ExtB_DATA_pin_0		GPIO_PIN_0//5

void ExB0_SetClkPinState(uint8_t State);
void ExB0_SetEnPinState(uint8_t State);
void ExB0_SetDataPinState(uint8_t State);

#endif
