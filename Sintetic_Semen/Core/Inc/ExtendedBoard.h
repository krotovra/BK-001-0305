/*
 * ExtendedBoard.h
 *
 * Created: 20.06.2019 9:00:22
 *  Author: VasinS
 */ 


#ifndef EXTENDEDBOARD_H_
#define EXTENDEDBOARD_H_

#define UINT8T unsigned char
typedef  void (*VoidFunkUType)(UINT8T);

struct struct_ExtendedBoard
{
	//битовая строка для хранения
	//состояния светодиодов
	UINT8T BitStr[5];
	
	//указатели на функции работы с
	//аппаратной частью
	//должны быть определены
	VoidFunkUType ExtendedBoard_SetClkPinState;
	VoidFunkUType ExtendedBoard_SetEnPinState;
	VoidFunkUType ExtendedBoard_SetDataPinState;	
};

typedef struct struct_ExtendedBoard ExtendedBoard;

void ExtendedBoard_Init(ExtendedBoard* ExB, VoidFunkUType SetClkPinState, VoidFunkUType SetEnPinState, VoidFunkUType SetDataPinState);
void ExtendedBoard_Update(ExtendedBoard* ExB);
void ExtendedBoard_SetLedState(ExtendedBoard* ExB, UINT8T ledNum, UINT8T state);
void ExtendedBoard_ClearAll(ExtendedBoard* ExB);
void ExtendedBoard_SetAll(ExtendedBoard* ExB);

#endif /* EXTENDEDBOARD_H_ */
