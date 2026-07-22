/*
 * StandProcessor.c
 *
 *  Created on: 27 ���. 2020 �.
 *      Author: VasinS
 */

#include "AnswerCheckList.h"
#include "StandProcessor.h"
#include "RandomSequenceWithoutRepetitions.h"
#include "stm32f1xx_hal.h"
#include "dfr0299.h"

#define TrackOffset 0	///////
#define QCount 5		///////////дефайн для пропуска ответов
#define LearningMode 0
#define ControlMode  1
static UINT8 WorkMode = LearningMode;
static UINT8 RemainingQuestionCount = 0;
static UINT8 LastQuestionNumber = 0;
static UINT8 OldInfoNum = 255;

void StandProcessor_Init()
{
	WorkMode = LearningMode;

	RemainingQuestionCount = 0;
	LastQuestionNumber = 0;
	OldInfoNum = 255;

	StandProcessor_LL_Init();
}

void StandProcessor_RemainingQuestionCountDec()
{
	if(RemainingQuestionCount > 0)
	{
		RemainingQuestionCount--;
	}

}

void StandProcessor_CheckOldQuestion(UINT8 answer_number)
{
	if(AnswerCheckList_Check(LastQuestionNumber, answer_number) == 1)
	{
		StandProcessor_SetAnswerResultIndicationState(Answer_Correct);
	}
	else
	{
		StandProcessor_SetAnswerResultIndicationState(Answer_Incorrect);
	}
}

void StandProcessor_GetInfo(UINT8 number)
{
	mp3_specify_tracking(number);
	HAL_Delay(500);
}

void StandProcessor_AskNextQuestion()
{
	StandProcessor_SetAnswerResultIndicationState(Answer_Reset);

	LastQuestionNumber = RSeqWR_GetNext();
	StandProcessor_RemainingQuestionCountDec();
	mp3_specify_tracking(QCount + LastQuestionNumber + 1);

}

void StandProcessor_GetInfo_SetAnswer(UINT8 number)
{
	if(WorkMode == LearningMode)
	{
		if((StandProcessor_GetPlayerBusyState() == 1) && (OldInfoNum == number))
		{
			StandProcessor_SetAnswerPositionIndicationState(Answer_Reset);
			mp3_stop();
		}
		else
		{
			StandProcessor_GetInfo(number);
			StandProcessor_SetAnswerPositionIndicationState(number);
		}

		OldInfoNum = number;
	}

	if(WorkMode == ControlMode)
	{
		StandProcessor_SetAnswerPositionIndicationState(number);
		StandProcessor_CheckOldQuestion(number);

		HAL_Delay(1000);

		StandProcessor_SetAnswerPositionIndicationState(Answer_Reset);
		if(RemainingQuestionCount == 0)
		{
			StandProcessor_LearningStart();
		}
		else
		{
			StandProcessor_AskNextQuestion();
		}
	}
}

void StandProcessor_LearningStart()
{
	WorkMode = LearningMode;
	RemainingQuestionCount = 0;

	StandProcessor_SetWorkModeLed(LearningMode);
	StandProcessor_SetAnswerResultIndicationState(Answer_Reset);
	mp3_stop();
}

void StandProcessor_ControlStart()
{

	RSeqWR_CreateSeq(StandProcessor_GetTime_ms());
	WorkMode = ControlMode;
	RemainingQuestionCount = 20   ;			////////////////


	StandProcessor_SetWorkModeLed(ControlMode);
	StandProcessor_SetAnswerPositionIndicationState(Answer_Reset);
	StandProcessor_AskNextQuestion();
}


