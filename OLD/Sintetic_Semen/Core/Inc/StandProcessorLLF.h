/*
 * StandProcessorLLF.h
 *
 *  Created on: 27 ���. 2020 �.
 *      Author: VasinS
 */

#ifndef STANDPROCESSORLLF_H_
#define STANDPROCESSORLLF_H_

#include "TypeDefine.h"

#define PinON  1
#define PinOFF 0

#define Answer_Reset     0

#define Answer_Correct   1
#define Answer_Incorrect 2

#define Stages_Semen				      1
#define Instruments_For_Semen             2
#define Rectocervical_way                 3
#define Manocervical_way                  4
#define Vizocervical_way			      5
/*
#define Perimeter                     6
#define Salpingitis                   7
#define Ovariitis                     8
#define Persistent_yellow_body        9
#define Luteal_cysts                  10
#define Ovarian_hypofunction          11
#define Follicular_cysts              12
*/


void StandProcessor_SetVolumePlayer();
void StandProcessor_VolumePlayerInc();
void StandProcessor_VolumePlayerDec();

void StandProcessor_SetAnswerResultIndicationState(UINT8 s);
void StandProcessor_SetAnswerPositionIndicationState(UINT8 s);
void StandProcessor_SetItemPositionIndicationState(UINT8 s);
void StandProcessor_SetWorkModeLed(UINT8 mode);
void StandProcessor_LL_Init();

UINT8 StandProcessor_GetTime_ms();
void StandProcessor_IncTime_ms();

UINT8 StandProcessor_GetPlayerBusyState();


//void Flash_All();

#endif /* STANDPROCESSORLLF_H_ */
