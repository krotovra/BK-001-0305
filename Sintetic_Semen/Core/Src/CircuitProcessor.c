/*
 * CircuitProcessor.c
 *
 *  Created on: 15 июл. 2019 г.
 *      Author: VasinS
 */

#include "CircuitProcessor.h"

void CircuitProcessor_ResetAllCircuit(CircuitProcessor* CP)
{
	for(int i = 0; i < ExBoardsCount * 40; i++)
	{
		( (CP->Cf)[i] ).State = CircuitConfig_State_OFF;
		( (CP->Cf)[i] ).Mode  = CircuitConfig_Mode_NORMAL;
		( (CP->Cf)[i] ).Period = 0;
		( (CP->Cf)[i] ).Offset = 0;
	}

	CP->Cnt = 0;
	CP->PreCnt = 0;
}

void CircuitProcessor_Init(CircuitProcessor* CP, unsigned int PreCntMax)
{
	for(int i = 0; i < ExBoardsCount; i++)
	{
		ExtendedBoard_ClearAll( &((CP->ExB)[i]) );
	}

	for(int i = 0; i < ExBoardsCount; i++)
	{
		ExtendedBoard_Update( &((CP->ExB)[i]) );
	}

	CP->Cnt = 0;
	CP->PreCnt = 0;
	CP->PreCntMax = PreCntMax;

	for(int i = 0; i < ExBoardsCount * 40; i++)
	{
		( (CP->Cf)[i] ).State = CircuitConfig_State_OFF;
		( (CP->Cf)[i] ).Mode  = CircuitConfig_Mode_NORMAL;
		( (CP->Cf)[i] ).Period = 0;
		( (CP->Cf)[i] ).Offset = 0;
	}
}


void CircuitProcessor_Update(CircuitProcessor* CP)
{


	for(int i = 0; i < ExBoardsCount; i++)
	{
		for(int j = 0; j < 40; j++)
		{
			CircuitConfig cconf = (CP->Cf)[i*40 + j];
			if(cconf.State == CircuitConfig_State_OFF)
			{
				//если цепь выключена:
				ExtendedBoard_SetLedState( &((CP->ExB)[i]), j, 0);
			}
			else if(cconf.Mode == CircuitConfig_Mode_NORMAL)
			{
				//иначе,
				//если режим работы цепи "НОРМАЛЬНЫЙ":
				ExtendedBoard_SetLedState( &((CP->ExB)[i]), j, 1);
			}
			else
			{
				//иначе,
				//если режим работы цепи "МИГАНИЕ":
				signed int offset = (signed int)(cconf.Offset);
				signed int period = (signed int)(cconf.Period);
				signed int cnt    = (signed int)(CP->Cnt);
				signed int t      = (signed int)0;

				t = cnt - offset;


				if( (t % period) == 0 )
				{
					ExtendedBoard_SetLedState( &((CP->ExB)[i]), j, 1);
				}
				else
				{
					ExtendedBoard_SetLedState( &((CP->ExB)[i]), j, 0);
				}
			}
		}

		CP->PreCnt = CP->PreCnt + 1;

		if((CP->PreCnt) == (CP->PreCntMax))
		{
			CP->Cnt = (CP->Cnt + 1) % 840;
			CP->PreCnt = 0;
		}




		ExtendedBoard_Update( &((CP->ExB)[i]) );
	}
}

void CircuitProcessor_SetExBoardPin(CircuitProcessor* CP, UINT8T BoardNum, VoidFunkUType SetClkPinState, VoidFunkUType SetEnPinState, VoidFunkUType SetDataPinState)
{
	ExtendedBoard_Init(&( (CP->ExB)[BoardNum] ), SetClkPinState, SetEnPinState, SetDataPinState);
}

void CircuitProcessor_CircuitConfigure(CircuitProcessor* CP, UINT8T CircuitNum, UINT8T Mode, UINT8T Offset, UINT8T Period)
{
	( (CP->Cf)[CircuitNum - 1] ).Period = Period;
	( (CP->Cf)[CircuitNum - 1] ).Offset = Offset;
	( (CP->Cf)[CircuitNum - 1] ).Mode   = Mode;
}

void CircuitProcessor_CircuitSetState(CircuitProcessor* CP, UINT8T CircuitNum, UINT8T State)
{
	( (CP->Cf)[CircuitNum - 1] ).State = State;
}
