/*
 * AnswerCheckList.c
 *
 *  Created on: 27 ���. 2020 �.
 *      Author: VasinS
 */

#include "AnswerCheckList.h"

#define QuestionCount 20
UINT8 QuestionCheckList[QuestionCount]=
{
		Answer_Stages_Semen,					//0
		Answer_Stages_Semen,					//1
		Answer_Stages_Semen,					//2
		Answer_Stages_Semen,					//3
		Answer_Instruments_For_Semen,			//4
		Answer_Instruments_For_Semen,	    	//5
		Answer_Instruments_For_Semen,			//6
		Answer_Instruments_For_Semen,			//7
		Answer_Instruments_For_Semen,			//8
		Answer_Instruments_For_Semen,			//9
		Answer_Instruments_For_Semen,			//10
		Answer_Instruments_For_Semen,			//11
		Answer_Instruments_For_Semen,			//12
		Answer_Instruments_For_Semen,			//13
		Answer_Rectocervical_way,		     	//14
		Answer_Rectocervical_way,               //15
		Answer_Manocervical_way,				//16
		Answer_Manocervical_way,				//17
		Answer_Vizocervical_way,				//18
		Answer_Vizocervical_way					//19

};



UINT8 AnswerCheckList_Check(UINT8 question_number, UINT8 answer_number)
{
	UINT8 result = 0;

	if(QuestionCheckList[question_number] == answer_number)
	{
		result = 1;
	}

	return result;
}


