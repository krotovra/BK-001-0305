/*
 * StandProcessor.h
 *
 *  Created on: 27 ���. 2020 �.
 *      Author: VasinS
 */

#ifndef STANDPROCESSOR_H_
#define STANDPROCESSOR_H_

#include "TypeDefine.h"
#include "StandProcessorLLF.h"

void StandProcessor_GetInfo_SetAnswer(UINT8 number);
void StandProcessor_LearningStart();
void StandProcessor_ControlStart();
void StandProcessor_Init();

void StandProcessor_GetInfo(UINT8 number);

#endif /* STANDPROCESSOR_H_ */
