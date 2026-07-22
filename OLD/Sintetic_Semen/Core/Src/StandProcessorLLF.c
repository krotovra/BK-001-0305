/*
 * StandProcessorLLF.c
 *
 *  Created on: 27 ���. 2020 �.
 *      Author: VasinS
 */

#include "StandProcessorLLF.h"
#include "stm32f1xx_hal.h"
#include "dfr0299.h"
#include "ExtendedBoard_PinWork.h"
#include "CircuitProcessor.h"

//static UINT8 PlayerVolume = 3;
static VUINT8 Time_ms = 0;
UINT8 PlayerVolume = 0;

CircuitProcessor CP;

void StandProcessor_IncTime_ms()
{
	Time_ms++;
	if(Time_ms == 255) Time_ms = 0;
}

UINT8 StandProcessor_GetTime_ms()
{
	return Time_ms;
}

void StandProcessor_LL_Init()
{
	PlayerVolume = 3;
	Time_ms = 0;

	CircuitProcessor_SetExBoardPin(&CP, 0, ExB0_SetClkPinState, ExB0_SetEnPinState, ExB0_SetDataPinState);
	CircuitProcessor_Init(&CP, 40);

	StandProcessor_SetAnswerResultIndicationState(Answer_Reset);
	StandProcessor_SetAnswerPositionIndicationState(Answer_Reset);

	StandProcessor_SetWorkModeLed(0);

	CircuitProcessor_Update(&CP);

//	mp3_set_device (2);

	StandProcessor_SetVolumePlayer();
}

UINT8 StandProcessor_GetPlayerBusyState()
{
	UINT8 result = 1 - HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
	return result;
}

void StandProcessor_SetWorkModeLed(UINT8 mode)
{
	switch(mode)
	{
		case 0:

			CircuitProcessor_CircuitSetState(&CP, 3, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 4, CircuitConfig_State_OFF);
			CircuitProcessor_Update(&CP);
			break;
		case 1:

			CircuitProcessor_CircuitSetState(&CP, 3, CircuitConfig_State_OFF);
			CircuitProcessor_CircuitSetState(&CP, 4, CircuitConfig_State_ON);

			CircuitProcessor_Update(&CP);
			break;
	}
}

void StandProcessor_SetVolumePlayer()
{
	switch(PlayerVolume)
	{
		case 0:
			CircuitProcessor_CircuitSetState(&CP, 5, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 6, CircuitConfig_State_OFF);
			CircuitProcessor_CircuitSetState(&CP, 7, CircuitConfig_State_OFF);
			CircuitProcessor_CircuitSetState(&CP, 8, CircuitConfig_State_OFF);
			CircuitProcessor_CircuitSetState(&CP, 9, CircuitConfig_State_OFF);
			CircuitProcessor_Update(&CP);
			mp3_set_volume(14);
			break;
		case 1:
			CircuitProcessor_CircuitSetState(&CP, 5, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 6, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 7, CircuitConfig_State_OFF);
			CircuitProcessor_CircuitSetState(&CP, 8, CircuitConfig_State_OFF);
			CircuitProcessor_CircuitSetState(&CP, 9, CircuitConfig_State_OFF);
			CircuitProcessor_Update(&CP);
			mp3_set_volume(18);
			//mp3_set_volume(5);
			break;
		case 2:
			CircuitProcessor_CircuitSetState(&CP, 5, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 6, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 7, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 8, CircuitConfig_State_OFF);
			CircuitProcessor_CircuitSetState(&CP, 9, CircuitConfig_State_OFF);
			CircuitProcessor_Update(&CP);
			mp3_set_volume(22);
			break;
		case 3:
			CircuitProcessor_CircuitSetState(&CP, 5, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 6, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 7, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 8, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 9, CircuitConfig_State_OFF);
			CircuitProcessor_Update(&CP);
			mp3_set_volume(26);
			break;
		case 4:
			CircuitProcessor_CircuitSetState(&CP, 5, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 6, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 7, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 8, CircuitConfig_State_ON);
			CircuitProcessor_CircuitSetState(&CP, 9, CircuitConfig_State_ON);
			CircuitProcessor_Update(&CP);
			mp3_set_volume(30);
			break;
		default:
			break;
	}
}

void StandProcessor_VolumePlayerInc()
{
	if(PlayerVolume < 4)
	{
		PlayerVolume++;
		StandProcessor_SetVolumePlayer();
	}
}

void StandProcessor_VolumePlayerDec()
{
	if(PlayerVolume > 0)
	{
		PlayerVolume--;
		StandProcessor_SetVolumePlayer();
	}
}

void StandProcessor_SetAnswerResultIndicationState(UINT8 s)
{
	switch(s)
	{
	case Answer_Reset:
		CircuitProcessor_CircuitSetState(&CP, 2, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 1, CircuitConfig_State_OFF);
		CircuitProcessor_Update(&CP);
		break;

	case Answer_Correct:
		CircuitProcessor_CircuitSetState(&CP, 2, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 1, CircuitConfig_State_OFF);
		CircuitProcessor_Update(&CP);
		break;

	case Answer_Incorrect:
		CircuitProcessor_CircuitSetState(&CP, 2, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 1, CircuitConfig_State_ON);
		CircuitProcessor_Update(&CP);
		break;

	default:
		break;
	}
}


void StandProcessor_SetAnswerPositionIndicationState(UINT8 s)
{
	switch(s)
	{
	case Answer_Reset:
		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
/*		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);*/
		break;

	case Stages_Semen:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
/*		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);*/
		break;

	case Instruments_For_Semen:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
/*		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);*/
		break;

	case Rectocervical_way:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
/*		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);*/
		break;

	case Manocervical_way:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
/*		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);*/
		break;

	case Vizocervical_way:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_ON);
/*		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);*/
		break;

	/*case Perimeter:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);
		break;

	case Salpingitis:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);
		break;

	case Ovariitis:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);
		break;

	case Persistent_yellow_body:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);
		break;

	case Luteal_cysts:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);
		break;

	case Ovarian_hypofunction:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_ON);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_OFF);
		break;

	case Follicular_cysts:

		CircuitProcessor_CircuitSetState(&CP, 10, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 11, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 12, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 13, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 14, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 15, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 16, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 17, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 18, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 19, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 20, CircuitConfig_State_OFF);
		CircuitProcessor_CircuitSetState(&CP, 21, CircuitConfig_State_ON);
		break;*/



	default:
		break;
	}
	CircuitProcessor_Update(&CP);
}

/*void Flash_All()
{
//	CircuitProcessor_ResetAllCircuit(&CP);

CircuitProcessor_CircuitSetState(&CP, 1, 1);
			CircuitProcessor_Update(&CP);
			HAL_Delay(2000);
			CircuitProcessor_CircuitSetState(&CP, 1, 0);
			CircuitProcessor_Update(&CP);

			HAL_Delay(2000);

for(UINT8 num = 0; num < 40; num++){

		CircuitProcessor_CircuitSetState(&CP, num+1, 1);
		CircuitProcessor_Update(&CP);
	HAL_Delay(3000);
		CircuitProcessor_CircuitSetState(&CP, num+1, 0);
		CircuitProcessor_Update(&CP);*/

