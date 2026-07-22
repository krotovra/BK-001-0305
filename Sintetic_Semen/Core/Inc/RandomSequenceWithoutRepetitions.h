/*
 * RandomSequenceWithoutRepetitions.h
 *
 *  Created on: 24 ���. 2020 �.
 *      Author: VasinS
 */

#ifndef RANDOMSEQUENCEWITHOUTREPETITIONS_H_
#define RANDOMSEQUENCEWITHOUTREPETITIONS_H_

#include "TypeDefine.h"
#include "stdlib.h"

#define RSeqWRSize 20

void  RSeqWR_CreateSeq(UINT8 start_value);
UINT8 RSeqWR_GetSeqSize();
UINT8 RSeqWR_GetNext();

#endif /* RANDOMSEQUENCEWITHOUTREPETITIONS_H_ */
