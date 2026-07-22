/*
 * RandomSequenceWithoutRepetitions.c
 *
 *  Created on: 24 ���. 2020 �.
 *      Author: VasinS
 */

#include "RandomSequenceWithoutRepetitions.h"

UINT8 RSeqWR[RSeqWRSize];
static UINT8 Position=0;

void RSeqWR_CreateSeq(UINT8 start_value)
{
	srand(start_value);

	for(int i=0; i<RSeqWRSize; i++)
	{
		RSeqWR[i] = i;
	}

	for(int i=0; i<RSeqWRSize-1; i++)
	{
		UINT8 end_pos = RSeqWRSize - 1 - i;
		UINT8 rand_pos = rand() % (RSeqWRSize - i);

		UINT8 sw = RSeqWR[end_pos];
		RSeqWR[end_pos] = RSeqWR[rand_pos];
		RSeqWR[rand_pos] = sw;
	}

	Position = 0;
}

UINT8 RSeqWR_GetSeqSize()
{
	return RSeqWRSize;
}

UINT8 RSeqWR_GetNext()
{
	UINT8 value = RSeqWR[Position];
	Position++;
	Position = Position % RSeqWRSize;

	return value;
}
