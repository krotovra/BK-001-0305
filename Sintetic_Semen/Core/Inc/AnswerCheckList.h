/*
 * AnswerCheckList.h
 *
 *  Created on: 27 ���. 2020 �.
 *      Author: VasinS
 */

#ifndef ANSWERCHECKLIST_H_
#define ANSWERCHECKLIST_H_

#include "TypeDefine.h"

#define		Answer_Stages_Semen				      	1
#define		Answer_Instruments_For_Semen            2
#define		Answer_Rectocervical_way                3
#define		Answer_Manocervical_way                 4
#define		Answer_Vizocervical_way 		    	5
/*
#define		Answer_Perimeter                    6
#define		Answer_Salpingitis                  7
#define		Answer_Ovariitis                    8
#define		Answer_Persistent_yellow_body       9
#define		Answer_Luteal_cysts                 10
#define		Answer_Ovarian_hypofunction         11
#define		Answer_Follicular_cysts 			12
*/


UINT8 AnswerCheckList_Check(UINT8 question_number, UINT8 answer_number);

#endif /* ANSWERCHECKLIST_H_ */
