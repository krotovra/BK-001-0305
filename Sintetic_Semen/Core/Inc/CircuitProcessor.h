/*
 * CircuitProcessor.h
 *
 *  Created on: 15 èþë. 2019 ã.
 *      Author: VasinS
 */

#ifndef CIRCUITPROCESSOR_H_
#define CIRCUITPROCESSOR_H_

#include "ExtendedBoard.h"

#define ExBoardsCount 1


enum CircuitConfig_State{CircuitConfig_State_ON = 1, CircuitConfig_State_OFF = 0};

enum CircuitConfig_Mode{CircuitConfig_Mode_NORMAL = 0, CircuitConfig_Mode_BLINK = 1};

struct struct_CircuitConfig
{
	UINT8T State  : 1;
	UINT8T Mode   : 1;
	UINT8T Offset : 3;
	UINT8T Period : 3;
};

typedef struct struct_CircuitConfig CircuitConfig;



struct struct_CircuitProcessor
{
	unsigned int Cnt;
	unsigned int PreCnt;
	unsigned int PreCntMax;
	ExtendedBoard ExB[ExBoardsCount];
	CircuitConfig Cf[ExBoardsCount * 40];
};

typedef struct struct_CircuitProcessor CircuitProcessor;



void CircuitProcessor_Init(CircuitProcessor* CP, unsigned int PreCntMax);
void CircuitProcessor_Update(CircuitProcessor* CP);
void CircuitProcessor_SetExBoardPin(CircuitProcessor* CP, UINT8T BoardNum, VoidFunkUType SetClkPinState, VoidFunkUType SetEnPinState, VoidFunkUType SetDataPinState);
void CircuitProcessor_CircuitConfigure(CircuitProcessor* CP, UINT8T CircuitNum, UINT8T Mode, UINT8T Offset, UINT8T Period);
void CircuitProcessor_CircuitSetState(CircuitProcessor* CP, UINT8T CircuitNum, UINT8T State);
void CircuitProcessor_ResetAllCircuit(CircuitProcessor* CP);

#endif /* CIRCUITPROCESSOR_H_ */
