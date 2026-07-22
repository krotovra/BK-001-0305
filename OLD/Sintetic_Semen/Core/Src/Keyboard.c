/*
 * Keyboard.c
 *
 *  Created on: 20 ���. 2020 �.
 *      Author: VasinS
 */

#include "Keyboard.h"
#include "StandProcessor.h"
#include "stm32f1xx_hal.h"


#define KeyboardArraySize KeyboardSize / 8 + 1

UINT8 KeyboardArr_curr[KeyboardArraySize];
UINT8 KeyboardArr_old[KeyboardArraySize];
UINT8 KeyboardArr_stable[KeyboardArraySize];

UINT8 KeyboardGetLockState()
{
	return StandProcessor_GetPlayerBusyState();
}

UINT8 ButtonRead(UINT8 button_number)
{
	UINT8 result = 0;

	switch(button_number)
	{
		//объявление кнопок по пинам
		case Key_Stages_Semen:    				    result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);  //Линия5
			break;
		case Key_Instruments_For_Semen:             result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);  //Линия6
			break;
		case Key_Rectocervical_way:               	result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);  //Линия7
			break;
		case Key_Manocervical_way:    				result = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15); //Линия8
			break;
		case Key_Vizocervical_way:                  result = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12); //Линия9
			break;
/*
		case Key_Perimeter:                     result = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11); //Линия10
			break;
		case Key_Salpingitis:                   result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15); //Линия11
			break;
		case Key_Ovariitis:                     result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14); //Линия12
			break;
		case Key_persistent_yellow_body:        result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13); //Линия13
			break;
		case Key_Luteal_cysts:                  result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12); //Линия14
			break;
		case Key_Ovarian_hypofunction:          result = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14); //Линия15
			break;
		case Key_Follicular_cysts:              result = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15); //Линия16
			break;
*/

		//Звук
		case Key_VolumeInc:                     result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);  //Линия4(+Звук)
			break;
		case Key_VolumeDec:                     result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);  //Линия3(-Звук)
			break;

		//Режимы обучения
		case Key_Learning:                      result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);  //Линия1
			break;
		case Key_Control:                       result = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);  //Линия2
			break;

		default: break;
	}

	return result;
}

void ButtonProcess(UINT8 button_number, UINT8 state)
{
	switch(button_number)
	{
		case Key_Stages_Semen:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(1);
			break;

		case Key_Instruments_For_Semen:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(2);
			break;

		case Key_Rectocervical_way:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(3);
			break;

		case Key_Manocervical_way:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(4);
			break;

		case Key_Vizocervical_way:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(5);
			break;
			/*
		case Key_Perimeter:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(6);
			break;

		case Key_Salpingitis:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(7);
			break;

		case Key_Ovariitis:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(8);
			break;

		case Key_persistent_yellow_body:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(9);
			break;


		case Key_Luteal_cysts:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(10);
			break;

		case Key_Ovarian_hypofunction:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(11);
			break;

		case Key_Follicular_cysts:
			if(state == 1) StandProcessor_GetInfo_SetAnswer(12);
			break;
*/




		case Key_Learning:  //Обучение
			if(state == 1) StandProcessor_LearningStart();
			break;

		case Key_Control:  //Экзамен
			if(state == 1) StandProcessor_ControlStart();
			break;

		case Key_VolumeInc:  //+Звук
			if(state == 1) StandProcessor_VolumePlayerInc();
			break;

		case Key_VolumeDec:  //-Звук
			if(state == 1) StandProcessor_VolumePlayerDec();
			break;

		default: break;
	}
}

void KeyboardInit()
{
	for(int i=0; i<KeyboardArraySize; i++)
	{
		KeyboardArr_curr[i]   = 0;
		KeyboardArr_old[i]    = 0;
		KeyboardArr_stable[i] = 0;
	}
}

void KeyboardRead()
{
	for(int i=0; i<KeyboardSize; i++)
	{
		UINT8 KeyState = ButtonRead(i);

		KeyboardArr_curr[(i>>3)] = ((KeyboardArr_curr[(i>>3)]) & ~(1 << (i%8))) | (KeyState << (i%8));
	}
}

void KeyboardProcess()
{
	KeyboardRead();

	if(KeyboardGetLockState() == 0)
	{
		StandProcessor_SetAnswerPositionIndicationState(Answer_Reset);
	}

	for(int i=0; i<KeyboardArraySize; i++)
	{
		if(KeyboardArr_curr[i] != KeyboardArr_stable[i])
		{
			if(KeyboardArr_curr[i] == KeyboardArr_old[i])
			{

				UINT8 NewState    = KeyboardArr_curr[i];
				UINT8 StableState = KeyboardArr_stable[i];
				UINT8 XorState    = NewState ^ StableState;

				for(int j=0; j<8; j++)
				{
					if((XorState & 1) == 1)
					{
						ButtonProcess(i*8 + j, (NewState & 1));
					}

					XorState = XorState >> 1;
					NewState = NewState >> 1;
				}

				KeyboardArr_stable[i] = KeyboardArr_old[i];
			}
		}
	}

	for(int i=0; i<KeyboardArraySize; i++)
	{
		KeyboardArr_old[i] = KeyboardArr_curr[i];
	}
}
