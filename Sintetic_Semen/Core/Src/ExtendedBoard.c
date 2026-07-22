/*
 * ExtendedBoard.c
 *
 * Created: 20.06.2019 9:01:25
 *  Author: VasinS
 */ 

#include "ExtendedBoard.h"

void ExtendedBoard_Init(ExtendedBoard* ExB, VoidFunkUType SetClkPinState, VoidFunkUType SetEnPinState, VoidFunkUType SetDataPinState)
{
	ExB->ExtendedBoard_SetClkPinState  = SetClkPinState;
	ExB->ExtendedBoard_SetEnPinState   = SetEnPinState;
	ExB->ExtendedBoard_SetDataPinState = SetDataPinState;


	//устанавливаем линию ENABLE в HIGH
	(ExB->ExtendedBoard_SetEnPinState)(1);
	//устанавливаем линию CLK в LOW
	(ExB->ExtendedBoard_SetClkPinState)(0);
	//устанавливаем линию DATA
	(ExB->ExtendedBoard_SetDataPinState)(0);
}

void ExtendedBoard_SetBit(ExtendedBoard* ExB, UINT8T BytePosition, UINT8T BitPosition)
{
	(ExB->BitStr)[BytePosition] = (ExB->BitStr)[BytePosition] | (1 << BitPosition); 
}

void ExtendedBoard_ResetBit(ExtendedBoard* ExB, UINT8T BytePosition, UINT8T BitPosition)
{
	(ExB->BitStr)[BytePosition] = (ExB->BitStr)[BytePosition] & ~(1 << BitPosition);
}

UINT8T ExtendedBoard_GetBit(ExtendedBoard* ExB, UINT8T BytePosition, UINT8T BitPosition)
{
	return (((ExB->BitStr)[BytePosition]) >> BitPosition) & 1;
}

void ExtendedBoard_Update(ExtendedBoard* ExB)
{
	//устанавливаем линию CLK в LOW
	(ExB->ExtendedBoard_SetClkPinState)(0);
	
	//устанавливаем линию ENABLE в LOW
	(ExB->ExtendedBoard_SetEnPinState)(0);
	
	
	for(int i=4; i>=0; i--)
	{
		for(int j=7; j>=0; j--)
		{
			UINT8T state = ExtendedBoard_GetBit(ExB, i, j);
			
			//устанавливаем линию DATA
			(ExB->ExtendedBoard_SetDataPinState)(state);
			
			//устанавливаем линию CLK в HIGH
			(ExB->ExtendedBoard_SetClkPinState)(1);
			
			//устанавливаем линию CLK в LOW
			(ExB->ExtendedBoard_SetClkPinState)(0);			
		}
	}
	
	
	//устанавливаем линию ENABLE в HIGH
	(ExB->ExtendedBoard_SetEnPinState)(1);
}

void ExtendedBoard_SetLedState(ExtendedBoard* ExB, UINT8T ledNum, UINT8T state)
{
	//ограничим максимальный номер светодиода
	ledNum = ledNum % 40;
	
	UINT8T BytePosition = ledNum / 8;
	UINT8T BitPosition  = ledNum % 8;
	
	if(state == 0)
	{
		ExtendedBoard_ResetBit(ExB, BytePosition , BitPosition);
	}
	else
	{
		ExtendedBoard_SetBit(ExB, BytePosition , BitPosition);
	}

}

void ExtendedBoard_ClearAll(ExtendedBoard* ExB)
{
	for(int i = 0; i<5; i++)
	{
		(ExB->BitStr)[i] = 0;
	}
}

void ExtendedBoard_SetAll(ExtendedBoard* ExB)
{
	for(int i = 0; i<5; i++)
	{
		(ExB->BitStr)[i] = 255;
	}
}
